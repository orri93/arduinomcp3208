add_library(libarduinomcp3208 STATIC src/gosmcp3208.cpp src/gosmcp3208.h)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_PLATFORM_INDEPENDENT_CODE ON)

include_directories(
  ${sublibraries_include}
  ${CMAKE_SOURCE_DIR}/sublibraries/arduinosensor/src)
