#include<stdio.h>
#include<math.h>
#define N 30


int main(){
	
	int i,j,kontrol=0;
	int data;
	float veri[N][N], k[N];
	float kok[N];
	float deger, x, sonuc;
	
	printf("Veri sayisini giriniz.");
	scanf("%d", &data);
	
	
	for(i=0;i<data;i++){
		
		printf("\n%d. x degerinizi giriniz.", i+1);
		scanf("%f", &kok[i]);
		
		printf("\n%d. f(x) degerinizi giriniz.", i+1);
		scanf("%f", &veri[i][0]);
		
	}
	
	printf("\n\nhangi x degerine ulasmak istediginizi giriniz: ");
	scanf("%f", &x);
	
	deger = (x - kok[0])/(kok[1]-kok[0]);
	
	k[0] = 1;
	
	for(i=1;i<data;i++){
		
		k[i] = k[i-1] * ((deger-(i-1))/i);
	}
	
	j=0;
	
	
	while(kontrol == 0){
		
		for(i=0;i<data;i++){
			
			veri[i][j+1] = veri[i+1][j] - veri[i][j];
			 
		}
		
		j++;
				
		if(j == (data)){
			
			kontrol = 1;
			
		}
		
	}
	
	sonuc = 0;
	
	for(i=0;i<data;i++){
	
		sonuc = sonuc + (veri[0][i] * k[i]);
		
	}
	
	printf("\n\n			sonuc = %f", sonuc);
	
	return 0;
}
