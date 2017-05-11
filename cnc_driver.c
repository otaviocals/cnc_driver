const int ledPin1 =  8;
const int ledPin2 =  9;
const int ledPin3 =  10;
const int ledPin4 =  11;

const int forw_but_2 = 3;
const int back_but_2 = 4;
const int led_ind_2 = 12;

const int forw_but_1 = 5;
const int back_but_1 = 6;
const int led_ind_1 = 13;

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

void forward_1()
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

void backward_1()
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
  //Stepper 1
  forw_state_1 = digitalRead(forw_but_1);
  back_state_1 = digitalRead(back_but_1);

  if (forw_state_1 == HIGH && back_state_1 == LOW)
  {
    digitalWrite(led_ind_1, HIGH);
    forward();
  }
  else if (forw_state_1 == LOW && back_state_1 == HIGH)
  {
    digitalWrite(led_ind_1, HIGH);
    backward();
  }
  else
  {
    digitalWrite(led_ind_1, LOW);
  }

  //Stepper 2
  forw_state_2 = digitalRead(forw_but_2);
  back_state_2 = digitalRead(back_but_2);

  if (forw_state_2 == HIGH && backstate_2 == LOW)
  {
      digitalWrite(led_ind_2, HIGH);
      forward_1();
  }
  else if (forw_state_2 == LOW && back_state_2 == HIGH)
  {
      digitalWrite(led_ind_2, HIGH);
      backward_1();
  }
  else
  {
      digitalWrite(led_ind_2, LOW);
  }
}
