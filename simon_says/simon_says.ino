#include <ArduinoSTL.h>
#include <vector>
using namespace std;

#define RESTART_INPUT_PORT 8

#define GREEN_INPUT_PORT 1
#define ORANGE_INPUT_PORT 2
#define RED_INPUT_PORT 3

#define GREEN_OUTPUT_PORT 10
#define ORANGE_OUTPUT_PORT 11
#define RED_OUTPUT_PORT 12

int colorOutputs[3] = {GREEN_OUTPUT_PORT, ORANGE_OUTPUT_PORT, RED_OUTPUT_PORT};
int colorInputs[3] = {GREEN_OUTPUT_PORT, ORANGE_OUTPUT_PORT, RED_OUTPUT_PORT};

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
vector<int> levelSequence;
vector<int> userInput;

/* helper functions */

vector<int> generateSequence(int currentLevel)
{
  int listLength = currentLevel + 2;

  vector<int> sequence;
  int prevItem;
  int i = 0;

  while (i < listLength)
  {
    int color = colorOutputs[rand() % 3];
    if (color != prevItem)
    {
      sequence.push_back(color);
      prevItem = color;
      i++;
    }
  }

  return sequence;
}

bool matching(vector<int> input, vector<int> sequence)
{
  /* should never happen, but eh, better be safe */
  if (input.size() > sequence.size())
    return false;

  for (int i = 0; i < input.size(); i++)
  {
    if (input[i] != sequence[i])
    {
      return false;
    }
  }
  return true;
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
    digitalWrite(GREEN_OUTPUT_PORT, LOW);
    digitalWrite(ORANGE_OUTPUT_PORT, LOW);
    digitalWrite(RED_OUTPUT_PORT, LOW);
    level = 1;
    userInput.clear();
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
    levelSequence = generateSequence(level);
    gameState = State::blinking;
  }

  /* blinking */
  if (gameState == State::blinking)
  {

    for (const auto &port : levelSequence)
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
    for (const auto &port : colorInputs)
    {
      if (digitalRead(port) == HIGH && (userInput.empty() || port != userInput.back()))
      {
        userInput.push_back(port);

        if (matching(userInput, levelSequence))
        {
          if (userInput.size() == levelSequence.size())
          {
            // go to next level;
            userInput.clear();
            levelSequence.clear();
            level++;
            digitalWrite(GREEN_OUTPUT_PORT, HIGH);
            digitalWrite(ORANGE_OUTPUT_PORT, HIGH);
            digitalWrite(RED_OUTPUT_PORT, HIGH);
            delay(200);
            digitalWrite(GREEN_OUTPUT_PORT, LOW);
            digitalWrite(ORANGE_OUTPUT_PORT, LOW);
            digitalWrite(RED_OUTPUT_PORT, LOW);
            delay(200);
            digitalWrite(GREEN_OUTPUT_PORT, HIGH);
            digitalWrite(ORANGE_OUTPUT_PORT, HIGH);
            digitalWrite(RED_OUTPUT_PORT, HIGH);
            delay(200);
            digitalWrite(GREEN_OUTPUT_PORT, LOW);
            digitalWrite(ORANGE_OUTPUT_PORT, LOW);
            digitalWrite(RED_OUTPUT_PORT, LOW);

            if (level > 3)
            {
              delay(500);
              gameState = State::finish;
            }
            else
            {
              delay(1000);
              levelSequence = generateSequence(level);
              gameState = State::blinking;
            }
          }
        }
        else
        {
          // restart level;
          userInput.clear();
          digitalWrite(GREEN_OUTPUT_PORT, HIGH);
          digitalWrite(ORANGE_OUTPUT_PORT, HIGH);
          digitalWrite(RED_OUTPUT_PORT, HIGH);
          delay(1000);
          digitalWrite(GREEN_OUTPUT_PORT, LOW);
          digitalWrite(ORANGE_OUTPUT_PORT, LOW);
          digitalWrite(RED_OUTPUT_PORT, LOW);
          delay(1000);
          gameState = State::blinking;
        }
      }
    }
  }

  /* finish */
  if (gameState == State::finish)
  {
    digitalWrite(GREEN_OUTPUT_PORT, HIGH);
    digitalWrite(ORANGE_OUTPUT_PORT, HIGH);
    digitalWrite(RED_OUTPUT_PORT, HIGH);
  }
}
