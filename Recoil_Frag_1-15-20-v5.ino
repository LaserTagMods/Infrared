/* 
 *  use two IR pins numbers 2 and 3
 *  use an indicator led at pin 5
 *  use an ir receiver at pin 4
 *  use a button at pin 6
 *  
 */

int parity = 0; // 0 = even; 1 = odd
int ActionState = 0; // variable used for storing a State
int IRledPin1 = 2; // LED connected to digital pin 2 output to send IR
int IRledPin2 = 3; // LED power supply #1 connect to pin 3
int LED1 = 5; // LED indicator light
int RXLED = 17; // The RX LED has a defined Arduino pin
int TXLED = 30; // The TX LED has a defined Arduino pin
const byte IR_Sensor_Pin = 4; // Pin used for IR receiver
int B[4];
int P[6];
int T[2];
int D[8];
int C[1];
int U[2];
int Z[3];

//******************************************************************************************************************************************************************************************
//******************************************************************************************************************************************************************************************
//******************************************************************************************************************************************************************************************
//******************************************************************************************************************************************************************************************
// This procedure sends a 38KHz pulse to the IRledPin 
// for a certain # of microseconds. We'll use this whenever we need to send codes
void pulseIR1(long microsecs) {
  // we'll count down from the number of microseconds we are told to wait 
  cli();  // this turns off any background interrupts
  while (microsecs > 0) {
    // 38 kHz is about 13 microseconds high and 13 microseconds low
   digitalWrite(IRledPin1, HIGH);  // this takes about 3 microseconds to happen
   delayMicroseconds(10);         // hang out for 10 microseconds, you can also change this to 9 if its not working
   digitalWrite(IRledPin1, LOW);   // this also takes about 3 microseconds
   delayMicroseconds(10);         // hang out for 10 microseconds, you can also change this to 9 if its not working
   // so 26 microseconds altogether
   microsecs -= 26;
  }
  sei();  // this turns them back on
}
void pulseIR2(long microsecs) {
  // we'll count down from the number of microseconds we are told to wait
  cli();  // this turns off any background interrupts
  while (microsecs > 0) {
   // 38 kHz is about 13 microseconds high and 13 microseconds low
   digitalWrite(IRledPin2, HIGH);  // this takes about 3 microseconds to happen
   delayMicroseconds(10);         // hang out for 10 microseconds, you can also change this to 9 if its not working
   digitalWrite(IRledPin2, LOW);   // this also takes about 3 microseconds
   delayMicroseconds(10);         // hang out for 10 microseconds, you can also change this to 9 if its not working  
   // so 26 microseconds altogether
   microsecs -= 26;
  }
  sei();  // this turns them back on
}
//******************************************************************************************************************************************************************************************
//******************************************************************************************************************************************************************************************
void SendIR() {
  Serial.println("Sending IR1");
  // sending IR protocol on first pin
  pulseIR1(2000);
  delayMicroseconds(500);
  pulseIR1(B[0]); // B1
  delayMicroseconds(500);
  pulseIR1(B[1]); // B2
  delayMicroseconds(500);
  pulseIR1(B[2]); // B3
  delayMicroseconds(500);
  pulseIR1(B[3]); // B4
  delayMicroseconds(500);
  pulseIR1(P[0]); // P1
  delayMicroseconds(500);
  pulseIR1(P[1]); // P2
  delayMicroseconds(500);
  pulseIR1(P[2]); // P3
  delayMicroseconds(500);
  pulseIR1(P[3]); // P4
  delayMicroseconds(500);
  pulseIR1(P[4]); // P5
  delayMicroseconds(500);
  pulseIR1(P[5]); // P6
  delayMicroseconds(500);
  pulseIR1(T[0]); // T1
  delayMicroseconds(500);
  pulseIR1(T[1]);  // T2
  delayMicroseconds(500);
  pulseIR1(D[0]);  // D1
  delayMicroseconds(500);
  pulseIR1(D[1]);  // D2
  delayMicroseconds(500);
  pulseIR1(D[2]); // D3
  delayMicroseconds(500);
  pulseIR1(D[3]);  // D4
  delayMicroseconds(500);
  pulseIR1(D[4]);  // D5
  delayMicroseconds(500);
  pulseIR1(D[5]);  // D6
  delayMicroseconds(500);
  pulseIR1(D[6]);  // D7
  delayMicroseconds(500);
  pulseIR1(D[7]);  // D8
  delayMicroseconds(500);
  pulseIR1(C[0]);  // C1
  delayMicroseconds(500);
  pulseIR1(U[0]);  // U1
  delayMicroseconds(500);
  pulseIR1(U[1]);  // U2
  delayMicroseconds(500);
  pulseIR1(Z[0]); // Z1
  delayMicroseconds(500);
  pulseIR1(Z[1]); // Z2
  // short delay and then send send protocol on second pin
  delayMicroseconds(2000);
  Serial.println("Sending IR2");
  pulseIR2(2000);
  delayMicroseconds(500);
  pulseIR2(B[0]); // B1
  delayMicroseconds(500);
  pulseIR2(B[1]); // B2
  delayMicroseconds(500);
  pulseIR2(B[2]); // B3
  delayMicroseconds(500);
  pulseIR2(B[3]); // B4
  delayMicroseconds(500);
  pulseIR2(P[0]); // P1
  delayMicroseconds(500);
  pulseIR2(P[1]); // P2
  delayMicroseconds(500);
  pulseIR2(P[2]); // P3
  delayMicroseconds(500);
  pulseIR2(P[3]); // P4
  delayMicroseconds(500);
  pulseIR2(P[4]); // P5
  delayMicroseconds(500);
  pulseIR2(P[5]); // P6
  delayMicroseconds(500);
  pulseIR2(T[0]); // T1
  delayMicroseconds(500);
  pulseIR2(T[1]);  // T2
  delayMicroseconds(500);
  pulseIR2(D[0]);  // D1
  delayMicroseconds(500);
  pulseIR2(D[1]);  // D2
  delayMicroseconds(500);
  pulseIR2(D[2]); // D3
  delayMicroseconds(500);
  pulseIR2(D[3]);  // D4
  delayMicroseconds(500);
  pulseIR2(D[4]);  // D5
  delayMicroseconds(500);
  pulseIR2(D[5]);  // D6
  delayMicroseconds(500);
  pulseIR2(D[6]);  // D7
  delayMicroseconds(500);
  pulseIR2(D[7]);  // D8
  delayMicroseconds(500);
  pulseIR2(C[0]);  // C1
  delayMicroseconds(500);
  pulseIR2(U[0]);  // U1
  delayMicroseconds(500);
  pulseIR2(U[1]);  // U2
  delayMicroseconds(500);
  pulseIR2(Z[0]); // Z1
  delayMicroseconds(500);
  pulseIR2(Z[1]); // Z2

}
//******************************************************************************************************************************************************************************************


