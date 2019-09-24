#include<stdio.h>
#include<stdlib.h>
#include"Table2.h"
#include"Person.h"

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
	p1 = MakePersonData(900254, "Lee", "Seoul");
	TBLInsert(&myTbl, GetSSN(p1), p1);

	p1 = MakePersonData(900139, "Kim", "Jeju");
	TBLInsert(&myTbl, GetSSN(p1), p1);

	p1 = MakePersonData(900827, "Han", "Kangwon");
	TBLInsert(&myTbl, GetSSN(p1), p1);

	// 데이터 탐색
	p2 = TBLSearch(&myTbl, 900254);
	if (p2 != NULL)
		ShowPerInfo(p2);

	p2 = TBLSearch(&myTbl, 900139);
	if (p2 != NULL)
		ShowPerInfo(p2);

	p2 = TBLSearch(&myTbl, 900827);
	if (p2 != NULL)
		ShowPerInfo(p2);

	// 데이터 삭제
	p3 = TBLDelete(&myTbl, 900254);
	if (p3 != NULL)
		free(p3);

	p3 = TBLDelete(&myTbl, 900139);
	if (p3 != NULL)
		free(p3);

	p3 = TBLDelete(&myTbl, 900827);
	if (p3 != NULL)
		free(p3);

	return 0;
}
