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

  // 10 cm threshold - check if an object is detected
  if (distance >= 0 && distance <= 10)
  {
    if (distanceCounter % 2 == 0) // Turn on if counter is even (counter mod 2 = 0)
    {
      digitalWrite(bulb, HIGH);
    }
    else
    {
      digitalWrite(bulb, LOW);
    }
    distanceCounter++; //Increment counter by 1 so can alternate btwn even and odd
  }
  else
  {
    distanceCounter = 0;
  }

  // Gives a bit of delay so doesn't flicker a ton
  delay(700);
}
