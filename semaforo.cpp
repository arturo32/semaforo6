#define NOTE_A4  440
#define todos 1

//SEMÁFORO 1
#define pinclock 13
#define pindata 12
#define pinlatch 11
#define pinverde 10   //ultimo led
#define pinvermelho 9  //ultimo led
#define pinRED 8  //semáforo para pedestre
#define pinGREEN 7  //semáforo para pedestre
#define tempoped 2000 //tempo de espera para o semaforo do pedestre se tornar verde
#define tempovermelho 10000 // tempo   em que o semáforo fica vermelho antes de "descer" 
#define tempoverde 990 // tempo em que o semáforo fica verde antes de "descer" 
#define somped 2  //auto falante 

//SEMÁFORO 2
#define pinclock2 6
#define pindata2 5
#define pinlatch2 4
#define pinverde2 A5   //ultimo led
#define pinvermelho2 A4  //ultimo led
#define pinRED2 A3  //semáforo para pedestre
#define pinGREEN2 A2  //semáforo para pedestre
#define tempoped2 2000 //tempo de espera para o semaforo do pedestre se tornar verde
#define tempovermelho2 10000 //tempo em que o semáforo fica vermelho antes de "descer" 
#define somped2 3  //auto falante 

int melody = NOTE_A4;


void setup() {

  pinMode (pinclock, OUTPUT);
  pinMode (pinlatch, OUTPUT);
  pinMode (pindata, OUTPUT);
  pinMode (pinverde, OUTPUT);
  pinMode (pinvermelho, OUTPUT);
  pinMode (pinRED, OUTPUT);
  pinMode (pinGREEN, OUTPUT);

  pinMode (pinclock2, OUTPUT);
  pinMode (pinlatch2, OUTPUT);
  pinMode (pindata2, OUTPUT);
  pinMode (pinverde2, OUTPUT);
  pinMode (pinvermelho2, OUTPUT);
  pinMode (pinRED2, OUTPUT);
  pinMode (pinGREEN2, OUTPUT);

  digitalWrite (pinRED, HIGH);
  digitalWrite (pinGREEN2, HIGH);
  tone(somped2, melody);
  

  for (int i = 0; i < 5; i++) {
    digitalWrite (pinclock, HIGH);
    digitalWrite(pinclock2, HIGH);
    delay(10);
    digitalWrite (pinclock, LOW);
    digitalWrite (pinclock2, LOW);
    delay(10);
  }

  digitalWrite (pindata, HIGH);
  digitalWrite (pindata2, HIGH);
  delay(10);
  digitalWrite (pinclock, HIGH);
  digitalWrite (pinclock2, HIGH);
  delay(10);
  digitalWrite (pinclock, LOW);
  digitalWrite (pinclock2, LOW);
  delay(10);
  digitalWrite (pindata, LOW);
  digitalWrite (pindata2, LOW);
  delay(10);
  digitalWrite (pinlatch, HIGH);
  digitalWrite (pinlatch2, HIGH);
 
  
}

void preparo() {
  for (int i = 0; i < 5; i++) {
    digitalWrite (pinclock, HIGH);
    digitalWrite(pinclock2, HIGH);
    delay(10);
    digitalWrite (pinclock, LOW);
    digitalWrite (pinclock2, LOW);
    delay(10);
  }

  for (int i = 0; i < 5; i++) {
    digitalWrite(pinclock2, HIGH);
    delay(10);
    digitalWrite (pinclock2, LOW);
    delay(10);
  }


  digitalWrite (pindata, HIGH);
  digitalWrite (pindata2, HIGH);
  delay(10);
  digitalWrite (pinclock, HIGH);
  digitalWrite (pinclock2, HIGH);
  delay(10);
  digitalWrite (pinclock, LOW);
  digitalWrite (pinclock2, LOW);
  delay(10);
  digitalWrite (pindata, LOW);
  digitalWrite (pindata2, LOW);
  delay(10);
  digitalWrite (pinlatch, HIGH);
  digitalWrite (pinlatch2, HIGH);
}


