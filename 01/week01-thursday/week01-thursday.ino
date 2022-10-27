int button;
int light;
void setup() {
  // put your setup code here, to run once:
  pinMode(9,OUTPUT);
  pinMode(2,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 button = digitalRead(2);
 light = analogRead(A0);
 Serial.println(light);
 if(button==HIGH){
   digitalWrite(9,HIGH);
 }else{
   digitalWrite(9,LOW);
 }
 delay(10);
}



