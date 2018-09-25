//here we add a flag to the node along with data and next pointer

#include <bits/stdc++.h>

using namespace std;

struct node
{
	int data;
	char flag;
	node *next;
};

//creating node
void createnode(node **head,int value)
{
	node *temp=new node;
	temp->data=value;
	temp->next=*head;
	*head=temp;
}

//display node
void display(node *head)
{
	node *temp=new node;
	temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<'\t';
		temp=temp->next;
	}
	cout<<endl;
}

//checking intersection of two nodes
void intersection(node *head1, node *head2)
{
	node *temp1=head1;
	node *temp2=head2;
	while(temp1!=NULL)
	{
		temp1->flag='V';
		temp1=temp1->next;
	}
	while(temp2!=NULL)
	{
		if(temp2->flag=='V')
		{
			cout<<temp2->data<<endl;
			break;
		}
		temp2=temp2->next;
	}
}

int return_node(node *cur)
{
	node *temp=new node;
	int count=0;
	node *cur_new=cur;
	while(cur_new->next!=NULL)
	{
		if(cur->data==cur_new->next->data)
		{
			temp=cur_new->next;
			cur_new->next=cur_new->next->next;
			delete temp;
			count=1;
		}
		else
		{
			cur_new=cur_new->next;
		}
	}
	return count;	
}

node* remove_every_duplicate(node *head)
{
	node *pre=head;
	node *temp=new node;
	node *temp2=new node;
	node *cur=head;
	int count,c=0;
	while(cur->next!=NULL)
	{
		if(cur->next==temp)
		{
			temp2=cur->next;
			cur->next=cur->next->next;
			delete temp2;
		}
		else
		{
			count=return_node(cur);
			if(count==0)
				cur=cur->next;
			else
			{
				if(cur==head)
					pre=cur->next;
				temp=cur;
				cur=pre;
			}
		}
	}
	return pre;
}

node* remove_sorted(node *head)
{
	node *temp=head,*temp2=head,*temp3=new node,*temp4=new node;
	while(temp->next!=NULL)
	{
		temp2=temp->next;
		if(temp4==head)
			head=head->next;
		else if(temp2==temp4)
		{
			temp->next=temp->next->next;
			delete (temp2);
		}
		if(temp2->data==temp->data)
		{
			temp->next=temp->next->next;
			delete (temp2);
			if(temp->next==NULL)
			{
				temp4=temp;
				temp=head;
			}
			if(temp->data==temp->next->data)
				continue;
			else
				temp4=temp;
				temp=head;
		}
		else
		{
			temp=temp->next;
		}
	}
	return head;
}

int main()
{
	node *headd=new node;
	headd->data=5;
	headd->next=NULL;
	node *headd1=new node;
	headd1->data=111;
	headd1->next=NULL;
	createnode(&headd,5);
	createnode(&headd,4);
	createnode(&headd,3);
	createnode(&headd,2);
	createnode(&headd,1);
	// createnode(&headd,10);
	// createnode(&headd,1);
	// createnode(&headd,1);
	// createnode(&headd,8);
	// createnode(&headd,5);
	//createnode(&headd1,12);
	//createnode(&headd1,13);
	//headd1->next->next->next=headd->next->next;
	display(headd);
	headd=remove_sorted(headd);
	display(headd);
	//display(headd1);
	//intersection(headd,headd1);
}