//******************************************************************************************************************************************************************************************
void SendFrag() {
  // This is the code for my particular laser tag gear for the Alpha (Red team) in Team Deathmatch, for others use the 'recieve brx sketch'
  // to 'grab' the proper code from the respawn station or general (recommend respawn station to avoid dual codes)
  Serial.println("Delay Countdown");
  Serial.println("5");
  digitalWrite(LED1, HIGH);
  delay(500);
  digitalWrite(LED1, LOW);
  delay(500);
  Serial.println("4");
  digitalWrite(LED1, HIGH);
  delay(500);
  digitalWrite(LED1, LOW);
  delay(500);  
  Serial.println("3");
  digitalWrite(LED1, HIGH);
  delay(500);
  digitalWrite(LED1, LOW);
  delay(500);
  Serial.println("3");
  digitalWrite(LED1, HIGH);
  delay(500);
  digitalWrite(LED1, LOW);
  delay(500);
  Serial.println("2");
  digitalWrite(LED1, HIGH);
  delay(500);
  digitalWrite(LED1, LOW);
  delay(500);
  

  digitalWrite(LED1, HIGH);
  SendIR();
  digitalWrite(LED1, LOW);
  delay(250);
  digitalWrite(LED1, HIGH);
  SendIR();
  digitalWrite(LED1, LOW);
  delay(250);
  digitalWrite(LED1, HIGH);
  SendIR();
  digitalWrite(LED1, LOW);
  delay(250);
  digitalWrite(LED1, HIGH);
  SendIR();
  digitalWrite(LED1, LOW);
  delay(250);
  digitalWrite(LED1, HIGH);
  SendIR();
  digitalWrite(LED1, LOW);
  delay(250);
  digitalWrite(LED1, HIGH);
  SendIR();
  digitalWrite(LED1, LOW);
  delay(250);
  digitalWrite(LED1, HIGH);
  SendIR();
  digitalWrite(LED1, LOW);
  delay(250);
  digitalWrite(LED1, HIGH);
  SendIR();
  digitalWrite(LED1, LOW);
  Serial.println("Delay Countdown");
  delay(15000);
  ActionState=0; // resets action state back to armable position so that IR Receive is engaged
  Serial.println("Grenade is Unarmed");
  Serial.println("Ready to Arm again");
}
//******************************************************************************************************************************************************************************************
//******************************************************************************************************************************************************************************************
// this procedure breaksdown each player bit of the brx ir signal recieved and assigns the applicable bit value then adds them together to identify the player ID (1-64)
void creategrenade() {
      // determining indivudual protocol values for player ID bits
      // Also assign IR values for sending player ID with device originated tags
      if (P[0] > 750) {
        P[0] = 1000;
      } else {
        P[0] = 500;
      }
      if (P[1] > 750) {
        P[1]=1000;
      } else {
        P[1]=500;
      }
      if (P[2] > 750) {
        P[2]=1000;
      } else {
        P[2]=500;
      }
      if (P[3] > 750) {
        P[3]=1000;
      } else {
        P[3]=500;
      }
      if (P[4] > 750) {
        P[4]=1000;
      } else {
        P[4]=500;
      }
      if (P[5] > 750) {
        P[5]=1000;
      } else {
        P[5]=500;
      }
  B[0]=1000;
  B[1]=500;
  B[2]=1000;
  B[3]=500;
  T[0]=1000;
  T[1]=500;
  D[0]=1000;
  D[1]=1000;
  D[2]=500;
  D[3]=500;
  D[4]=1000;
  D[5]=500;
  D[6]=500;
  D[7]=500;
  C[0]=500;
  U[0]=500;
  U[1]=500;
}
//******************************************************************************************************************************************************************************************
//******************************************************************************************************************************************************************************************
void paritycheck() {
  // parity changes, parity starts as even as if zero 1's
  // are present in the protocol recieved and being sent
  parity = 0;
  if (B[0] > 750) {
    if (parity == 0) {parity = 1;}
    else {parity = 0;}
  }
  if (B[1] > 750) {
    if (parity == 0) {parity = 1;}
    else {parity = 0;}
  }
  if (B[2] > 750) {
    if (parity == 0) {parity = 1;}
    else {parity = 0;}
  }
  if (B[3] > 750) {
    if (parity == 0) {parity = 1;}
    else {parity = 0;}
  }
  if (P[0] > 750) {
    if (parity == 0) {parity = 1;}
    else {parity = 0;}
  }
  if (P[1] > 750) {
    if (parity == 0) {parity = 1;}
    else {parity = 0;}
  }
  if (P[2] > 750) {
    if (parity == 0) {parity = 1;}
    else {parity = 0;}
  }
  if (P[3] > 750) {
    if (parity == 0) {parity = 1;}
    else {parity = 0;}
  }
  if (P[4] > 750) {
    if (parity == 0) {parity = 1;}
    else {parity = 0;}
  }
  if (P[5] > 750) {
    if (parity == 0) {parity = 1;}
    else {parity = 0;}
  }
  if (T[0] > 750) {
    if (parity == 0) {parity = 1;}
    else {parity = 0;}
  }
  if (T[1] > 750) {
    if (parity == 0) {parity = 1;}
    else {parity = 0;}
  }
  if (D[0] > 750) {
    if (parity == 0) {parity = 1;}
    else {parity = 0;}
  }
  if (D[1] > 750) {
    if (parity == 0) {parity = 1;}
    else {parity = 0;}
  }
  if (D[2] > 750) {
    if (parity == 0) {parity = 1;}
    else {parity = 0;}
  }
  if (D[3] > 750) {
    if (parity == 0) {parity = 1;}
    else {parity = 0;}
  }
  if (D[4] > 750) {
    if (parity == 0) {parity = 1;}
    else {parity = 0;}
  }
  if (D[5] > 750) {
    if (parity == 0) {parity = 1;}
    else {parity = 0;}
  }
  if (D[6] > 750) {
    if (parity == 0) {parity = 1;}
    else {parity = 0;}
  }
  if (D[7] > 750) {
    if (parity == 0) {parity = 1;}
    else {parity = 0;}
  }
  if (C[0] > 750) {
    if (parity == 0) {parity = 1;}
    else {parity = 0;}
  }
  if (U[0] > 750) {
    if (parity == 0) {parity = 1;}
    else {parity = 0;}
  }
  if (U[1] > 750) {
    if (parity == 0) {parity = 1;}
    else {parity = 0;}
  }
  if (parity == 0) {
    Z[0]=1050;
    Z[1]=525;
  }
  else {
    Z[0]=525;
    Z[1]=1050;
  }
  Serial.println("Modified Parity Bits:");
  Serial.println(Z[0]);
  Serial.println(Z[1]);  
}
//******************************************************************************************************************************************************************************************
void checkbutton() {
  //read the button/switch inputs
  int armingbutton = digitalRead(6);
  if (armingbutton == LOW) {
  Serial.println("grenade Armed!!!");
    creategrenade(); // creates grenade tag with player bits received
    paritycheck(); // fixes last two bits based upon modified tag bits
    ActionState = 1; // this stops the looping process for looking for an arming signal (brx signal)
    Serial.print("The Action state is ");
    Serial.println(ActionState);
    }
}

