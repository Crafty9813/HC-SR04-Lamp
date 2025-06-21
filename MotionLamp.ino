#define trigPin 6
#define echoPin 5
#define bulb 9 

int distanceCounter = 0;

void setup()
{
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  pinMode(bulb, OUTPUT);   
}

void loop()
{
  int duration, distance;

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(500);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;

  // 10 cm threshold
  if (distance >= 0 && distance <= 10)
  {
    if (distanceCounter % 2 == 0)
    {
      digitalWrite(bulb, HIGH);
    }
    else
    {
      digitalWrite(bulb, LOW);
    }
    distanceCounter++;
  }
  else
  {
    distanceCounter = 0;
  }

  delay(500);
}
