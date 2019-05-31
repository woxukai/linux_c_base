#include "soapH.h"
#include "calc.nsmap"                           /* 与add.h的第一行命名空间(ns)有关 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int add (const char *server, int num1, int num2, int *sum);

int
main (int argc, char **argv)
{
  int result = -1;
  char *server = "http://localhost:4567";       /* 定义server */
  int num1 = 0;
  int num2 = 0;
  int sum = 0;
  if (argc < 3)                                 /* 判断传入参数 */
    {
      printf ("usage: %s num1 num2 \n", argv[0]);
      exit (0);
    }
  num1 = atoi (argv[1]);
  num2 = atoi (argv[2]);
  result = add (server, num1, num2, &sum);      /* 执行add() */
  if (result != 0)                              /* 输出result */
    {
      printf ("soap err,errcode = %d\n", result);
    }
  else
    {
      printf ("%d+%d=%d\n", num1, num2, sum);
    }
  return 0;
}

int
add (const char *server, int num1, int num2, int *sum)
{
  struct soap add_soap;                         /* 创建add_soap()结构体 */
  int result = 0;
  soap_init (&add_soap);                        /* soap_init()*/
  soap_call_ns__add (&add_soap, server, "", num1, num2, sum); /* 调用soap_call_ns_add() */
  if (add_soap.error)
    {
      printf ("soap error:%d,%s,%s\n", add_soap.error,
          *soap_faultcode (&add_soap), *soap_faultstring (&add_soap));
      result = add_soap.error;
    }
  soap_end (&add_soap);                         /* 释放内存空间 */
  soap_done (&add_soap);
  return result;
}
