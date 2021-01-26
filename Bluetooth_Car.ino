#include<Servo.h>
#include<SoftwareSerial.h>

Servo sg90;
//byte led1=0; //
//byte led2=1;

SoftwareSerial bt_iletisim(4,7); //rx,tx
float sure = 0.0;
float mesafe=0.0;
byte buzer=2;
int pos = 0;
#define sol_ileri 8
#define sol_geri 9
#define sol_hiz 5

int sag_ileri=13;
#define sag_geri 12
#define sag_hiz 11

const byte trig=10;
const byte echo=6;
int motorlar_hiz = 250;
byte son_islem;

void setup()
{  
  sg90.attach(3);
  sg90.write(90);
//pinMode(led1,OUTPUT);
//pinMode(led2,OUTPUT);  
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(buzer,OUTPUT);
  pinMode(sol_ileri, OUTPUT);
  pinMode(sag_ileri, OUTPUT);
  pinMode(sol_geri, OUTPUT);
  pinMode(sag_geri, OUTPUT);
  pinMode(sol_hiz, OUTPUT);
  pinMode(sag_hiz, OUTPUT);

  Serial.begin(9600);
  bt_iletisim.begin(9600);
}

void loop()
{
    digitalWrite(trig , HIGH);
    delay(1);
    digitalWrite(trig , LOW);
    sure = pulseIn(echo , HIGH);
    mesafe = (sure / 2.0) / 29.1;
   // if(mesafe<20.0)
//{
// digitalWrite(buzer,1);
//dur();
//delay(1000);
//delay(300);
//dur();
//}
//else if(mesafe>15.0)
//{
//digitalWrite(buzer,0);
//}
Serial.println(mesafe);
  if (bt_iletisim.available())
  { 
    char data = bt_iletisim.read();
    if (data == '2')
    {
      dur();
      delay(10);
      geri();
      son_islem = 2;  
    }
    else if (data == '1')
    {
      dur();
      delay(10);
      ileri();
      son_islem=1;
    }
    else if (data == '3')
    {
      dur();
      delay(10);
          sag();
      son_islem = 3; 
    }
    else if (data == '4')
    {
      dur();
      delay(10);
      sol();
      son_islem = 4;    
    }
    else if (data == '6')
    {
    dur();
    }
    else if (data == '0')
    {
      motorlar_hiz = motorlar_hiz + 25;
    if (motorlar_hiz > 250)
    {
      motorlar_hiz = 250;
    }
    son_isleme_devam_et();
    }
    else if (data == '5')
    {
      motorlar_hiz = motorlar_hiz - 25;
      if (motorlar_hiz < 0)
      {
        motorlar_hiz = 0;
      }
    
      son_isleme_devam_et();
    }
    else if(data=='8')
    {
      dur();     
      sonar();
      son_islem=8;
    }    
  }
  } 
void ileri()
{  
  digitalWrite(sol_ileri, 1);
  digitalWrite(sag_ileri, 1);
  digitalWrite(sol_geri, 0);
  digitalWrite(sag_geri, 0);
  analogWrite(sol_hiz, motorlar_hiz);
  analogWrite(sag_hiz, motorlar_hiz);
 sg90.write(90); 
}
void geri()
{ 
  digitalWrite(sol_ileri, 0);
  digitalWrite(sag_ileri, 0);
  digitalWrite(sol_geri, 1);
  digitalWrite(sag_geri, 1);
  analogWrite(sol_hiz, motorlar_hiz);
  analogWrite(sag_hiz, motorlar_hiz); 
  sg90.write(90);
}
void sol()
{
  digitalWrite(sol_ileri, 1);
  digitalWrite(sag_ileri, 0);
  digitalWrite(sol_geri, 0);
  digitalWrite(sag_geri, 1);
  analogWrite(sol_hiz, motorlar_hiz);
  analogWrite(sag_hiz, motorlar_hiz);
  sg90.write(90);
}
void sag()
{
  digitalWrite(sol_ileri, 0);
  digitalWrite(sag_ileri, 1);
  digitalWrite(sol_geri, 1);
  digitalWrite(sag_geri, 0);
  analogWrite(sol_hiz, motorlar_hiz);
  analogWrite(sag_hiz, motorlar_hiz);
  sg90.write(90);
}
void dur()
{  
  digitalWrite(sol_ileri, 0);
  digitalWrite(sag_ileri, 0);
  digitalWrite(sol_geri, 0);
  digitalWrite(sag_geri, 0);
  analogWrite(sol_hiz, 0);
  analogWrite(sag_hiz, 0);  
}
void son_isleme_devam_et()
{
  if (son_islem == 2)
  {
    geri();
 }
  else if (son_islem == 1)
  {
    ileri();
   
  }
  else if (son_islem == 3)
  {
    sag();
    
  }
  else if (son_islem == 4)
  {
    sol();
  }
  else if(son_islem==8)
  {
    sonar();
  }}
int sonar()
  {
  for (pos = 180; pos >= 0; pos--)
 {
  digitalWrite(trig , HIGH);
  delay(1);
  digitalWrite(trig , LOW);
  sure = pulseIn(echo , HIGH);
  mesafe = (sure / 2.0) / 29.1;
    if(mesafe<15.0)
 {
 digitalWrite(buzer,1); 
 }
else if(mesafe>15.0)  
  {
    digitalWrite(buzer,0); 
  }

sg90.write(pos);
delay(15); 
 }
  for (pos = 0; pos <= 180; pos++)
  {

      digitalWrite(trig , HIGH);
  delay(1);
  digitalWrite(trig , LOW);
  sure = pulseIn(echo , HIGH);
  mesafe = (sure / 2.0) / 29.1;
     if(mesafe<15.0)
 {
 digitalWrite(buzer,1);
}
else if(mesafe>15.0)
  {
    digitalWrite(buzer,0); 
  }   
   sg90.write(pos);
    delay(15);
  }
  }
