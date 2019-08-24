
#include <iostream>
using namespace std;

#include "CEncDesProtocol.h"  //包含加密协议头文件


//实现所有虚函数的实现
class HwEncDec : public CEncDesProtocol
{
public:
	virtual int EncData(unsigned char *plain, int plainlen, unsigned char *cryptdata, int *cryptlen);
	virtual int DecData(unsigned char *cryptdata, int cryptlen, unsigned char *plain, int *plainlen);
};

