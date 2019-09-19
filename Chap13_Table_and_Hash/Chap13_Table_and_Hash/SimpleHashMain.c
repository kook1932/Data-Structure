#include<stdio.h>
#include<stdlib.h>
#include"Person.h"
#include"Table.h"

int MyHashFunc(int k)
{
	return k % 100;
}

int main(void)
{
	Table myTbl;
	Person * p1;
	Person * p2;
	Person * p3;

	TBLInit(&myTbl, MyHashFunc);

	// 데이터 입력
	p1 = MakePersonData(20120003, "Lee", "Seoul");
	TBLInsert(&myTbl, GetSSN(p1), p1);

	p1 = MakePersonData(20130012, "Kim", "Jeju");
	TBLInsert(&myTbl, GetSSN(p1), p1);

	p1 = MakePersonData(20170049, "Han", "Kangwon");
	TBLInsert(&myTbl, GetSSN(p1), p1);

	// 데이터 탐색
	p2 = TBLSearch(&myTbl, 20120003);
	if (p2 != NULL)
		ShowPerInfo(p2);

	p2 = TBLSearch(&myTbl, 20130012);
	if (p2 != NULL)
		ShowPerInfo(p2);

	p2 = TBLSearch(&myTbl, 20170049);
	if (p2 != NULL)
		ShowPerInfo(p2);

	// 데이터 삭제
	p3 = TBLDelete(&myTbl, 20120003);
	if (p3 != NULL)
		free(p3);

	p3 = TBLDelete(&myTbl, 20130012);
	if (p3 != NULL)
		free(p3);

	p3 = TBLDelete(&myTbl, 20170049);
	if (p3 != NULL)
		free(p3);
	
	return 0;
}