#include <stdio.h>
#include <stdlib.h>
#define COTE 5   //Taille

typedef struct coordonees{  //L'endroit ou l'on se trouve

    int x;
    int y;
    int compteur;

}coordonees;

//Prototypage
void init(int carre[][COTE], coordonees *pointeur);
void Afficher(int carre [][COTE]);
int RechercherVide(int carre[][COTE], coordonees *pointeur);
int AvancerGauche(int carre[][COTE],int i, coordonees *pointeur);
int AvancerDroite(int carre[][COTE],int i, coordonees *pointeur);


int main()
{
    int surface=(COTE*COTE);
    int carre[COTE][COTE];
    int i=0;
    coordonees pointeur;

    init(carre,&pointeur);
    for (i=1;i<surface;i++){
        RechercherVide(carre,&pointeur);
        AvancerDroite(carre,i,&pointeur);
        if (RechercherVide(carre,&pointeur)==0){
            AvancerGauche(carre,i,&pointeur);
        }
    }
    Afficher(carre);


    return 0;
}


void init(int carre[][COTE], coordonees *pointeur){
//BUT Initialiser le tableau et placer le pointeur qui servira � remplir notre carr� par la suite
//ENTRER Le tableau � la bonne taille, vide avec le pointeur en 0,0
//Sortie Le tableau initialis� avec le pointeur placer en COTE/2,COTE/2+1 arrondi � l'entier sup�rieur

    int i=0;
    int j=0;
    for (i=0;i<COTE;i++){          //On initialise le tableau en le remplissant de 0
        for (j=0;j<COTE;j++){
            carre[i][j]=0;
        }

    }
    pointeur->y=COTE/2-1;
    pointeur->x=COTE/2;
    pointeur->compteur=1;
    carre[pointeur->y][pointeur->x]=pointeur->compteur;  //Le nord du milieu du carr� sera notre point de d�part et vaut donc 1
}

int RechercherVide(int carre[][COTE], coordonees *pointeur){
//BUT Chercher la prochaine cellule du tableau remplissable
//ENTREE  Le tableau vide et les coordonees du pointeur avant d�placement
//SORTIE On retourne 1 si l'on doit seulement avancer vers la droite et 0 si l'on doit ajouter � cela un mouvement vers la gauche

    if (pointeur->x+1==COTE){  //Si le pointeur risque d'aller trop loin on le fait aller � l'opposer du tableau
        pointeur->x=-1;
    }
    if (pointeur->y-1==-1){  //Si le pointeur risque d'aller trop loin on le fait aller � l'opposer du tableau
        pointeur->y=COTE;
    }
    if (carre[pointeur->y-1][pointeur->x+1]==0){    //On v�rifie si la case haut � droite est "vide" c�d =0
       return 1;
    }else if (carre[pointeur->y-1][pointeur->x]<pointeur->compteur){   //Si la premi�re condition n'est pas v�rifi� on regarde si la case en haut � gauche de la pr�c�dente est libre (c�d celle 2 cases au dessus de la case initiale)

       return 0;
    }


   return 1;
}


int AvancerDroite(int carre[][COTE],int i, coordonees *pointeur){
//BUT Avancer le curseur en diagonale droite et placer le bon nombre
//ENTREE les coordon�es du pointeur la valeur qu'il doit avoir
//SORTIE la cellule voulue remplie
    pointeur->compteur=pointeur->compteur+1;
    pointeur->x=pointeur->x+1;
    pointeur->y=pointeur->y-1;
    //printf("%d",pointeur->x);
    carre[pointeur->y][pointeur->x]=pointeur->compteur;
    return 0;
}

int AvancerGauche(int carre[][COTE],int i, coordonees *pointeur){
//BUT Avancer le curseur en diagonale gauche et placer le bon nombre
//ENTREE les coordon�es du pointeur la valeur qu'il doit avoir
//SORTIE la cellule voulue remplie
    pointeur->y=pointeur->y-1;
    pointeur->x=pointeur->x-1;
   // printf("%d",pointeur->x);
    carre[pointeur->x][pointeur->y]=pointeur->compteur+1;
    return 0;
}

void Afficher(int carre[][COTE]){
//BUT    Afficher le carre magique rempli
//ENTREE Le tableau rempli
//SORTIE Le tableau rempli et affich�

    int i=0;
    int j=0;
    for (i=0;i<COTE;i++){          //On initialise le tableau en le remplissant de 0
        for (j=0;j<COTE;j++){
            printf("   %d",carre[i][j]);
        }

        printf("\n");
    }
}
