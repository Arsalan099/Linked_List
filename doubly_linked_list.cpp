/*

It has both previous and next pointer
Advantages
1. Can traverse in both forward and backward direction.
2. Delete operation becomes easy.
3. Insertion at any point also becomes easy as we know the previous and next node address.

Disadvantges
1. Extra space needed for previous pointer.
2. Extra operation required for maintainance of the operation.


XOR APPROACH
What we do here is we create a XOR of next and previous nodes and store it in npx

Node A:
npx = 0 XOR add(B) // bitwise XOR of zero and address of B

Node B:
npx = add(A) XOR add(C) // bitwise XOR of address of A and address of C

Node C:
npx = add(B) XOR add(D) // bitwise XOR of address of B and address of D

Node D:
npx = add(C) XOR 0 // bitwise XOR of address of C and 0

While traversiong we need the address of previous node in order to calculate the next node.
For example when we are at node C, we must have address of B. XOR of add(B) and npx of C gives us the add(D).
The reason is simple: npx(C) is “add(B) XOR add(D)”.
If we do xor of npx(C) with add(B), we get the result as “add(B) XOR add(D) XOR add(B)” which is “add(D) XOR 0” which is “add(D)”.
So we have the address of next node. Similarly we can traverse the list in backward direction. 
*/

#include <bits/stdc++.h>

using namespace std;

struct node
{
	int data;
	node *pre;
	node *next;
};

class linked_list
{
	private:
		node *start;
	public:
		linked_list()
		{
			start=NULL;
		}

		void insert_begin(int val)
		{
			node *temp=new node;
			temp->data=val;
			temp->pre=NULL;
			temp->next=NULL;
			if(start==NULL)
			{
				start=temp;
			}
			else
			{
				temp->next=start;
				start->pre=temp;
				start=temp;
			}
		}

		void insert_after_node_with_data_n(int val,int n)
		{
			node *ins=new node;
			int counter=0;
			ins->data=val;
			ins->pre=NULL;
			ins->next=NULL;
			if(start==NULL)
				start=ins;
			else
			{
				node *temp=start;
				while(temp!=NULL)
				{
					if(temp->data==n)
					{
						ins->next=temp->next;
						ins->pre=temp;
						temp->next=ins;
						if(ins->next!=NULL)
							ins->next->pre=ins;
						counter=1;
						break;
					}
					temp=temp->next;
				}
				if(counter==0)
					cout<<"Data not found!!!"<<endl;
			}
		}

		void insert_end(int val)
		{
			node *ins=new node;
			ins->data=val;
			ins->next=NULL;
			ins->pre=NULL;
			if(start==NULL)
				start=ins;
			else
			{
				node *temp=start;
				while(temp->next!=NULL)
				{
					temp=temp->next;
				}
				temp->next=ins;
				ins->pre=temp;
			}
		}

		void insert_before_node_with_data_n(int val,int n)
		{
			node *ins=new node;
			int counter=0;
			ins->data=val;
			ins->pre=NULL;
			ins->next=NULL;
			if(start==NULL)
				start=ins;
			else
			{
				node *temp=start;
				while(temp!=NULL)
				{
					if(temp->data==n)
					{
						ins->pre=temp->pre;
						if(ins->pre!=NULL)
							ins->pre->next=ins;
						else
							start=ins;
						ins->next=temp;
						temp->pre=ins;
						counter=1;
						break;
					}
					temp=temp->next;
				}
				if(counter==0)
					cout<<"Data not found!!!"<<endl;
			}
		}

		void delete_first_node()
		{
			if(start==NULL||start->next==NULL&&start->pre==NULL)
			{
				start=NULL;
				return;
			}
			else
			{
				node *temp=start;
				start=start->next;
				start->pre=NULL;
				delete(temp);
			}
		}

		void delete_last_node()
		{
			if(start==NULL||start->next==NULL&&start->pre==NULL)
			{
				start=NULL;
				return;
			}
			else
			{
				node *temp=start;
				while(temp->next!=NULL)
				{
					temp=temp->next;
				}
				temp->pre->next=NULL;
				delete(temp);
			}
		}

		void delete_node_with_data_n(int n)
		{
			if(start==NULL||start->next==NULL&&start->pre==NULL&&start->data==n)
			{
				start=NULL;
				return;
			}
			else
			{
				node *temp=start;
				int counter=0;
				while(temp!=NULL)
				{
					if(temp->data==n)
					{
						if(temp->pre!=NULL)
						{
							temp->pre->next=temp->next;
						}
						else
						{
							temp->next->pre=NULL;
							start=temp->next;
						}
						if(temp->next!=NULL)
						{
							temp->next->pre=temp->pre;
						}
						else
						{
							temp->pre->next=NULL;
						}
						counter=1;
						break;
					}
					temp=temp->next;
				}
				if(counter==0)
				{
					cout<<"Data not found!!!"<<endl;
					return;
				}
				delete(temp);
			}
		}

		void reverse()
		{
			node *temp=start;
			node *swap=temp;
			if(temp==NULL||temp->next==NULL)
				return;
			while(temp!=NULL)
			{
				if(temp->next==NULL)
					start=temp;
				swap=temp->next;
				temp->next=temp->pre;
				temp->pre=swap;
				temp=temp->pre;
			}
		}

		void display()
		{
			node *temp=start;
			while(temp!=NULL)
			{
				cout<<temp->data<<"\t";
				temp=temp->next;
			}
			cout<<endl;
		}
};

int main()
{
	linked_list obj;
	obj.insert_begin(3);
	obj.insert_begin(2);
	obj.insert_begin(1);
	obj.insert_end(4);
	// obj.insert_end(6);
	// obj.insert_before_node_with_data_n(3,1);
	// obj.insert_before_node_with_data_n(2,3);
	// obj.insert_before_node_with_data_n(1,2);
	// obj.insert_before_node_with_data_n(7,1);
	obj.display();
	// obj.delete_node_with_data_n(4);
	obj.reverse();
	obj.display();
	return 0;
}