void verde() {
  
  digitalWrite (pinverde, HIGH);  //início
  digitalWrite (pinvermelho2, HIGH);  //início
  delay(10);
  digitalWrite (pinlatch, LOW);
  digitalWrite (pinlatch2, LOW);
  delay(tempoverde);
  
   //VERDE COMEÇA A DESCER
 
  for (int j = 0; j < 5; j++) {
    digitalWrite (pinclock, HIGH);
    delay(10);
    digitalWrite (pinclock, LOW);
    delay(10);
    digitalWrite (pinlatch, HIGH);
    delay(10);
    digitalWrite (pinlatch, LOW);
    delay(990);
    }
    
}


void amarelo() {
  digitalWrite (pinclock, HIGH);
  delay(10);
  digitalWrite (pinclock, LOW);
  delay(10);
  digitalWrite (pinlatch, HIGH);
  digitalWrite (pinverde, LOW);   //ÚLTIMO VERDE SE APAGA
  delay(10);
  digitalWrite (pinlatch, LOW);
  delay(10);
  digitalWrite (pinclock, HIGH);
  delay(10);
  digitalWrite (pinclock, LOW);
  delay(2970);
}


void vermelho() {

  digitalWrite (pinlatch, HIGH);      
  delay(10);
  digitalWrite (pinlatch, LOW);
  delay(10);
  digitalWrite (pinclock, HIGH);
  delay(10);
  digitalWrite (pinclock, LOW);
  delay(10);
  digitalWrite (pinlatch, HIGH);     //PRIMEIRO LED ACENDE
  digitalWrite (pinvermelho, HIGH);  //ÚLTIMO LED ACENDE
  delay(10);
  digitalWrite (pinlatch, LOW);
  delay(tempoped);

  //LIGA PEDESTRE

  digitalWrite (pinRED, LOW);
  digitalWrite (pinGREEN, HIGH); //APARTIR DAQUI, 10 SEGUNDOS DE ONDA VERDE PARA PEDESTRES 
  noTone(somped2);
  tone(todos, melody);
  delay(7000);


   //VERMELHO2 COMEÇA A DESCER

  for (int j = 0; j < 2; j++) {
    digitalWrite (pinclock2, HIGH);
    delay(10);
    digitalWrite (pinclock2, LOW);
    delay(10);
    digitalWrite (pinlatch2, HIGH);
    delay(10);
    digitalWrite (pinlatch2, LOW);
    delay(990); 
  }
    
  digitalWrite (pinclock2, HIGH);
  delay(10);
  digitalWrite (pinclock2, LOW);
  delay(10);
  digitalWrite (pinlatch2, HIGH);
  delay(10);
  digitalWrite (pinlatch2, LOW);
  delay(10); //irá se somar com os delays do DESLIGA PEDESTRE e se tornará 990

  //INTERRUPÇÃO DA DESCIDA     
  //DESLIGA PEDESTRE2

  digitalWrite (pinGREEN2, LOW);
  noTone(todos);
  digitalWrite (pinRED2, !digitalRead(pinRED2));
  delay(250);
  digitalWrite (pinRED2, !digitalRead(pinRED2));
  delay(250);
  digitalWrite (pinRED2, !digitalRead(pinRED2));
  delay(250);
  digitalWrite (pinRED2, !digitalRead(pinRED2));
  delay(230); //correção de tempo
  digitalWrite (pinRED2, !digitalRead(pinRED2));

  for (int j = 0; j < 2; j++) {
    digitalWrite (pinclock2, HIGH);
    delay(10);
    digitalWrite (pinclock2, LOW);
    delay(10);
    digitalWrite (pinlatch2, HIGH);
    delay(10);
    digitalWrite (pinlatch2, LOW);
    delay(990);
  }

  digitalWrite (pinvermelho2, LOW);


  //AMARELO2 ACENDE

  digitalWrite (pinclock2, HIGH);
  delay(10);
  digitalWrite (pinclock2, LOW);
  delay(10);
  digitalWrite (pinlatch2, HIGH);
  digitalWrite (pinvermelho2, LOW);   //ÚLTIMO VERMELHO SE APAGA
  delay(10);
  digitalWrite (pinlatch2, LOW);
  delay(10);
  //EMPURRA PRO OUTRO CI
  digitalWrite (pinclock2, HIGH);
  delay(10);
  digitalWrite (pinclock2, LOW);
  delay(2970);

  //VERDE2 ACENDE
  

  digitalWrite (pinlatch2, HIGH);   
  delay(10);
  digitalWrite (pinlatch2, LOW);
  delay(10);
  digitalWrite (pinclock2, HIGH);
  delay(10);
  digitalWrite (pinclock2, LOW);
  delay(10);
  digitalWrite (pinlatch2, HIGH);
  digitalWrite (pinverde2, HIGH); // VERDE ACENDE
  delay(10);
  digitalWrite (pinlatch2, LOW);
  delay(2990);
  
   //VERDE2 COMEÇA A DESCER
 
  for (int j = 0; j < 5; j++) {
    digitalWrite (pinclock2, HIGH);
    delay(10);
    digitalWrite (pinclock2, LOW);
    delay(10);
    digitalWrite (pinlatch2, HIGH);
    delay(10);
    digitalWrite (pinlatch2, LOW);
    delay(990); 
  }

  digitalWrite (pinverde2, LOW);  //ÚLTIMO VERDE DESLIGA

  //VEMELHO2 ACENDE

  for (int i = 0; i < 5; i++) {
    digitalWrite(pinclock2, HIGH);
    delay(10);
    digitalWrite (pinclock2, LOW);
    delay(10);
  }
  digitalWrite (pindata2, HIGH);
  delay(10);
  digitalWrite (pinclock2, HIGH);
  delay(10);
  digitalWrite (pinclock2, LOW);
  delay(10);
  digitalWrite (pindata2, LOW);
  delay(10);
  digitalWrite (pinlatch2, HIGH);
  digitalWrite (pinvermelho2, HIGH);  //início
  delay(10);
  digitalWrite (pinlatch2, LOW);
  delay(tempoped);

  //LIGA PEDESTRE

  digitalWrite (pinRED2, LOW);
  digitalWrite (pinGREEN2, HIGH); //APARTIR DAQUI, 10 SEGUNDOS DE ONDA VERDE PARA PEDESTRES 
  tone(somped2, melody);
  delay(7000);
      


  //VERMELHO COMEÇA A DESCER 

  for (int h = 0; h < 2; h++) {
    digitalWrite (pinclock, HIGH);
    delay(10);
    digitalWrite (pinclock, LOW);
    delay(10);
    digitalWrite (pinlatch, HIGH);
    delay(10);
    digitalWrite (pinlatch, LOW);
    delay(990);
  }

  digitalWrite (pinclock, HIGH);
  delay(10);
  digitalWrite (pinclock, LOW);
  delay(10);
  digitalWrite (pinlatch, HIGH); 
  delay(10);
  digitalWrite (pinlatch, LOW);
  delay(10); //irá se somar com os delays do DESLIGA PEDESTRE e se tornará 990

  //INTERRUPÇÃO DA DESCIDA     
  //DESLIGA PEDESTRE

  digitalWrite (pinGREEN, LOW);
  noTone(somped);
  digitalWrite (pinRED, !digitalRead(pinRED));
  delay(250);
  digitalWrite (pinRED, !digitalRead(pinRED));
  delay(250);
  digitalWrite (pinRED, !digitalRead(pinRED));
  delay(250);
  digitalWrite (pinRED, !digitalRead(pinRED));
  delay(230); //correção de tempo
  digitalWrite (pinRED, !digitalRead(pinRED));


  for (int p = 0; p < 2; p++) {
    digitalWrite (pinclock, HIGH);
    delay(10);
    digitalWrite (pinclock, LOW);
    delay(10);
    digitalWrite (pinlatch, HIGH);
    delay(10);
    digitalWrite (pinlatch, LOW);
    delay(990);
  }

  digitalWrite(pinvermelho, LOW); //desligar ultimo led
}


void loop() {

  //VERDE
  verde();

  //AMARELO
  amarelo();

  //VERMELHO
  vermelho();
  preparo();
  
}
