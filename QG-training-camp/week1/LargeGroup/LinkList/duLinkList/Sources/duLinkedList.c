#include <stdio.h>
#include "duLinkedList.h"
#include <stdlib.h>
#include <string.h>

void show(void)
{
	printf("\n\n\n\n\t\t\t***************双向链表ADT**************\n");
	printf("\t\t\t---------------------------------------\n");
    printf("\t\t\t-------------1.创建空链表--------------\n");
    printf("\t\t\t-------------2.销毁链表-------------\n");
    printf("\t\t\t---------3.插入数据到某一节点前--------\n");
    printf("\t\t\t---------4.插入数据到某一节点后--------\n");
    printf("\t\t\t-------------5.遍历链表---------------\n");
    printf("\t\t\t-------------6.删除某一节点-----------\n");
    printf("\t\t\t--------------7.退出------------------\n");
    printf("\t\t\t---------------------------------------\n");
    printf("\t\t\t***************************************\n");
    printf("\t\t\t请输入对应的数字(1-7)：");
}



Status InitList_DuL(DuLinkedList *L)					//创建空链表 
{
	 DuLinkedList p;
	p=(DuLinkedList)malloc(sizeof(DuLNode));
	if(!p)	
	{
	printf("内存未能成功分配\n");
	return ERROR;
	}
	p->next=NULL;
	p->prior=NULL;

	*L=p ;
	return SUCCESS;
}


void DestroyList_DuL(DuLinkedList *L)					//销毁链表 
{
	DuLinkedList p;
	while(!*L) 
	{
		p=(*L);
		(*L)=(*L)->next;								//传递，释放 
		free(p);
	}
}


Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q)				//在一个节点前插入节点 
{
DuLinkedList p1=q;
if(p->next == NULL)												//假如是空链表 
    {
        p->next = q;
        q->prior = p;
    }
    else														//如果不是就找到那个要求节点 
    {
    	while(p->data != p1->data)
    {
        p = p->next;    
    }
        printf("请输入想要插入的数据\n");						//再插入，先断开再连起来 
   		scanf("%d",&p1->data);
        p1= p->next;
        p->next = q;
        q->next = p1;
        p1->prior = q;
        q->prior = p;
        return SUCCESS;
    }

}


Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)				//在一个节点后插入节点
{
DuLinkedList p1=q;												//假如是空链表 
if(p->next == NULL)
    {
        p->next = q;
        q->prior = p;
    } 
	else														//如果不是空链表就找到那个节点 
	{
	while(p->data != p1->data)
    {
        p = p->next;    
    }
    printf("请输入想要插入的数据\n");
    scanf("%d",&p1->data);										//与上面的原理差不多 
    if(p->next==NULL)											//假如是最后一个节点插入 
    {
    	p->next = p1;
    p1->prior = p;
	}
    else														//中间插入 
	{
	p1->next=p->next;
	p1->prior=p; 
    p->next = p1;
    p1->next->prior = p1;}
	}	
}


Status DeleteList_DuL(DuLNode *p, ElemType *e)					//删除一个节点 
{
if(p->next == NULL)												//假如是空链表 
    {
        printf("链表为空，无法删除\n");
        return ERROR;
    }
    else														//假如不是也是找到那个节点 
    {
        DuLinkedList right = p->next, left = p;
        //找到删除结点的位置
        while(right->data != *e)
        {
            left = right;
            right = right->next;
            if(right == NULL)
            {
                printf("找不到该数据\n");
                return ERROR;
            }
        }
        if(right->next!=NULL){										//	中间的节点释放 
		  left->next = right->next;
            right->next->prior = left;
        }
        else	
        {														//最后的节点释放 
            left->next = NULL;
        }
        free(right);
        return SUCCESS;
    }
	
}


void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))		//遍历函数输出，与单链表无异 
{
	 if(L == NULL)
    {
        printf("链表未创建，请先创建链表\n");
    }  
	else if(L->next == NULL)
	{
		printf("当前链表为空\n");
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


int judge_int(void) 						//防止师兄脸滚键盘 
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
            if (word[m] < '0' || word[m] > '9') //检验是否有乱输入其他字符
            {
                printf("请输入整数：");
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
        case 1: //创建空链表
        {
            if (InitList_DuL(&head))
            {
                printf("空链表创建成功\n");
            }
            else
            {
                printf("空链表创建失败\n");
            }
            break;
        }
        case 2: //销毁链表
        {
            DestroyList_DuL(&head);
            printf("链表销毁完成\n");
            break;
        }
        case 3: //插入数据到某一节点前 
        {
            if (head == NULL)
            {
                printf("链表为空， 请先创建链表\n");
            }
            else
            {
            	int n;
            	DuLinkedList q;
              printf("请输入你想插入的后一节点的数据：");
                	scanf("%d", &n);
                	q = (DuLinkedList)malloc(sizeof(DuLNode));
                	if (q == NULL)
                	{
                    printf("内存未能成功分配");
                    return ERROR;
               		}
                	q->data = n;
                	q->next = NULL;
               		 if (InsertBeforeList_DuL(head, q))
                	{
                    printf("数据插入成功\n");
               		}
                	else
                	{
                    printf("数据插入失败\n");
               		}
				
			}
            break;
        }
        case 4: //插入数据到某一节点后
        {
            if (head == NULL)
            {
                printf("链表为空， 请先创建链表\n");
            }
            else
            {
            	int n;
            	DuLinkedList q;
              printf("请输入想插入数据的前一个节点：");
                	scanf("%d", &n);
                	q = (DuLinkedList)malloc(sizeof(DuLNode));
                	if (q == NULL)
                	{
                    printf("内存未能成功分配");
                    return ERROR;
               		}
                	q->data = n;
                	q->next = NULL;
               		 if (InsertAfterList_DuL(head, q))
                	{
                    printf("数据插入成功\n");
               		}
                	else
                	{
                    printf("数据插入失败\n");
               		}
				
			}
            break;
        }
		case 5: //遍历链表
        {
            if (head == NULL || head->next == NULL)
            {
                printf("链表不存在或者只存在一个空的头结点\n");
            }
            else
            {
                TraverseList_DuL(head, print);
            }
            break;
        }
        case 6: //删除数据
        {
            printf("请输入你要删除后节点的前节点数据：");
            scanf("%d", &n);
            ElemType *e;
            e = &n;
            if (DeleteList_DuL(head, e))
            {
                printf("成功删除%d这个数据\n", *e);
            }
            else
            {
                printf("数据删除失败\n");
            }
            break;
        }
        case 7: //退出程序 
        {
            DestroyList_DuL(&head);
            break;
        }
        default:
        {
            printf("请重新输入数字！(1-7)\n");
            break;
        }
    }
    } while (choice != 7);

    return 0;
}
