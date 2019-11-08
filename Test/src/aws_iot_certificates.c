/*
 * Copyright 2010-2015 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * Additions Copyright 2016 Espressif Systems (Shanghai) PTE LTD
 *
 * Licensed under the Apache License, Version 2.0 (the "License").
 * You may not use this file except in compliance with the License.
 * A copy of the License is located at
 *
 *  http://aws.amazon.com/apache2.0
 *
 * or in the "license" file accompanying this file. This file is distributed
 * on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
 * express or implied. See the License for the specific language governing
 * permissions and limitations under the License.
 */

/**
 * @file aws_iot_certifcates.c
 * @brief File to store the AWS certificates in the form of arrays
 */

#ifdef __cplusplus
extern "C" {
#endif

const char aws_root_ca_pem[] = {"-----BEGIN CERTIFICATE-----\n\
MIIDQTCCAimgAwIBAgITBmyfz5m/jAo54vB4ikPmljZbyjANBgkqhkiG9w0BAQsF\n\
ADA5MQswCQYDVQQGEwJVUzEPMA0GA1UEChMGQW1hem9uMRkwFwYDVQQDExBBbWF6\n\
b24gUm9vdCBDQSAxMB4XDTE1MDUyNjAwMDAwMFoXDTM4MDExNzAwMDAwMFowOTEL\n\
MAkGA1UEBhMCVVMxDzANBgNVBAoTBkFtYXpvbjEZMBcGA1UEAxMQQW1hem9uIFJv\n\
b3QgQ0EgMTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBALJ4gHHKeNXj\n\
ca9HgFB0fW7Y14h29Jlo91ghYPl0hAEvrAIthtOgQ3pOsqTQNroBvo3bSMgHFzZM\n\
9O6II8c+6zf1tRn4SWiw3te5djgdYZ6k/oI2peVKVuRF4fn9tBb6dNqcmzU5L/qw\n\
IFAGbHrQgLKm+a/sRxmPUDgH3KKHOVj4utWp+UhnMJbulHheb4mjUcAwhmahRWa6\n\
VOujw5H5SNz/0egwLX0tdHA114gk957EWW67c4cX8jJGKLhD+rcdqsq08p8kDi1L\n\
93FcXmn/6pUCyziKrlA4b9v7LWIbxcceVOF34GfID5yHI9Y/QCB/IIDEgEw+OyQm\n\
jgSubJrIqg0CAwEAAaNCMEAwDwYDVR0TAQH/BAUwAwEB/zAOBgNVHQ8BAf8EBAMC\n\
AYYwHQYDVR0OBBYEFIQYzIU07LwMlJQuCFmcx7IQTgoIMA0GCSqGSIb3DQEBCwUA\n\
A4IBAQCY8jdaQZChGsV2USggNiMOruYou6r4lK5IpDB/G/wkjUu0yKGX9rbxenDI\n\
U5PMCCjjmCXPI6T53iHTfIUJrU6adTrCC2qJeHZERxhlbI1Bjjt/msv0tadQ1wUs\n\
N+gDS63pYaACbvXy8MWy7Vu33PqUXHeeE6V/Uq2V8viTO96LXFvKWlJbYK8U90vv\n\
o/ufQJVtMVT8QtPHRh8jrdkPSHCa2XV4cdFyQzR1bldZwgJcJmApzyMZFo6IQ6XU\n\
5MsI+yMRQ+hDKXJioaldXgjUkK642M4UwtBV8ob2xJNDd2ZhwLnoQdeXeGADbkpy\n\
rqXRfboQnoZsG4q5WTP468SQvvG5\n\
-----END CERTIFICATE-----\n"};

const char certificate_pem_crt[] = {"-----BEGIN CERTIFICATE-----\n\
MIIDWjCCAkKgAwIBAgIVANZTHMC+rFXuKXzB4osSnMtyH68QMA0GCSqGSIb3DQEB\n\
CwUAME0xSzBJBgNVBAsMQkFtYXpvbiBXZWIgU2VydmljZXMgTz1BbWF6b24uY29t\n\
IEluYy4gTD1TZWF0dGxlIFNUPVdhc2hpbmd0b24gQz1VUzAeFw0xOTExMDMxMTIx\n\
MzhaFw00OTEyMzEyMzU5NTlaMB4xHDAaBgNVBAMME0FXUyBJb1QgQ2VydGlmaWNh\n\
dGUwggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQCUuCyFAg5d1dMqERgZ\n\
zySs4P/1WvAvM+O4KjVEev6vdMSVUWXyWYxbfdL7orKBc1k3B+AtUEp4Xn4Tfoj4\n\
MNLge75239GMEKCm3fDxh4Fu++sLXAdB8jrxceHUTC+IpMJPFjRgWTuX8XZZabvY\n\
VmVC9npHaOOCJaSWkiai5Uh+5LE3KQI6m7WvriUXmYtqNIqy7Mxnt4XvWfsS5nIm\n\
0ExqroKSZOyhHVNi2VsOv94/3fSjiQoOwE25z9d5wNZjB13yPXVJ5NHIuERdmycx\n\
NfXBY1f4GlIx7cZSpQRgowNMKF1/dDjc9NdNUTSC7aLSoUGGwRRt99IOofKLLGJj\n\
cUifAgMBAAGjYDBeMB8GA1UdIwQYMBaAFJ5cOTuuKAtOQiUWon9AgdapwqTEMB0G\n\
A1UdDgQWBBQbQM6tv9Iu3gAaPxJGaFxDB5qAjjAMBgNVHRMBAf8EAjAAMA4GA1Ud\n\
DwEB/wQEAwIHgDANBgkqhkiG9w0BAQsFAAOCAQEAo9BF2ypvQWXCnsM1d/Hmnhot\n\
J0a/38BmjPrdL6e+Afks/F2XGLnyfILr2O/k2irXnYCRXorUN7ol8v9OooVz7xZb\n\
XsEY3yjleAdL8goCHdxfUI06RzQFXUfH70IY+1udC/FPRzNGIZc0sswuFXPFeaY3\n\
OCQNUFcGVu99k56g/H5iwEyYYmXyQBui+0IUuT/3IbT9QuKOC2jg+ZZLnRE04PJ6\n\
mG9KTaXJnMLtGYn9ILrXTxDn8Chm2tUFXZKtn7q6kLtFZLJPQzsaJygUIiOV75DK\n\
iT6WlCYoIqiFW+mIR4V+Us87HsxMd/JwbuDd/VzVOJou5oug5N8dEWE85Jr99Q==\n\
-----END CERTIFICATE-----\n"};

const char private_pem_key[] = {"-----BEGIN RSA PRIVATE KEY-----\n\
MIIEpAIBAAKCAQEAlLgshQIOXdXTKhEYGc8krOD/9VrwLzPjuCo1RHr+r3TElVFl\n\
8lmMW33S+6KygXNZNwfgLVBKeF5+E36I+DDS4Hu+dt/RjBCgpt3w8YeBbvvrC1wH\n\
QfI68XHh1EwviKTCTxY0YFk7l/F2WWm72FZlQvZ6R2jjgiWklpImouVIfuSxNykC\n\
Opu1r64lF5mLajSKsuzMZ7eF71n7EuZyJtBMaq6CkmTsoR1TYtlbDr/eP930o4kK\n\
DsBNuc/XecDWYwdd8j11SeTRyLhEXZsnMTX1wWNX+BpSMe3GUqUEYKMDTChdf3Q4\n\
3PTXTVE0gu2i0qFBhsEUbffSDqHyiyxiY3FInwIDAQABAoIBAQCH2b2BOqGZAexF\n\
LxxO5zPfYCEwJYPl+oZ4AsZp6digug+hPpvbyAU4xjVme/aH3bCPXnhfrEp6rgaJ\n\
FDtWTHM1cJRJzqaCReYax/6DA38uvJy24bgXe4hwadEatwVs0uRUjjoGET0ozP+J\n\
KdbYBgO2KaUFekDo8C3rBVKZ1sxkbGseWni4G/TFSlNbWUY5CTiVQJDSoG0HMIg3\n\
sSbal/0svKsB6TrSHGXmCwLRPe3UiYpD0+2btzs11WtZwAleI9ROmNtIYdnvMPIa\n\
mpyy5ihiRpebHYwOG1ZacwwUEfsbeuTo+XbewKBjdgM8wRS/GWJa7gqlTB3oo7Kz\n\
/dISPFoBAoGBAMUbSnEmZzSspOT3tmVZiOWuxQv/IZ8JsCe+kEvrP2J/VcjQMzLj\n\
KjoGviF7LQ2jpPyPcWJD7DdyRPrzm0HQ/a+njgfAkvblX6L+/AWg6dxEEd9/yK93\n\
SXvXR5aPqVpu37WbYy/xeMvKYB9BBd080nrS1yx7B4N1D1EZnvCmD3AfAoGBAMEn\n\
ve9BfvL57FCZEpUTCrk/z+jDKudnQqJmZua2/+8SxiNTzGSoGfp3bW+O71SddO9v\n\
RxKSKj2DcxShq9CH47b0Gp/ledYYIMk1cnb4aTKxEspRauCf4A/bGnyf1St/Hxs/\n\
Jfr8rVYYzedlYSZscpVR11uOF/wz19+7dd1uiReBAoGBALnTQtluFTrJ0SO0jhb6\n\
1F+F52up+q6PWa3+sNeCT92yotORxdMh63uNQ88Y657COxeIvKKh2p9jcbkN1b+1\n\
IpZp5zNT0LpIAWQP9NXxoMjyu870D+WtFnBUw78kbcs+YFY8ysQ2aWXnw7tzd+3e\n\
G6mEASyESM8cm3YgK4JBbKiNAoGAJ1ZTrT1WgF97zDJQgYG+RloDmrDctQHnpTFb\n\
tZMBbowRRDKVxs4hdEwMQpMGlOH4Zabw/4w7BAoYTtRaLH7wVltCbNwMQxjo3HGB\n\
HU+cBRHg9Mk+Df8hX7lMnKLkhBZAnIjw0DvThVxJ2t1furaNY3GmfWPj6J4aUdtY\n\
tr8DNoECgYAXOoqdWzxqVlQbWStLnzLlUw0raS9kBtMggEkeWdjVtMEUQbghNMcH\n\
sHP4AkjY0UtnH9efGRAUEWBeJH7RAuVZaAJJ/rX8qJqM0DOiYHxjzLg9fDboLyM+\n\
4An5zk4Zxs7Uycb5hDs7mFbHkaYzW9D4YoPmjjQuh/Ip5fpaghzf3A==\n\
-----END RSA PRIVATE KEY-----\n"};


#ifdef __cplusplus
}
#endif
