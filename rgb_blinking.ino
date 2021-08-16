int rp=9;
int gp=10;
int bp=11;

void setup() {
  pinMode(rp, OUTPUT);
  pinMode(gp, OUTPUT);
  pinMode(bp, OUTPUT);

}

void loop() {

  digitalWrite(rp, HIGH);
  delay(1000);
  digitalWrite(rp, LOW);
  digitalWrite(gp, HIGH);
  digitalWrite(bp, LOW);
  delay(1000);
  digitalWrite(rp, LOW);
  digitalWrite(gp, LOW);
  digitalWrite(bp, HIGH);
  delay(1000);
  digitalWrite(rp, HIGH);
  digitalWrite(bp, HIGH);
  digitalWrite(gp, HIGH);
  delay(1000);

}
