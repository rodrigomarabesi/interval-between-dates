#include <stdio.h>
#include <locale.h>

/*
Desenvolvido imaginando um usuário coerente
*/

int dias(int mes, int bissexto);
int bissexto(char resposta);
int intervalo(int mes1, int dia1, int mes2, int dia2, int bissexto);

main(){
	int mes1, dia1, mes2, dia2, dias; 
	char resp;
	
	setlocale(LC_ALL, "Portuguese");
	
	printf("Digite o dia do mês inicial\n");
	scanf("%d", &dia1);
	printf("Digite o número referente ao mês inicial (1 a 12)\n");
	scanf("%d", &mes1);
	
	printf("\nDigite o dia do mês final\n");
	scanf("%d", &dia2);
	printf("Digite o número referente ao mês final (1 a 12)\n");
	scanf("%d", &mes2);
	
	//Vou desenvolver em breve
	if (mes2 < mes1){
		printf("Função não desenvolvida, insira apenas meses do mesmo ano!");
		return 1;
	}
	
	
	printf("\nAno bissexto?\nResponda com 's' ou 'n' (sem aspas)\n");
	scanf(" %c", &resp);
	
	
	
	dias = intervalo(mes1, dia1, mes2, dia2, bissexto(resp));
	printf("\n\nIntervalo entre essas datas: %d dias corridos\n\n", dias);
	system("pause");
	return 0;
}


//Retornar número de dias entre as datas inseridas
int intervalo(int mes1, int dia1, int mes2, int dia2, int bissexto){
	if (mes1 == mes2)
		return dia2 - dia1;
	int i, total = 0;
	for (i = mes1 + 1; i < mes2; i++){
		//printf("total: %d", total);
		total = total + dias(i, bissexto);
	}	
	total = total + dia2 + (dias(mes1, bissexto) - dia1);
	return total;
}

//Retornar true ou false dependendo da resposta do usuario sobre o ano ser bissexto
int bissexto(char resposta){
	if (resposta == 's')
		return 1;
	return 0;	
}

//Retornar quantidade de dias do mês dependendo do ano ser bissexto ou nao
int dias(int mes, int bissexto){
	if (mes == 2){
		if (bissexto == 1)
			return 29;
		return 28;	
	}
	if (mes % 2 == 0 && mes <= 7 || mes % 2 != 0 && mes >= 8)
		return 30;
	return 31;
}
