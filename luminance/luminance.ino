#define LEDPIN 9
#define LUMPIN A1

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LEDPIN,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int luminance;
  luminance = analogRead(LUMPIN);
  Serial.println(luminance/4);
  analogWrite(LEDPIN,luminance/4);
}
