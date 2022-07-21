#include<stdio.h>
#include<math.h>
#define N 30






int main(){
	
	int bilx;
	int i,j,k,s;
	float katsayi[N][N];
	float a,b;



	
	printf("Matrisinizin kaca kaclik oldugunu giriniz.\n");
	scanf("%d", &bilx);
	
	for(i=0;i<bilx;i++){
		
		for(j=0;j<bilx;j++){
		
			printf("\n%d. sutunun %d. satir degerini giriniz: ", i+1, j+1);
			scanf("%f", &katsayi[i][j]);
			s=j+1;
		}
		
	}
	
	
	printf("\n\n\nGirdiginiz matris:\n\n");
	
	for(i=0;i<bilx;i++){
			
		for(j=0;j<bilx;j++){
				
			printf("%f	", katsayi[i][j]);
		}
			
		printf("\n\n");
	}
	
	for(i=0;i<bilx;i++){
		for(j=bilx;j<(bilx*2);j++){
			
			if(j != i+bilx){
			
				katsayi[i][j] = 0;
			
			}
			else{
				katsayi[i][j] = 1;
			}
		}
	}
	

	
	for(k=0;k<bilx;k++){
	
		for(i=k;i<bilx;i++){
			
			b = katsayi[i][k];
			
			if(b != 0){
				
			
				for(j=0;j<(2 * bilx);j++){

				katsayi[i][j] = katsayi[i][j] / b;

				}
			

			
				if(i != k){
				
					a = katsayi[i][k];	
					
					for(j=0;j<(2 * bilx);j++){
					
						katsayi[i][j] = katsayi[i][j] - katsayi[k][j];
	
					}
				

							
					for(j=0;j<(2 * bilx);j++){
	
						katsayi[i][j] = katsayi[i][j] * a;
		
					}
					

												
				}
			}
		}
		

	}
	
	for(k=bilx-1;k>=0;k--){
	
		for(i=k;i>=0;i--){
			
			b = katsayi[i][k];
			if(b != 0){
			
				for(j=0;j<(2 * bilx);j++){

					katsayi[i][j] = katsayi[i][j] / b;

				}
			

			
				if(i != k){
				
					a = katsayi[i][k];	
					
					for(j=0;j<(2 * bilx);j++){
					
						katsayi[i][j] = katsayi[i][j] - katsayi[k][j];
	
					}
				

							
					for(j=0;j<(2 * bilx);j++){

						katsayi[i][j] = katsayi[i][j] * a;
		
					}
					

												
				}
			}
		}
		

	}
	
	printf("Girdiginiz matrisin tersi:\n\n");
	
	for(i=0;i<bilx;i++){
			
		for(j=bilx;j<(2 * bilx);j++){
				
			printf("%f	", katsayi[i][j]);
		}
			
		printf("\n\n");
	}




	return 0;
	
}

