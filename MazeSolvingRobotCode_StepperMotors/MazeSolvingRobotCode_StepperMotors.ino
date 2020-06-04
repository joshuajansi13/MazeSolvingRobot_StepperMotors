
int directionPinRight = 2;
int directionPinLeft = 7;
int pwmPin = 5;
int pwmPin2 = 6;
int sleepPin = 4;
int sleepPin2 = 3;
int echo1 = 8;
int trigger1 = 9;
int echo2 = 11;
int trigger2 = 10;
double wheelRadius = 2.6;
int trigger3 = 13;
int echo3 = 12;
int LEFT = 3;
int RIGHT = 2;
int STRAIGHT = 1;
int OBSTACLE_CLOSE = 0;
float straightDistance = 0, rightDistance = 0, leftDistance = 0;

void setup() {
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(trigger1, OUTPUT);
  pinMode(echo1,INPUT);
  pinMode(trigger2, OUTPUT);
  pinMode(echo2,INPUT);
  pinMode(trigger3, OUTPUT);
  pinMode(echo3,INPUT);
  Serial.begin(9600);
}



void loop() {
  TurnOnWheels();
  GoStraight();
//  straightDistance = (straightDistance*0.8) + (0.2*GetDistance(STRAIGHT));
//  rightDistance = (rightDistance*0.8) + (0.2*GetDistance(RIGHT));
//  leftDistance = (leftDistance*0.8) + (0.2*GetDistance(LEFT));
    straightDistance = GetDistance(STRAIGHT);
    rightDistance = GetDistance(RIGHT);
    leftDistance = GetDistance(LEFT);
    
    if (straightDistance < OBSTACLE_CLOSE) {
      if (leftDistance < OBSTACLE_CLOSE && rightDistance < OBSTACLE_CLOSE) {
        LeftTurn90();
        LeftTurn90();
      }
      else if (leftDistance > rightDistance) {
        LeftTurn90();
      }
      else if (rightDistance > leftDistance) {
        RightTurn90();
      }
    }
}

void inchesToTravel(int x) {
  
  return;
}

void GoStraight() {
  digitalWrite(directionPinRight,HIGH);
  digitalWrite(directionPinLeft,LOW);
  analogWrite(pwmPin,127);
  analogWrite(pwmPin2,127);
  return;
}

void RightTurn90() {
  digitalWrite(directionPinRight,LOW);
  digitalWrite(directionPinLeft,LOW);
  delay(550);
  return;
}

void LeftTurn90() {
  digitalWrite(directionPinRight,HIGH);
  digitalWrite(directionPinLeft,HIGH);
  delay(550);
  return;
}
void TurnOnWheels () {
      digitalWrite(sleepPin,HIGH);
      digitalWrite(sleepPin2,HIGH);
      analogWrite(pwmPin,127);
      analogWrite(pwmPin2,127);
      return;
}

void TurnOffWheels () {
      digitalWrite(sleepPin,LOW);
      digitalWrite(sleepPin2,LOW);
      analogWrite(pwmPin,0);
      analogWrite(pwmPin2,0);
      return;
}

double GetDistance(int directions) {
  double duration, distance;
  if (directions == STRAIGHT) {
  digitalWrite(trigger1,LOW);
  
  delayMicroseconds(2);
  digitalWrite(trigger1,HIGH);
  
  delayMicroseconds(10);
  duration = pulseIn(echo1,HIGH);
  distance = (duration/2)*0.0343;
 
  Serial.println("distance1 =  ");
 
  //Serial.println(distance);
  }
  else if (directions == RIGHT) {
  digitalWrite(trigger2,LOW);
  
  delayMicroseconds(2);
  digitalWrite(trigger2,HIGH);
  
  delayMicroseconds(10);
  duration = pulseIn(echo2,HIGH);
  distance = (duration/2)*0.0343;
 
  Serial.println("distance2 =  ");
 
  //Serial.println(distance);
  }

  else if (directions == LEFT) {
  digitalWrite(trigger3,LOW);
  
  delayMicroseconds(3);
  digitalWrite(trigger3,HIGH);
  
  delayMicroseconds(10);
  duration = pulseIn(echo3,HIGH);
  distance = (duration/2)*0.0343;
 
  Serial.println("distance3 =  ");
 
  //Serial.println(distance);
  }
  return distance;

}



