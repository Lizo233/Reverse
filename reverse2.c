#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int arg_index,char *args[]) {

	if (arg_index<2) {printf("too few argument");exit(0);}//参数不足
	printf("file name = %s \n",args[1]);//回显文件名

	FILE *a=fopen(args[1],"rb+");//以二进制读写方式打开文件
	fseek(a,0,SEEK_END);
	int size=ftell(a);//获取文件大小
	printf("size:%d \n",size);//回显文件大小

	char *buff=malloc(size-1);//实际上分配了size个字节的内存
	char newfile[256];

	strcpy(newfile,args[1]);
	strcat(newfile,".r");//加上后缀

	fseek(a,0,SEEK_SET);
	fread(buff,1,size,a);//将文件读取到缓冲区

	buff[size] = '\0';
	printf("%s",buff);//输出文件原本内容

	FILE *b=fopen(newfile,"wb+");
	if (b == NULL) { printf("unable to open new file"); return -1; }

	char *revbuff=malloc(size-1);//实际上分配了size个字节的内存

	for (int i=0;i<size;i++) {
		revbuff[i] = buff[(size - 1) - i];
	}
	fwrite(revbuff,1,size,b);

	return 0;
}
// author:Lizo
