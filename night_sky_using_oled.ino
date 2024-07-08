#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64 
#define OLED_RESET    -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define NUM_STARS 50
int stars[NUM_STARS][2];

void setup() {
  Serial.begin(115200);

 
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

  for (int i = 0; i < NUM_STARS; i++) {
    stars[i][0] = random(SCREEN_WIDTH);
    stars[i][1] = random(SCREEN_HEIGHT);
  }

  display.clearDisplay();
}

void loop() {
  display.clearDisplay();

  for (int i = 0; i < NUM_STARS; i++) {
    int brightness = random(0, 256);
    display.drawPixel(stars[i][0], stars[i][1], brightness > 128 ? SSD1306_WHITE : SSD1306_BLACK);
  }

  display.display();
  delay(100);
}

