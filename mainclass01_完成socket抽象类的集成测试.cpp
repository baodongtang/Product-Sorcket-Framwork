#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

#include "CSocketProtocol.h"
#include "CSckFactoryImp1.h"
#include "CSckFactoryImp2.h"

//面向抽象类编程,框架实现完毕  发送接收报文
int SckSendAndRec01(CSocketProtocol *sp, unsigned char *in, int inlen, unsigned char *out, int *outlen)
{
	int ret = 0;
	ret = sp->cltSocketInit();
	if (ret != 0)  
	{
		goto End;
	}

	ret = sp->cltSocketSend(in, inlen);
	if (ret != 0)
	{
		goto End;
	}
	
	ret = sp->cltSocketRev(out, outlen);
	if (ret != 0)
	{
		goto End;
	}
	//统一释放资源
End:
	ret = sp->cltSocketDestory(); 
	return 0;
}

//写一个框架
int main011()
{
	int ret = 0;
	unsigned char in[4096];  //主调函数分配内存
	int inlen;
	unsigned char out[4096];
	int outlen = 0;

	strcpy((char *)in, "aadddddddddddaaaaaaaaaaa");
	inlen = 9;


	CSocketProtocol *sp = NULL;  //基类指针
	sp = new CSckFactoryImp1

	//sp = new CSckFactoryImp2; //

	ret = SckSendAndRec01(sp, in, inlen, out, &outlen); //发送的内容

	if (ret != 0)
	{
		printf("func SckSendAndRec() err:%d \n", ret);
		return ret;
	}
	delete sp; //想通过父类指针 释放所有的子类对象的资源 ..

	cout<<"hello..."<<endl;
	system("pause");
	return ret;
}