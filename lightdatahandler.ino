int photosensor = A0;//light sensor connected to A0


// Declaring variables
int analogvalue;  
char light[30];


void setup() {

	Serial.begin();
    
    pinMode(D6, OUTPUT);
    pinMode(D7, OUTPUT);

	//Particle.variable("AnalogData", analogvalue);

    Particle.variable("Light", light);

    Particle.subscribe("hook-response/light", myHandler, MY_DEVICES);
}
void myHandler(const char *event, const char *data) {

}

void loop() {

    //Reading light value
	analogvalue = analogRead(photosensor);
	//Converting light value into string for particle.publish()
    sprintf(light,"%d", analogvalue);
    
    if (analogvalue < 50)
    {
        digitalWrite(D6, HIGH);
        digitalWrite(D7, HIGH);
    }
    else
    {
        digitalWrite(D6, LOW);
        digitalWrite(D7, LOW);
    }
    
    
    //Publishing to thinkspeak
	Particle.publish("light", light, PRIVATE);


	delay(10000);
}
