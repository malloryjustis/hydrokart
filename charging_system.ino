
// two photoresistor input
int photoPin = A0;
int photoPin1 = A1;

// relay outputs
int relay1 = 8;
int relay2 = 9;
int relay3 = 10;
int relay4 = 11;

void setup() {
  // put your setup code here, to run once:
  // set all pins to output, and have them set at low output (NO, so circuit is open in all of them, not current initially to any battery)
  pinMode(relay1, OUTPUT);
  digitalWrite(relay1, LOW);
  pinMode(relay2, OUTPUT);
  digitalWrite(relay2, LOW);
  pinMode(relay3, OUTPUT);
  digitalWrite(relay3, LOW);
  pinMode(relay4, OUTPUT);
  digitalWrite(relay4, LOW);
  
  //outputs supplying current to the photoresistors (later change this so that it cna all come out the 5 V port)
  pinMode(6, OUTPUT);
  digitalWrite(6, HIGH);
  pinMode(7, OUTPUT);
  digitalWrite(7, HIGH);

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  
  // read the two light sensors
  int lightRaw = analogRead(photoPin);
  int light = map(lightRaw, 1023, 0, 10, 0);
  int lightRaw1 = analogRead(photoPin1);
  int light1 = map(lightRaw1, 1023, 0, 10, 0);

  int light_level = analogRead(photoPin);
  int light_level1 = analogRead(photoPin1);

  // if both pins read >1, that means that the battery is fully charged. The relay switches will stay open (no connection). If it is not fully charges the relay will close, allowing current to go through.
  if (light > 1 && light1 > 1) {
    digitalWrite(relay1, LOW);
  }

  else {
    digitalWrite(relay1, HIGH);
  }

  Serial.println(light_level, light_level1);
}
