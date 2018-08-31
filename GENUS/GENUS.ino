//-----------------------#define e Variáveis------------------------//
#define LED_RED 11
#define LED_BLUE 12
#define LED_GREEN 10
#define LED_YELLOW_1 8
#define LED_YELLOW_2 9

#define BUTTON_RED 4
#define BUTTON_BLUE 7
#define BUTTON_GREEN 6
#define BUTTON_YELLOW 3

#define TEMPO_PISCA 600
#define TEMPO_ENTRE 150

int qnt = 4;
int play = 1;
int jogada = 0;
int sorteados[50];  // QT_SEQ é o tamanho da sequência dos leds

//--------------Declaração da função de cada elemento---------------//
void setup() {
  Serial.begin(9600);

  pinMode(LED_RED, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_YELLOW_1, OUTPUT);
  pinMode(LED_YELLOW_2, OUTPUT);

  pinMode(BUTTON_RED, INPUT_PULLUP);
  pinMode(BUTTON_BLUE, INPUT_PULLUP);
  pinMode(BUTTON_GREEN, INPUT_PULLUP);
  pinMode(BUTTON_YELLOW, INPUT_PULLUP);




  randomSeed(analogRead(0)); //Sorteia uma nova sequencia toda vez que liga o Arduino
}

//----------Loop do sorteio, leitura de botão e comparação----------//
void loop() {
  //Acende tudo
  digitalWrite(LED_RED, HIGH);
  digitalWrite(LED_BLUE, HIGH);
  digitalWrite(LED_GREEN, HIGH);
  digitalWrite(LED_YELLOW_1, HIGH);
  digitalWrite(LED_YELLOW_2, HIGH);


  le_botao(); //Jogador aperta qlqer botão e já inicia o sorteio
  //Apaga tudo
  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_BLUE, LOW);
  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_YELLOW_1, LOW);
  digitalWrite(LED_YELLOW_2, LOW);
  delay(500);

  qnt = 4;
  play = 1;
  jogada = 0;

  while (play == 1) {

    //-----------------------Sorteio da sequência-----------------------//
    //QT_SEQ é o tamanho da sequência - quantas vezes os LEDs piscam
    
    while (jogada < qnt) {
      sorteados[jogada] = random(4);
      jogada ++;
    } //Fim do sorteio
    for(int i = 0;i<qnt;i++){
       pisca_led(sorteados[i]);
       delay(TEMPO_ENTRE);
    }
      

    //---------------------Comparação da sequência----------------------//
    int vez; //Definido fora do for para poder verificar numero de acertos no final
    for (vez = 0; vez < qnt; vez ++) {
      if (le_botao() == sorteados[vez]) {
        pisca_led(sorteados[vez]);
      } else {
        play = 0;
        piscar_todos();
        break; //Sai do for
      }
    }
    
    if(play == 1){
      qnt++;
    }
  }
} //Fim do loop

//------------------------Função piscar LED-------------------------//
void pisca_led(int posicao) {
  Serial.println(posicao);

  if (posicao == 0) {
    digitalWrite(LED_RED, HIGH);
    delay(TEMPO_PISCA);
    digitalWrite(LED_RED, LOW);
  } else if (posicao == 1) {
    digitalWrite(LED_BLUE, HIGH);
    delay(TEMPO_PISCA);
    digitalWrite(LED_BLUE, LOW);
  } else if (posicao == 2) {
    digitalWrite(LED_GREEN, HIGH);
    delay(TEMPO_PISCA);
    digitalWrite(LED_GREEN, LOW);
  } else if (posicao == 3) {
    digitalWrite(LED_YELLOW_1, HIGH);
    digitalWrite(LED_YELLOW_2, HIGH);
    delay(TEMPO_PISCA);
    digitalWrite(LED_YELLOW_1, LOW);
    digitalWrite(LED_YELLOW_2, LOW);
  }
  delay(100);

} //Fim do pisca_led

//------------------------Função ler os botões----------------------//
int le_botao () {
  int result = -1; //-1 indica que nenhum botão foi apertado

  while (result == -1) {
    if (digitalRead(BUTTON_RED) == LOW) {
      result = 0;    //Posição 0
    } else if (digitalRead(BUTTON_BLUE) == LOW) {
      result = 1;
    } else if (digitalRead(BUTTON_GREEN) == LOW) {
      result = 2;
    } else if (digitalRead(BUTTON_YELLOW) == LOW) {
      result = 3;
    }
  }
  return result; //Retorna o inteiro int le_botao
}

void piscar_todos(){
    digitalWrite(LED_RED, HIGH);
  digitalWrite(LED_BLUE, HIGH);
  digitalWrite(LED_GREEN, HIGH);
  digitalWrite(LED_YELLOW_1, HIGH);
  digitalWrite(LED_YELLOW_2, HIGH);


  delay(TEMPO_ENTRE); //Jogador aperta qlqer botão e já inicia o sorteio
  //Apaga tudo
  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_BLUE, LOW);
  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_YELLOW_1, LOW);
  digitalWrite(LED_YELLOW_2, LOW);
}

