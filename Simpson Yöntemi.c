#include<stdio.h>
#include<math.h>
#define N 10

int main(){
	
	int derece;
	int i, j;
	int n;
	float katsayi[N];
	float kok_1, kok_2;
	float deger_1, deger_2, deger;
	float h, toplam_c4, toplam_c2, sonuc;

	
	printf("fonksiyonuzun derecesini giriniz: \n");
	scanf("%d", &derece);
	
	for(i=0;i<=derece;i++){
		
		printf("\nfonksiyonuzun %d dereceli terimini giriniz: ", derece-i);
		scanf("%f", &katsayi[i]);
		
	}
	
	printf("\nfonksiyonuzun kok araligini giriniz: \n");
	scanf("%f", &kok_1);
	scanf("%f", &kok_2);
	
	printf("\nkac tane parabol kullanilacagini giriniz: ");
	scanf("%d", &n);
	
	deger_1=0;
	deger_2=0;
	
	for(i=0;i<=derece;i++){
		
		deger_1 = deger_1 + katsayi[i] * pow(kok_1, derece-i);
		deger_2 = deger_2 + katsayi[i] * pow(kok_2, derece-i);
		
	}
	
	if(deger_1 < 0){
			
		deger_1 = deger_1 * -1;
	}	

	if(deger_2 < 0){
			
		deger_2 = deger_2 * -1;
	}
	
			
	h = (kok_2 - kok_1) / n;
	
	toplam_c4 = 0;
	
	for(i=1;i<n;i=i+2){
		
		deger=0;
		
		for(j=0;j<=derece;j++){
		
			deger = deger + katsayi[j] * pow(kok_1+(h*i), derece-j);
		
		}
		
		if(deger < 0){
			
			deger = deger * -1;
		}	
		
		toplam_c4 = toplam_c4 + deger;

		
	}
	
	toplam_c2 = 0;
	
	for(i=2;i<n-1;i=i+2){
		
		deger=0;
		
		for(j=0;j<=derece;j++){
		
			deger = deger + katsayi[j] * pow(kok_1+(h*i), derece-j);
		
		}	
		
		if(deger < 0){
			
			deger = deger * -1;
		}	
		
		toplam_c2 = toplam_c2 + deger;

		
	}
	
	sonuc = (h/3) * ((deger_1 + deger_2) + (4 * toplam_c4) + (2 * toplam_c2));
	
	printf("Sonuc = %f", sonuc);
	
	

	
	return 0;
}
