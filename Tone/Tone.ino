#define NOTE_C 262
#define NOTE_D 294
#define NOTE_E 330
#define NOTE_F 349
#define NOTE_G 392
#define NOTE_A 440
#define NOTE_B 493

#define NOTE_C_LOW 62
#define NOTE_D_LOW 94
#define NOTE_E_LOW 130
#define NOTE_F_LOW 149
#define NOTE_G_LOW 192
#define NOTE_A_LOW 240
#define NOTE_B_LOW 293

#define NOTE_C_HIGH 462
#define NOTE_D_HIGH 494
#define NOTE_E_HIGH 530
#define NOTE_F_HIGH 549
#define NOTE_G_HIGH 592
#define NOTE_A_HIGH 640
#define NOTE_B_HIGH 693

#define ACTIVATED LOW

const int BUZZER = 3;
const int LED = 13;

const int BUTTON_C = 10;
const int BUTTON_D = 9;
const int BUTTON_E = 8;
const int BUTTON_F = 7;
const int BUTTON_G = 6;
const int BUTTON_A = 5;
const int BUTTON_B = 4;

const int BUTTON_SUSTAIN = 12;
const int BUTTON_OCTAVE = 11;

const int BUTTON_DELETE = 53;
const int BUTTON_RECORD = 51;

int octave = 0;
bool sustain = false;
int record_state = 0;
int notes[3500];
int n = 0;

void setup()
{
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);

  pinMode(BUTTON_C, INPUT);
  digitalWrite(BUTTON_C, HIGH);
  pinMode(BUTTON_D, INPUT);
  digitalWrite(BUTTON_D, HIGH);
  pinMode(BUTTON_E, INPUT);
  digitalWrite(BUTTON_E, HIGH);
  pinMode(BUTTON_F, INPUT);
  digitalWrite(BUTTON_F, HIGH);
  pinMode(BUTTON_G, INPUT);
  digitalWrite(BUTTON_G, HIGH);
  pinMode(BUTTON_A, INPUT);
  digitalWrite(BUTTON_A, HIGH);
  pinMode(BUTTON_B, INPUT);
  digitalWrite(BUTTON_B, HIGH);

  pinMode(BUTTON_OCTAVE, INPUT);
  digitalWrite(BUTTON_OCTAVE, HIGH);
  pinMode(BUTTON_SUSTAIN, INPUT);
  digitalWrite(BUTTON_SUSTAIN, HIGH);

  pinMode(BUTTON_RECORD, INPUT);
  digitalWrite(BUTTON_RECORD, HIGH);
  pinMode(BUTTON_DELETE, INPUT);
  digitalWrite(BUTTON_DELETE, HIGH);

  Serial.begin(9600);
}

