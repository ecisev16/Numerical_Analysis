#include<stdio.h>
#include<math.h>
#define N 10

int main(){
	
	int derece, t_derece;
	int i;
	int iterasyon_no, kontrol=0;
	float katsayi[N], turev_katsayi[N];
	float kok_x, new_x;
	float deger_x, t_deger_x;
	float epsilon, hata_payi;
	
	printf("fonksiyonuzun derecesini giriniz.\n");
	scanf("%d", &derece);
	
	for(i=0;i<=derece;i++){
		
		printf("\nfonksiyonuzun %d dereceli terimini giriniz: ", derece-i);
		scanf("%f", &katsayi[i]);
		
	}
	
	printf("\nfonksiyonuzun x degerinizi giriniz: ");
	scanf("%f", &kok_x);

	

	
	printf("\nFonksiyonuzun epsilon degerini giriniz: ");
	scanf("%f", &epsilon);
	
	for(i=0;i<=derece;i++){
	
		turev_katsayi[i] = katsayi[i] * (derece-i);
	}
		
	t_derece= derece-1;
	
	
	for(i=0;i<=derece;i++){
		printf("\nfonksiyon dereceleri: %f", katsayi[i]);
		
		
	}
	
	printf("\n\n");
	
	for(i=0;i<=t_derece;i++){
		printf("\nturevinin dereceleri: %f", turev_katsayi[i]);
		
		
	}
	
	printf("\n\n");
	
	iterasyon_no = 1;
	
	while (kontrol == 0){
		
		

		
		deger_x = 0;

		for(i=0;i<=derece;i++){
		
			deger_x = deger_x + katsayi[i] * pow(kok_x, derece-i);

		
		}
	
		printf("\n\n deger X:%f ", deger_x);
		
		t_deger_x = 0;
		
		for(i=0;i<=t_derece;i++){
		
			t_deger_x = t_deger_x + turev_katsayi[i] * pow(kok_x, t_derece-i);

		}
		
		printf("\n turev deger X:%f ", t_deger_x);
		
		new_x = kok_x - (deger_x / t_deger_x);
		
		printf("\n yeni X: %f \n kok X: %f ", new_x,kok_x);
		
		hata_payi = new_x - kok_x ;
		
		printf("\n\n hata payi %f\n\n\n", hata_payi);
		
		if(epsilon >= hata_payi){
			
			kontrol = 1;
			printf("\n			Kok= %f\n", new_x);
			printf("\nIteraston sayisi: %d\n", iterasyon_no);
			
		}
		
		kok_x = new_x;
		

		iterasyon_no++;
		
	
	}
	

	
	return 0;
}
