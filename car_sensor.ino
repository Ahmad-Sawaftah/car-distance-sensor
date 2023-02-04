//Rled == RED LED , Gled == GREEN LED , Oled == ORANGE LED ;


const int echo=10;
const int triger=9;
const int Rled=5;
const int Gled=4;
const int Oled=3;
const int sound=6;
int val;
int distance;


void setup() {
    pinMode(echo,INPUT);
    pinMode(triger,OUTPUT);
    pinMode(Rled,OUTPUT);
    pinMode(Gled, OUTPUT);
    pinMode(Oled, OUTPUT);
    pinMode(sound,OUTPUT);
}

void loop() {
  // lunch the triger :
    digitalWrite(triger,LOW);
    delayMicroseconds(2);
    digitalWrite(triger,HIGH);
    delayMicroseconds(10);
    digitalWrite(triger,LOW);

  // get the distance :
    val =pulseIn(echo,HIGH);
    distance=val*0.034/2;

  // control the sound and the LED :

    if(distance<15 && distance>10){
      digitalWrite(Gled,HIGH);
    }

    if(distance<10 && distance>5){
      digitalWrite(Gled, LOW);
      digitalWrite(Oled,HIGH);
      digitalWrite(sound,HIGH);
      delay(1200);
      digitalWrite(sound,LOW);
    }

    if(distance<5){
      digitalWrite(Oled, LOW);
      digitalWrite(Rled,HIGH);
      digitalWrite(sound,HIGH);
      delay(500);
      digitalWrite(sound,LOW);
    }

    

    
}
