#include <stdio.h>

void main(int arg_index,char *args[]) {
	if (arg_index<2) {printf("too few argument,ÇëÊäÈë²ÎÊý");exit(0);}
	printf("file name = %s \n",args[1]);
	FILE *a=fopen(args[1],"rb+");
	fseek(a,0,SEEK_END);
	int size=ftell(a);
	printf("size:%d \n",size);
	char *buff=calloc(size+1,1);
	char *newfile=calloc(256,1);
	strcpy(newfile,args[1]);
	strcat(newfile,".rev");
	fseek(a,0,SEEK_SET);
	fread(buff,1,size,a);
	printf("%s",buff);
	FILE *b=fopen(newfile,"wb+");
	char *revbuff=calloc(size+1,1);
	int c=0;
	for (c=0;c<=size;c++) {
		revbuff[c]=buff[size-c-1];
	}
	fwrite(revbuff,1,size,b);
}
// author:Lizo
