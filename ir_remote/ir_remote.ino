#include <IRremote.h>

const int irReceiverPin = 2; //pin the receiver is connected to

const int NUM_OF_BUTS = 21;
unsigned long BUTTON_CODES[NUM_OF_BUTS] = {
    4077698816, //button 0
    4010852096, //button 1
    3994140416, //button 2
    3977428736, //button 3
    3944005376, //button 4
    3927293696, //button 5
    3910582016, //button 6
    3877158656, //button 7
    3860446976, //button 8
    3843735296, //button 9
    4144545536, //button DOWN
    4111122176, //button UP
    4127833856, //button VOL-
    4261527296, //button VOL+
    4060987136, //button EQ
    4244815616, //button FUNC/STOP
    4194680576, //button PLAY/PAUSE
    4044275456, //button ST/REPT
    4211392256, //button CH-
    4177968896, //button CH+
    4278238976  //button CH/POWER
  };
String BUTTON_NAMES[NUM_OF_BUTS] = {
    "0","1","2","3","4","5","6","7","8","9",
    "DOWN","UP","VOL-","VOL+",
    "EQ","FUNC/STOP","PLAY/PAUSE",
    "ST/REPT","CH-","CH+","CH/POWER"
  };


void setup(){
  IrReceiver.begin(irReceiverPin, ENABLE_LED_FEEDBACK); // Start the receiver object
  
  Serial.begin(9600);
}
void loop() {
  if (IrReceiver.decode()) {
    //Serial.println(IrReceiver.decodedIRData.decodedRawData);
    int button_id = findButton(IrReceiver.decodedIRData.decodedRawData);
    if(button_id <0){
      Serial.println("Unknown button is pressed! ");
      Serial.println(IrReceiver.decodedIRData.decodedRawData);
    } else{
      Serial.print("Button ");
      Serial.print(BUTTON_NAMES[button_id]);
      Serial.println(" is pressed!");
    }
    delay(100);
    IrReceiver.resume(); // Receive the next value
  }
}
int findButton(unsigned long val){
  for(int i = 0; i < NUM_OF_BUTS; i++){
    if(val == BUTTON_CODES[i]) return i;
  }
  return -1;
}