void loop()
{
  if (digitalRead(BUTTON_RECORD) == ACTIVATED)
  {
    if (record_state == 0)
    {
      record_state = 1;
      n = 0;
    }
    else if (record_state == 1)
    {
      record_state = 2;
    }
    else if (record_state == 2)
    {
      for (int i = 0; i < n; i++)
      {
        tone(BUZZER, notes[i]);
        delay(10);
        Serial.println(notes[i]);
      }
    }

    Serial.println(record_state);

    delay(250);
  }

  if (record_state == 1)
  {
    digitalWrite(LED, HIGH);
  }

  if (digitalRead(BUTTON_DELETE) == ACTIVATED)
  {
    record_state = 0;
    n = 0;

    delay(250);

    Serial.println(record_state);
  }

  if (digitalRead(BUTTON_OCTAVE) == ACTIVATED)
  {
    if (octave == 0)
    {
      octave = 1;
    }
    else if (octave == 1)
    {
      octave = -1;
    }
    else if (octave == -1)
    {
      octave = 0;
    }

    delay(250);
  }

  if (digitalRead(BUTTON_SUSTAIN) == ACTIVATED)
  {
    sustain = !sustain;

    delay(250);
  }

  while (digitalRead(BUTTON_C) == ACTIVATED)
  {
    if (octave == 0)
    {
      tone(BUZZER, NOTE_C);
    }
    else if (octave == 1)
    {
      tone(BUZZER, NOTE_C_HIGH);
    }
    else if (octave == -1)
    {
      tone(BUZZER, NOTE_C_LOW);
    }

    if (record_state == 1)
    {
      int note = NOTE_C;
      if (octave == 0)
      {
        note = NOTE_C;
      }
      else if (octave == 1)
      {
        note = NOTE_C_HIGH;
      }
      else if (octave == -1)
      {
        note = NOTE_C_LOW;
      }
      notes[n] = note;
      n++;
      Serial.println(n);
    }

  }

  while (digitalRead(BUTTON_D) == ACTIVATED)
  {
    if (octave == 0)
    {
      tone(BUZZER, NOTE_D);
    }
    else if (octave == 1)
    {
      tone(BUZZER, NOTE_D_HIGH);
    }
    else if (octave == -1)
    {
      tone(BUZZER, NOTE_D_LOW);
    }

    if (record_state == 1)
    {
      int note = NOTE_D;
      if (octave == 0)
      {
        note = NOTE_D;
      }
      else if (octave == 1)
      {
        note = NOTE_D_HIGH;
      }
      else if (octave == -1)
      {
        note = NOTE_D_LOW;
      }
      notes[n] = note;
      n++;
      Serial.println(n);
    }

  }

  while (digitalRead(BUTTON_E) == ACTIVATED)
  {
    if (octave == 0)
    {
      tone(BUZZER, NOTE_E);
    }
    else if (octave == 1)
    {
      tone(BUZZER, NOTE_E_HIGH);
    }
    else if (octave == -1)
    {
      tone(BUZZER, NOTE_E_LOW);
    }

    if (record_state == 1)
    {
      int note = NOTE_E;
      if (octave == 0)
      {
        note = NOTE_E;
      }
      else if (octave == 1)
      {
        note = NOTE_E_HIGH;
      }
      else if (octave == -1)
      {
        note = NOTE_E_LOW;
      }
      notes[n] = note;
      n++;
      Serial.println(n);
    }

  }

  while (digitalRead(BUTTON_F) == ACTIVATED)
  {
    if (octave == 0)
    {
      tone(BUZZER, NOTE_F);
    }
    else if (octave == 1)
    {
      tone(BUZZER, NOTE_F_HIGH);
    }
    else if (octave == -1)
    {
      tone(BUZZER, NOTE_F_LOW);
    }

    if (record_state == 1)
    {
      int note = NOTE_F;
      if (octave == 0)
      {
        note = NOTE_F;
      }
      else if (octave == 1)
      {
        note = NOTE_F_HIGH;
      }
      else if (octave == -1)
      {
        note = NOTE_F_LOW;
      }
      notes[n] = note;
      n++;
      Serial.println(n);
    }

  }

  while (digitalRead(BUTTON_G) == ACTIVATED)
  {
    if (octave == 0)
    {
      tone(BUZZER, NOTE_G);
    }
    else if (octave == 1)
    {
      tone(BUZZER, NOTE_G_HIGH);
    }
    else if (octave == -1)
    {
      tone(BUZZER, NOTE_G_LOW);
    }

    if (record_state == 1)
    {
      int note = NOTE_G;
      if (octave == 0)
      {
        note = NOTE_G;
      }
      else if (octave == 1)
      {
        note = NOTE_G_HIGH;
      }
      else if (octave == -1)
      {
        note = NOTE_G_LOW;
      }
      notes[n] = note;
      n++;
      Serial.println(n);
    }

  }

  while (digitalRead(BUTTON_A) == ACTIVATED)
  {
    if (octave == 0)
    {
      tone(BUZZER, NOTE_A);
    }
    else if (octave == 1)
    {
      tone(BUZZER, NOTE_A_HIGH);
    }
    else if (octave == -1)
    {
      tone(BUZZER, NOTE_A_LOW);
    }

    if (record_state == 1)
    {
      int note = NOTE_A;
      if (octave == 0)
      {
        note = NOTE_A;
      }
      else if (octave == 1)
      {
        note = NOTE_A_HIGH;
      }
      else if (octave == -1)
      {
        note = NOTE_A_LOW;
      }
      notes[n] = note;
      n++;
      Serial.println(n);
    }

  }

  while (digitalRead(BUTTON_B) == ACTIVATED)
  {
    if (octave == 0)
    {
      tone(BUZZER, NOTE_B);
    }
    else if (octave == 1)
    {
      tone(BUZZER, NOTE_B_HIGH);
    }
    else if (octave == -1)
    {
      tone(BUZZER, NOTE_B_LOW);
    }

    if (record_state == 1)
    {
      int note = NOTE_B;
      if (octave == 0)
      {
        note = NOTE_B;
      }
      else if (octave == 1)
      {
        note = NOTE_B_HIGH;
      }
      else if (octave == -1)
      {
        note = NOTE_B_LOW;
      }
      notes[n] = note;
      n++;
      Serial.println(n);
    }

  }

  if (!sustain)
  {
    noTone(BUZZER);
  }

  digitalWrite(LED, LOW);
}
