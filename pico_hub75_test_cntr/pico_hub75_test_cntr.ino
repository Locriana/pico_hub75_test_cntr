#include <DMD_RGB.h>

//Number of panels in x and y axis
#define DISPLAYS_ACROSS 1
#define DISPLAYS_DOWN 1

#define ENABLE_DUAL_BUFFER false

#define DMD_PIN_A 6
#define DMD_PIN_B 7
#define DMD_PIN_C 8
#define DMD_PIN_D 9
#define DMD_PIN_E 10
// put all mux pins at list
uint8_t mux_list[] = { DMD_PIN_A , DMD_PIN_B , DMD_PIN_C , DMD_PIN_D , DMD_PIN_E };

// pin OE must be one of PB0 PB1 PA6 PA7
#define DMD_PIN_nOE 15    // OE
#define DMD_PIN_SCLK 12

uint8_t custom_rgbpins[] = { 11, 0, 1, 2, 3, 4, 5 }; // CLK, R0, G0, B0, R1, G1, B1


//https://github.com/board707/DMD_STM32/wiki/quick_start#supported-panels

DMD_RGB <RGB64x32plainS16, COLOR_4BITS> dmd(mux_list, DMD_PIN_nOE, DMD_PIN_SCLK, custom_rgbpins, DISPLAYS_ACROSS, DISPLAYS_DOWN, ENABLE_DUAL_BUFFER);
//DMD_RGB <RGB128x64plainS32, COLOR_4BITS> dmd(mux_list, DMD_PIN_nOE, DMD_PIN_SCLK, custom_rgbpins, DISPLAYS_ACROSS, DISPLAYS_DOWN, ENABLE_DUAL_BUFFER);

//DMD_Standard_Font Arial_F(Arial_14);




void setup(void)
{
    dmd.init();
    dmd.setBrightness(0x60);
    dmd.fillScreen(dmd.Color888(0x00, 0x00, 0x00));
    Serial.println("Setup exit");
}

void loop(void) {
  static uint16_t cntr;
  dmd.setFont(NULL);
  dmd.setTextSize(1);
  dmd.setCursor(1,1);
  dmd.fillScreen(dmd.Color888(0x00, 0x00, 0x00));
  dmd.setTextColor(dmd.Color888(0xFF, 0x00, 0xFF));
  dmd.print("Test\n");
  dmd.setCursor(1,10);
  dmd.setTextSize(2);
  dmd.setTextColor(dmd.Color888(0x00, 0xFF, 0xFF));
  dmd.printf("%02X",cntr>>8);
  dmd.setTextColor(dmd.Color888(0x00, 0xFF, 0x00));
  dmd.printf("%02X",cntr & 0x00FF);
  cntr++;
  delay(100);
}
