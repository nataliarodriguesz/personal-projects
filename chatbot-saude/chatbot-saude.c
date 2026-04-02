#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>

int sistema(){
	int op = telaInicial();

	if(op == 2){
		printf("\nAté logo! Cuide-se bem\n");
		return 0;
	}
	
	int gravidade = nivelGravidade();
	if(gravidade == 1){
		printf("\nEncerrando o atendimento ...\n");
		return 0;
	}
	
	int sintoma = menuSintomas();
	system("pause");	
	if(sintoma != 9){
		aviso();
		system("pause");
	}	
	return 0;		
}

int telaInicial(){
	int op;
	system("cls");
	
	printf("=============================================\n");
    printf("          ASSISTENTE DE SAÚDE VIRTUAL        \n");
    printf("=============================================\n\n");
	printf("Olá! Eu sou o seu Assistente de Saúde Virtual.\n");
	printf("Posso te ajudar a entender melhor seus sintomas\n");
	printf("e orientar sobre cuidados básicos.\n\n");
	printf("ATENÇÃO: minhas orientações são informativas\n");
	printf("e não substituem o atendimento médico.\n\n");
	
	printf("---------------------------------------------\n");
	printf("Deseja continuar?\n");	
	printf("1. Sim, quero continuar\n");
	printf("2. Não, sair\n");
	printf("---------------------------------------------\n");
	
	do{
		printf("Escolha: ");
		scanf("%d", &op);
		if(op != 1 && op != 2){
			printf("Opção inválida! Por favor, tente novamente.\n\n");
		}
	}while(op != 1 && op != 2);	
	
	return op;
} 

int nivelGravidade(){
	int op;
	system("cls");
	
	printf("===========================================\n");
    printf("         AVALIAÇÃO INICIAL DE GRAVIDADE     \n");
    printf("===========================================\n\n");
	printf("Você está sentindo algum desses sintomas agora?\n\n");
	printf("- Falta de ar intensa\n");
	printf("- Dor forte no peito\n");	
	printf("- Desmaio ou Confusão mental\n");
	printf("- Sangramento Abundante\n\n");
	
	printf("-------------------------------------------\n");
	printf("1. Sim, tenho um desses sintomas.\n");
	printf("2. Não, nenhum desses.\n");
	printf("-------------------------------------------\n");
	
	do{
		printf("Escolha: ");
		scanf("%d", &op);
		if(op != 1 && op != 2){
			printf("Opção inválida! Por favor, tente novamente.\n\n");
		}
	}while(op != 1 && op != 2);
	
	if (op == 1) {
        printf("\nATENÇÃO: Isso pode ser uma URGÊNCIA médica.\n");
        printf("Procure um pronto-socorro ou ligue 192 (SAMU).\n");
    } else {
        printf("\nTudo bem! Vamos continuar.\n\n");
    }

	return op;
}

int menuSintomas(){
	int op;
	system("cls");
	
	printf("===========================================\n");
    printf("        ESCOLHA DO SINTOMA PRINCIPAL       \n");
    printf("===========================================\n\n");
    
	printf("Qual é o sintoma principal que você está\n");
	printf("sentindo agora?\n\n");
	printf("1. Febre\n");
	printf("2. Tosse / Dor de Garganta\n");
	printf("3. Dor de cabeça\n");
	printf("4. Dor abdominal\n");
	printf("5. Náusea / Vômito / Diarreia\n");
	printf("6. Dores no corpo\n");
	printf("7. Cansaço ou falta de ar leve\n");
	printf("8. Coceira, vermelhidão ou manchas na pele\n");
	printf("9. Outro sintoma\n\n");
	printf("------------------------------------------\n");
	
	do{
		printf("Escolha: ");
		scanf("%d", &op);
		while(getchar() != '\n');
		if(op < 1 || op > 9){
			printf("Opção inválida! Por favor, tente novamente.\n\n");
		}
	}while(op < 1 || op > 9);
	
	switch(op) {
		case 1:
			febre();
			break;
		case 2:
			tosse();
			break;
		case 3:
			dorCabeca();
			break;
		case 4:
			dorAbdominal();
			break;
		case 5:
			nausea();
			break;
		case 6:
			dorCorpo();
			break;	
		case 7:
			cansaco();
			break;
		case 8:
			manchas();
			break;
		case 9:
			outroSintoma();
			break;
		default:
			break;
	}
	
	return op;
}

