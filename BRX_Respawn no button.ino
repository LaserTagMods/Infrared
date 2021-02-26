// This sketch will send out a BRX-Respawn-Alpha-Team signal (probably works...)
// Completed by Red, Josh and Jay
 
int IRledPin =  13;    // LED connected to digital pin 13
 
// The setup() method runs once, when the sketch starts
 
void setup()   {                
  // initialize the IR digital pin as an output:
  pinMode(IRledPin, OUTPUT);      
 
  Serial.begin(9600);
}
 
void loop()                     
{
// you can enable or disable the blue respawn, red respawn or green respawn by removing the foreward
// slashes on the commands and code sections below and adding them to the unaplicable ones.
  
  Serial.println("Sending IR signal");
 
 SendAlphaRespawn();  // remove the forward slashes to activate, add forward slashes to deactivate
 delay(300); // wait 3 seconds for next respawn signal
 SendBravoRespawn();  // remove the forward slashes to activate, add forward slashes to deactivate
 delay(300); // wait 3 secons for next respawns signal
 SendVanguardRespawn(); // remove forward slashes to activate, add forward slashes to deactivate
 delay(300);  // wait 3 seconds (5 seconds * 1000 milliseconds) This causes a delay between respawns, you can adjust this or add a button code in... comming soon.
}
 
// This procedure sends a 38KHz pulse to the IRledPin 
// for a certain # of microseconds. We'll use this whenever we need to send codes
void pulseIR(long microsecs) {
  // we'll count down from the number of microseconds we are told to wait
 
  cli();  // this turns off any background interrupts
 
  while (microsecs > 0) {
    // 38 kHz is about 13 microseconds high and 13 microseconds low
   digitalWrite(IRledPin, HIGH);  // this takes about 3 microseconds to happen
   delayMicroseconds(10);         // hang out for 10 microseconds, you can also change this to 9 if its not working
   digitalWrite(IRledPin, LOW);   // this also takes about 3 microseconds
   delayMicroseconds(10);         // hang out for 10 microseconds, you can also change this to 9 if its not working
 
   // so 26 microseconds altogether
   microsecs -= 26;
  }
 
  sei();  // this turns them back on
}
 
void SendAlphaRespawn() {
  // This is the code for my particular laser tag gear for the Alpha (Red team) in Team Deathmatch, for others use the 'recieve brx sketch'
  // to 'grab' the proper code from the respawn station or general (recommend respawn station to avoid dual codes)
 
    pulseIR(2000);
  delayMicroseconds(500);
  pulseIR(1000);
  delayMicroseconds(500);
  pulseIR(1000);
  delayMicroseconds(500);
  pulseIR(1000);
  delayMicroseconds(500);
  pulseIR(1000);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(1000);
  delayMicroseconds(500);
  pulseIR(1000);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(1000);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(1000);

 
  delay(65); // wait 65 milliseconds before sending it again

 // copy code from above, dont be silly only type it once

    pulseIR(2000);
  delayMicroseconds(500);
  pulseIR(1000);
  delayMicroseconds(500);
  pulseIR(1000);
  delayMicroseconds(500);
  pulseIR(1000);
  delayMicroseconds(500);
  pulseIR(1000);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(1000);
  delayMicroseconds(500);
  pulseIR(1000);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(1000);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(1000);

}

void SendBravoRespawn() {
// This is the code for my particular laser tag gear for the Bravo/Nexus/freeforall (Blue team) in deathmatch or supremacy, for others use the 'recieve brx sketch'
// to 'grab' the proper code from the respawn station or general (recommend respawn station to avoid dual codes)
 
    pulseIR(2000);
  delayMicroseconds(500);
  pulseIR(1000);
  delayMicroseconds(500);
  pulseIR(1000);
  delayMicroseconds(500);
  pulseIR(1000);
  delayMicroseconds(500);
  pulseIR(1000);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(1000);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(1000);
  delayMicroseconds(500);
  pulseIR(1000);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(1000);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(1000);
  delayMicroseconds(500);
  pulseIR(500);

 
  delay(65); // wait 65 milliseconds before sending it again

 // copy code from above, dont be silly only type it once

    pulseIR(2000);
  delayMicroseconds(500);
  pulseIR(1000);
  delayMicroseconds(500);
  pulseIR(1000);
  delayMicroseconds(500);
  pulseIR(1000);
  delayMicroseconds(500);
  pulseIR(1000);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(1000);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(1000);
  delayMicroseconds(500);
  pulseIR(1000);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(1000);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(1000);
  delayMicroseconds(500);
  pulseIR(500);

}

void SendVanguardRespawn() {
// This is the code for my particular laser tag gear for the Vanguard/Infected (Green team) in Infected or supremacy, for others use the 'recieve brx sketch'
// to 'grab' the proper code from the respawn station or general (recommend respawn station to avoid dual codes)
 
    pulseIR(2000);
  delayMicroseconds(500);
  pulseIR(1000);
  delayMicroseconds(500);
  pulseIR(1000);
  delayMicroseconds(500);
  pulseIR(1000);
  delayMicroseconds(500);
  pulseIR(1000);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(1000);
  delayMicroseconds(500);
  pulseIR(1000);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(1000);
  delayMicroseconds(500);
  pulseIR(1000);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(1000);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(1000);

 
  delay(65); // wait 65 milliseconds before sending it again

 // copy code from above, dont be silly only type it once

    pulseIR(2000);
  delayMicroseconds(500);
  pulseIR(1000);
  delayMicroseconds(500);
  pulseIR(1000);
  delayMicroseconds(500);
  pulseIR(1000);
  delayMicroseconds(500);
  pulseIR(1000);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(1000);
  delayMicroseconds(500);
  pulseIR(1000);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(1000);
  delayMicroseconds(500);
  pulseIR(1000);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(1000);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(500);
  delayMicroseconds(500);
  pulseIR(1000);

}
