#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

int ledverdPin = 13; //Led no pino 13
int ldrPin = 0; //LDR no pino analígico A0
int ldrValor = 0; //Valor lido do LDR
int laserPin = 2;
int ledvermPin = 4;
/*
 //https://maxpromer.github.io/LCD-Character-Creator/
  byte b1[8] = {
  //B0
  B00000,
  B00000,
  B11110,
  B10001,
  B10001,
  B10001,
  B10001,
  B11110
};
byte b2[8]{//B1
  B11110,
  B10001,
  B10001,
  B10001,
  B10001,
  B11110,
  B00000,
  B00000
};
byte l1[8]{//L2
  B00000,
  B00000,
  B11100,
  B11100,
  B11100,
  B11100,
  B11100,
  B11100
};
byte l2[8]{//L3
  B11100,
  B11100,
  B11100,
  B11111,
  B11111,
  B11111,
  B00000,
  B00000
};
byte l3[8]{//L4
  B00000,
  B00000,
  B00000,
  B11111,
  B11111,
  B11111,
  B00000,
  B00000
};
byte u1[8]{//U5
  B00000,
  B00000,
  B11100,
  B11100,
  B11100,
  B11100,
  B11100,
  B11100
};
byte u2[8]{//U6
  B11100,
  B11100,
  B11100,
  B11111,
  B11111,
  B11111,
  B00000,
  B00000
};
byte u3[8]{//U7
  B00111,
  B00111,
  B00111,
  B11111,
  B11111,
  B11111,
  B00000,
  B00000
};
byte u4[8]{//U8
  B00000,
  B00000,
  B00111,
  B00111,
  B00111,
  B11111,
  B11111,
  B11111
};
byte e1[8]{//E9
  B00000,
  B00000,
  B11111,
  B11111,
  B11111,
  B11000,
  B11000,
  B11111
};
byte e2[8]{//E10
  B11111,
  B11000,
  B11000,
  B11111,
  B11111,
  B11111,
  B00000,
  B00000
};
byte a1[8]{//A11
  B00000,
  B00000,
  B11111,
  B11111,
  B11000,
  B11000,
  B11000,
  B11111
};
byte a2[8]{//A12
  B11111,
  B11000,
  B11000,
  B11000,
  B11000,
  B11000,
  B00000,
  B00000
};
byte a3[8]{//A13
  B11111,
  B00011,
  B00011,
  B00011,
  B00011,
  B00011,
  B00000,
  B00000
};
byte a4[8]{//A14
  B00000,
  B00000,
  B11111,
  B11111,
  B00011,
  B00011,
  B00011,
  B11111
};
 */


void setup() {
 pinMode(ledvermPin,OUTPUT); 
 pinMode(laserPin,OUTPUT);
 pinMode(ledverdPin,OUTPUT);
 
/*
lcd.createChar(0, b1);
lcd.createChar(1, b2);
lcd.createChar(2, l1);
lcd.createChar(3, l2);
lcd.createChar(4, l3);
lcd.createChar(5, u1);
lcd.createChar(6, u2);
lcd.createChar(7, u3);
lcd.createChar(8, u4);
lcd.createChar(9, e1);
lcd.createChar(10, e2);
lcd.createChar(11, a1);
lcd.createChar(12, a2);
lcd.createChar(13, a3);
lcd.createChar(14, a4);
 */
 
 lcd.begin(16, 2);
 lcd.clear();
 //Posiciona o cursor na coluna 5, linha 0;
 lcd.setCursor(4, 0);
 //Envia o texto entre aspas para o LCD
 lcd.print("BLUELAB");
 
 Serial.begin(9600); //Inicia a comunicação serial
}
 
void loop() {
 ///ler o valor do LDR
 ldrValor = analogRead(ldrPin); //O valor lido será entre 0 e 1023
 
 digitalWrite(laserPin,HIGH);
 
  //Porta trancada e fechada
  if(ldrValor>=920){
      digitalWrite(ledverdPin,LOW);
      digitalWrite(ledvermPin,HIGH);
      lcd.setCursor(4, 1);
      lcd.print("FECHADO");
      delay(500);
      rolarPararMeio();
      Serial.println("A porta esta trancada");
  }
  
  //Porta fechada e destrancada
  else if (ldrValor<= 770 ){
    digitalWrite(ledvermPin,HIGH);
    digitalWrite(ledverdPin,HIGH);
    lcd.setCursor(4, 1);
    lcd.print("ABERTO");
    delay(500);
    rolarPararMeio();
    Serial.println("A porta esta fechada");
  }
  
  //Porta aberta
  else{
    digitalWrite(ledverdPin,HIGH);
    digitalWrite(ledvermPin,LOW);
    lcd.setCursor(4, 1);
    lcd.print("ABERTO");
    delay(500);
    rolarPararMeio();
    Serial.println("A porta esta aberta");
  }
  
 //imprime o valor lido do LDR no monitor serial
 Serial.println(ldrValor);
 delay(100);
}

void rolarPararMeio(){
  for (int posicao = 0; posicao < 23; posicao++){
    
    lcd.scrollDisplayLeft();
    delay(250);
    
  }
/*  lcd.setCursor(0,1);
  for (int posicao = 0; posicao < 11; posicao++){
    
    lcd.scrollDisplayLeft();
    delay(250);
    
  }*/
  //lcd.setCursor(4,1);
  delay(1000);
}
