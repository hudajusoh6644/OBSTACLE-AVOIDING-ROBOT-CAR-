//hcsr04 code for the car project week 3 //
//DONE//

//motor driver pins
#define in1 2
#define in2 3
#define in3 4
#define in4 5

#define enA 6
#define enB 7

//sensor pins
#define trig_pin 9 //analog input 1
#define echo_pin 10 //analog input 2

long duration, distance;

void setup(){

  delay(random(500,2000));   // delay for random time
  Serial.begin(9600);

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);

  pinMode(echo_pin, INPUT);//sensor pin 
  pinMode(trig_pin, OUTPUT);//sensor pin 
}

void loop(){

  digitalWrite(trig_pin, LOW);

  delayMicroseconds(2);   

  digitalWrite(trig_pin, HIGH);     // send waves for 10 us

  delayMicroseconds(10);

  duration = pulseIn(echo_pin, HIGH); // receive reflected waves

  distance = duration / 58.2;   // convert to distance

  delay(10);

  if (distance > 19)            

  {
    digitalWrite(enA, 70);
    digitalWrite(enB, 70);
    digitalWrite(in1, LOW);//FORWARD
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
  }

if (distance < 18)

  {
    digitalWrite(in1, LOW);//stop
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);

    delay(500);

    digitalWrite(enA, 70);
    digitalWrite(enB, 70);
    digitalWrite(in1, HIGH);//REVERSE
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);

    delay(500);

    digitalWrite(in1, LOW);//stop
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);

    delay(100);  
  
  digitalWrite(enA, 70);
  digitalWrite(enB, 85);
  digitalWrite(in1, HIGH); //right
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

  delay(500);

  digitalWrite(enA, 70);
  digitalWrite(enB, 70);
  digitalWrite(in1, LOW);//FORWARD
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

  }

}

