// Projeto 12 -  Motor de passo controlado por Arduino

// Declarando variáveis para os pinos do motor

int motorPin1 = 4; // Azul   - Pino 1 do motor 28BYJ-48
int motorPin2 = 5; // Rosa   - Pino 2 do motor 28BYJ-48
int motorPin3 = 6; // Amarelo - Pino 3 do motor 28BYJ-48
// Laranja - Pino 4 do motor 28BYJ-48 o pino 5 (Vermelho) é o pino de... 
//alimentação do motor de passo (VCC) 
int motorPin4 = 7;   

int velocMotor = 1200;  // Variáveis para configurar a velocidade do motor
int contagem = 0;  // Variável usada como contador de passos
int passosPorRotacao = 512;  // Número de passos por rontação completa
int vetorLigDesl[8] = {B01000, B01100, B00100, B00110, B00010, B00011, 
B00001, B01001};
 // Vetor que manipula os pinos do motor entre 0 e 1 (Desliga/Liga)

void setup() {
  // Declara os pinos do motor como pinos de saída

  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
}

void loop(){
  if(contagem < passosPorRotacao )
    sentidoHorario();  // Função para rotacionar em sentido horário
  else if (contagem == passosPorRotacao * 2)
    contagem = 0;
  else
    sentidoAntiHorario();  // Função para rotacionar em sentido anti horário
  contagem++;
}

/*Configurando os pinos para ULN2003.
o delay "motorSpeed" determina o tempo para a velocidade do motor*/

void sentidoAntiHorario()
{
  for(int i = 0; i < 18; i++)
  {
    setOutput(i);
    delayMicroseconds(velocMotor);
  }
}

void sentidoHorario()
{
  for(int i = 17; i >= 0; i--)
  {
    setOutput(i);
    delayMicroseconds(velocMotor);
  }
}

void setOutput(int out)  // Faz a manipulação de 0 e 1
{
  digitalWrite(motorPin1, bitRead(vetorLigDesl[out], 0));
  digitalWrite(motorPin2, bitRead(vetorLigDesl[out], 1));
  digitalWrite(motorPin3, bitRead(vetorLigDesl[out], 2));
  digitalWrite(motorPin4, bitRead(vetorLigDesl[out], 3));
}
