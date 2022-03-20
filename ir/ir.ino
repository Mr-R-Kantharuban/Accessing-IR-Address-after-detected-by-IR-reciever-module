#include <IRremote.h>

const int RECV_PIN = 7;
IRrecv irrecv(RECV_PIN);
decode_results results;
unsigned long key_value = 0;


void setup(){
  Serial.begin(9600);
  irrecv.enableIRIn();
//  irrecv.blink13(true);
}

void loop(){
  if (irrecv.decode(&results)){
//        Serial.println(results.value, HEX);
         if (results.value == 0XFFFFFFFF)
          results.value = key_value; 
         
          switch(results.value){
          case 0xFFFD30CF:
          Serial.println("0");
          break;
          case 0xFFFD40BF:
          Serial.println("1");
          break;
//          case 0xFFFD30CF:
//          Serial.println("2");
//          break;
          case 0xFFFDC03F:
          Serial.println("3");
          break;
          case 0xFFFDA05F:
          Serial.println("4");
          break;
          case 0xFFFD609F:
          Serial.println("5");
          break;
          case 0xFFFDE01F:
          Serial.println("6");
          break;
          case 0xFFFD10EF:
          Serial.println("7");
          break;
          case 0xFFFD906F:
          Serial.println("8");
          break;
          case 0xFFFD50AF:
          Serial.println("9");
          break;
          }
     
        key_value = results.value;
        irrecv.resume(); 
  }
}