void aviso(){
	printf("\n\n As informações fornecidas são apenas\n");
	printf(" orientativas e não substituem avaliação\n");
	printf(" médica profissional.\n\n");
}

void febre() {
	int dias;
	char esc;
	system("cls");
	
	printf("===========================================\n");
    printf("              AVALIAÇÃO DE FEBRE           \n");
    printf("===========================================\n\n");
    
	printf("Há quantos dias você está com a febre? ");
	scanf("%d", &dias);
	while(getchar() != '\n');
	
	do {
		printf("Está acima de 38 graus? (S/N):         ");
		scanf("%c", &esc);
		esc = toupper(esc);
	} while (esc != 'S' && esc != 'N');
	
	printf("\n---------------------------------------------\n");
	if (dias >= 2 && esc == 'S') {
		printf("Procure um posto de saúde para avaliação.\n");
	} else {
		printf("Recomendações:\n");
		printf("- Beber bastante água\n");
		printf("- Fazer repousar\n");
		printf("- Ficar atento a outros sintomas.\n");
	}
	printf("---------------------------------------------\n");
}

void tosse() {
	char esc;
	system("cls");
	
	printf("=============================================\n");
    printf("    AVALIAÇÃO DE TOSSE / DOR DE GARGANTA     \n");
    printf("=============================================\n\n");
    
	do {
		printf("Você está com tosse seca? (S/N): ");
		scanf("%c", &esc);
		while(getchar() != '\n');
		esc = toupper(esc);
	} while (esc != 'S' && esc != 'N');
	
	do {
		printf("Você está com catarro?    (S/N): ");
		scanf("%c", &esc);		
		esc = toupper(esc);
	} while (esc != 'S' && esc != 'N');
	
	printf("\n---------------------------------------------\n");
	printf("Recomendações:\n");
	printf("- Beber bastante água.\n");
	printf("- Evitar ar-condicionado e poeira.\n");
	printf("- Gargarejos com água morna e sal podem ajudar\n");
	printf("na dor.\n");
	printf("---------------------------------------------\n");
}

void dorCabeca(){
	char esc;
	system("cls");
	
	printf("===========================================\n");
    printf("        AVALIAÇÃO DE DOR DE CABEÇA          \n");
    printf("===========================================\n\n");
    
	do{
		printf("É uma dor frequente? (S/N): ");
		scanf("%c", &esc);
		esc = toupper(esc);
	} while (esc != 'S' && esc != 'N');
	
	printf("\n---------------------------------------------\n");
	printf("Recomendações:\n");
	printf("- Descansar em local tranquilo e hidratado.\n");
	printf("- Evitar telas e luz forte\n\n");
	printf("- Procurar atendimento se: \n");
	printf("               Dor súbita e intensa\n");
	printf("               Perda de consciência\n");	
	printf("               Febre, rigidez na nuca.\n");
	printf("---------------------------------------------\n");
}

void dorAbdominal(){
	char esc;
	system("cls");
	
	printf("===========================================\n");
    printf("        AVALIAÇÃO DE DOR ABDOMINAL         \n");
    printf("===========================================\n\n");
	
	do{
		printf("Comeu algo diferente recentemente? (S/N): ");
		scanf("%c", &esc);
		while(getchar() != '\n');
		esc = toupper(esc);
	}while(esc != 'S' && esc != 'N');
	
	do{
		printf("Está conseguindo se hidratar?      (S/N): ");
		scanf("%c", &esc);
		esc = toupper(esc);
	}while(esc != 'S' && esc != 'N');
	
	printf("\n---------------------------------------------\n");
	printf("Recomendações: \n");
	printf("- Evitar alimentos gordurosos.\n");
	printf("- Tente se manter hidratado (água, soro caseiro).\n");
	printf("---------------------------------------------\n");
}

