#include<stdio.h>
#include<stdint.h>
#include<netinet/in.h>
#include"add-nbo.h"

int main(int argc, char* argv[]){
	if(argc==3){
	FILE *fp;
	uint32_t sum=0;
	for(int i=1;i<3;i++){
		uint32_t tmp;
		fp=fopen(argv[i],"rb");
		fread(&tmp,32,1,fp);
		tmp=my_nthol(tmp);
		sum+=tmp;
		printf("%d(0x%x)",tmp,tmp);
		if(i==1)
			printf(" + ");
		else if(i==2)
			printf(" = ");
		tmp=0;
	}
	fclose(fp);
	printf("%d(0x%x)\n",sum,sum);
	}
}	
