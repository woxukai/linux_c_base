#ifndef _SHMDATA_H_HEADER
#define _SHMDATA_H_HEADER

#define TEXT_SZ 2048
struct shared_use_st
{
	int writeten;//0读 1写
	char text[TEXT_SZ]; //读入和写入的缓存
};

#endif
