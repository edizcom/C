#include <stdio.h>

int main(void) {

    int klingon;
    
    printf("ml' nob:\n");
////////////Gifts:

    scanf("%d", &klingon);
    
    switch (klingon)
    {
        case 1:
		  printf("Qapla'\n");	        
          printf("%s","noH QapmeH wo' Qaw'lu'chugh yay chavbe'lu' 'ej wo' choqmeH may' DoHlu'chugh lujbe'lu'.\n");
          break;
//////////Success To win a victory for victory, and there is enough to pass a battle off the battle for it.
    
        case 2:
          printf("Qapla'\n");	
          printf("%s","Qu' buSHa'chugh SuvwI', batlhHa' vangchugh, qoj matlhHa'chugh, pagh ghaH SuvwI''e'.\n");
          break;
//////////Success If a warrior does not ignore himself, if he be not dishonored, or she's not a warrior.
        case 3:
          printf("Qapla'\n");	
          printf("%s","qaStaHvIS wa' ram loS SaD Hugh SIjlaH qetbogh loD.\n");
          break;
//////////Success Four thousand throats may be cut in one night by a running man.
        case 4:
          printf("Qapla'\n");	
          printf("%s","Ha'DIbaH DaSop 'e' DaHechbe'chugh yIHoHQo'.\n");
          break;
//////////Success Do not kill an animal unless you intend to eat it.
        case 5:
          printf("Qapla'\n");	
          printf("%s","leghlaHchu'be'chugh mIn lo'laHbe' taj jej.\n");
          break;
//////////Success A sharp knife is nothing without a sharp eye.
       
        default:
        printf("%s","luj\n");
////////////////////////lose
    }
    
    return 0;
}
