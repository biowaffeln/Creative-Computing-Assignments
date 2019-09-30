#define RESTART_INPUT_PORT 8

#define GREEN_INPUT_PORT 1
#define ORANGE_INPUT_PORT 2
#define RED_INPUT_PORT 3

#define GREEN_OUTPUT_PORT 10
#define ORANGE_OUTPUT_PORT 11
#define RED_OUTPUT_PORT 12

enum State
{
  idle,
  start,
  blinking,
  input,
  finish
};

enum Level
{
  level1,
  level2,
  level3
};

State gameState;
Level level;

void setup()
{
  /* initial state */
  gameState = State::idle;
  level = Level::level1;

  /* LED Inputs */
  pinMode(GREEN_INPUT_PORT, INPUT);
  pinMode(ORANGE_INPUT_PORT, INPUT);
  pinMode(RED_INPUT_PORT, INPUT);

  /* restart input */
  pinMode(RESTART_INPUT_PORT, INPUT);

  pinMode(GREEN_OUTPUT_PORT, OUTPUT);
  pinMode(ORANGE_OUTPUT_PORT, OUTPUT);
  pinMode(RED_OUTPUT_PORT, OUTPUT);
  digitalWrite(GREEN_OUTPUT_PORT, LOW);
  digitalWrite(ORANGE_OUTPUT_PORT, LOW);
  digitalWrite(RED_OUTPUT_PORT, LOW);

  /* for debugging */
  // Serial.begin(9600);
}

void loop()
{
  /* reset */
  if (digitalRead(8) == HIGH)
  {
    gameState = State::start;
  }

  /* start state */
  if (gameState == State::start)
  {
    digitalWrite(GREEN_OUTPUT_PORT, HIGH);
    digitalWrite(ORANGE_OUTPUT_PORT, HIGH);
    digitalWrite(RED_OUTPUT_PORT, HIGH);
    delay(500);
    digitalWrite(GREEN_OUTPUT_PORT, LOW);
    digitalWrite(ORANGE_OUTPUT_PORT, LOW);
    digitalWrite(RED_OUTPUT_PORT, LOW);
    delay(500);
    digitalWrite(GREEN_OUTPUT_PORT, HIGH);
    digitalWrite(ORANGE_OUTPUT_PORT, HIGH);
    digitalWrite(RED_OUTPUT_PORT, HIGH);
    delay(500);
    digitalWrite(GREEN_OUTPUT_PORT, LOW);
    digitalWrite(ORANGE_OUTPUT_PORT, LOW);
    digitalWrite(RED_OUTPUT_PORT, LOW);
    delay(1000);
    gameState = State::blinking;
  }

  /* blinking */
  if (gameState == State::blinking)
  {
  }

  /* finish */
  if (gameState == State::finish)
  {
    delay(500);
    digitalWrite(GREEN_OUTPUT_PORT, HIGH);
    digitalWrite(ORANGE_OUTPUT_PORT, HIGH);
    digitalWrite(RED_OUTPUT_PORT, HIGH);
  }
}
