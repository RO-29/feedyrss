#include <LiquidCrystal.h>
#include <Servo.h>
//#include "mario.h"
#define MAX 45     // Max servo degree
#define MIN 0      // Min servo degree

#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D4  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G4  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978


LiquidCrystal lcd(12,11,5,4,3,2);
//int ledPing =13;
int ledPing=8;
char ser;
String email ="";
//int ledPinf = 9;
int ledPinf=10;

int melody[] = {NOTE_B5,NOTE_G4,NOTE_A5,NOTE_D4,0,NOTE_D4,NOTE_A5,NOTE_B5,NOTE_G4,0};

int noteDurations[] = { 4,4,4,4,4,4,4,4,4,4};
 
Servo flag;

void setup(){
  Serial.begin(9600);
  lcd.begin(16,2);
  pinMode(ledPing,OUTPUT);
  pinMode(ledPinf,OUTPUT);
  
  //flag.attach(servoPin);
}

void loop(){
  
  lcd.clear();
  lcd.setCursor(0,0);
  if (Serial.available()) {
         lcd.setCursor(0,1);
         ser = Serial.read();     //read the serial port
          //if incoming character is 0, no mail, LED is low 
         if (ser == '0'){
             digitalWrite(ledPing,LOW);
			 digitalWrite(ledPinf,LOW);
             flag.write(MIN); 
             //lcd.write("You got no mail/feed!");           
          }
          //if other characters, servo flag turns, Lcd display and play sound"
         else if(ser > '0') {
           flag.write(MAX);
           lcd.clear();
           if(ser=='<')
		     gmail_p();
           email ="";  // reset email
           lcd.clear(); 
           if(ser=='>')
            facebook_p();
           email ="";  //reset email   
         }
       
 
    }

 
  //delay(1000);
 
    
}
/*
 *parse  the email from incoming characters.
 *adding each character to email string
 */

void gmail_p(){

	   led_blink(ledPing);
           getEmail('>');  //parse email function ,code block is below
            //print email ,code block is below
            playSound_1(0,5); // play melody
           printEmail();         
       }

void facebook_p(){

	       led_blink(ledPinf);
               getEmail('<');  //parse email function ,code block is below
 //print email ,code block is below
               playSound_1(5,10);
               printEmail(); // play melody
         }
void getEmail(char stream){
    char temp=Serial.read();
    while(Serial.available()>0 && temp!=stream){
      char nextChar = Serial.read(); 
      email += nextChar;
	  
    }
}

void led_blink(int led){

for(int i=0;i<5;i++){

  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);               // wait for a second

}


}
/*
 * print email and scroll it
 *
 */
void printEmail(){
  int emailLength = email.length();
  lcd.setCursor(0,0);
  lcd.print(email);
  //delay(500);
  //scroll it to left until the final char of email is displayed on LCD
  for (int positionCounter = 0; positionCounter <emailLength-12; positionCounter++) {
    lcd.scrollDisplayLeft(); 
    delay(500);
  }
  lcd.clear();
  lcd.print(email);
  
}
/*This code play tune from melody array . 
* literally from public domain code
* from arduino Tone tutorial http://arduino.cc/en/Tutorial/Tone
*/
void playSound_1(int a,int b){
 
   // iterate over the notes of the melody:
  for (int thisNote = a; thisNote < b; thisNote++) {

    // to calculate the note duration, take one second 
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 3000/noteDurations[thisNote];
    tone(8, melody[thisNote],noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
  }
    
}


