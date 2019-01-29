#include<stdio.h>

int Compteur_Ligne(int *p)
{
	int nLignes=0;
	FILE *fp;
    fp=fopen("monfichier.txt","a+");
    
	int c;
	while((c=getc(fp)) != EOF)
	{
		if(c == '\n')
		{
			nLignes++;
		}
	}
	*p=nLignes;
	fclose(fp);
}

void Save()
{
  	char Prenom[30], Nom[30], Num[15], Email[30];
  	int Id;
  	system("cls");
  	FILE *fp;
    fp=fopen("monfichier.txt","a+");
  	
	printf("\n\t******AJOUTER UN NOUVEL UTILISATEUR******\n\n");
  	printf("Entrez votre Prenom : \n");
    scanf("%s", &Prenom);
 	printf("Entrez votre Nom: \n");
    scanf("%s", &Nom);
    printf("Entrez votre Num : \n");
    scanf("%s", &Num);
    printf("Entrez votre Email: \n");
    scanf("%s", &Email);
    printf("Entrez votre Identifiant : \n");
	scanf("%d", &Id);
	printf("Erreur veuillez entrer votre identifiant a nouveau : \n");
	scanf("%d", &Id);
    
    fprintf(fp, "%s %s %s %s %d\n", Prenom, Nom, Num, Email, Id);
    
    fclose(fp);
}

void Affichage()
{
	char Prenom[30], Nom[30], Num[15], Email[30];
	int Id;
	int i;
	int *p;
	int nLignes;
	p=&nLignes;
	Compteur_Ligne(p);
	
	FILE *fp;
    fp=fopen("monfichier.txt","a+");
    system("cls");
	int c;
  	if((c=getc(fp)) == EOF)
  	{
  		printf("\n\t******************\n");
  		printf("\n\tERREUR DE FICHIER");
  		return;
	}
	
	printf("\n\t***************REPERTOIRE***************\n\n");
	
	for(i=1;i<nLignes+1;i++)
	{
		fscanf(fp, "%s", &Prenom);
        fscanf(fp, "%s", &Nom);
        fscanf(fp, "%s", &Num);
        fscanf(fp, "%s", &Email);
        fscanf(fp, "%d", &Id);
        printf("\n\t*************UTILISATEUR %d**************\n\n", i);
        printf("Nom : %s \n", Nom);
        printf("Prenom : %s \n", Prenom);
        printf("Numero de tel : %s \n", Num);
        printf("Email : %s \n", Email);
        printf("Identifiant : %d \n", Id);
	}
	
fclose ( fp );
}

void Recherche()
{
	char Prenom[30], Nom[30], Num[15], Email[30];
	int Id;
	int ide;
	int i;
	char Choixuser;
	int *p;
	int nLignes;
	p=&nLignes;
	Compteur_Ligne(p);
	system("cls");
	FILE *fp;
    fp=fopen("monfichier.txt","a+");
    
    int c;
  	if((c=getc(fp)) == EOF)
  	{
  		printf("\n\t******************\n");
		printf("\n\tERREUR DE FICHIER");
  		return;
	}
  
	printf("\n\t*************UTILISATEURS*************\n\n");
	for(i=1;i<nLignes+1;i++)
	{
		fscanf(fp, "%s", &Prenom);
        fscanf(fp, "%s", &Nom);
        fscanf(fp, "%s", &Num);
        fscanf(fp, "%s", &Email);
        fscanf(fp, "%d", &Id);
		printf("Utilisateur %s : %d \n", Nom, Id);
	}
	printf("\n\t*********RECHERCHE UTILISATEUR*********\n\n");
	fclose(fp);
	fp=fopen("monfichier.txt","a+");
	
    printf("Rentrer l'Id d'un Utilisateur : ");
    scanf("%d",&ide);
    
    for(i=1;i<nLignes+1;i++)
    	{	
        fscanf(fp, "%s", &Prenom);
        fscanf(fp, "%s", &Nom);
        fscanf(fp, "%s", &Num);
        fscanf(fp, "%s", &Email);
        fscanf(fp, "%d\n", &Id);
        if(ide == Id)
        {
        printf("\nNom : %s \n", Nom);
        printf("Prenom : %s \n", Prenom);
        printf("Numero de tel : %s \n", Num);
        printf("Email : %s \n", Email);
        printf("Identifiant : %d \n", Id);
		}
		}
	fclose(fp);
}

