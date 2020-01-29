#include <Arduino.h>
#include <WiFi.h>
#include <ESP32Ping.h>
#include <Wire.h>
#include <PubSubClient.h>
#include <Adafruit_BME280.h>
#include <Adafruit_CCS811.h>
#include <Adafruit_SGP30.h>
#include <Adafruit_ADS1015.h>
#include <Adafruit_Sensor.h>

#define MQTT_VERSION MQTT_VERSION_3_1

#define SEALEVELPRESSURE_HPA (1013.25)

// Sensors
Adafruit_BME280 bme;
Adafruit_CCS811 ccs;
Adafruit_SGP30 sgp;
Adafruit_ADS1115 ads(0x48);  /* Use this for the 16-bit version */

// WiFi constants for phone hotspot
const char* ssid = "Pixel_1459";
const char* password = "test1234";

// mqtt broker 
const char* mqtt_server = "enose.ml";
int mqtt_port = 1884;
long lastmsg = 0;

WiFiClient espClient;
PubSubClient client(espClient);


void connectToNetwork() {
    // Connect to WiFi
    WiFi.begin(ssid, password);
    Serial.println("Connecting to WiFi...");
    while(WiFi.status() != WL_CONNECTED) {
        delay(100);
        Serial.println(".");
        
    }
    Serial.println(WiFi.localIP());

    
}

void callback(char* topic, byte* message, unsigned int length) {
    Serial.print("Message arrived on topic: ");
    Serial.print(topic);
    Serial.print(". Message: ");
    String messageTemp;

    for (int i = 0; i < length; i++) {
        Serial.print((char)message[i]);
        messageTemp += (char)message[i];
    }
    Serial.println();

    // callback for urine detection

}

void setup() {
    Serial.begin(115200);

    connectToNetwork();

    client.setServer(mqtt_server, mqtt_port);
    client.setCallback(callback);
    
    delay(1000);
    //client.subscribe("mqtt/output");

    ads.begin();
    // Check sensors are working
    if(!bme.begin() || !ccs.begin() || !sgp.begin()) {
        Serial.println("Sensors are not connected properly!");
        while(1);
    }
}

void reconnect() {
        char clientID[] = "00000000"; // null terminated 8 chars long
        while(!client.connected()) {
       
        Serial.println("Attempting MQTT connection");
        for (int i = 0; i < 8; i++) {
        clientID[i] = random(65, 91); // use only letters A to Z
        }
        if (client.connect(clientID, "michael", "password")) {
            Serial.println("Connected");
            client.publish("debug", "Connection success!");
        } else {
            Serial.println("Failed to connect. rc = ");
            Serial.print(client.state());
            Serial.println("Trying again in 5 seconds");
            delay(5000);
        }
    }
}

uint32_t getAbsoluteHumidity(float temperature, float humidity) {
    // approximation formula from Sensirion SGP30 Driver Integration chapter 3.15
    const float absoluteHumidity = 216.7f * ((humidity / 100.0f) * 6.112f * exp((17.62f * temperature) / (243.12f + temperature)) / (273.15f + temperature)); // [g/m^3]
    const uint32_t absoluteHumidityScaled = static_cast<uint32_t>(1000.0f * absoluteHumidity); // [mg/m^3]
    return absoluteHumidityScaled;
}



void loop() {
    int16_t mics5524;
    bool ccsDataAvailable = ccs.available();
    bool ccsError = ccs.readData();

    while(WiFi.status() != WL_CONNECTED) {
        Serial.print("Failed to connect to WiFi trying again");
        delay(500);
        Serial.print(".");

    }

    if(!client.connected()) {
        reconnect();
    }
    


    // Read and publish data    


    // Read mics from ADC
    mics5524 = ads.readADC_SingleEnded(0);
    char mics[8];
    // Send MICS alcohol
    dtostrf(mics5524, 1, 2, mics);
    client.publish("mics", mics);

    /* BME 280 */
    // Send temperature
    char temp[8];
    dtostrf(bme.readTemperature(),1,2,temp);
    client.publish("temperature", temp);
    // Send pressure
    char pressure[16];
    //float yum = bme.readPressure();
    dtostrf(bme.readPressure(),1,2,pressure);
    client.publish("pressure", pressure);
    // Send Humidity
    char humidity[16];
    dtostrf(bme.readHumidity(),1,2,humidity);
    client.publish("humidity", humidity);
    


    /* CCS 811 */
    // Send eCO2
    char ccsCO2[16];
    itoa(ccs.geteCO2(), ccsCO2, 10);
    client.publish("CCS_eCO2", ccsCO2);
    // Send Total VOC
    char ccsTVOC[16];
    itoa(ccs.getTVOC(), ccsTVOC, 10);
    client.publish("CCS_TVOC", ccsTVOC);



    /* SGP 30 */
    float bme_temperature = bme.readTemperature();
    float bme_humidity = bme.readHumidity();
    sgp.setHumidity(getAbsoluteHumidity(bme_temperature,bme_humidity));
        if (! sgp.IAQmeasure()) {
        Serial.println("Measurement Failed!");
        return; 
    }
    // Send TVOC
    char sgpTVOC[16];
    itoa(sgp.TVOC, sgpTVOC, 10);
    client.publish("SGP_TVOC", sgpTVOC);
    // Send eCO2
    char sgpeCO2[16];
    itoa(sgp.eCO2, sgpeCO2, 10);
    client.publish("SGP_eCO2", sgpeCO2);

    if (! sgp.IAQmeasureRaw()) {
        Serial.println("Raw Measurement failed");
        return;
    }
    // Send raw H2
    char rawH2[8];
    itoa(sgp.rawH2, rawH2, 10);
    client.publish("SGP_H2", rawH2);
    // Send raw Ethanol
    char rawEthanol[8];
    itoa(sgp.rawEthanol, rawEthanol, 10);
    client.publish("SGP_Ethanol", rawEthanol);

    client.loop();
    delay(2000);
    


}

