#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int i,j,n,maiusc=0,minu=0,lunghezza=1,numero=0,speciale=0,consecutivo=1,uguale=0,same=1;
	char password[17];
	char oldPassword[17];
	
	printf("inserire le password da mettere\n");
	scanf("%d",&n);//input per sapere quando password verrano inserite
	for(i=0;i<n;i++){
	
	printf("inserire password nuova\n");
	scanf("%s",password);//input password nuova
	printf("inserire password vecchia\n");
	scanf("%s",oldPassword);//input vecchia password
	
	if(strlen(password)<8||strlen(password)>16){
		int lunghezza =0;//non è lunga correttamente
	}
	for(j=0;j<strlen(password);j++){
		if(password[j]>64&&password[j]<91){
			maiusc=1;//ci sono maiuscole
		}
		if(password[j]>96&&password[j]<123){
			minu=1;//ci sono minuscole
		}
		if(password[j]>47&&password[j]<58){
			numero =1;//numero presente
		}
		if(password[j]>0&&password[j]<48||password[j]>57&&password[j]<65||password[j]>90&&password[j]<97||password[j]>122&&password[j]<255){
			speciale=1;// è presente un carattere speciale
		}
		if(j>1){//entra se maggiore di 1
			if(password[j]==password[j-1]){
				consecutivo=0;//due lettere sono uguali consecutivamente
			}
		}	
	     if(password[j]==oldPassword[j]){
			uguale++;//carattere uguale
		}
	}
	if(strcmp(password,oldPassword)==0 || uguale==(strlen(oldPassword)-1)||uguale==(strlen(oldPassword)+1)){
		same=0;//sono cambiati 0 o 1 caratteri
	}
	if(lunghezza!=0&&maiusc==1&&minu==1&&numero==1&&consecutivo!=0&&same!=0&&speciale==1)
		printf("1\n");
	else
		printf("0\n");
}
	return 0;
}
