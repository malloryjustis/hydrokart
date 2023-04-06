
int photoPin = A0;
int photoPin1 = A1;

void setup() {
  // put your setup code here, to run once:
  pinMode(8, OUTPUT);
  digitalWrite(8, LOW);
  pinMode(9, OUTPUT);
  digitalWrite(9, HIGH);
  pinMode(7, OUTPUT);
  digitalWrite(7, HIGH);

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  int lightRaw = analogRead(photoPin);
  int light = map(lightRaw, 1023, 0, 10, 0);
  int lightRaw1 = analogRead(photoPin1);
  int light1 = map(lightRaw1, 1023, 0, 10, 0);

  int light_level = analogRead(photoPin);
  int light_level1 = analogRead(photoPin1);

  if (light > 1 && light1 > 1) {
    digitalWrite(8, LOW);
  }

  else {
    digitalWrite(8, HIGH);
  }

  Serial.println(light_level, light_level1);
}
