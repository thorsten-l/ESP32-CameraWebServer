#include <Arduino.h>
#include <App.hpp>
#include <SimpleWiFi.h>
#include <CameraSetup.h>
#include <CameraServer.h>

void setup() {
  pinMode( BOARD_LED, OUTPUT );
  pinMode( FLASH_LED, OUTPUT );
  digitalWrite( BOARD_LED, true );  
  digitalWrite( FLASH_LED, false );  
  Serial.begin(115200);
  delay( 3000 ); // wait for serial monitor
  Serial.setDebugOutput(true);
  Serial.println( "\n\n\n" APP_NAME " - Version " APP_VERSION );
  Serial.println( "Build date: " __DATE__ " " __TIME__ "\n");

  Serial.println();
  Serial.printf("CPU Frequency       : %dMHz\n", ESP.getCpuFreqMHz() );
  Serial.println();

  initializeCamera();

  digitalWrite( FLASH_LED, true );  
  disableWiFi();
  digitalWrite( FLASH_LED, false );  
  connectWiFi();

  startCameraServer();

  Serial.print("Camera Ready! Use 'http://");
  Serial.print(WiFi.localIP());
  Serial.println("' to connect");
}

void loop()
{
  if( WiFi.isConnected() == false )
  {
    connectWiFi();
  }
  delay(10000);
}
