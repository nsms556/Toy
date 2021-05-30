#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

const char* ssid = "";
const char* password = "";

ESP8266WebServer server(80);

int LED = 16;
int LED_OFF = HIGH;
int LED_ON = LOW;

void sendHtml(String url){
    String html = "";
    html += "<html><script src=\"http://www.w3schools.com/lib/w3data.js\"></script>";
    html += "<body><div w3-include-html=\"" + url + "\"></div>";
    html += "<script>w3IncludeHTML();</script></body></html>";
    server.send(200, "text/html", html);
}

void setup() {
    pinMode(LED, OUTPUT);
    digitalWrite(LED, LED_ON);
    Serial.begin(115200);

    WiFi.mode(WIFI_STA);
	WiFi.begin(ssid, passwor

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.print("Connected to ");
    Serial.println(WiFi.SSID());
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());

    if (MDNS.begin("esp8266")) {
        Serial.println("MDNS responder started");
    }

    server.on("/", []() {
        sendHtml("");
    });
    server.on("/off", []() {
        sendHtml("");
    });
    server.on("/lv1", []() {
        sendHtml("");
    });
    server.on("/lv2", []() {
        sendHtml("");
    });
    server.on("/lv3", []() {
        sendHtml("");
    });
}