#include <Arduino.h>
#include <App.hpp>
#include "SimpleWiFi.h"

static byte mac[6];

void disableWiFi()
{
  WiFi.disconnect();
  WiFi.persistent(false);
  WiFi.mode(WIFI_OFF);
  delay(1000);
}

void connectWiFi()
{
  Serial.print("\nConnecting to WiFi network: " WIFI_SSID " " );

  WiFi.mode(WIFI_OFF);
  WiFi.disconnect(true,true);
  delay(2000);

  WiFi.begin();
  WiFi.setHostname(HOSTNAME);
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASS);

  while (WiFi.status() != WL_CONNECTED)
  {
    digitalWrite( BOARD_LED, 1 ^ digitalRead(BOARD_LED));
    delay(500);
    Serial.print(".");
  }

  Serial.println(" connected.\n");
  digitalWrite( BOARD_LED, false );

  WiFi.macAddress(mac);
  Serial.printf("WiFi MAC Address    : %02X:%02X:%02X:%02X:%02X:%02X\n", mac[0], mac[1], mac[2], mac[3], mac[4], mac[5] );
  Serial.printf("WiFi Hostname       : %s\n", WiFi.getHostname());
  Serial.print( "WiFi IP-Address     : " );
  Serial.println( WiFi.localIP() );
  Serial.print( "WiFi Gateway-IP     : " );
  Serial.println( WiFi.gatewayIP() );
  Serial.print( "WiFi Subnetmask     : " );
  Serial.println( WiFi.subnetMask() );
  Serial.print( "WiFi DNS Server     : " );
  Serial.println( WiFi.dnsIP() );
  Serial.println();
}
