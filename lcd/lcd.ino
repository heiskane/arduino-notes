#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const char to_print[] = 
  "We're no strangers to love. "
  "You know the rules and so do I (do I). "
  "A full commitment's what I'm thinking of. "
  "You wouldn't get this from any other guy. "
  "I just wanna tell you how I'm feeling. "
  "Gotta make you understand. "
  "Never gonna give you up. "
  "Never gonna let you down. "
  "Never gonna run around and desert you. "
  "Never gonna make you cry. "
  "Never gonna say goodbye. "
  "Never gonna tell a lie and hurt you. "
  "We've known each other for so long. "
  "Your heart's been aching, but you're too shy to say it (say it). "
  "Inside, we both know what's been going on (going on). "
  "We know the game and we're gonna play it. "
  "And if you ask me how I'm feeling. "
  "Don't tell me you're too blind to see. "
  "Never gonna give you up. "
  "Never gonna let you down. "
  "Never gonna run around and desert you. "
  "Never gonna make you cry. "
  "Never gonna say goodbye. "
  "Never gonna tell a lie and hurt you. "
  "Never gonna give you up. "
  "Never gonna let you down. "
  "Never gonna run around and desert you. "
  "Never gonna make you cry. "
  "Never gonna say goodbye. "
  "Never gonna tell a lie and hurt you. ";


void setup() {
  lcd.begin(16, 1);
  lcd.print("Why does this need initial input to work?");
}

void loop() {
  //lcd.print(to_print);
  lcd.autoscroll();
  // TODO: Try to set cursor to end of screen first
  for (int i = 0; i < strlen(to_print); i++) {
    char c = to_print[i];
    lcd.print(c);
    //lcd.scrollDisplayLeft();
    delay(250);
  }
}
