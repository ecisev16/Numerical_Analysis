#include<stdio.h>
#include<math.h>
#define N 10

int main(){
	
	int bilx;
	int i,j,k,s;
	float katsayi[N][N], kok[i];
	float a,b;
	float deger;


	
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
		printf("\n");
		
	}
	
	printf("\nDenkleminizin matrisi: \n\n");
	
	for(i=0;i<bilx;i++){
			
		for(j=0;j<=bilx;j++){
				
			printf("%f	", katsayi[i][j]);
		}
			
		printf("\n\n");
	}
	
	for(k=0;k<bilx;k++){
	
		for(i=k;i<bilx;i++){
			
			b = katsayi[i][k];
			
			if(b != 0){
			
			for(j=0;j<=bilx;j++){

				katsayi[i][j] = katsayi[i][j] / b;

			}
			

			
			if(i != k){
				
				a = katsayi[i][k];	
					
				for(j=0;j<=bilx;j++){
					
					katsayi[i][j] = katsayi[i][j] - katsayi[k][j];
	
				}
				
							
				for(j=0;j<=bilx;j++){

					katsayi[i][j] = katsayi[i][j] * a;
		
				}
					
												
			}
			}
			
		}
		

		printf("\n\n");
	}
	
	for(i=0;i<bilx;i++){
		
		katsayi[i][bilx] = katsayi[i][bilx] * -1; 
	}
	
	for(i=0;i<=bilx;i++){
		
		kok[i] = 1;
	}
	
	

	for(i=bilx-1;i>=0;i--){
		
		deger=0;
		
		for(j=bilx;j>=0;j--){
			
			if(i!=j){
				
				deger = deger + (kok[j] * katsayi[i][j] * -1);
				
			}
			
		}
			
		kok[i] = deger;

			
			
	}
	
	printf("Denkleminizin ust ucgen matrisi: \n\n");
	
	for(i=0;i<bilx;i++){
			
		for(j=0;j<=bilx;j++){
				
			printf("%f	", katsayi[i][j]);
		}
			
		printf("\n\n");
	}	
	
	for(i=0;i<bilx;i++){
		
		printf("\n kok%d:%f", i+1, kok[i]);
	}


	return 0;
}
