#include <stdio.h>
#include "duLinkedList.h"
#include <stdlib.h>
#include <string.h>

void show(void)
{
	printf("\n\n\n\n\t\t\t***************˫������ADT**************\n");
	printf("\t\t\t---------------------------------------\n");
    printf("\t\t\t-------------1.����������--------------\n");
    printf("\t\t\t-------------2.��������-------------\n");
    printf("\t\t\t---------3.�������ݵ�ĳһ�ڵ�ǰ--------\n");
    printf("\t\t\t---------4.�������ݵ�ĳһ�ڵ��--------\n");
    printf("\t\t\t-------------5.��������---------------\n");
    printf("\t\t\t-------------6.ɾ��ĳһ�ڵ�-----------\n");
    printf("\t\t\t--------------7.�˳�------------------\n");
    printf("\t\t\t---------------------------------------\n");
    printf("\t\t\t***************************************\n");
    printf("\t\t\t�������Ӧ������(1-7)��");
}



Status InitList_DuL(DuLinkedList *L)					//���������� 
{
	 DuLinkedList p;
	p=(DuLinkedList)malloc(sizeof(DuLNode));
	if(!p)	
	{
	printf("�ڴ�δ�ܳɹ�����\n");
	return ERROR;
	}
	p->next=NULL;
	p->prior=NULL;

	*L=p ;
	return SUCCESS;
}


void DestroyList_DuL(DuLinkedList *L)					//�������� 
{
	DuLinkedList p;
	while(!*L) 
	{
		p=(*L);
		(*L)=(*L)->next;								//���ݣ��ͷ� 
		free(p);
	}
}


Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q)				//��һ���ڵ�ǰ����ڵ� 
{
DuLinkedList p1=q;
if(p->next == NULL)												//�����ǿ����� 
    {
        p->next = q;
        q->prior = p;
    }
    else														//������Ǿ��ҵ��Ǹ�Ҫ��ڵ� 
    {
    	while(p->data != p1->data)
    {
        p = p->next;    
    }
        printf("��������Ҫ���������\n");						//�ٲ��룬�ȶϿ��������� 
   		scanf("%d",&p1->data);
        p1= p->next;
        p->next = q;
        q->next = p1;
        p1->prior = q;
        q->prior = p;
        return SUCCESS;
    }

}


Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)				//��һ���ڵ�����ڵ�
{
DuLinkedList p1=q;												//�����ǿ����� 
if(p->next == NULL)
    {
        p->next = q;
        q->prior = p;
    } 
	else														//������ǿ�������ҵ��Ǹ��ڵ� 
	{
	while(p->data != p1->data)
    {
        p = p->next;    
    }
    printf("��������Ҫ���������\n");
    scanf("%d",&p1->data);										//�������ԭ���� 
    if(p->next==NULL)											//���������һ���ڵ���� 
    {
    	p->next = p1;
    p1->prior = p;
	}
    else														//�м���� 
	{
	p1->next=p->next;
	p1->prior=p; 
    p->next = p1;
    p1->next->prior = p1;}
	}	
}


Status DeleteList_DuL(DuLNode *p, ElemType *e)					//ɾ��һ���ڵ� 
{
if(p->next == NULL)												//�����ǿ����� 
    {
        printf("����Ϊ�գ��޷�ɾ��\n");
        return ERROR;
    }
    else														//���粻��Ҳ���ҵ��Ǹ��ڵ� 
    {
        DuLinkedList right = p->next, left = p;
        //�ҵ�ɾ������λ��
        while(right->data != *e)
        {
            left = right;
            right = right->next;
            if(right == NULL)
            {
                printf("�Ҳ���������\n");
                return ERROR;
            }
        }
        if(right->next!=NULL){										//	�м�Ľڵ��ͷ� 
		  left->next = right->next;
            right->next->prior = left;
        }
        else	
        {														//���Ľڵ��ͷ� 
            left->next = NULL;
        }
        free(right);
        return SUCCESS;
    }
	
}


void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))		//��������������뵥�������� 
{
	 if(L == NULL)
    {
        printf("����δ���������ȴ�������\n");
    }  
	else if(L->next == NULL)
	{
		printf("��ǰ����Ϊ��\n");
	}  
    else
    {
        DuLinkedList temp = L->next;
        while(temp != NULL)
        {
           visit(temp->data);
            temp = temp->next;
        }
        printf("\n");
    }

	
}


int judge_int(void) 						//��ֹʦ���������� 
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
            if (word[m] < '0' || word[m] > '9') //�����Ƿ��������������ַ�
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








void print(ElemType e)
{
    printf("%d\t", e);
}


int main()
{

    ElemType choice, n = 0;
    DuLinkedList head = NULL;

    do
    {
        show();
        choice = judge_int();
        system("cls");
        switch (choice)
        {
        case 1: //����������
        {
            if (InitList_DuL(&head))
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
            DestroyList_DuL(&head);
            printf("�����������\n");
            break;
        }
        case 3: //�������ݵ�ĳһ�ڵ�ǰ 
        {
            if (head == NULL)
            {
                printf("����Ϊ�գ� ���ȴ�������\n");
            }
            else
            {
            	int n;
            	DuLinkedList q;
              printf("�������������ĺ�һ�ڵ�����ݣ�");
                	scanf("%d", &n);
                	q = (DuLinkedList)malloc(sizeof(DuLNode));
                	if (q == NULL)
                	{
                    printf("�ڴ�δ�ܳɹ�����");
                    return ERROR;
               		}
                	q->data = n;
                	q->next = NULL;
               		 if (InsertBeforeList_DuL(head, q))
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
        case 4: //�������ݵ�ĳһ�ڵ��
        {
            if (head == NULL)
            {
                printf("����Ϊ�գ� ���ȴ�������\n");
            }
            else
            {
            	int n;
            	DuLinkedList q;
              printf("��������������ݵ�ǰһ���ڵ㣺");
                	scanf("%d", &n);
                	q = (DuLinkedList)malloc(sizeof(DuLNode));
                	if (q == NULL)
                	{
                    printf("�ڴ�δ�ܳɹ�����");
                    return ERROR;
               		}
                	q->data = n;
                	q->next = NULL;
               		 if (InsertAfterList_DuL(head, q))
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
		case 5: //��������
        {
            if (head == NULL || head->next == NULL)
            {
                printf("�������ڻ���ֻ����һ���յ�ͷ���\n");
            }
            else
            {
                TraverseList_DuL(head, print);
            }
            break;
        }
        case 6: //ɾ������
        {
            printf("��������Ҫɾ����ڵ��ǰ�ڵ����ݣ�");
            scanf("%d", &n);
            ElemType *e;
            e = &n;
            if (DeleteList_DuL(head, e))
            {
                printf("�ɹ�ɾ��%d�������\n", *e);
            }
            else
            {
                printf("����ɾ��ʧ��\n");
            }
            break;
        }
        case 7: //�˳����� 
        {
            DestroyList_DuL(&head);
            break;
        }
        default:
        {
            printf("�������������֣�(1-7)\n");
            break;
        }
    }
    } while (choice != 7);

    return 0;
}
