#include <Arduino.h>
#include <WiFi.h>
#include <Wire.h>
#include <Adafruit_BME280.h>
#include <Adafruit_CCS811.h>
#include <Adafruit_Sensor.h>
#include <AWS_IOT.h>
#include <ArduinoJson.h>
#include <Preferences.h>
#include <DNSServer.h>
#include <WiFiManager.h>

#define SEALEVELPRESSURE_HPA (1013.25)

const size_t capacity = JSON_OBJECT_SIZE(7);



char HOST_ADDRESS[]="al98lr4rrmy3s-ats.iot.us-east-1.amazonaws.com";
char CLIENT_ID[] = "client id";
char TOPIC_NAME[] = "$aws/things/Electronic-Nose/Test2";
unsigned long delayTime;

int status = WL_IDLE_STATUS;
int tick=0,msgCount=0,msgReceived = 0;
char payload[512];
char rcvdPayload[512];

Adafruit_BME280 bme;
Adafruit_CCS811 ccs;
AWS_IOT eNose;
WiFiManager manager;

void mySubCallBackHandler (char *topicName, int payloadLen, char *payLoad)
{
    strncpy(rcvdPayload,payLoad,payloadLen);
    rcvdPayload[payloadLen] = 0;
    msgReceived = 1;
}

void setup() {
    Serial.begin(115200);
    manager.setAPStaticIPConfig(IPAddress(10,0,1,1), IPAddress(10,0,1,1), IPAddress(255,255,255,0));

    // Connect to WiFi using the manager
    manager.autoConnect("Electronic Nose");
    delayTime = 1000;

   delay(2000);

    if(WiFi.status() == WL_CONNECTED) {
        // Connect to AWS IoT and Subscribe to topic
        Serial.println("Connected to WiFi succesfully");
        if(eNose.connect(HOST_ADDRESS, CLIENT_ID) == 0) {
                Serial.println("Connected to AWS");
                delay(delayTime);

                if(0==eNose.subscribe(TOPIC_NAME, mySubCallBackHandler)) {
                    Serial.println("subscribed");
                } else {
                    Serial.println("Subscribe failed.");
                    while(1);
                }
            } else {
                Serial.println("AWS Connection failed");
                while(1);
    }
    }

    // Check sensors are working
    if(!bme.begin() || !ccs.begin()) {
        // bme280 not working or connected wrong
        Serial.println("Sensors are not connected properly!");
    }
    // Wait for the sensor to be ready
    while(!ccs.available());



}

void loop() {

    if(tick >= 5 && ccs.available()) {
        DynamicJsonDocument doc(capacity);
        // Every 10 seconds make a publish
        tick = 0; // reset the tick
        doc["Temperature"] = bme.readTemperature();
        doc["Pressure"] = bme.readPressure();
        doc["Altitude"] = bme.readAltitude(SEALEVELPRESSURE_HPA);
        doc["Humidity"] = bme.readHumidity();
        doc["Alcohol"] = analogRead(33);
        if(!ccs.readData()) {
            doc["CO2"] = ccs.geteCO2();
            doc["TVOC"] = ccs.getTVOC();
            serializeJson(doc,payload);
            if(eNose.publish(TOPIC_NAME, payload) == 0) {
                Serial.print("Publishing Message: ");
                Serial.println(payload);
            } else {
                Serial.println("Publish Failed");
            }
        } else {
            Serial.println("ERROR with CCS!");
            while(1);
        }
        delay(500);

    }



    vTaskDelay(1000/ portTICK_RATE_MS);
    tick++;


}

