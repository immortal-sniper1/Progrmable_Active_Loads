#include <SPI.h>
#include <MCP_ADC.h>


MCP3008 mcp1(13, 11, 12);      //  ESP32 use SWSPI  dataIn, dataOut, Clock  
                              //   SS is 10         MISO    MOSI     CLK
#define SPI_SS_1 =10;


void setup()
{
  Serial.begin(115200);
  Serial.println(__FILE__);
  Serial.print("MCP_ADC_LIB_VERSION: ");
  Serial.println(MCP_ADC_LIB_VERSION);

  SPI.begin();

  mcp1.begin(SPI_SS_1);

  Serial.println();
  Serial.println("ADC\tCHAN\tMAXVALUE");
  Serial.print("mcp1\t");
  Serial.print(mcp1.channels());
  Serial.print("\t");
  Serial.println(mcp1.maxValue());
}


void loop()
{
  Serial.print(millis());
  Serial.print("\tmcp1:\t");
  for (int channel = 0 ; channel < mcp1.channels(); channel++)
  {
    uint16_t val = mcp1.read(channel);
    Serial.print(val);
    Serial.print("\t");
    delay(1);       //  added so single reads are better visible on a scope
  }
  Serial.println();

  delay(1000);
}


//  -- END OF FILE --