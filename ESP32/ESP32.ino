#if defined(ESP8266)
#include <ESP8266WiFi.h>
#include <SoftwareSerial.h>

SoftwareSerial Serial2(D5, D5); // RX, TX

#elif defined(ESP32)

#include <WiFi.h>

#else

#error Architecture not supported.

#endif

#include <PubSubClient.h>

const char *ssid = "yourSSID";
const char *password = "yourPass";
const char *mqtt_server = "io.adafruit.com";
#define user "yourUser"
#define key "yourAPI"
WiFiClient espClient;
PubSubClient client(espClient);
unsigned long lastMsg = 0;
#define MSG_BUFFER_SIZE (70)
char msg[MSG_BUFFER_SIZE];
String lectura = "";

void setup_wifi()
{
  delay(10);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  randomSeed(micros());

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void reconnect()
{
  // Loop until we're reconnected
  while (!client.connected())
  {
    Serial.print("Attempting MQTT connection...");
    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);
    if (client.connect(clientId.c_str(), user, key))
    {
      Serial.println("connected");
    }
    else
    {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

void setup()
{
  Serial.begin(115200);
  Serial2.begin(9600);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
}

void loop()
{

  if (!client.connected())
  {
    reconnect();
  }

  if (Serial2.available())
  {
    lectura = Serial2.readStringUntil('\n');
    // Serial.println(lectura);
  }

  client.loop();

  unsigned long now = millis();
  if (now - lastMsg > 5000 && lectura != "")
  {
    lastMsg = now;
    Serial.println("Publishing:" + lectura);
    client.publish("Sochoag/feeds/adquisicion-map-and-analog.location", lectura.c_str());
  }
}
