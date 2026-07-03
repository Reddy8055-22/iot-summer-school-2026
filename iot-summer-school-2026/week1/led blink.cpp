void setup(){
    pinMode(13 , OUTPUT);//defines bulitin led for work and can connect other led 
}
void loop(){
    digitalWrite(13, HIGH);//truns on led , high indicates voltage
    delay(2500);// delays the code for 2.5 seconds after excuting above line
    digitalWrite(13, Low);//truns off led , low indicates voltage 
    delay(2500);// delays code the for 2.5 seconds after excuting above line
}