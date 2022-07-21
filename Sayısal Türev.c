#include<stdio.h>
#include<math.h>
#define N 10

int main(){
	
	int derece;
	int i;
	int yontem;
	float katsayi[N];
	float x, next_x;
	float deger_1, deger_2;
	float deltax;
	float sonuc;
	
	printf("fonksiyonuzun derecesini giriniz.\n");
	scanf("%d", &derece);
	
	for(i=0;i<=derece;i++){
		
		printf("\nfonksiyonuzun %d dereceli terimini giriniz: ", derece-i);
		scanf("%f", &katsayi[i]);
		
	}
	
	printf("\nfonksiyonuzun x degerinizi giriniz: ");
	scanf("%f", &x);

	
	
	
	printf("\nFonksiyonunuzun delta x i giriniz: ");
	scanf("%f", &deltax);

	
	
	printf("\n\nHangi yontemi kullanmak istediginizi giriniz: \n\n ileri fark icin : 1 \n geri fark icin : 2 \n merkezi fark icin : 3 \n\n");
	scanf("%d", &yontem);
	
	while((yontem != 1)&& (yontem != 2)&& (yontem != 3)){
		printf("hata, gecerli bir sayi giriniz.");
		scanf("%d", &yontem);
	}
	
	
	if (yontem==1){
	
	next_x = x + deltax;
	
	}
	else {
		if(yontem==2){
		
		next_x = x;
		x = x - deltax ; 
		
		}
		else {
			if(yontem==3){
				
				next_x = x + deltax;
				x = x - deltax ;
				deltax = deltax + deltax;
				
			}
		}
	}
	
	
	
	deger_1=0;
	for(i=0;i<derece;i++){
		
		deger_1= deger_1 + katsayi[i]*pow(x,derece-i);
			
		
			
	}
	
	deger_2=0;
	for(i=0;i<derece;i++){
	
		deger_2= deger_2 + katsayi[i]*pow((next_x),derece-i);
			
		
	}
	
	sonuc=(deger_2 - deger_1)/deltax;	
	
	printf("sonuc: %f", sonuc);
		

	
	return 0;
}
