#include <iostream.h>
#include <math.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
using namespace std;
typedef int type;
typedef struct Node
{
	type data;
	Node *next;
}node;
node *head=NULL;
node *rear = NULL;
bool isEmpty()
{
	if (head==NULL)
		return true;
	return false;
}
void show()
{
	node *ptr = head;
	cout<<"Du lieu trong Linked la: \n";
	while(ptr !=NULL)
	{
		cout << ptr->data<<"\t";
		ptr=ptr->next;
	}
	cout<<endl;
}
int length()
{
	int dem=0;
	node *temp = head;
	while(temp!=NULL)
	{
		dem++;
		temp=temp->next;
	}
	return dem;
	
}
void Push(type Item)
{
	node *p=new Node;
	if(isEmpty())
	{
	p->next=head;
	p->data=Item;
	head=p;
	}
	else
	{
		node *temp;
		int dem = 1;
		temp=head;
		while (dem<length())
		{
			dem++;
			temp=temp->next;
		}
		p->data=Item;
		p->next=temp->next;
		temp->next=p;
	}
}
void peek()
{
	cout<<"Phan tu dau tien: " << head->data<<"\n";
}
void Pop()
{
	
	if (isEmpty())
	{
		cout<<"\nDa het du lieu\n";
	}
	else
	{
		cout<<"Du lieu da xoa: "<<head->data<<"\n";
		head=head->next;
	}
}

int main()
{
		srand((int)time(0));
	int chon,pos, val,dem=0;
	bool exit=false;
	while(dem<50)
	{
		dem++;
		Push(rand()%101);
	}
	show();
	while (!exit)
	{
		cout<<"\n----------MENU----------";
		cout<<"\n1. Push\n2. Pop\n3. Peek\n4. Kiem tra do dai \n5. Xem Du Lieu\n6. Thoat\nChon: ";
		cin>>chon;
		switch(chon)
		{
			case 1: 
			{
				cout<<"Push: ";
				cin>>val;
				Push(val);
				show();	
			}
			break;
			case 2:
			{
				if (isEmpty())
				{
					cout<<"Du lieu rong";
				}	
				else
				{
					Pop();
				show();
				}
			}
			break;
			case 3:peek();break;
			case 4: 
			{
				cout<<"Do dai du lieu: "<<length();
			}
			break;
			case 5:
			{
				show();
			}
			break;
			default:
			exit=true;break;
		}
	}
	getch();
}
