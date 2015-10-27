const int pinBuzzer = 11;
const int scaleLength = 6;

// this is Cmaj, starting at C1
const int frequencies[] = {33, 37, 41, 44, 49, 55, 62};
const int baseOctave = 2;
const int maxOctaves = 4;

const int pinKey = 7;

const int pinX = A4;
const int pinY = A5;

int noteInterval;
int scaleInterval;

void setup() {
  Serial.begin(9600);

  pinMode(pinX, INPUT);
  pinMode(pinY, INPUT);
  pinMode(pinKey, INPUT);

  pinMode(pinBuzzer, OUTPUT);

  noteInterval = 1024 / scaleLength;
  scaleInterval = 1024 / maxOctaves;
}

void loop() {
  int valueX = analogRead(pinX);
  int valueY = analogRead(pinY);

  int note = valueX / noteInterval;
  int scale = (baseOctave - 1) + valueY / scaleInterval;
  int frequency = frequencies[note] * pow(2, scale);

  if (digitalRead(pinKey) == HIGH) {
    tone(pinBuzzer, frequency);
  } else {
    noTone(pinBuzzer);
  }
}
