#include <Arduino.h>
#include <App.hpp>
#include <SimpleWiFi.h>
#include <CameraSetup.h>
#include <CameraServer.h>

static time_t lastTimestamp = 0;

void setup() {
  pinMode( BOARD_LED, OUTPUT );
  digitalWrite( BOARD_LED, true );  
  Serial.begin(115200);
  delay( 3000 ); // wait for serial monitor
  Serial.setDebugOutput(true);
  Serial.println( "\n\n\n" APP_NAME " - Version " APP_VERSION );
  Serial.println( "Build date: " __DATE__ " " __TIME__ "\n");

  Serial.println();
  Serial.printf("CPU Frequency       : %dMHz\n", ESP.getCpuFreqMHz() );
  Serial.println();

  initializeCamera();

  disableWiFi();
  connectWiFi();

  startCameraServer();

  Serial.print("Camera Ready! Use 'http://");
  Serial.print(WiFi.localIP());
  Serial.println("' to connect");
}

void loop()
{
  time_t currentTimestamp = millis();

  if (( currentTimestamp - lastTimestamp >= 5000 )) // check every 5s
  {
    lastTimestamp = currentTimestamp;

    if( WiFi.isConnected() == false )
    {
      connectWiFi();
    }
  }
}
