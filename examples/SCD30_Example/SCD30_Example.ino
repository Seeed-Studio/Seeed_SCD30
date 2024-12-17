#include "SCD30.h"

#if defined(ARDUINO_ARCH_AVR)
    #pragma message("Defined architecture for ARDUINO_ARCH_AVR.")
    #define SERIAL Serial
#elif defined(ARDUINO_ARCH_SAM)
    #pragma message("Defined architecture for ARDUINO_ARCH_SAM.")
    #ifdef SEEED_XIAO_M0
        #define SERIAL Serial
    #elif defined(ARDUINO_SAMD_VARIANT_COMPLIANCE)
        #define SERIAL SerialUSB
    #else
        #define SERIAL Serial
    #endif
#elif defined(ARDUINO_ARCH_SAMD)
    #pragma message("Defined architecture for ARDUINO_ARCH_SAMD.")
    #ifdef SEEED_XIAO_M0
        #define SERIAL Serial
    #elif defined(ARDUINO_SAMD_VARIANT_COMPLIANCE)
        #define SERIAL SerialUSB
    #else
        #define SERIAL Serial
    #endif
#elif defined(ARDUINO_ARCH_STM32F4)
    #pragma message("Defined architecture for ARDUINO_ARCH_STM32F4.")
    #ifdef SEEED_XIAO_M0
        #define SERIAL Serial
    #elif defined(ARDUINO_SAMD_VARIANT_COMPLIANCE)
        #define SERIAL SerialUSB
    #else
        #define SERIAL Serial
    #endif
#else
    #pragma message("Not found any architecture.")
    #define SERIAL Serial
#endif



void setup() {
    Wire.begin();
    SERIAL.begin(115200);
    SERIAL.println("SCD30 Raw Data");
    scd30.initialize();
}

void loop() {
    float result[3] = {0};

    if (scd30.isAvailable()) {
        scd30.getCarbonDioxideConcentration(result);
        SERIAL.print("Carbon Dioxide Concentration is: ");
        SERIAL.print(result[0]);
        SERIAL.println(" ppm");
        SERIAL.println(" ");
        SERIAL.print("Temperature = ");
        SERIAL.print(result[1]);
        SERIAL.println(" ℃");
        SERIAL.println(" ");
        SERIAL.print("Humidity = ");
        SERIAL.print(result[2]);
        SERIAL.println(" %");
        SERIAL.println(" ");
        SERIAL.println(" ");
        SERIAL.println(" ");
    }

    delay(2000);
}
