const int ledPin1 =  8;
const int ledPin2 =  9;
const int ledPin3 =  10;
const int ledPin4 =  11;
const int forw_but = 5;
const int back_but = 6;
const int led_ind = 13;

const int step_delay = 40;


int forw_state = 0;
int back_state = 0;


void setup() {
  pinMode(ledPin1, OUTPUT);      
  pinMode(ledPin2, OUTPUT);      
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(forw_but, INPUT);
  pinMode(back_but, INPUT);
  pinMode(led_ind, OUTPUT);
}

void forward()
{
  //A
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, HIGH);
  digitalWrite(ledPin4, HIGH);
  delay(step_delay);
  //B
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, HIGH);
  digitalWrite(ledPin4, LOW);
  delay(step_delay);
  //C
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, HIGH);
  digitalWrite(ledPin3, HIGH);
  digitalWrite(ledPin4, LOW);
  delay(step_delay);
  //D
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, HIGH);
  digitalWrite(ledPin3, HIGH);
  digitalWrite(ledPin4, LOW);
  delay(step_delay);
  //E
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, HIGH);
  digitalWrite(ledPin3, HIGH);
  digitalWrite(ledPin4, HIGH);
  delay(step_delay);
  //F
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, HIGH);
  digitalWrite(ledPin3, LOW);
  digitalWrite(ledPin4, HIGH);
  delay(step_delay);
  //G
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, HIGH);
  digitalWrite(ledPin3, LOW);
  digitalWrite(ledPin4, HIGH);
  delay(step_delay);
  //H
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW);
  digitalWrite(ledPin4, HIGH);
  delay(step_delay);

}

void backward()
{
  //H
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW);
  digitalWrite(ledPin4, HIGH);
  delay(step_delay);
  //G
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, HIGH);
  digitalWrite(ledPin3, LOW);
  digitalWrite(ledPin4, HIGH);
  delay(step_delay);
  //F
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, HIGH);
  digitalWrite(ledPin3, LOW);
  digitalWrite(ledPin4, HIGH);
  delay(step_delay);
  //E
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, HIGH);
  digitalWrite(ledPin3, HIGH);
  digitalWrite(ledPin4, HIGH);
  delay(step_delay);
  //D
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, HIGH);
  digitalWrite(ledPin3, HIGH);
  digitalWrite(ledPin4, LOW);
  delay(step_delay);
  //C
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, HIGH);
  digitalWrite(ledPin3, HIGH);
  digitalWrite(ledPin4, LOW);
  delay(step_delay);
  //B
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, HIGH);
  digitalWrite(ledPin4, LOW);
  delay(step_delay);
  //A
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, HIGH);
  digitalWrite(ledPin4, HIGH);
  delay(step_delay);
}

void loop()
{
  //forward();
  forw_state = digitalRead(forw_but);
  back_state = digitalRead(back_but);

  if (forw_state == HIGH && back_state == LOW)
  {
    digitalWrite(led_ind, HIGH);
    forward();
  }
  else if (forw_state == LOW && back_state == HIGH)
  {
    digitalWrite(led_ind, HIGH);
    backward();
  }
  else
  {
    digitalWrite(led_ind, LOW);
  }
}
