/*
    Program Monitoring Water Level
    dibuat oleh Indobot
*/
#define BLYNK_PRINT Serial  //Pendeklarasian Library
#include &amp;lt;ESP8266WiFi.h&amp;gt;
#include &amp;lt;BlynkSimpleEsp8266.h&amp;gt;
#define TRIGGERPIN D1  // Pemilihan Pin
#define ECHOPIN D2

char auth[] = "XXXX"; // masukkan kode autentikasi disini
char ssid[] = "Indobot"; //nama wifi
char pass[] = "123456789"; //password
WidgetLCD lcd(V1);

void setup() {  //Pengaturan Pin dan Variabel
  Serial.begin(9600);
  pinMode(TRIGGERPIN, OUTPUT);
  pinMode(ECHOPIN, INPUT);
  Blynk.begin(auth, ssid, pass);
  lcd.clear();
  lcd.print(0, 0, "Jarak dalam cm");
}

void loop() {  //Perulangan Program
  lcd.clear();
  lcd.print(0, 0, "Jarak dalam cm");
  long duration, distance;
  digitalWrite(TRIGGERPIN, LOW);
  delayMicroseconds(3);
  digitalWrite(TRIGGERPIN, HIGH);
  delayMicroseconds(12);
  digitalWrite(TRIGGERPIN, LOW);
  duration = pulseIn(ECHOPIN, HIGH);
  distance = (duration / 2) / 29.1;
  Serial.print(distance);
  Serial.println("Cm");
  lcd.print(7, 1, distance);
  Blynk.run();
  delay(3500);
}
