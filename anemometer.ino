const int REED_PIN = 2; // Pin connected to reed switch
const int LED_PIN = 13; // LED pin - active-high
int cps = 0;
int equa = (cps*(105*M_PI*2))/60;
const unsigned long PERIOD = 60000UL;
unsigned long target_time = 0L ;
float mph = 0;
void setup() 
{
  Serial.begin(9600);
  pinMode(REED_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
}


void loop ()
{
  if (millis () - target_time >= PERIOD)
  {
    target_time += PERIOD ;   // change scheduled time exactly, no slippage will happen
   // Serial.print("\n");
    //Serial.print(cps);
    mph = (cps*(0.344488*M_PI*2))/1/88;
    cps = 0;
    Serial.print("\n");
    Serial.print(mph);
    }
  int proximity = digitalRead(REED_PIN); // Read the state of the switch
  if (proximity == LOW) // If the pin reads low, the switch is closed.
  {
    cps++;

    digitalWrite(LED_PIN, HIGH); // Turn the LED on
    delay(100);

  }
  else
  {
    digitalWrite(LED_PIN, LOW); // Turn the LED off
  }
