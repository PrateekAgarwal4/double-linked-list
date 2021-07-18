#include<iostream>

using namespace std;

class node{
	public:
		int data;
		node* next;
		node* prev;
		
		node(int val)
		{
			data=val;
			next=NULL;
			prev=NULL;
		}
}; 

void insertat_head(node* &head,int val)
{
	node*n=new node(val);
	n->next=head;
	if(head!=NULL)
	{
		head->prev=n;
	}
	head=n;
}

void insertat_tail(node* &head,int val)
{
	if(head==NULL)
	{
		insertat_head(head,val);
		return;
	}
	node*n =new node(val);
	node*temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=n;
	n->prev=temp;
	//n->next=NULL; //no need as already mentioned in the constructor;
	
}
void deleteathead(node* &head)
{
	node* todelete=head;
	head=head->next;
	head->prev=NULL;
	
	delete todelete;
	
}

void deletion(node* &head,int pos)
{
	if(pos==1)
	{
		deleteathead(head);
		return;
	}
	node* temp=head;
	int count=1;
	while(temp!=NULL && count!=pos)
	{
		temp=temp->next;
		count++;
	}
	temp->prev->next=temp->next;
	//if(temp->next!=NULL){//
	temp->next->prev=temp->prev;
     
	delete temp;
}
void display(node* head)
{
	node*temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<"->";
		temp=temp->next;
	}
	cout<<"NULL";
	cout<<endl;
}

int main()
{
	node* head=NULL;
	insertat_tail(head,1);
	insertat_tail(head,2);
	insertat_tail(head,3);
	insertat_tail(head,4);
	display(head);
	insertat_head(head,5);
	display(head);
	deletion(head,5);
	display(head);
}
