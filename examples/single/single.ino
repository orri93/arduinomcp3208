#include <SPI.h>

#include <gosmcp3208.h>

#define SERIAL_BAUD   115200


#define PIN_SC            10

::gos::Mcp3208 mcp3208(PIN_SC);

uint16_t value;

void setup() {
  SPI.begin();
  mcp3208.begin();
  Serial.begin(SERIAL_BAUD);
  Serial.println("MCP 3208 Reading single channel example");
}

void loop() {
  value = mcp3208.read(0);
  Serial.print("Channel 0: ");
  Serial.println(value, DEC);
  delay(2000);
  value = mcp3208.read(7);
  Serial.print("Channel 7: ");
  Serial.println(value, DEC);
  delay(2000);
}
