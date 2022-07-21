#include<stdio.h>
#include<math.h>
#define N 10

int main(){
	
	int derece;
	int i;
	int iterasyon_no, kontrol=0;
	float katsayi[N];
	float kok_1, kok_2, kok_c;
	float deger_1, deger_2, deger_c;
	float epsilon, hata_payi;
	
	printf("fonksiyonuzun derecesini giriniz.\n");
	scanf("%d", &derece);
	
	for(i=0;i<=derece;i++){
		
		printf("\nfonksiyonuzun %d dereceli terimini giriniz: ", derece-i);
		scanf("%f", &katsayi[i]);
		
	}
	
	printf("\nfonksiyonuzun kok araligini giriniz: \n");
	scanf("%f", &kok_1);
	scanf("%f", &kok_2);
	
	deger_1=0;
	deger_2=0;
	
	for(i=0;i<=derece;i++){
		
		deger_1 = deger_1 + katsayi[i] * pow(kok_1, derece-i);
		deger_2 = deger_2 + katsayi[i] * pow(kok_2, derece-i);
		
	}
	

	
	while ((deger_1 * deger_2) > 0){
		
		printf("Kokler gecersiz. Fonksiyonuzun kok araligini giriniz: \n");
		scanf("%f", &kok_1);
		scanf("%f", &kok_2);
		
		deger_1=0;
		deger_2=0;
	
		for(i=0;i<=derece;i++){
		
			deger_1 = deger_1 + katsayi[i] * pow(kok_1, derece-i);
			deger_2 = deger_2 + katsayi[i] * pow(kok_2, derece-i);
		
		}
		

		
	}
	
	printf("\n\nFonksiyonuzun epsilon degerini giriniz: ");
	scanf("%f", &epsilon);
	
	iterasyon_no = 1;
	
	while (kontrol == 0){
		
		
		
		if ((deger_1==0)&& (deger_2==0)){
			
			for(i=0;i<=derece;i++){
		
			deger_1 = deger_1 + katsayi[i] * pow(kok_1, derece-i);
			deger_2 = deger_2 + katsayi[i] * pow(kok_2, derece-i);
		
			}
		}
		
		printf("\n deger 1:%f \n deger 2:%f \n", deger_1, deger_2);		
		
		hata_payi = fabs(kok_2 - kok_1) / pow(2, iterasyon_no);
		printf("\n            hata payi: %f \n\n", hata_payi);
	
		
		
		kok_c = ((kok_2*deger_1)-(kok_1*deger_2)) / (deger_1 - deger_2);
		printf("\n kok C: %f\n", kok_c);
		
		if(epsilon >= hata_payi){
			
			printf("\n\n                            Kok= %f", kok_c);
			kontrol = 1;
			printf("\n iterasyon sayisi: %d", iterasyon_no);
		}
		else{
			
			deger_c = 0;
			
			for(i=0;i<=derece;i++){
		
				deger_c = deger_c + katsayi[i] * pow(kok_c, derece-i);


			}
			printf("\n deger C: %f ", deger_c);
			
			if(deger_c * deger_1 < 0){
				
				kok_2 = kok_c;
				
			}
			else{
				
				kok_1 = kok_c;
				
			}
			
			iterasyon_no++;
			deger_1 = 0;
			deger_2 = 0;

			
		}

	
	}
	
	
	return 0;
}
