#include <Arduino.h>

#include "gosmcp3208.h"

#define GOS_MCP_3208_ERRT_ ""

namespace gos {
namespace mcp3208 {
const uint8_t bits = 12;
const uint16_t resolution = 1 << bits;
}

Mcp3208::Mcp3208(
  const uint8_t&  pincs,   /* PIN for Chip Select CS is often 10 */
  const uint32_t& clock,   /* SPI CLOCK 1000000 (1MHz) */
  const uint8_t&  order,   /* SPI bit order MSB FIRST */
  const uint8_t&  mode) :  /* MODE0 */
  pincs_(pincs), spisettings_(clock, order, mode) {
}

void Mcp3208::initialize() {
  pinMode(pincs_, OUTPUT);
  digitalWrite(pincs_, HIGH);
}

bool Max6675::read(double& value, const uint8_t& channel) {
  SPI.beginTransaction(spisettings_);
  digitalWrite(pincs_, LOW);
    // CSB Fall to Output Enable
#ifdef DELAY_MCP_3208_AFTER_EN
  delayMicroseconds(DELAY_MCP_3208_AFTER_EN);
#endif

  SPI.transfer(0b01100000 | ((channel & 0b111) << 2));
  uint8_t first = spiTransfer(0);
  uint8_t second = spiTransfer(0);

  digitalWrite(pincs_, HIGH);
  SPI.endTransaction();

  
}

const char* Max6675::error(uint8_t& length) {
  if (raw_ & 0x0004) {
    length = sizeof(GOS_MAX_6675_ERRT_OPEN);
    return GOS_MAX_6675_ERRT_OPEN;
  } else {
    length = 0;
    return nullptr;
  }
}

}
