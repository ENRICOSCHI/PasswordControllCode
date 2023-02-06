#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
Named variable
*/
	
int i,j,n,maiusc=0,minu=0,lunghezza=1,numero=0,speciale=0,consecutivo=1,uguale=0,same=1;
char password[100],oldPassword[100];

/*

CHECK BEFORE THE FOR OF CHECKS

*/

void ControlloLunghezza(){
	if(strlen(password)<8||strlen(password)>16)
		lunghezza = 0;//it's not long correctly
}

/*

CHECKS INSIDE THE FOR OF CHECKS

*/

void ControlloMauiscole(){
	if(password[j]>64&&password[j]<91)
		maiusc=1;//there are uppercase
}
void ControlloMinuscole(){
	if(password[j]>96&&password[j]<123)
		minu=1;//there are lowercase
}
void ControlloNumeri(){
	if(password[j]>47&&password[j]<58)
		numero =1;//there's at least a number
}
void ControlloCaratteriSpeciali(){
	if(password[j]>0&&password[j]<48||password[j]>57&&password[j]<65||password[j]>90&&password[j]<97||password[j]>122&&password[j]<=255)
		speciale=1;// there's a special character
}
void ControlloLettereConsecutive(){
	if(j>1)//enter if greater than 1
		if(password[j]==password[j-1])
			consecutivo=0;//2 consecutive letter are equal  
}
void ControlloCarattereUguale(){
	if(password[j]==oldPassword[j])
		uguale++;//same character
}

/*

CHECKS AFTER THE FOR OF CHECKS

*/

void ControlloTraLeDuePassword(){
	if(strcmp(password,oldPassword)==0 || uguale==(strlen(oldPassword)-1)||uguale==(strlen(oldPassword)+1))
		same=0;//are chenged 0 or 1 character
}

void RepilogoControlli(){	
	//if the password is corret it print 1 else 0
	if(lunghezza!=0&&maiusc==1&&minu==1&&numero==1&&consecutivo!=0&&same!=0&&speciale==1)
		printf("1\n");
	else
		printf("0\n");
}

/*

THE MAIN START

*/


int main(int argc, char *argv[]) {
/*
the program start with the firts request to the user
*/
	
printf("inserire le password da mettere\n");
scanf("%d",&n);//input per sapere quante password verrano inserite
	
//first for
for(i=0;i<n;i++){
		
	//asking to the user to put the new and old password
	printf("inserire password nuova\n");
	scanf("%s",password);//input password nuova
	printf("inserire password vecchia\n");
	scanf("%s",oldPassword);//input vecchia password
	
	//check for the lenght of the word (>8 && <16)
	ControlloLunghezza();
	
	//for of checks
	for(j=0;j<strlen(password);j++){	
		ControlloMauiscole();
		ControlloMinuscole();
		ControlloNumeri();
		ControlloCaratteriSpeciali();
		ControlloLettereConsecutive();
		ControlloCarattereUguale();		
	}
	
	ControlloTraLeDuePassword();
	//print the 1 or 0 in the console
	RepilogoControlli();
	}
	
return 0;
}
