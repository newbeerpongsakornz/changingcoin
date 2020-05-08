//variable
int sensor1 = D5;
int sensor2 = D6;
int sensor3 = D7;
int sensor4 = D8;
int isCounter1 = 0;
int isCounter2 = 0;
int isCounter3 = 0;
int isCounter4 = 0;
int have_money = 0;
int count5 = 0;
int delayis = 2000;

int checkmoney;
int complete_insert = 0;

void myDelayText(int period, int text){
    if( millis() - count5 > period)
    {
      count5 = millis();
      Serial.println(text);
    }
}

int checkCoin(int money) {
  isCounter1 = digitalRead(sensor1);
  isCounter2 = digitalRead(sensor2);
  isCounter3 = digitalRead(sensor3);
  isCounter4 = digitalRead(sensor4);
  if (isCounter1) {
    have_money += 1; //1
    delay(delayis);
    
  }
  
  if (isCounter2) {
    have_money += 2; //2
    delay(delayis);
  }
  
  if (isCounter3) {
    have_money += 5; //5
    delay(delayis);
  }
  
  if (isCounter4) {
    have_money += 10; //10
    delay(delayis);
  }

  if (have_money >= money)
  {
    
    complete_insert = 1;
  }
}

void setupCounter() {
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(sensor3, INPUT);
  pinMode(sensor4, INPUT);
  int checkmoney = 0;
}
