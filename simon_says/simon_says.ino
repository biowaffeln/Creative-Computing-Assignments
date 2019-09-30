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
  pinMode(1, INPUT);
  pinMode(2, INPUT);
  pinMode(3, INPUT);

  /* restart input */
  pinMode(8, INPUT);

  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);

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
    digitalWrite(10, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
    delay(500);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    delay(500);
    digitalWrite(10, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
    delay(500);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
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
    digitalWrite(10, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
  }
}
