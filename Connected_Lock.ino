
//////////////////////////////////////////////
//        RemoteXY include library          //
//////////////////////////////////////////////

// you can enable debug logging to Serial at 115200
//#define REMOTEXY__DEBUGLOG    

// RemoteXY select connection mode and include library 
#define REMOTEXY_MODE__WIFI_POINT

#include <ESP8266WiFi.h>

// RemoteXY connection settings 
#define REMOTEXY_WIFI_SSID "JasdiSecure"
#define REMOTEXY_WIFI_PASSWORD "Jasdi_Tech"
#define REMOTEXY_SERVER_PORT 6377
#define REMOTEXY_ACCESS_PASSWORD "Jasdi_Tech"


#include <RemoteXY.h>

// RemoteXY GUI configuration  
#pragma pack(push, 1)  
uint8_t RemoteXY_CONF[] =   // 42 bytes
  { 255,1,0,0,0,35,0,19,0,0,0,74,97,115,100,105,0,61,1,106,
  200,1,1,1,0,2,11,70,83,49,1,119,173,31,31,79,78,0,79,70,
  70,0 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  uint8_t switch_01; // =1 if switch ON and =0 if OFF

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0

} RemoteXY;   
#pragma pack(pop)
 
/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////

#define Led D2

void setup() 
{
  RemoteXY_Init (); 
  pinMode(Led, OUTPUT);
  // TODO you setup code
  
}

void loop() 
{ 
  RemoteXY_Handler ();
  
  if (RemoteXY.switch_01 == 1) {
      digitalWrite(Led, HIGH);
    } else {
    digitalWrite(Led, LOW);
   }
  
  // TODO you loop code
  // use the RemoteXY structure for data transfer
  // do not call delay(), use instead RemoteXY_delay() 
}