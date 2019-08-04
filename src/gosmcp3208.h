#ifndef _GOS_ARDUINO_LIBRARY_MCP_3208_H_
#define _GOS_ARDUINO_LIBRARY_MCP_3208_H_

#include <Arduino.h>

#include <SPI.h>

#define SPI_CLOCK_MCP_3208          125000 /* (125 kHz) */
#define SPI_MODE_MCP_3208        SPI_MODE0
#define SPI_BIT_ORDER_MCP_3208    MSBFIRST

#define DELAY_MCP_3208_AFTER_EN      10000 /* Microseconds */

#define GOS_MCP_3208_BIT                12
#define GOS_MCP_3208_MAX            0x0fff

namespace gos {
class Mcp3208{
public:
  Mcp3208(
    const uint8_t&  pincs = 10,                       /* PIN for Chip Select CS is often 10 */
    const uint32_t& clock = SPI_CLOCK_MCP_3208,       /* SPI CLOCK 1000000 (1MHz) */
    const uint8_t&  order = SPI_BIT_ORDER_MCP_3208,   /* SPI bit order MSB FIRST */
    const uint8_t&  mode = SPI_MODE_MCP_3208);        /* MODE 0 */
  Mcp3208(const uint8_t&  pincs, const SPISettings& spisettings);
  void begin();
  uint16_t read(const uint8_t& channel);
  void read(uint16_t* values, const uint8_t& lowest, const uint8_t& highest);
private:
  uint8_t pincs_;
  SPISettings spisettings_;
};
}

#endif /* _GOS_ARDUINO_LIBRARY_MCP_3208_H_ */

