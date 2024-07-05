const int speakerPin = 6;   // speaker digital pin
const int wirePin = A1;   //  wire detector analog pin
/////////////////////////

unsigned long avg = 0;
int count = 0;


void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(wirePin);
  
  if (sensorValue == 0) {
    return 0;
  }
  avg = (sensorValue + avg) / 2;

  if (count > 400) { 
    
    Serial.println(avg);
    
    if (avg > 110) { // voltage detected
       
        // bipper
        tone(speakerPin, 1000);     
        delay(0);       
        noTone(speakerPin);
    } 

    avg = 0;
    count = 0;
  }
  
  count++;
}
