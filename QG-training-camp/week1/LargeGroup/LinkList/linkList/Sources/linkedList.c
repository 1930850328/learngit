#include <stdio.h>
#include "linkedList.h"
#include <stdlib.h>
#include<string.h>

void show(void)
{
    printf("\n\n\n\t\t\t***************������ADT***************\n");
    printf("\t\t\t---------------------------------------\n");
    printf("\t\t\t-------------1.����������--------------\n");
    printf("\t\t\t--------------2.��������--------------\n");
    printf("\t\t\t--------------3.������--------------\n");
    printf("\t\t\t--------------4.ɾ�����--------------\n");
    printf("\t\t\t--------------5.��������--------------\n");
    printf("\t\t\t--------------6.��������--------------\n");
    printf("\t\t\t--------------7.��ת����--------------\n");
    printf("\t\t\t---------8.�ж������Ƿ�ɻ�-----------\n");
    printf("\t\t\t--------9.��ת�����е�ż�����--------\n");
    printf("\t\t\t-----------10.�����м���------------\n");
    printf("\t\t\t---------------11.�˳�----------------\n");
    printf("\t\t\t--------------------------------------\n");
    printf("\t\t\t**************************************\n");
    printf("\t\t\t�������Ӧ������(1-11)��");
}

Status InitList(LinkedList *L)
{
    LinkedList list;                          //����ͷ�ڵ�
    list = (LinkedList)malloc(sizeof(LNode)); //�����ڴ�
    if (list == NULL)						//����ʧ�� 
    {
        printf("�ڴ�δ�ܷ���");
        return ERROR;
    }
    list->next = NULL;
    *L = list;
    return SUCCESS;
}

void DestroyList(LinkedList *L)
{
    LinkedList t;						
    while(*L != NULL)
    {
        t = *L;						//���ڵ�һ��һ������t�ͷ� 
       (*L) =(*L)->next;
        free(t);
    }
}

Status InsertList(LNode *p, LNode *q)
{
    LinkedList left = p;			//������һ���ڵ��������� 
    LinkedList right = q;			
    
    while (left->next!=NULL)
    {
        left = left->next;
    }
    left->next = right;				//�����½ڵ� 
    return SUCCESS;
}

Status DeleteList(LNode *p, ElemType *e)
{
    LinkedList right = p->next;			//��Ҫ��ɾ���ڵ� 
    LinkedList left = p;				//��ɾ�ڵ��ǰһ���ڵ� 
    if (right == NULL)
    {
        printf("����Ϊ�գ��޷�ɾ��\n");
    }
    else
    {
        while (left->data != *e)		//�����ҵ���ɾ���ǰһ���ڵ�
        {
            left = right;
            right = right->next;
            if (right == NULL)
            {
                printf("û�и�����\n");
                return ERROR;
            }
        }
        *e = right->data;				//��¼��ɾ�ڵ����ݸ�������ʾ 
        left->next = right->next;
        free(right);					//�ͷű�ɾ�ڵ� 
        return SUCCESS;
    }
}

void TraverseList(LinkedList L, void (*visit)(ElemType e))//��Ȼ��ҪΪprintf��һ������ָ�룬ʦ��ʦ��������̫�Ͻ��� 
{
    LinkedList t;
    t = L->next;
    while (t != NULL)
    {
        visit(t->data);										//��������� 
        t = t->next;
    }
    printf("\n");
}

void print(ElemType e)									//һ�������۵�������� 
{
    printf("%d\t", e);
}

Status SearchList(LinkedList L, ElemType e)				//���Һ��� 
{
    LinkedList s;
    s = L->next;
    while (s != NULL)
    {
        if (s->data == e)
            return SUCCESS;
        s = s->next;
    }
    return ERROR;
}

Status ReverseList(LinkedList *L)						// ��ת��������������ѧϰ�����ϵ�ͷ�巨�������Һþ������� http://c.biancheng.net/view/8105.html 
{
    LNode *newHead; //����ÿ�η�ת��ĵ�һ���ڵ�
    LNode *left;    //ÿ�ζ�ָ��ǰһ���ڵ�
    LNode *right;   // ����δ��תǰ����һ���ڵ�
    left = (*L)->next;
    right = left->next;
    left->next = NULL;
    newHead = left;
    while (right != NULL)
    {
        left = right;
        right = left->next;
        left->next = newHead;
        newHead = left;
    }
    (*L)->next = newHead;
}

Status IsLoopList(LinkedList L)							//ʦ�������ʵ������� get������ָ������� 
{
    LinkedList fast = L, slow = L;
    while (fast->next != NULL && slow->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == NULL)
            return ERROR;
        if (fast == slow)
            return SUCCESS;
    }
    return ERROR;
}

