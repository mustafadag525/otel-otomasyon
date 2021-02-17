#include <stdio.h>
#include <stdlib.h>
struct katilimci
{
    char soyisim[20];
    char isim[20];
    int kahvalti; //0=hayir 1=evet
    int aksamyemegi; // 0=hayir 1=evet
    int hotel;  //1=otel yok 2=2 yýldizli 3=3 yildizli
    int yanliz; // 0=arkadýyla 1=yanliz
};

void ikiyildizli(struct katilimci tab[4])
{
    int i;
    printf("Ýki yildizli hotelde konaklayan katilimcilar\n");
    for(i=0;i<4;i++)
    {
        if(tab[i].hotel==2)
        {
            printf("Soyad: %s, Ad : %s \n",tab[i].soyisim,tab[i].isim);
        }
    }
}

void kahvalti(struct katilimci tab[],int *nb)
{
    int i;
    *nb=0;
    for(i=0;i<4;i++)
    {
        if(tab[i].kahvalti==1)
        {
            *nb=*nb+1;
            if(tab[i].yanliz==0)
            {
                *nb=*nb+1;
            }
        }
    }
}
void fatura(struct katilimci p,int *total)
{
    *total=0;
    if(p.kahvalti==1)
        *total+=15;
    if(p.aksamyemegi==1)
        *total+=35;
    if(p.yanliz==0)
        *total*=2;
    if(p.hotel==2)
        *total+=75;
    if(p.hotel==3)
        *total+=100;
}

int main()
{
    int n;
    int m;
    struct katilimci Tablo[4]={{"boz","can",0,1,2,1},{"osman","haci",0,0,1,0},{"boze","jean",1,0,2,1},{"giy","jean",0,1,1,0}};
    ikiyildizli(Tablo);

    kahvalti(Tablo,&n);
    fatura(Tablo[2],&m);
    printf("Kahvalti yapan katilimcilar : %d \n",n);
    printf("%s soyisimli katilimci tarafindan odenen fatura: %d ",Tablo[2].soyisim,m);
    return 0;
}
