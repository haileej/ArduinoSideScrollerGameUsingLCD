

// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//button stuff:
const int buttonPin = 7;
bool isJumping = false;

int block_column = 15;



void setup() {

  // set up the LCD's number of columns and rows:

  lcd.begin(16, 2);

  //i think makeit so that the button is an input into arduino:
  pinMode(buttonPin, INPUT);
  
  //print start message:
  lcd.print("Game Start Soon");
  
  //wait a couple seconds
  delay(2000);

  //set the cursor on the far right side
  lcd.setCursor(16, 0);

  // start scrolling the message away
  lcd.autoscroll();

  //this for loop is to add a space one at a time to get the message to scroll away
  for(int i = 0; i<=14; i++){
    lcd.print(" ");
    delay(200);
  }

  //clearing the spaces and letters from the display
  lcd.clear();

  //waiting a second before the void loop/actual game starts
  delay(550);

  //stopping the autoscroll because it isn't actually pertinent to the game
  lcd.noAutoscroll();

}


 int num_of_blocks_jumped = 0;
 int delay_time = 300;

//now starting the actual game
void loop() {

  //clearing the screen every loop but theres no delay from this to the next writing of the character so you don't actually see the screen getting cleared visually
  lcd.clear();
 

  //reading the button being pressed:
  if (digitalRead(buttonPin) == HIGH) {
    isJumping = true;
    // Handle jump logic
  } else {
    isJumping = false;
  }

  //if statement for whether the button is being pushed
  //if it is pushed, then the character goes up for a second
  if(isJumping == true){

    //if the button is pushed
    //sets the cursor to write on the top row
    lcd.setCursor(3,0);

    //writes the character
    lcd.write(219);

    //leaves it on the top row for a sec (not actual a sec just a moment)
    //delay(300);
  }
  //otherwise (the button is not pressed) the cursor is just written on the bottom
   else{

    //set cursor to write on bottom
    lcd.setCursor(3,1);

    //write the character
    lcd.write(219);
  }
  

  // Draw block
  lcd.setCursor(block_column, 1); // always on bottom row
  lcd.write(byte(255)); // block character

// Check collision
  if (block_column == 3 && isJumping == false) {
    lcd.clear();
    lcd.setCursor(3, 0);
    lcd.print("Game Over");
    delay(2000);
    block_column = 15; // reset game
  } else {
    block_column--;
    if (block_column < 0) {
      block_column = 15;
      num_of_blocks_jumped++;
    }
  }

 
  //adding a delay between the void loops otherwise it will malfunction
 delay(delay_time);

  
  
  
} 