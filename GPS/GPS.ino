#include <SoftwareSerial.h>
#include <TinyGPS++.h>

SoftwareSerial gpsSerial(2, 3);  // RX, TX
TinyGPSPlus gps;  // Create a TinyGPS++ object

void setup() {
  Serial.begin(9600);
  gpsSerial.begin(9600);
  Serial.println("GPS start");
}

void loop() {
  while (gpsSerial.available()) {
    char c = gpsSerial.read();
    if (gps.encode(c)) {
      if (gps.location.isUpdated()) {
        Serial.print("Latitude: ");
        Serial.println(gps.location.lat(), 6);
        Serial.print("Longitude: ");
        Serial.println(gps.location.lng(), 6);
      }
      if (gps.altitude.isUpdated()) {
        Serial.print("Altitude: ");
        Serial.print(gps.altitude.meters());
        Serial.println(" meters");
      }
    }
  }
}
