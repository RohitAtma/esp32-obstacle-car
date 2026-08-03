int ForwardPin = 4;
int BackwardPin = 5;
int DelayTime = 1000;
int Distance;
long duration;
int TrigPin = 14;
int EchoPin = 25;
int ForwardPinTwo = 12;
int BackwardPinTwo = 13;

void Forward(){
digitalWrite(ForwardPin, LOW);
digitalWrite(BackwardPin, HIGH);
digitalWrite(ForwardPinTwo, HIGH);
digitalWrite(BackwardPinTwo, LOW);
}
void Backward(){
digitalWrite(ForwardPin, HIGH);
digitalWrite(BackwardPin, LOW);
digitalWrite(ForwardPinTwo, LOW);
digitalWrite(BackwardPinTwo, HIGH);
}
void Left(){
digitalWrite(ForwardPin, HIGH);
digitalWrite(BackwardPin, HIGH);
digitalWrite(ForwardPinTwo, HIGH);
digitalWrite(BackwardPinTwo, LOW);
}
void Right(){
digitalWrite(ForwardPin, HIGH);
digitalWrite(BackwardPin, LOW);
digitalWrite(ForwardPinTwo, HIGH);
digitalWrite(BackwardPinTwo, HIGH);
}
void Stop(){
digitalWrite(ForwardPin, LOW);
digitalWrite(BackwardPin, LOW);
digitalWrite(ForwardPinTwo, LOW);
digitalWrite(BackwardPinTwo, LOW);
}

void setup()
{
  Serial.begin(9600);
  pinMode(ForwardPin, OUTPUT);
  pinMode(BackwardPin, OUTPUT);
  pinMode(ForwardPinTwo, OUTPUT);
  pinMode(BackwardPinTwo, OUTPUT);
  pinMode(TrigPin, OUTPUT);
  pinMode(EchoPin, INPUT);
}

void loop()
{
  if(millis() >= 30000){
    Stop();
    return;
  }

  digitalWrite(TrigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin, LOW);

  duration = pulseIn(EchoPin, HIGH, 30000);
  Distance = duration * 0.0343 / 2;

  Serial.print("Duration: ");
  Serial.print(duration);
  Serial.print(" | Distance: ");
  Serial.println(Distance);

  if (duration == 0) {
    Forward();
  }
  else if (Distance < 15) {
    Backward();
    delay(DelayTime);
    Left();
    delay(DelayTime);
  }
  else {
    Forward();
  }
}