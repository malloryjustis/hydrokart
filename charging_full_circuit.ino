// input from photoresistors
int photoPin = A0;
int photoPin1 = A1;

// power photoresistors
int powerphotopin = 6;
int powerphotopin1 = 7;

//relays
int relay1 = 8
int relay2 = 9
int relay3 = 10
int relay4 = 11

void setup() {
  // put your setup code here, to run once:

  // power photopins
  pinMode(powerphotopin, OUTPUT);
  digitalWrite(powerphotopin, HIGH);
  pinMode(powerphotopin1, OUTPUT);
  digitalWrite(powerphotopin1, HIGH);

  // relay pins set at original output of low (circuit open, no current can flow to batteries)
  pinMode(relay1, OUTPUT);
  digitalWrite(relay1, LOW);
  pinMode(relay2, OUTPUT);
  digitalWrite(relay2, LOW);
  pinMode(relay3, OUTPUT);
  digitalWrite(relay3, LOW);
  pinMode(relay4, OUTPUT);
  digitalWrite(relay4, LOW);

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

  // close relay1 to test how much charge is in the battery
  digitalWrite(relay1, HIGH);
  // if fully charge (light and light1 are both green), we will open relay1 (LOW) and move to relay2
  charge1: if (light > 1 && light1 > 1) {
    digitalWrite(relay1, LOW);
    // close relay2 circuit to check
    digitalWrite(relay2; HIGH);
    charge2: if (light > 1 && light1 > 1) {
      // if fully charged, open relay2 and move on to relay3
      digitalWrite(relay2, LOW);
      digitalWrite(relay3; HIGH);
      charge3: if (light > 1 && light1 > 1) {
        digitalWrite(relay3, LOW);
        digitalWrite(relay4, HIGH);
        charge4: if (light > 1 && light1 > 1) {
          digitalWrite(relay4, LOW);
        }
        else {
          digitalWrite(relay4, HIGH);
          goto charge4;
        }
      }
      else {
        digitalWrtie(relay3, HIGH)
        goto charge3;
      }
    }
    else {
      digitalWrite(relay2, HIGH);
      goto charge2;
    }
  }
  else {
    digitalWrite(relay1, HIGH);
    goto charge1;
  }
