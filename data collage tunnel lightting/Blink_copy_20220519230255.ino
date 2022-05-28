int led[]={22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,8};
int btn=5;
int btn2=4;
int sayac=0;
int butondrm=0;
int prestate =0;

int potDeger;
void setup() {
  
  for( int i=0;i<30;i++)
  {
    pinMode(led[i],OUTPUT);
    attachInterrupt(0,durum,RISING);
    attachInterrupt(1,drm,RISING);
  }
}

void loop() {
  
  potDeger = analogRead(A0);
  potDeger = map(potDeger, 0, 1023, 5, 200);
   
switch(sayac)
{
  case 0:
      for(int j = 0 ; j<31 ; j++){
        digitalWrite(led[j], HIGH);
        delay(potDeger);
      }
      for(int k = 0 ; k<31 ; k++){
        digitalWrite(led[k], LOW);
        delay(potDeger);
        attachInterrupt(0,durum,RISING);
      }
break;

case 1:
             for(int a = 0 ; a<31 ; a++){
        digitalWrite(led[a], HIGH);
    
        delay(10);
             }
             attachInterrupt(0,durum,RISING);
             break;
default:
break;

      }
}
void durum(){
 sayac = 1;
  
}
void drm(){
  sayac = 0;
}
