double VREF;
double VIN;
double resultado;
int cantidad;
int boton = 10;

int modo = 1;

int leds[] = {LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW};
void setup()
{
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(boton, INPUT);
  pinMode(0, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  //Leer valor en bits
  VREF = analogRead(A0);
  VIN = analogRead(A1);
  
  //Escala de bits a valor real en voltaje
  VREF = VREF * 5 / 1023;
  VIN = VIN * 5 / 1023;

  //VREF = 5;
  //VIN = 3;
  Serial.print(VREF);
  Serial.print("     ");
  Serial.println(VIN);
  
  resultado = VIN / VREF;

  cantidad = round(resultado * 8);
  cantidad = constrain(cantidad, 0, 8);
  Serial.println(cantidad);

  //Cambiar de modo
  if (digitalRead(boton) == 1)
  {
  modo *= -1;
  LowAll();
  }

  //Modo de operacion
  if (modo == 1)
  {
    //Prender un unico LED
    if (cantidad != 0)
    {
      LowAll();
      leds[cantidad - 1] = HIGH;
    }

    else
    {
      LowAll();
    }
    digWrite();
  }

  else
  {
    if (cantidad != 0)
    {
      for (int i = 0; i < 8; i++)
      {
        if (i <= (cantidad-1))
        {
          leds[i] = HIGH;
        }
        else
        {
          leds[i] = LOW;
        }
      }      
    }

    else 
    {
      LowAll();
    }
    digWrite();
  }
  delay(125);
}

void LowAll ()
{
  for(int i = 0; i < 8; i++)
  {
    leds[i] = LOW;
  }
}

void digWrite () 
{
  for(int i = 0; i < 8; i++)
  {
    digitalWrite((i+2), leds[i]);
  }
}