LNode *ReverseEvenList(LinkedList *L)					// ����ż���ڵ㽻�� 
{
LNode *p1,*p2,*p,*count,*first;
int a,x=0;
p1=(*L);
first=(*L);
count=(*L);												//count�������� 
p2=(*L)->next;

while(count!=NULL){
	count=count->next;
	x++;
}														//x��¼�ж��ٸ��ڵ� 
p=p1;
for(a=1;a<=x/2;a++)										//�������� 
{
	p1=p->next;
	p2=p1->next;
	
	p->next=p2;
	p1->next=p2->next;
	p2->next=p1;
	 
    p=p1;
}
return first;										//����ͷ��� 
}

LNode *FindMidNode(LinkedList *L)					//����Ҳ�����ÿ���ָ����ɣ���лʦ�����Ե����ʣ����� 
{	
    LinkedList fast = (*L), slow = (*L);
    while (fast->next != NULL)
    {
        slow = slow->next;								//��ָ����һ�� 
        fast = fast->next->next;						//��ָ�������� 
        if (fast == slow)
        {
            printf("������ɻ����м�ڵ�\n");
        }
    }
    return slow;
}

int judge_int(void) 										//��ֹʦ���������� 
{
    int len, num = 0, arg = 1;
    char word[10];
    int m, j = 1, k;
    while (j)
    {
        scanf("%s", word);
        len = strlen(word);
        for (m = 0; m < len; m++)
        {
            if (word[m] < '0' || word[m] > '9') 		//�����Ƿ��������������ַ�
            {
                printf("������������");
                break;
            }
            else
            {
                if (m == len - 1)
                    j = 0;
            }
        }
    }
    return num;
}

int main()							//������ 
{

    ElemType choice, n = 0;
    LinkedList head = NULL;

    do
    {
        show();						//���� 
        choice = judge_int();
        system("cls");
        switch (choice)
        {
        case 1: //����������
        {
            if (InitList(&head))
            {
                printf("���������ɹ�\n");
            }
            else
            {
                printf("��������ʧ��\n");
            }
            break;
        }
        case 2: //��������
        {
            DestroyList(&head);
            printf("�����������\n");
            break;
        }
        case 3: //��������
        {
            if (head == NULL)
            {
                printf("����Ϊ�գ� ���ȴ�������\n");
            }
            else
            {
            	int n;
            	LinkedList q;
              printf("���������ݣ�");
                	scanf("%d", &n);
                	q = (LinkedList)malloc(sizeof(LNode));
                	if (q == NULL)
                	{
                    printf("�ڴ�δ�ܳɹ�����");
                    return ERROR;
               		}
                	q->data = n;
                	q->next = NULL;
               		 if (InsertList(head, q))
                	{
                    printf("���ݲ���ɹ�\n");
               		}
                	else
                	{
                    printf("���ݲ���ʧ��\n");
               		}
				
			}
            break;
        }
        case 4: //ɾ������
        {
            printf("��������Ҫɾ����ڵ��ǰ�ڵ����ݣ�");
            scanf("%d", &n);
            ElemType *e;
            e = &n;
            if (DeleteList(head, e))
            {
                printf("�ɹ�ɾ��%d�������\n", *e);
            }
            else
            {
                printf("����ɾ��ʧ��\n");
            }
            break;
        }
        case 5: //��������
        {
            if (head == NULL || head->next == NULL)
            {
                printf("�������ڻ���ֻ����һ���յ�ͷ���\n");
            }
            else
            {
                TraverseList(head, print);
            }
            break;
        }
        case 6: //��������
        {
            printf("��������Ҫ���ҵ����ݣ�");
            scanf("%d", &n);
            if (SearchList(head, n))
            {
                printf("��������\n");
            }
            else
            {
                printf("����������\n");
            }
            break;
        }
        case 7: //��ת����
        {
            if (head == NULL || head->next == NULL)
            {
                printf("����Ϊ�ջ�������ֻ�����������\n");
                printf("����תʧ��\n");
            }
            else
            {
                if (ReverseList(&head))
                {
                    printf("����ת�ɹ�\n");
                }
                else
                {
                    printf("����תʧ��\n");
                }
            }
            break;
        }
        case 8: //�ж������Ƿ�ɻ�
        {
            if (head == NULL || head->next == NULL)
            {
                printf("����Ϊ��\n");
            }
            else
            {
                if (IsLoopList(head))
                {
                    printf("����ɻ�\n");
                }
                else
                {
                    printf("����û�гɻ�\n");
                }
            }
            break;
        }
        case 9: //��ת�����е�ż�����
        {
            if (head == NULL || head->next == NULL)
            {
                printf("����Ϊ��\n");
            }
            else
            {
                TraverseList(ReverseEvenList(&head), print);
            }
            break;
        }
        case 10: //�����м���
        {
            if (head == NULL || head->next == NULL)
            {
                printf("���ǿ�����\n");
            }
            else
            {
                printf("�����м䴢���ֵΪ%d\n", (FindMidNode(&head))->data);
            }
            break;
        }
        case 11: //�˳����� 
        {
            DestroyList(&head);
            break;
        }
        default:
        {
            printf("�������������֣�(1-11)\n");
            break;
        }
        }
    } while (choice != 11);

    return 0;
}
