int redPin=2;
int greenPin=4;
int yellowPin=5;
int br=115200;
String myLed;

void setup() {
  Serial.begin(br);
  pinMode(redPin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  pinMode(yellowPin,OUTPUT);
}

void loop() {
  Serial.println("Please select a colour (red,green,yellow)" );
  while(Serial.available()==0){
  }
  myLed=Serial.readString();
  myLed.toLowerCase();
  if(myLed=="red"){
    Serial.println("Your selected led is Red");
    digitalWrite(redPin,HIGH);
    digitalWrite(greenPin,LOW);
    digitalWrite(yellowPin,LOW);
  }
  if(myLed=="green"){
    Serial.println("Your selected led is Green");
    digitalWrite(greenPin,HIGH);
    digitalWrite(yellowPin,LOW);
    digitalWrite(redPin,LOW);
  }
  if(myLed=="yellow"){
    Serial.println("Your selected led is Yellow");
    digitalWrite(yellowPin,HIGH);
    digitalWrite(redPin,LOW);
    digitalWrite(greenPin,LOW);
  }
}
