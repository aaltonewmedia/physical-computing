int light; //0-1023
int pot;
int b;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(9,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  light = analogRead(A0); // 0 to 1023
  pot = analogRead(A1);
  Serial.println("Min:0, Max:1023");
  Serial.print(light);
  Serial.print(' ');
  Serial.println(pot);
  b = map(light,pot,0,100,255);

  if(light < pot){ 
    analogWrite(9,b);
  }else{
    analogWrite(9,0);
  }
  delay(10);
}
