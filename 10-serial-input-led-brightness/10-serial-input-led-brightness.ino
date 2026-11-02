 int ui;
 int writeVal;
 int redPin=4;
 int br=115200;
 int waitT=100;
 String prompt="Please Input Desired Brightness (0-10)";

 void setup() {
  // put your setup code here, to run once:
  Serial.begin(br);
  pinMode(redPin,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(prompt);
  while (Serial.available()==0){

  }
ui=Serial.parseInt();
writeVal=pow(2,(8./10.)*ui)-1;
Serial.println(writeVal);
analogWrite(redPin,writeVal);
}
