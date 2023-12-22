//Dans cette partie , on aura le dechiffrement CESAR et AFFINE par BRUTEFORCE
#include <stdio.h>
#include <string.h>

//Voici notre fonction principale
void main(){
    int choice;
    char message[100];
    printf("1. Brute force Cesar\n2. Brute force Affine\n : ");
    do {
        printf("Entrez 1 ou 2\n : ");
        scanf("%d",&choice);
    }while(choice<1 || choice>2);

    if (choice==1){
        printf("\nEntrez le message : ");
        scanf("%s",&message);
        Brute_cesar(message);
    }
    else if (choice==2){
        printf("\nEntrez le message : ");
        scanf("%s",&message);
        Brute_affine(message);
    }
    
}


//Fonction pour dechiffrer par BRUTE FORCE CESAR
void Brute_cesar(char message[]){
    int i;
    int var; //Dans cette variable on va stoquer la position trouvé dans l'alphabet;
    char c; //Ici on va stoquer le caractere quand on a deja appliqué la clé dessus
    int hu;
    char AI[26]="zyxwvutsrqponmlkjihgfedcba";
    int key; 


    size_t taille_message=strlen(message);
    printf("Voici la liste de tout les possibilites de decryptages  :  \n");
    for (key=1 ; key<=26 ; key++ ){
        char message_crypte[100]="";
        for (i=0;i<taille_message;i++){
            char *position = strchr(AI, message[i]); //On utilise ici le pointeur de positions d'une lettre (Vu sur internet)
            //printf("voici la %ld",position-A);
            var=position-AI;
            hu=(var+key)%26; //Drole de nom mais c'est pour la position dans l'alphabet
            //printf("Voici %c ",A[(var+key)%26]);
            c=AI[hu];
            message_crypte[i]=c;
            if (i==taille_message){
                message_crypte[i+1]='\0';
            }
            
        }
        printf("\n%s",message_crypte);
    }
    
    main();

}


//Fonction pour calculer le pgcd de deux nombres (Servira pour le chiffrement affine)
int gcd(int key1_affine, int b) {
    while (b != 0) {
        int temp = b;
        b = key1_affine % b;
        key1_affine = temp;
    }
    return key1_affine;
}

//Fonction pour calculer l'inverse modulaire des fonctions de dechiffrement affine
int inverse_modulo(int key1_affine, int m) {
    int i;
    for (i = 1; i < m; i++) {
        if ((key1_affine * i) % m == 1) {
            return i;
        }
    }
    return -1; // Pas d'inverse multiplicatif trouvé
}


//Fonction pour le brute_force_affine
void Brute_affine(char message[]){
    int o , key1_affine , key2_affine;
    char message_decrypte_affine[100]=""; //On reserve cet espace pour stoquer le message dechiffrer
    size_t taille=strlen(message); //Ici , on stoque la longueur du message
    char v; //Ici , on va stoquer le caractere quand on aura deja appliquer la cle 
    int var;
    int m=26; //Pour stoquer le modulo lors du calcuL de l'inverse
    char A[26]="abcdefghijklmnopqrstuvwxyz";
    printf("\nVoici la liste de tout les messages decryptes affine possibles : ");
    for (key1_affine=1;key1_affine<=26;key1_affine++){
        if ( gcd(key1_affine , m)==1 ){
            for (key2_affine=1 ; key2_affine<=26 ; key2_affine++){
                for (o=0;o<taille;o++){
                    char *position=strchr(A,message[o]);
                    var=position-A;
                    
                    v=A[( inverse_modulo(key1_affine , m)*(var-key2_affine) )%26];
                    message_decrypte_affine[o]=v;
                    
                    if (o==taille){
                        message_decrypte_affine[o+1]='\0';
                    }
                    
                }printf("\n%s",&message_decrypte_affine);
            }
        }
    }
}
