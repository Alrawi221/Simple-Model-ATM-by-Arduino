#include<Key.h>
#include<Keypad.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
char getPad[4];

const byte row = 4;
const byte col = 4;
byte colPin[] = {6, A1, A0, 7};
byte rowPin[] = {A5, A4, A3, A2};
char keys[row][col] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'},
};
int i = 0;
int c = 0;
int x=0;
int errorss=0;

char correct[4] = {'1', '2', '3', '4'};
Keypad keypad = Keypad(makeKeymap(keys), rowPin, colPin, row, col);

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
  //pinMode(13, 1);
 
   pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
pinMode(0,INPUT_PULLUP);
pinMode(1,OUTPUT);
pinMode(A1,INPUT);
  pinMode(13,INPUT_PULLUP);
  pinMode(8,INPUT_PULLUP);
    pinMode(7,INPUT_PULLUP);
  void motors();
    void starter();
}
void loop() {
while(digitalRead(7)==LOW){
  starter();
   char key = keypad.getKey();
  lcd.setCursor(i, 1);

  if (key != NO_KEY) {
    getPad[i] = key;
    lcd.print("*");
    lcd.setCursor(i, 1);
    i++;


    if (key == '#') {
        lcd.clear();
      for (int j = 0; j < 4; j++) {
        if (getPad[j] == correct[j]) {
          c++;

        }
      }
      if (c == 4) {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("hellow..!");
        delay(1500);
        bb:
        while(c==4){
      if(digitalRead(13)==LOW){
        motors();
        
digitalWrite(1,LOW);
analogWrite(10,0);
digitalWrite(0,LOW);
analogWrite(9,0);

      }
      if(digitalRead(8)==LOW){
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.println("Thank you!");
        lcd.setCursor(0, 1);
          lcd.println("Take Your card");
          delay(7000);
           lcd.clear();

           for(int i=0;i<4;i++){
           getPad[i]='0';
           }
           i = 0;
          c=0;
        break;
        }
    
       else{
     lcd.clear();
      lcd.setCursor(0, 0);
        lcd.print("Select:pull");
        lcd.setCursor(0, 1);
        lcd.print("OR    Exit");
        delay(80);
 
       
  }
  
     
  
          }
          }
        
      
        

       
else if(errorss==3){
    lcd.clear();
    lcd.setCursor(0, 0);
  lcd.print("ERROR you tried");
  lcd.setCursor(0, 1);
  lcd.print("    4 times ");
  delay(7000);
 
    lcd.clear();
    
      lcd.setCursor(0,1);
    lcd.print("dans:  ");
       lcd.setCursor(8,1);
       lcd.print("sec");
     delay(500);
    
    for (int s=60;s>0;s--){
  int va = s;
  lcd.setCursor(5,1);
 char message[2];
   sprintf(message, "%02d",va); 
    lcd.print(message);
    delay(500);                            
                                
 }
 lcd.clear();
    errorss=0;
    i=0;
    
  }

      else if(c!=4){
       lcd.clear();
       /*  for(int s=0;s<4;s++){
          lcd.print(getPad[s]);}
          for(int s=0;s<4;s++){
          lcd.print(correct[s]);}*/
           
        lcd.print("PIN is ERROR..!");
        delay(2000);
        i = 0;
          c=0;
               errorss++;

        lcd.clear();
   
    

      }


    }


  }}
  if(digitalRead(7)==HIGH){
    lcd.clear();
     lcd.setCursor(0, 0);
    lcd.print("Enter Your Card");
    }

    if(digitalRead(0)==LOW){
      
      digitalWrite(10,LOW);
digitalWrite(1,HIGH);
analogWrite(9,255);

delay(500);}
  
  }
  
void motors()
{

             
         lcd.clear();
         lcd.print("get 1000 RS ..");
         

digitalWrite(10,HIGH);
digitalWrite(1,LOW);
analogWrite(9,255);

delay(500);

 
 x=1  ;            
  
 
  }

  void starter(){
    
     lcd.setCursor(0, 0);

  //lcd.print("Enter Your Card and");
  lcd.print("Enter YOUR PIN..");

    }

    
