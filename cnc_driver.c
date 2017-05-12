int clockPin = 8;
int latchPin = 9;
int dataPin = 10;

int bit_array[] = {
  0,0,0,0,0,0,0,0};

const int forw_but_1 = 6;
const int back_but_1 = 5;
const int led_ind_1 = 13;

const int forw_but_2 = 4;
const int back_but_2 = 3;
const int led_ind_2 = 13;

const int step_delay = 10;

int forw_state_1 = 0;
int back_state_1 = 0;
int forw_state_2 = 0;
int back_state_2 = 0;

int counter_1 = 0;
int counter_2 = 0;

int shift_value = 0;


void setup() {

  //Serial.begin(9600);

  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);

  pinMode(forw_but_1, INPUT);
  pinMode(back_but_1, INPUT);
  pinMode(led_ind_1, OUTPUT);

  pinMode(forw_but_2, INPUT);
  pinMode(back_but_2, INPUT);
  pinMode(led_ind_2, OUTPUT);
}

void move_stepper_1(int counter)
{
  //A
  if (counter == 0)
  {
    bit_array[0] = HIGH;
    bit_array[1] = LOW;
    bit_array[2] = HIGH;
    bit_array[3] = HIGH;
  }
  //B
  if (counter == 1)
  {  
    bit_array[0] = HIGH;
    bit_array[1] = LOW;
    bit_array[2] = HIGH;
    bit_array[3] = LOW; 
  }   
  //C
  if (counter == 2)
  {
    bit_array[0] = HIGH;
    bit_array[1] = HIGH;
    bit_array[2] = HIGH;
    bit_array[3] = LOW;
  }
  //D
  if (counter == 3)
  {
    bit_array[0] = LOW;
    bit_array[1] = HIGH;
    bit_array[2] = HIGH;
    bit_array[3] = LOW;
  }
  //E
  if (counter == 4)
  {
    bit_array[0] = LOW;
    bit_array[1] = HIGH;
    bit_array[2] = HIGH;
    bit_array[3] = HIGH;
  }
  //F
  if (counter == 5)
  {
    bit_array[0] = LOW;
    bit_array[1] = HIGH;
    bit_array[2] = LOW;
    bit_array[3] = HIGH;
  }
  //G
  if (counter == 6)
  {
    bit_array[0] = HIGH;
    bit_array[1] = HIGH;
    bit_array[2] = LOW;
    bit_array[3] = HIGH;
  }
  //H
  if (counter == 7)
  {
    bit_array[0] = HIGH;
    bit_array[1] = LOW;
    bit_array[2] = LOW;
    bit_array[3] = HIGH;
  }

}

void move_stepper_2(int counter)
{
  //A
  if (counter == 0)
  {
    bit_array[4] = HIGH;
    bit_array[5] = LOW;
    bit_array[6] = HIGH;
    bit_array[7] = HIGH;
  }
  //B
  if (counter == 1)
  {  
    bit_array[4] = HIGH;
    bit_array[5] = LOW;
    bit_array[6] = HIGH;
    bit_array[7] = LOW; 
  }   
  //C
  if (counter == 2)
  {
    bit_array[4] = HIGH;
    bit_array[5] = HIGH;
    bit_array[6] = HIGH;
    bit_array[7] = LOW;
  }
  //D
  if (counter == 3)
  {
    bit_array[4] = LOW;
    bit_array[5] = HIGH;
    bit_array[6] = HIGH;
    bit_array[7] = LOW;
  }
  //E
  if (counter == 4)
  {
    bit_array[4] = LOW;
    bit_array[5] = HIGH;
    bit_array[6] = HIGH;
    bit_array[7] = HIGH;
  }
  //F
  if (counter == 5)
  {
    bit_array[4] = LOW;
    bit_array[5] = HIGH;
    bit_array[6] = LOW;
    bit_array[7] = HIGH;
  }
  //G
  if (counter == 6)
  {
    bit_array[4] = HIGH;
    bit_array[5] = HIGH;
    bit_array[6] = LOW;
    bit_array[7] = HIGH;
  }
  //H
  if (counter == 7)
  {
    bit_array[4] = HIGH;
    bit_array[5] = LOW;
    bit_array[6] = LOW;
    bit_array[7] = HIGH;
  }

}


void loop()
{


  //Stepper 1
  forw_state_1 = digitalRead(forw_but_1);
  back_state_1 = digitalRead(back_but_1);

  if (forw_state_1 == HIGH && back_state_1 == LOW)
  {
    digitalWrite(led_ind_1, HIGH);
    counter_1 += 1;
    if (counter_1 > 7)
    {
      counter_1 = 0;
    }
    move_stepper_1(counter_1);
  }
  else if (forw_state_1 == LOW && back_state_1 == HIGH)
  {
    digitalWrite(led_ind_1, HIGH);
    counter_1 -=  1;
    if (counter_1 < 0)
    {
      counter_1 = 7;
    }
    move_stepper_1(counter_1);
  }
  else
  {
    digitalWrite(led_ind_1, LOW);
  }


  //Stepper 2
  forw_state_2 = digitalRead(forw_but_2);
  back_state_2 = digitalRead(back_but_2);

  if (forw_state_2 == HIGH && back_state_2 == LOW)
  {
    digitalWrite(led_ind_2, HIGH);
    counter_2 = counter_2 + 1;
    if (counter_2 > 7)
    {
      counter_2 = 0;
    }
    move_stepper_2(counter_2);
  }
  else if (forw_state_2 == LOW && back_state_2 == HIGH)
  {
    digitalWrite(led_ind_2, HIGH);
    counter_2 = counter_2 - 1;
    if (counter_2 < 0)
    {
      counter_2 = 7;
    }
    move_stepper_2(counter_2);
  }
  else
  {
    digitalWrite(led_ind_2, LOW);
  }


  //Shifting Out
  digitalWrite(latchPin, LOW);
  shift_value = 0;
  for( int i = 7; i >= 0; --i )
  {
    shift_value += bit_array[i]*pow(2,i);
    //Serial.print(bit_array[i]);
  }
  //Serial.println(shift_value);
  shiftOut(dataPin, clockPin, MSBFIRST, shift_value);
  digitalWrite(latchPin, HIGH);


  delay(step_delay);

}