void nausea(){
	char esc;
	system("cls");
	
	printf("===========================================\n");
    printf("  AVALIAÇÃO DE NÁUSEA / VÔMITO / DIARREIA   \n");
    printf("===========================================\n\n");	
    
    do{
		printf("Está conseguindo se hidratar? (S/N): ");
		scanf("%c", &esc);
		while(getchar() != '\n');
		esc = toupper(esc);
	}while(esc != 'S' && esc != 'N');
	
	do{
		printf("As fezes estão líquidas?      (S/N): ");
		scanf("%c", &esc);
		while(getchar() != '\n');
		esc = toupper(esc);
	}while(esc != 'S' && esc != 'N');
    
    printf("\n---------------------------------------------\n");
	printf("Recomendações: \n");
	printf("- Tente se manter hidratado (água, soro caseiro).\n");
	printf("- Faça alimentação leve (arroz, banana, maçã, torrada).\n");
    printf("- Evite leite, frituras e alimentos muito gordurosos.\n");
    printf("---------------------------------------------\n");
}

void dorCorpo(){
	system("cls");

	printf("===========================================\n");
    printf("        AVALIAÇÃO DE DORES NO CORPO        \n");
    printf("===========================================\n\n");	
	
	printf("Dores no corpo podem indicar virose, esforço\n");
	printf("físico ou dengue, caso as dores persistam por\n"); 
	printf("mais de 4 dias é aconselhável consultar um mé-\n");
	printf("dico para melhor diagnóstico\n");

	printf("\n---------------------------------------------\n");	
	printf("Recomendações: \n");
	printf("- Hidratação\n");
	printf("- Repouso\n");
	printf("- Analgésico leve, se necessário\n");
	printf("---------------------------------------------\n");
}

void cansaco(){
	char esc;
	system("cls");

	printf("===========================================\n");
    printf("  AVALIAÇÃO DE CANSAÇO / FALTA DE AR LEVE   \n");
    printf("===========================================\n\n");	
    
    do{
		printf("É recente? (S/N): ");
		scanf("%c", &esc);
		esc = toupper(esc);
	}while(esc != 'S' && esc != 'N');
	
	printf("\n---------------------------------------------\n");
	printf("Recomendações: \n");
	printf("- Descanse e evite atividades físicas intensas\n");
	printf("- Beba bastante água para manter-se hidratado(a).\n\n");
	printf("- Procurar atendimento se: \n");
	printf("               O sintoma piorar\n");
	printf("               Dor no peito ou chiado\n");	
	printf("               inchaço nas pernas.\n");
	printf("               cianose(lábios inchados)\n");
	printf("---------------------------------------------\n");
}

void manchas(){
	system("cls");
	char esc;
	
	printf("==============================================\n");
    printf(" AVALIAÇÃO DE COCEIRA / VERMELHIDÃO / MANCHAS  \n");
    printf("==============================================\n\n");
	
    do{
		printf("As manchas coçam? (S/N): ");
		scanf("%c", &esc);
		esc = toupper(esc);
	}while(esc != 'S' && esc != 'N');
	
	printf("\n---------------------------------------------\n");
	printf("Recomendações: \n");
	printf("- Evite coçar\n");
	printf("- Manter pele limpa\n\n");
	printf("- Procurar atendimento se: \n");
	printf("               Febre\n");
	printf("               Inchaço\n");	
	printf("               Dificuldade de respirar\n");
	printf("               Espalhamento rápido\n");
	printf("---------------------------------------------\n");	
}

void outroSintoma(){
	system("cls");
	
	printf("===========================================\n");
    printf("          AVALIAÇÃO DE OUTRO SINTOMA        \n");
    printf("===========================================\n\n");
    
	printf("Entendido!\n");
	printf("Eu posso oferecer apenas informações gerais sobre sintomas leves.\n\n");
	printf("Como o seu sintoma não está na lista anterior, o ideal é procurar\n");
	printf("um posto de saúde ou médico para uma avaliação mais detalhada.\n\n");
	printf("LEMBRE-SE: buscar atendimento é sempre a melhor opção para garantir\n");
	printf("um diagnóstico correto e o tratamento adequado.\n");
	printf("---------------------------------------------\n");
}

int main(){
	setlocale(LC_ALL, "portuguese");
	
	sistema();
	return 0;
}
