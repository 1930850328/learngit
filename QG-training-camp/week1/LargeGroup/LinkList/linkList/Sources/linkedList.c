#include <stdio.h>
#include "linkedList.h"
#include <stdlib.h>
#include<string.h>

void show(void)
{
    printf("\n\n\n\t\t\t***************单链表ADT***************\n");
    printf("\t\t\t---------------------------------------\n");
    printf("\t\t\t-------------1.创建空链表--------------\n");
    printf("\t\t\t--------------2.销毁链表--------------\n");
    printf("\t\t\t--------------3.插入结点--------------\n");
    printf("\t\t\t--------------4.删除结点--------------\n");
    printf("\t\t\t--------------5.遍历链表--------------\n");
    printf("\t\t\t--------------6.查找数据--------------\n");
    printf("\t\t\t--------------7.反转链表--------------\n");
    printf("\t\t\t---------8.判断链表是否成环-----------\n");
    printf("\t\t\t--------9.反转链表中的偶数结点--------\n");
    printf("\t\t\t-----------10.查找中间结点------------\n");
    printf("\t\t\t---------------11.退出----------------\n");
    printf("\t\t\t--------------------------------------\n");
    printf("\t\t\t**************************************\n");
    printf("\t\t\t请输入对应的数字(1-11)：");
}

Status InitList(LinkedList *L)
{
    LinkedList list;                          //定义头节点
    list = (LinkedList)malloc(sizeof(LNode)); //分配内存
    if (list == NULL)						//分配失败 
    {
        printf("内存未能分配");
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
        t = *L;						//将节点一个一个传给t释放 
       (*L) =(*L)->next;
        free(t);
    }
}

Status InsertList(LNode *p, LNode *q)
{
    LinkedList left = p;			//定义了一个节点遍历到最后 
    LinkedList right = q;			
    
    while (left->next!=NULL)
    {
        left = left->next;
    }
    left->next = right;				//插入新节点 
    return SUCCESS;
}

Status DeleteList(LNode *p, ElemType *e)
{
    LinkedList right = p->next;			//将要被删除节点 
    LinkedList left = p;				//被删节点的前一个节点 
    if (right == NULL)
    {
        printf("链表为空，无法删除\n");
    }
    else
    {
        while (left->data != *e)		//遍历找到被删点的前一个节点
        {
            left = right;
            right = right->next;
            if (right == NULL)
            {
                printf("没有该数据\n");
                return ERROR;
            }
        }
        *e = right->data;				//记录被删节点数据给后面显示 
        left->next = right->next;
        free(right);					//释放被删节点 
        return SUCCESS;
    }
}

void TraverseList(LinkedList L, void (*visit)(ElemType e))//竟然还要为printf搞一个函数指针，师兄师姐们真是太严谨啦 
{
    LinkedList t;
    t = L->next;
    while (t != NULL)
    {
        visit(t->data);										//遍历，输出 
        t = t->next;
    }
    printf("\n");
}

void print(ElemType e)									//一个不起眼的输出函数 
{
    printf("%d\t", e);
}

Status SearchList(LinkedList L, ElemType e)				//查找函数 
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

