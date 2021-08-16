#define trigPin 13
#define echoPin 12
#include <NewPing.h>
#define MAX_DISTANCE 200

NewPing sonar(trigPin, echoPin, MAX_DISTANCE);

int redPin=9;
int bluePin=10;
int greenPin=11;   //RGB leds
int rl=6;
int gl=5;
int bl=8;   // independent red ,green and blue light
int sensorPin=A0;
int sensorVal=0;  // to detect changes light intensity
int buzzerPin=4;  // the buzzer
float distance;
long duration=0;

void setup() {

  Serial.begin(9600);
  pinMode( redPin, OUTPUT );
  pinMode( bluePin, OUTPUT );
  pinMode( greenPin, OUTPUT );
  pinMode( rl, OUTPUT );
  pinMode( bl, OUTPUT );
  pinMode( gl, OUTPUT );
  pinMode( buzzerPin, OUTPUT );
  pinMode( trigPin, OUTPUT );
  pinMode( echoPin, OUTPUT );

}

void loop() {

  digitalWrite( bl, HIGH );
  delay(200);            //power on indicator
  Serial.println("STATUS :POWER ON");
  digitalWrite( gl, HIGH);
  Serial.println("CAR HEALTHY");              // regular car check

  sensorVal=analogRead(sensorPin);
  Serial.println("CHECKING LIGHT INTENSITY .....");
  Serial.print("Intensity:");
  Serial.println(sensorVal);
  if(sensorVal <= 900){
    
    Serial.println("ITS DARK...PUTTING LIGHTS ON");
    digitalWrite( gl, LOW);
    
     
    setColor( 255 ,255 ,0 );
    delay(300);
    digitalWrite(gl, HIGH);
    delay(300);
    digitalWrite(gl, LOW);
    delay(300);
  }

  else{
    digitalWrite(gl, HIGH);
    delay(200);
    digitalWrite(gl, LOW);
    Serial.println("LIGHTING SEEMS FINE AROUND YOU");
    setColor(0,0,0);
    delay(200);
  }

  
  distance=check_distance();
  digitalWrite(gl, HIGH);


  if(distance <=10 && distance!=0){
      digitalWrite(gl, LOW);
      Serial.println("WOOOHOOOO Stop");
      digitalWrite(buzzerPin, HIGH);
      Serial.println(distance);
      
      while(check_distance()<=10)
      {
        if(check_light()<=650){
        setColor(255,255,0);
        }
        Serial.println("WATCH YOUR BACK");
        Serial.println(check_distance());
        digitalWrite(rl, HIGH);
        
        check_distance();
      }
      digitalWrite(buzzerPin, LOW);
      Serial.println("THATS FINE");
      digitalWrite(rl,LOW);
      digitalWrite(gl, HIGH);
      delay(200);
      digitalWrite(gl, LOW);
      delay(200);

     digitalWrite(gl, HIGH);
      delay(200);
      digitalWrite(gl, LOW);
      delay(200);
      
    
  }

   digitalWrite(gl, HIGH);
      delay(300);
      digitalWrite(gl, LOW);
      digitalWrite(bl,LOW);

}

void setColor(int r , int g , int b){
   analogWrite( redPin, r);
   analogWrite( greenPin, g);
   analogWrite( bluePin, b);
}

long check_distance()
{
  

  unsigned int uS = sonar.ping();
  pinMode(echoPin,OUTPUT);
  digitalWrite(echoPin,LOW);
  pinMode(echoPin,INPUT);
  Serial.print("Ping: ");
  Serial.print(uS / US_ROUNDTRIP_CM);
  Serial.println("cm");
  return uS / US_ROUNDTRIP_CM;
}

int check_light()
{
  sensorVal=analogRead(sensorPin);
  return sensorVal;
}