void Supprimer_User()
{
	char Prenom[30], Nom[30], Num[15], Email[30];
	int Id;
	int ide;
	int i;
	int *p;
	int nLignes;
	p=&nLignes;
	Compteur_Ligne(p);
	FILE *fp;
	FILE *f;
	fp = fopen("monfichier.txt", "a+");
  	f = fopen("monfichiertemporaire.txt","a+");
  	system("cls");
  	int c;
  	if((c=getc(fp)) == EOF)
  	{
  		printf("\n\t******************\n");
  		printf("\n\tERREUR FICHIER DEJA VIDE");
  		return;
	}
  	
 	printf("\n\t*************UTILISATEURS*************\n\n");
	for(i=1;i<nLignes+1;i++)
	{
		fscanf(fp, "%s", &Prenom);
        fscanf(fp, "%s", &Nom);
        fscanf(fp, "%s", &Num);
        fscanf(fp, "%s", &Email);
        fscanf(fp, "%d", &Id);
		printf("Utilisateur %s : %d \n", Nom, Id);
	}
	fclose(fp);
	fp = fopen("monfichier.txt", "r+");
  	
	printf("\nSaisir l'identifiant de la personne a supprimer : ");
	scanf("%d",&ide);
	for(i=1;i<nLignes+1;i++)
  	{
  		fscanf(fp, "%s", &Prenom);
		fscanf(fp, "%s", &Nom);
		fscanf(fp, "%s", &Num);
		fscanf(fp, "%s", &Email);
		fscanf(fp, "%d\n", &Id);
		
		if (ide != Id)
		{
			fprintf(f, "%s %s %s %s %d\n", Prenom, Nom, Num, Email, Id);
		}
	}
	fclose(fp);
	fclose(f);
	remove("monfichier.txt");
    rename("monfichiertemporaire.txt","monfichier.txt");
    printf("utilisateur supprime");
}

int main (void)
{
	char Prenom[30];
	char Nom[30];
    char Num[15];
    char Email[30];
    int Id;
	char ChoixMenu;

	FILE *fp;
    fp=fopen("monfichier.txt","a+");
	Menu :
		system("cls");
    	printf("\n\t*************MENU************\n\n");
    	printf("\tA.Ajouter un utilisateur\n");
		printf("\tB.Lire toute la base de donne\n");
		printf("\tC.Chercher un utilisateur\n");
		printf("\tD.Vider la base de donne\n");
		printf("\tE.Supprimer un Utilisateur\n");
		printf("\tF.Quitter le programme\n");
    	
    	
		ChoixMenu=toupper(getch());
		switch(ChoixMenu)
		{
			case 'A' : goto Ajouter; break;
			case 'B' : goto Lecture; break;
			case 'C' : goto Chercher; break;
			case 'D' : goto SupprimerTout; break;
			case 'E' : goto SupprimerUser; break;
			case 'F' : return 0;
			default : goto Menu;		
		}
		
	Ajouter :
		Save();
    	Affichage();
    	getch();
    	goto Menu;
    
    Lecture : 
    	Affichage();
    	getch();
    	goto Menu;
    	
    Chercher :
    	Recherche();
    	getch();
    	goto Menu;
    	
    SupprimerTout :
    	fp=fopen("monfichier.txt","w+");
    	fclose(fp);
    	printf("\n\tLa base de donnee a ete vide\n");
    	getch();
    	goto Menu;
    	
  	SupprimerUser :
  		Supprimer_User();
  		getch();
  		goto Menu;
    
}
