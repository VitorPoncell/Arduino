// Projeto 4 – Tocador de melodia com sonorizador piezo

/* A diretiva #define é muito simples e útil, esta diretiva simplesmente
um valor e seu token correspondente, por exemplo, #define PI 3.141592653
589793238462643. No decorrer do seu programa você não precisa digitar 
todo o valor de PI, apenas #define PI.*/

#define NOTE_C3 131
#define NOTE_CS3 139
#define NOTE_D3 147
#define NOTE_DS3 156
#define NOTE_E3 165
#define NOTE_F3 175
#define NOTE_FS3 185
#define NOTE_G3 196
#define NOTE_GS3 208
#define NOTE_A3 220
#define NOTE_AS3 233
#define NOTE_B3 247
#define NOTE_C4 262
#define NOTE_CS4 277

#define NOTE_D4 294
#define NOTE_DS4 311
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_FS4 370
#define NOTE_G4 392
#define NOTE_GS4 415
#define NOTE_A4 440
#define NOTE_AS4 466
#define NOTE_B4 494

#define WHOLE 1
#define HALF 0.5
#define QUARTER 0.25
#define EIGHTH 0.125
#define SIXTEENTH 0.0625

// Definimos um array de valores inteiro tune[], preenchendo as notas da... 
//melodia "Puff, o Dragão Mágico"
int tune[] = { NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_B3, 
NOTE_G3, NOTE_A3, NOTE_C4, NOTE_C4, NOTE_G3, NOTE_G3, NOTE_F3, 
NOTE_F3, NOTE_G3, NOTE_F3, NOTE_E3, NOTE_G3, NOTE_C4, NOTE_C4,
NOTE_C4, NOTE_C4, NOTE_A3, NOTE_B3, NOTE_C4, NOTE_D4};

// Criamos um array de floats que armazena a duração de cada nota, 
//conforme melodia tocada
float duration[] = { EIGHTH, QUARTER+EIGHTH, SIXTEENTH, QUARTER, 
QUARTER, HALF, HALF, HALF, QUARTER, QUARTER, HALF+QUARTER, 
QUARTER, QUARTER, QUARTER, QUARTER+EIGHTH, EIGHTH, QUARTER, 
QUARTER, QUARTER, EIGHTH, EIGHTH, QUARTER, QUARTER, QUARTER, 
QUARTER, HALF+QUARTER};

int length;// Este inteiro será utilizado para calcular e armazenar o... 
//comprimento do array (número de notas na melodia)

void setup() {
  pinMode(8, OUTPUT); // Definimos o pino digital 8 como saída
  // A função sizeof retorna o número de bytes
  length = sizeof(tune) / sizeof(tune[0]); 
}
void loop() {
// Definimos um loop que itera o número de vezes correspondente as... 
//notas da melodia
  for (int x = 0; x < length; x ++) {  
// Então a próxima nota do array tune[] é reproduzida no pino digita 8
  tone(8, tune[x]); 
// Aqui esperamos o tempo necessario para que a melodia seja reproduzida
  delay(1500 * duration[x]); 
// Antes que a nota seguinte seja tocada você cessa o tom gerado no pino 8
  noTone(8); 
}
  delay(5000); // Espera 5 segundos antes de tocar a melodia novamente
}
