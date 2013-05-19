#include <Time.h>

#define bit_0 3
#define bit_1 4
#define bit_2 6
#define bit_3 7
#define digit_1 8
#define digit_2 9
#define digit_3 10
#define digit_4 11
#define digit_5 12
#define dur 100

float input = 0;
float current = 0;

void setup()
{
Serial.begin(9600);
pinMode(bit_0, OUTPUT);
pinMode(bit_1, OUTPUT);
pinMode(bit_2, OUTPUT);
pinMode(bit_3, OUTPUT);
pinMode(digit_1, OUTPUT);
pinMode(digit_2, OUTPUT);
pinMode(digit_3, OUTPUT);
pinMode(digit_4, OUTPUT);
pinMode(digit_5, OUTPUT);


}

void loop()
{
  int upper3 = 0;
  int lower2 = 0;
  unsigned int start = millis();
  unsigned int count = 0;


  Serial.println(input);
  if(current == 0)
  {
      current = input;
  }


 

  while(count < 2000)
  {      
     float diff = current - input;
     if(abs(diff) > .05)
     {
         if(diff < 0)
           current = current + 0.01;
         else
           current = current - 0.01;
     }
     else
     {
     current = input;
     }
     
     upper3 = (int) current;
     lower2 = ((int) (current*100)) % 100;
     draw(lower2%10, lower2/10, (upper3%10), (upper3%100)/10, upper3/100 );
     count = millis() - start;

 }

}

void draw(int l1, int l2, int l3, int l4, int l5)
{
  blank();
  if(l1 != -1)
  {
    bcd(l1);
    digitalWrite(digit_1, HIGH);
    digitalWrite(digit_2, LOW);
    digitalWrite(digit_3, LOW);
    digitalWrite(digit_4, LOW);
    digitalWrite(digit_5, LOW);
  }
   delay(3);

  blank();
  if(l2 != -1)
  {
    bcd(l2);
    digitalWrite(digit_1, LOW);
    digitalWrite(digit_2, HIGH);
    digitalWrite(digit_3, LOW);
    digitalWrite(digit_4, LOW);
    digitalWrite(digit_5, LOW);
  }
  delay(3);
 
  blank();
  if(l3 != -1)
  {
    bcd(l3);
    digitalWrite(digit_1, LOW);
    digitalWrite(digit_2, LOW);
    digitalWrite(digit_3, HIGH);
    digitalWrite(digit_4, LOW);
    digitalWrite(digit_5, LOW);
  }
  delay(3);
 
  blank();
  if(l4 != -1)
  {
    bcd(l4);
    digitalWrite(digit_1, LOW);
    digitalWrite(digit_2, LOW);
    digitalWrite(digit_3, LOW);
    digitalWrite(digit_4, HIGH);
    digitalWrite(digit_5, LOW);
  }
  delay(3);
 
  blank();
  if(l5 != -1)
  {
    bcd(l5);
    digitalWrite(digit_1, LOW);
    digitalWrite(digit_2, LOW);
    digitalWrite(digit_3, LOW);
    digitalWrite(digit_4, LOW);
    digitalWrite(digit_5, HIGH);
  }
  delay(3);
  blank();
}

void serialEvent()
{
 input = Serial.parseFloat();
}

void bcd(int out)
{
switch(out)
{
    case 9:
      digitalWrite(bit_0, HIGH);
      digitalWrite(bit_1, LOW);
      digitalWrite(bit_2, LOW);
      digitalWrite(bit_3, HIGH);
      break;
    case 8:
      digitalWrite(bit_0, LOW);
      digitalWrite(bit_1, LOW);
      digitalWrite(bit_2, LOW);
      digitalWrite(bit_3, HIGH);
      break;
    case 7:
      digitalWrite(bit_0, HIGH);
      digitalWrite(bit_1, HIGH);
      digitalWrite(bit_2, HIGH);
      digitalWrite(bit_3, LOW);
      break;
    case 6:
      digitalWrite(bit_0, LOW);
      digitalWrite(bit_1, HIGH);
      digitalWrite(bit_2, HIGH);
      digitalWrite(bit_3, LOW);
      break;
    case 5:
      digitalWrite(bit_0, HIGH);
      digitalWrite(bit_1, LOW);
      digitalWrite(bit_2, HIGH);
      digitalWrite(bit_3, LOW);
      break;
    case 4:
      digitalWrite(bit_0, LOW);
      digitalWrite(bit_1, LOW);
      digitalWrite(bit_2, HIGH);
      digitalWrite(bit_3, LOW);
      break;
    case 3:
      digitalWrite(bit_0, HIGH);
      digitalWrite(bit_1, HIGH);
      digitalWrite(bit_2, LOW);
      digitalWrite(bit_3, LOW);
      break;
    case 2:
      digitalWrite(bit_0, LOW);
      digitalWrite(bit_1, HIGH);
      digitalWrite(bit_2, LOW);
      digitalWrite(bit_3, LOW);
      break;
    case 1:
      digitalWrite(bit_0, HIGH);
      digitalWrite(bit_1, LOW);
      digitalWrite(bit_2, LOW);
      digitalWrite(bit_3, LOW);
      break;
    case 0:
      digitalWrite(bit_0, LOW);
      digitalWrite(bit_1, LOW);
      digitalWrite(bit_2, LOW);
      digitalWrite(bit_3, LOW);
      break;
}
}


void blank()
{
  digitalWrite(digit_1, LOW);
  digitalWrite(digit_2, LOW);
  digitalWrite(digit_3, LOW);
  digitalWrite(digit_4, LOW);
  digitalWrite(digit_5, LOW);
  delay(1);
}

