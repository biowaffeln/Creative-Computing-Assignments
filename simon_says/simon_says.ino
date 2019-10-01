#include <ArduinoSTL.h>
#include <list>

#define RESTART_INPUT_PORT 8

#define GREEN_INPUT_PORT 1
#define ORANGE_INPUT_PORT 2
#define RED_INPUT_PORT 3

#define GREEN_OUTPUT_PORT 10
#define ORANGE_OUTPUT_PORT 11
#define RED_OUTPUT_PORT 12

int colors[3] = {GREEN_OUTPUT_PORT, ORANGE_OUTPUT_PORT, RED_OUTPUT_PORT};

enum State
{
  idle,
  start,
  blinking,
  input,
  finish
};

State gameState;
int level;
std::list<int> sequence;
std::list<int> userInput;

/* helper functions */

std::list<int> generateSequence(int currentLevel)
{
  int listLength = currentLevel + 2;

  std::list<int> sequence;
  int prevItem;
  int i = 0;

  while (i < listLength)
  {
    int color = colors[rand() % 3];
    if (color != prevItem)
    {
      sequence.push_back(color);
      prevItem = color;
      i++;
    }
  }

  return sequence;
}

void setup()
{
  /* initial state */
  gameState = State::idle;
  level = 1;

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

    sequence = generateSequence(level);

    for (const auto &port : sequence)
    {
      digitalWrite(port, HIGH);
      delay(500);
      digitalWrite(port, LOW);
      delay(500);
    }
    gameState = State::input;
  }

  /* input */
  if (gameState == State::input)
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
