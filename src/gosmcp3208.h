#ifndef _GOS_ARDUINO_LIBRARY_MCP_3208_H_
#define _GOS_ARDUINO_LIBRARY_MCP_3208_H_

#include <Arduino.h>

#include <SPI.h>

#define SPI_CLOCK_MCP_3208          125000 /* (125 kHz) */
#define SPI_MODE_MCP_3208        SPI_MODE0
#define SPI_BIT_ORDER_MCP_3208    MSBFIRST

#define DELAY_MCP_3208_AFTER_EN      10000 /* Microseconds */

namespace gos {
namespace mcp3208 {
enum class Channel {
  SINGLE_0 = 0b1000,  /**< single channel 0 */
  SINGLE_1 = 0b1001,  /**< single channel 1 */
  SINGLE_2 = 0b1010,  /**< single channel 2 */
  SINGLE_3 = 0b1011,  /**< single channel 3 */
  SINGLE_4 = 0b1100,  /**< single channel 4 */
  SINGLE_5 = 0b1101,  /**< single channel 5 */
  SINGLE_6 = 0b1110,  /**< single channel 6 */
  SINGLE_7 = 0b1111,  /**< single channel 7 */
  DIFF_0PN = 0b0000,  /**< differential channel 0 (input 0+,1-) */
  DIFF_0NP = 0b0001,  /**< differential channel 0 (input 0-,1+) */
  DIFF_1PN = 0b0010,  /**< differential channel 1 (input 2+,3-) */
  DIFF_1NP = 0b0011,  /**< differential channel 1 (input 2-,3+) */
  DIFF_2PN = 0b0100,  /**< differential channel 2 (input 4+,5-) */
  DIFF_2NP = 0b0101,  /**< differential channel 2 (input 5-,5+) */
  DIFF_3PN = 0b0110,  /**< differential channel 3 (input 6+,7-) */
  DIFF_3NP = 0b0111   /**< differential channel 3 (input 6-,7+) */
};
extern const uint8_t bits;
extern const uint8_t resolution;
}
class Mcp3208{
public:
  Mcp3208(
    const uint8_t&  pincs = 10,                       /* PIN for Chip Select CS is often 10 */
    const uint32_t& clock = SPI_CLOCK_MAX_6675,       /* SPI CLOCK 1000000 (1MHz) */
    const uint8_t&  order = SPI_BIT_ORDER_MAX_6675,   /* SPI bit order MSB FIRST */
    const uint8_t&  mode = SPI_MODE_MAX_6675);        /* MODE 0 */
  void initialize();
  bool read(uint16_t& value, const uint8_t& channel);
  bool read(uint16_t* values, const Channel& lowest, const Channel& highest);
  const char* error(uint8_t& length);
private:
  uint8_t pincs_;
  uint16_t raw_;
  SPISettings spisettings_;
};
template<typename T> uint32_t speed3208
}

#endif /* _GOS_ARDUINO_LIBRARY_MCP_3208_H_ */

