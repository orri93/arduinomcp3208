#include <SPI.h>

#include <Arduino.h>

#include "gosmcp3208.h"

//#define GOS_MCP_3208_ERRT_ ""

namespace gos {

Mcp3208::Mcp3208(
  const uint8_t&  pincs,   /* PIN for Chip Select CS is often 10 */
  const uint32_t& clock,   /* SPI CLOCK 1000000 (1MHz) */
  const uint8_t&  order,   /* SPI bit order MSB FIRST */
  const uint8_t&  mode) :  /* MODE0 */
  pincs_(pincs), spisettings_(clock, order, mode) {
}

Mcp3208::Mcp3208(const uint8_t&  pincs, const SPISettings& spisettings) :
  pincs_(pincs),
  spisettings_(spisettings) {
}

void Mcp3208::begin() {
  pinMode(pincs_, OUTPUT);
  digitalWrite(pincs_, HIGH);
}

uint16_t Mcp3208::read(const uint8_t& channel) {
  SPI.beginTransaction(spisettings_);
  digitalWrite(pincs_, LOW);
    // CSB Fall to Output Enable
#ifdef DELAY_MCP_3208_AFTER_EN
  delayMicroseconds(DELAY_MCP_3208_AFTER_EN);
#endif
  SPI.transfer(0b01100000 | ((channel & 0b111) << 2));
  uint8_t first = SPI.transfer(0);
  uint8_t second = SPI.transfer(0);
  digitalWrite(pincs_, HIGH);
  SPI.endTransaction();
  return (first << 4) | (second >> 4);
}

void Mcp3208::read(uint16_t* values, const uint8_t& lowest, const uint8_t& highest) {
  uint8_t first, second, index = 0;
  SPI.beginTransaction(spisettings_);
  digitalWrite(pincs_, LOW);
  for (uint8_t ch = lowest; ch <= highest; ch++) {
    SPI.transfer(0b01100000 | ((ch & 0b111) << 2));
    first = SPI.transfer(0);
    second = SPI.transfer(0);
    values[index++] = (first << 4) | (second >> 4);
  }
  digitalWrite(pincs_, HIGH);
  SPI.endTransaction();
}

}