Status ReverseList(LinkedList *L)						// 反转单链表，这里我是学习网络上的头插法，花了我好久呜呜呜 http://c.biancheng.net/view/8105.html 
{
    LNode *newHead; //储存每次反转后的第一个节点
    LNode *left;    //每次都指向前一个节点
    LNode *right;   // 储存未反转前的下一个节点
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

Status IsLoopList(LinkedList L)							//师兄面试问到我啦， get到快慢指针的厉害 
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

LNode *ReverseEvenList(LinkedList *L)					// 奇数偶数节点交换 
{
LNode *p1,*p2,*p,*count,*first;
int a,x=0;
p1=(*L);
first=(*L);
count=(*L);												//count负责数数 
p2=(*L)->next;

while(count!=NULL){
	count=count->next;
	x++;
}														//x记录有多少个节点 
p=p1;
for(a=1;a<=x/2;a++)										//两两交换 
{
	p1=p->next;
	p2=p1->next;
	
	p->next=p2;
	p1->next=p2->next;
	p2->next=p1;
	 
    p=p1;
}
return first;										//返回头结点 
}

LNode *FindMidNode(LinkedList *L)					//照样也是运用快慢指针完成，多谢师兄面试的提问！！！ 
{	
    LinkedList fast = (*L), slow = (*L);
    while (fast->next != NULL)
    {
        slow = slow->next;								//慢指针走一格 
        fast = fast->next->next;						//快指针走两格 
        if (fast == slow)
        {
            printf("该链表成环无中间节点\n");
        }
    }
    return slow;
}

int judge_int(void) 										//防止师兄脸滚键盘 
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
            if (word[m] < '0' || word[m] > '9') 		//检验是否有乱输入其他字符
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

int main()							//主函数 
{

    ElemType choice, n = 0;
    LinkedList head = NULL;

    do
    {
        show();						//牌面 
        choice = judge_int();
        system("cls");
        switch (choice)
        {
        case 1: //创建空链表
        {
            if (InitList(&head))
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
            DestroyList(&head);
            printf("链表销毁完成\n");
            break;
        }
        case 3: //插入数据
        {
            if (head == NULL)
            {
                printf("链表为空， 请先创建链表\n");
            }
            else
            {
            	int n;
            	LinkedList q;
              printf("请输入数据：");
                	scanf("%d", &n);
                	q = (LinkedList)malloc(sizeof(LNode));
                	if (q == NULL)
                	{
                    printf("内存未能成功分配");
                    return ERROR;
               		}
                	q->data = n;
                	q->next = NULL;
               		 if (InsertList(head, q))
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
        case 4: //删除数据
        {
            printf("请输入你要删除后节点的前节点数据：");
            scanf("%d", &n);
            ElemType *e;
            e = &n;
            if (DeleteList(head, e))
            {
                printf("成功删除%d这个数据\n", *e);
            }
            else
            {
                printf("数据删除失败\n");
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
                TraverseList(head, print);
            }
            break;
        }
        case 6: //查找数据
        {
            printf("请输入你要查找的数据：");
            scanf("%d", &n);
            if (SearchList(head, n))
            {
                printf("该数存在\n");
            }
            else
            {
                printf("该数不存在\n");
            }
            break;
        }
        case 7: //反转链表
        {
            if (head == NULL || head->next == NULL)
            {
                printf("链表为空或者链表只含有两个结点\n");
                printf("链表反转失败\n");
            }
            else
            {
                if (ReverseList(&head))
                {
                    printf("链表反转成功\n");
                }
                else
                {
                    printf("链表反转失败\n");
                }
            }
            break;
        }
        case 8: //判断链表是否成环
        {
            if (head == NULL || head->next == NULL)
            {
                printf("链表为空\n");
            }
            else
            {
                if (IsLoopList(head))
                {
                    printf("链表成环\n");
                }
                else
                {
                    printf("链表没有成环\n");
                }
            }
            break;
        }
        case 9: //反转链表中的偶数结点
        {
            if (head == NULL || head->next == NULL)
            {
                printf("链表为空\n");
            }
            else
            {
                TraverseList(ReverseEvenList(&head), print);
            }
            break;
        }
        case 10: //查找中间结点
        {
            if (head == NULL || head->next == NULL)
            {
                printf("这是空链表\n");
            }
            else
            {
                printf("链表中间储存的值为%d\n", (FindMidNode(&head))->data);
            }
            break;
        }
        case 11: //退出程序 
        {
            DestroyList(&head);
            break;
        }
        default:
        {
            printf("请重新输入数字！(1-11)\n");
            break;
        }
        }
    } while (choice != 11);

    return 0;
}
