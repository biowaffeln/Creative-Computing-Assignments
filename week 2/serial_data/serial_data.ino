void setup()
{
  Serial.begin(9600);
  Serial.println("what's your name?");
}

bool welcome = true;

String phrases[4] = {
    "That's interesting, tell me more about that.",
    "How does this make you feel?",
    "Do you think this has something to do with your relationship with your mother?",
    "Can you elaborate on that?"};

void loop()
{

  if (Serial.available())
  {
    if (welcome)
    {
      Serial.println("Welcome. How are you?");
      Serial.readString();
      welcome = false;
    }
    else
    {
      String s = Serial.readString();
      Serial.println(s);
      Serial.println(phrases[rand() % 4]);
    }
  }
}