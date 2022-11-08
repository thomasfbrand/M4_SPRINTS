//definição do que vai ser usado e suas portas
#define led_amarelo 5
#define led_azul 18
#define led_verde 8
#define led_vermelho 9
#define buzzer 20
#define ldr 14
#define botao1 1
#define botao2 2
//definição de variaveis usadas ao longo do código
int frequencias[100];
int binario[4];
int i = 0;
int x = 0;
int y = 0;



void convertebinario(int vluz) { // função para transformar número em binário
  while(i < 4){
    // obtém o resto da divisão de num por 2
    binario[i] = vluz % 2;
    i++;
    vluz = vluz / 2;
  }
  i = 0;
}


void led_acesa(){
  if (binario[0] == 1){
    digitalWrite(led_vermelho, HIGH);
  }
  else{
    digitalWrite(led_vermelho, LOW);
  }
    if (binario[1] == 1){
    digitalWrite(led_verde, HIGH);
  }
  else{
    digitalWrite(led_verde, LOW);
  }
    if (binario[2] == 1){
    digitalWrite(led_azul, HIGH);
  }
  else{
    digitalWrite(led_azul, LOW);
  }
    if (binario[3] == 1){
    digitalWrite(led_amarelo, HIGH);
  }
  else{
    digitalWrite(led_amarelo, LOW);
  }
}
  

  
// código para identificar o número binário acendendo ou apagando LEDs de acordo com os 0 e 1.

void armazena_freq(int inteiro){ // função para o botão mudar a frequencia do buzzer e ir incrementando
    frequencias[x] = inteiro;
    x = x + 1;
    tone(buzzer, inteiro*700, 250);
  }



void musica(){  
    while(y < x){
      tone(buzzer, frequencias[y] * 700, 250);
      y++;
      convertebinario(frequencias[y]);
      led_acesa();
      delay(500);
    }
  }
  


void setup() {
  // definição dos tipos dos #define
  Serial.begin(115200);
  pinMode(led_amarelo, OUTPUT);
  pinMode(led_azul, OUTPUT);
  pinMode(led_verde, OUTPUT);
  pinMode(led_vermelho, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(ldr, INPUT);
  pinMode(botao1, INPUT_PULLUP);
  pinMode(botao2, INPUT_PULLUP);
}


void loop() {
  int valor_ldr = (analogRead(ldr));
  int luz_conv = (valor_ldr/269);
  convertebinario(valor_ldr);
  
  if (digitalRead(botao1) == LOW) {
    led_acesa();
        armazena_freq(luz_conv);
  }

  if(digitalRead(botao2) == LOW) {
    musica();
  }
  
  delay(500);

}
