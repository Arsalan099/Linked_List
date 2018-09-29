/*Advantages

1. Any node can be starting point
2. Only one pointer needed(last) where in general we need two head and tail
3. It is commonly used by operating system where applications are put in a list and traversed giving time to each of them to execute before going to next one and cycling again.

*/


#include<bits/stdc++.h>

using namespace std;

struct node
{
	int val;
	node *next;
};

class circular_linked_list
{
	private:
		node *last;
	public:
		circular_linked_list()
		{
			last=NULL;
		}
		
		void insert_end(int value)
		{
			node *temp=new node;
			temp->val=value;
			temp->next=NULL;
			if(last==NULL)
			{
				last=temp;
				last->next=last;
			}
			else
			{
				temp->next=last->next;
				last->next=temp;
				last=temp;
			}
		}
		
		void insert_begin(int value)
		{
			node *temp=new node;
			temp->val=value;
			temp->next=NULL;
			if(last==NULL)
			{
				last=temp;
				last->next=last;
			}
			else
			{
				temp->next=last->next;
				last->next=temp;
			}
		}
		
		int count()
		{
			int c=0;
			node *temp=last->next;
			do
			{
				c++;
				temp=temp->next;
			}while(temp!=last->next);
			return c;
		}
		
		void insert_between_nodes(int value,int n)
		{
			int c=count();
			c=n%c;
			node *temp=new node;
			node *temp_new=last;
			temp->val=value;
			temp->next=NULL;
			if(last==NULL)
			{
				last=temp;
				last->next=last;
			}
			else
			{
				while(c!=0)
				{
					temp_new=temp_new->next;
					c--;
				}
				if(temp_new==last)
				{
					temp->next=temp_new->next;
					temp_new->next=temp;
					last=temp;
				}
				else
				{
					temp->next=temp_new->next;
					temp_new->next=temp;
				}
			}
		}
		
		void display(node *lastt)
		{
			node *temp=lastt->next;
			do
			{
				cout<<temp->val<<'\t';
				temp=temp->next;
			}while(temp!=lastt->next);
			cout<<endl;
		}

		void display()
		{
			if(last==NULL)
				return;
			node *temp=last->next;
			do
			{
				cout<<temp->val<<'\t';
				temp=temp->next;
			}while(temp!=last->next);
			cout<<endl;
		}

		void middle_element()
		{
			node *head=last->next;
			node *slow=head;
			node *fast=head;
			while(fast->next!=head && fast->next->next!=head)
			{
				fast=fast->next->next;
				slow=slow->next;
			}
			cout<<slow->val<<endl;
		}

		void split()
		{
			node *head=last->next;
			if(head->next==head)
				return;
			node *slow=head;
			node *fast=head;
			while(fast->next!=head && fast->next->next!=head)
			{
				fast=fast->next->next;
				slow=slow->next;
			}
			node *temp1=slow->next,*temp=slow->next;
			slow->next=last->next;
			while(temp->next!=last->next)
				temp=temp->next;
			temp->next=temp1;
			display(temp);
			display(slow);
		}

		void sorted_insert(int value)
		{
			node *temp=new node;
			temp->val=value;
			temp->next=NULL;
			if(last==NULL)
			{
				last=temp;
				last->next=last;
			}
			else
			{
				node *cur=last->next;
				node *pre=last;
				while(cur->next!=last->next)
				{
					if(cur->val<=temp->val)
					{
						cur=cur->next;
						pre=pre->next;
					}
					else
					{
						pre->next=temp;
						temp->next=cur;
						break;
					}
				}
				if(cur->val>temp->val)
				{
					pre->next=temp;
					temp->next=cur;
					return;
				}
				if(cur==last)
				{
					temp->next=last->next;
					last->next=temp;
					if(cur->next==last&&cur->val>temp->val)
						return;
					last=temp;
				}
			}

		}

		void delete_end()
		{
			if(last==NULL||last->next==last)
				last=NULL;
			else
			{
				node *temp=last->next;
				while(temp->next!=last)
				{
					temp=temp->next;
				}
				temp->next=last->next;
				last=temp;
			}
		}

		void delete_begin()
		{
			if(last==NULL||last->next==last)
				last=NULL;
			else
			{
				last->next=last->next->next;
			}
		}

		void exchange_first_last()
		{
			if(last==NULL||last->next==last)
				return;
			node *temp=last->next;
			node *head=last->next;
			if(temp->next==last)
				last=last->next;
			else
			{
				node *pre=last;
				while(temp!=last)
				{
					pre=pre->next;
					temp=temp->next;
				}
				last->next=head->next;
				head->next=pre->next;
				pre->next=head;
				last=pre->next;
			}
		}
};

int main()
{
	circular_linked_list obj,obj1;
	// obj.insert_end(1);
	// obj.insert_end(2);
	// obj.insert_end(3);
	// obj.insert_end(4);
	// obj.insert_end(5);
	// obj.insert_end(6);
	// obj.insert_between_nodes(7,6);
	// obj.split();
	obj.sorted_insert(2);
	obj.sorted_insert(6);
	obj.sorted_insert(4);
	obj.sorted_insert(3);
	obj.sorted_insert(1);
	obj.sorted_insert(5);
	//obj.delete_begin();
	obj.display();
	obj.exchange_first_last();
	obj.display();
	return 0;
}