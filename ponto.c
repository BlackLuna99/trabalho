#include <stdio.h>

#define numero_gavetas 5
unsigned char gavetas[numero_gavetas]={0};

void usar(){
  int gaveta;

  while(1){
  printf("\nEscolha uma gaveta de 1 a %d",numero_gavetas);
  puts("Qual gaveta quer usar?");
  scanf(" %d",&gaveta);

  if(gaveta>=1&&gaveta<=numero_gavetas) break;
  else puts("gaveta invalida");

  }
  for(int i=0;i<numero_gavetas;i++){
    gavetas[i]=gavetas[i]>>1;
  }
  unsigned char mask=0b10000000;
  gavetas[gaveta-1]^=mask;

  for(int i=0;i<numero_gavetas;i++){
    printf("%d ",gavetas[i]);
  }

}

void trocar(){
  int menor,posicao;
  menor=gavetas[0];

  for(int i=0;i<numero_gavetas;i++){
  if(menor>=gavetas[i]){
    menor=gavetas[i];
    posicao=i;
  }
  }

  gavetas[posicao]=0;
  for(int i=0;i<numero_gavetas;i++){
    printf("%d ",gavetas[i]);
  }
}

int main() {
char escolha;

while(1){
puts("\nO que quer fazer.\nu=usar\nt=trocar\ns=sair");
scanf("%s",&escolha);

switch(escolha){
    case 'u':
    usar();
    break;
    case 't':
    trocar();
    break;
    case 's':
    return 0;
    break;
    default:
    puts("comando invalido");
}

}
return 0;
}