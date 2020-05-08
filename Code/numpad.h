const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};

byte rowPins[ROWS] = {0, 1, 2, 3};
byte colPins[COLS] = {4, 5, 6};


Keypad_I2C kpd( makeKeymap(keys), rowPins, colPins, ROWS, COLS, I2CADDR, PCF8574);

void setupKeypad(){
  
  Wire.begin();
  kpd.begin(makeKeymap(keys));
}

int complete_input = 0;

char* checkNum(const char number){
  if (number == '1')
  {
    return "1";
  }
  else if (number == '2')
  {
    return "2";
  }
  else if (number == '3')
  {
    return "3";
  }
  else if (number == '4')
  {
    return "4";
  }
  else if (number == '5')
  {
    return "5";
  }
  else if (number == '6')
  {
    return "6";
  }
  else if (number == '7')
  {
    return "7";
  }
  else if (number == '8')
  {
    return "8";
  }
  else if (number == '9')
  {
    return "9";
  }
  else if (number == '0')
  {
    return "0";
  }
  else if (number == '*')
  {
    return "*";
  }
  else if (number == '#')
  {
    return "#";
  }
}

char numbers[5] = "0";

int count = 0;
int can_pay = 0;

int keyReset(){
  char number = kpd.getKey();
  if (number == '*')
  {
    ESP.restart();
  }
}

int keyInput(){
  char number = kpd.getKey();
  
  
  if (number == '*')
  {
    if (count != 0)
    {
      count--;
      if (count == 0)
      {
        numbers[count] = '0';
      }
      else
      {
        numbers[count] = ' ';
      }
    }
    else
    {
      numbers[count] = '0';
    }
  }
  else if (number == '#')
  {
    for (int i = 0; i < count; i++)
    {
      if (numbers[i] != ' ' || numbers[i] != '\0')
      {
        int numm = numbers[i]-48;
        if(i == 3)
        {
          can_pay += numm*1000;
        }
        else if(i == 2)
        {
          can_pay += numm*100;
        }
        else if(i == 1)
        {
          can_pay += numm*10;
        }
        else if(i == 0)
        {
          can_pay += numm;
        }
      }
    }
  complete_input = 1;
  }
  else if (number)
  {
    char *num = checkNum(number);
    if (count <= 3)
    {
      numbers[count] = *num;
      count++;
    }
  }
}
