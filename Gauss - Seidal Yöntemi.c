#include<stdio.h>
#include<math.h>
#define N 10

int main(){
	
	int bilx;
	int i,j,s;
	int max_yer[N];
	int iterasyon;
	int kontrol = 0;
	float katsayi[N][N], new_line[N][N], kok[N], eski_kok[N];
	float max;
	float deger1;
	float hata_payi[N];
	float epsilon;

	printf("Denkleminizin bilinmeyen sayisini giriniz.\n");
	scanf("%d", &bilx);
	
	for(i=0;i<bilx;i++){
		
		for(j=0;j<bilx;j++){
		
			printf("\n%d. Denkleminizin %d. bilinmeyeninin kat sayisini giriniz: ", i+1, j+1);
			scanf("%f", &katsayi[i][j]);
			s=j+1;
		}
		printf("\n%d. Denkleminizin sonucunu giriniz: ", i+1);
		scanf("%f", &katsayi[i][s]);
		katsayi[i][s] = katsayi[i][s] * -1;
		printf("\n");
		
	}
	
	for(i=0;i<bilx;i++){
		printf("%d.kok deger1lerini giriniz: ", i+1);
		scanf("%f", &kok[i]);
	}
	
	printf("\n\nFonksiyonuzun epsilon deger1ini giriniz: ");
	scanf("%f", &epsilon);
	
	kok[bilx]=1;
	
	printf("\nDenkleminizin matrisi: \n\n");	
	
	for (i=0;i<bilx;i++){
		
		for(j=0;j<bilx;j++){
			
			printf("%f	", katsayi[i][j]);
			s=j+1;
		}
		printf("		%f", -katsayi[i][s]);
		printf("\n");
	}


	
	for(i=0;i<bilx;i++){
		
		max_yer[i] = 0;
		
	}
	
	for (i=0;i<bilx;i++){
		
		max = 0;
		
		for(j=0;j<bilx;j++){
			
			if(abs(katsayi[i][j])>=max){
				
				max = abs(katsayi[i][j]);
				max_yer[i] = j;
				
			}
		}
	}
	
	printf("\nDenklemde mutlak deger1ce en buyuk katsayilarin satir yerleri: \n");
	for(i=0;i<bilx;i++){
		
		printf("%d		", max_yer[i]);
		
	}
	
	printf("\n\n");
	
	for (i=0;i<bilx;i++){
		
		for(j=0;j<bilx;j++){
			
			new_line[max_yer[i]][j] = katsayi [i][j];
			
		}
		
		new_line[max_yer[i]][bilx] = katsayi[i][bilx];
		 
	}
	
	printf("\nDenkleminizin guncel matrisi: \n\n");	
	
	for (i=0;i<bilx;i++){
		
		for(j=0;j<bilx;j++){
			
			printf("%f	", new_line[i][j]);
			s=j+1;
		}
		printf("		%f", -new_line[i][s]);
		printf("\n");
	}
	
	while(kontrol != 3){
		
		kontrol=0;
		
		for(i=0;i<bilx;i++){
			eski_kok[i] = kok[i];
		}
	
	
		for(i=0;i<bilx;i++){
		
			deger1=0;
		
			for(j=0;j<=bilx;j++){
			
				if(i!=j){
				
					deger1 = deger1 + (kok[j] * new_line[i][j] * -1);
				
				}
			
			}
			
			kok[i] = deger1 / new_line[i][i];
			printf("\n kok%d:%f", i+1, kok[i]);
			
			
		}
		
		for(i=0;i<bilx;i++){
			
			hata_payi[i] = kok[i] - eski_kok[i];
			if(hata_payi[i] < 0){
				hata_payi[i] = hata_payi[i] * -1;  
			}
			
		}
		
		for(i=0;i<bilx;i++){
			
			if(epsilon >= hata_payi[i]){
			
				kontrol++;
			
			}
		}
		
		iterasyon++;
		printf("\niterasyon %d", iterasyon);
		
	}
	
	return 0;
}