//******************************************************************************************************************************************************************************************
// This procedure uses the preset IR_Sensor_Pin to determine if an ir received is BRX, if so it records the protocol received
void receiveBRXir() {
  // makes the action below happen as it cycles through the 25 bits as was delcared above
  for (byte x = 0; x < 4; x++) B[x]=0;
  for (byte x = 0; x < 6; x++) P[x]=0;
  for (byte x = 0; x < 2; x++) T[x]=0;
  for (byte x = 0; x < 8; x++) D[x]=0;
  for (byte x = 0; x < 1; x++) C[x]=0;
  for (byte x = 0; x < 2; x++) U[x]=0;
  for (byte x = 0; x < 2; x++) Z[x]=0;
  // checks for a 2 millisecond sync pulse signal with a tollerance of 500 microsecons
  if (pulseIn(IR_Sensor_Pin, LOW, 150000) > 1500) {
      // stores each pulse or bit, individually
      B[0] = (pulseIn(IR_Sensor_Pin, LOW, 5000)); // B1
      B[1] = (pulseIn(IR_Sensor_Pin, LOW, 5000)); // B2
      B[2] = (pulseIn(IR_Sensor_Pin, LOW, 5000)); // B3
      B[3] = (pulseIn(IR_Sensor_Pin, LOW, 5000)); // B4
      P[0] = (pulseIn(IR_Sensor_Pin, LOW, 5000)); // P1
      P[1] = (pulseIn(IR_Sensor_Pin, LOW, 5000)); // P2
      P[2] = (pulseIn(IR_Sensor_Pin, LOW, 5000)); // P3
      P[3] = (pulseIn(IR_Sensor_Pin, LOW, 5000)); // P4
      P[4] = (pulseIn(IR_Sensor_Pin, LOW, 5000)); // P5
      P[5] = (pulseIn(IR_Sensor_Pin, LOW, 5000)); // P6
      T[0] = (pulseIn(IR_Sensor_Pin, LOW, 5000)); // T1
      T[1] = (pulseIn(IR_Sensor_Pin, LOW, 5000)); // T2
      D[0] = (pulseIn(IR_Sensor_Pin, LOW, 5000)); // D1
      D[1] = (pulseIn(IR_Sensor_Pin, LOW, 5000)); // D2
      D[2] = (pulseIn(IR_Sensor_Pin, LOW, 5000)); // D3
      D[3] = (pulseIn(IR_Sensor_Pin, LOW, 5000)); // D4
      D[4] = (pulseIn(IR_Sensor_Pin, LOW, 5000)); // D5
      D[5] = (pulseIn(IR_Sensor_Pin, LOW, 5000)); // D6
      D[6] = (pulseIn(IR_Sensor_Pin, LOW, 5000)); // D7
      D[7] = (pulseIn(IR_Sensor_Pin, LOW, 5000)); // D8
      C[0] = (pulseIn(IR_Sensor_Pin, LOW, 5000)); // C1
      U[0] = (pulseIn(IR_Sensor_Pin, LOW, 5000)); // ?1
      U[1] = (pulseIn(IR_Sensor_Pin, LOW, 5000)); // ?2
      Z[0] = (pulseIn(IR_Sensor_Pin, LOW, 5000)); // Z1
      Z[1] = (pulseIn(IR_Sensor_Pin, LOW, 5000)); // Z2
      Z[2] = (pulseIn(IR_Sensor_Pin, LOW, 5000)); // Z3 check for incorrect IR
      if (Z[1] != Z[0] && Z[2] < 250) {
      creategrenade(); // creates grenade tag with player bits received
      paritycheck(); // fixes last two bits based upon modified tag bits
      ActionState = 1; // this stops the looping process for looking for an arming signal (brx signal)
      Serial.print("The Action state is ");
      Serial.println(ActionState);
      }
      }
}
//******************************************************************************************************************************************************************************************
//******************************************************************************************************************************************************************************************
//******************************************************************************************************************************************************************************************
//******************************************************************************************************************************************************************************************
//******************************************************************************************************************************************************************************************
// The setup() method runs once, when the sketch starts
void setup()   {
  Z[2]=0; // sets for ir detection for BRX signal
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(RXLED, OUTPUT); // Set RX LED as an output
  pinMode(TXLED, OUTPUT); // Set TX LED as an output
  pinMode(6, INPUT_PULLUP); // button press pin
  // initialize the IR digital pin as an output:
  pinMode(IRledPin1, OUTPUT);
  pinMode(IRledPin2, OUTPUT);
  // Get IR Reciever pin set up:
  pinMode(IR_Sensor_Pin, INPUT);
  // initialize the serial port to view printed actions
  pinMode (LED1, OUTPUT); // indicator light
  Serial.begin(9600);
  Serial.println("IR input set up.... IR Output Set up.... Ready for Arming...");
  }
//******************************************************************************************************************************************************************************************
//******************************************************************************************************************************************************************************************
//******************************************************************************************************************************************************************************************
//******************************************************************************************************************************************************************************************
void loop(){
  if (ActionState == 0) {receiveBRXir(); digitalWrite(LED1, HIGH); checkbutton();} // if the grenade is not armed, await to be armed
  if (ActionState == 1) {SendFrag();} // if the grenade is armed, procedure to release the tag is executed
}
