#ifndef _SHMDATA_H_HEADER
#define _SHMDATA_H_HEADER

#define TEXT_SZ 2048
struct shared_use_st
{
	int writeten;//0�� 1д
	char text[TEXT_SZ]; //�����д��Ļ���
};

#endif
