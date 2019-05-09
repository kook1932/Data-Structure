// ����04-1
// ���Ḯ��Ʈ�� ��尡 ������ �߰��ϴ� ���� �ƴ�, �Ӹ��� �߰��ǵ��� �Ѵ�.
#include<stdio.h>
#include<stdlib.h>

typedef struct _node
{
	int data;
	struct _node * next;
} Node;

int main(void)
{
	Node * head = NULL;
	Node * tail = NULL;
	Node * cur = NULL;

	Node * newNode = NULL;
	int readData;

	// �����͸� �Է� �޴� ����
	while (1)
	{
		printf("�ڿ��� �Է� :");
		scanf_s("%d", &readData);
		if (readData < 1)
			break;

		// ����� �߰�����
		newNode = (Node*)malloc(sizeof(Node));
		newNode->data = readData;
		newNode->next = NULL;

		if (tail == NULL)
			tail = newNode;
		else
			newNode->next = head;

		head = newNode;
	}
	printf("\n");

	// �Է� ���� ������ ��°���
	printf("�Է� ���� �������� ��ü���! \n");
	if (head == NULL)
		printf("����� �ڿ����� �������� �ʽ��ϴ�.");
	else
	{
		cur = head;
		printf("%d ", cur->data);

		while (cur->next != NULL)
		{
			cur = cur->next;
			printf("%d ", cur->data);
		}
	}
	printf("\n");

	// �޸� ��������
	if (head == NULL)
	{
		return 0;		// ������ ��尡 �������� �ʴ´�.
	}
	else
	{
		Node * delNode = head;
		Node * delNextNode = head->next;

		printf("%d��(��) �����մϴ�. \n", head->data);
		free(delNode);		// ù ��° ��� ����

		while (delNextNode != NULL)
		{
			delNode = delNextNode;
			delNextNode = delNextNode->next;
			printf("%d��(��) �����մϴ�. \n", delNode->data);
			free(delNode);
		}
	}
	return 0;
}