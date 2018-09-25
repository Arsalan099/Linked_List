/*

Linked list have the following advantages over array
1. Dynamic Size
2. Ease of insertion and deletion

Drawbacks
1. No random access. Thats why binary search cant be implemented.
2. Extra memory space
3. Not cache friendly. That is no locality of reference.

*/


#include <bits/stdc++.h>

using namespace std;

struct node
{
	int data;
	node *next;
};

class linked_list
{
	private:	
		node *head,*tail;
	public:
		linked_list()
		{
			head=NULL;
			tail=NULL;
		}

		//Creating the node and inserting new node at the end;
		void createnode(int value)
		{
			node *temp=new node;
			temp->data=value;
			temp->next=NULL;
			if(head==NULL)
			{
				head=temp;
				tail=temp;
			}
			else
			{
				tail->next=temp;
				tail=temp;
			}
		}

		//Display the contents of linked lists
		void display()
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

		//Inserting node at the beginning
		void insert_begin(int value)
		{
			node *temp= new node;
			temp->data=value;
			temp->next=head;
			head=temp;
		}

		//Inserting at a particular position
		void insert_point(int pos,int value)
		{
			node *temp=new node;
			node *pre=new node;
			node *cur=new node;
			temp->data=value;
			cur=head;
			for(int i=1;i<pos;i++)
			{
				pre=cur;
				cur=cur->next;
			}
			pre->next=temp;
			temp->next=cur;
		}

		//Deletion from the beginning
		void delete_begin()
		{
			node *temp=new node;
			temp=head;
			head=head->next;
			delete temp;
		}

		//Deletion at the end HERE WHILE LOOP WILL HAVE CUR->NEXT AS WE DONT WANT OUR LAST NODE TO BE NULL WHILE DELETING
		void delete_end()
		{
			node *del=new node;
			node *cur=new node;
			cur=head;
			while(cur->next!=NULL)
			{
				del=cur;
				cur=cur->next;
			}
			tail=del;
			tail->next=NULL;
			delete cur;
		}

		//Deletion at a point
		void delete_pos(int pos)
		{
			node *previous=new node;
			node *current=new node;
			current=head;
			for(int i=1;i<pos;i++)
			{
				previous=current;
				current=current->next;
			}
			previous->next=current->next;
			delete current;
		}

		//Deleting full linked list
		void delete_full()
		{
			node *temp=new node;
			while(head!=NULL)
			{
				temp=head;
				head=head->next;
				delete temp;
			}
			cout<<"Empty";
		}

		//Counting nodes using recursion
		int get_count()
		{
			node *temp=head;
			int count=0;
			while(temp!=NULL)
			{
				count++;
				temp=temp->next;
			}
			return count;
		}

		//Searching an element
		void search_element(int ele)
		{
			node *temp=head;
			int count=0;
			while(temp!=NULL)
			{
				count++;
				if(temp->data==ele)
				{
					cout<<"Element Found at "<<count<<" index"<<endl;
					break;
				}
				temp=temp->next;
			}
		}

		//Element at nth node
		void nth_node(int n)
		{
			node *temp=head;
			for(int i=1;i<n;i++)
			{
				temp=temp->next;
			}
			cout<<n<<"th value is "<<temp->data<<endl;
		}

		//Element at the nth node from end. Can also be done using length-n+1
		//use reference pointer and main pointer. First traverse ref pointer to n and then traverse both until referece pointer reach NULL
		void nth_node_end(int n)
		{
			node *ref=head;
			node *mainp=head;
			for(int i=1;i<n;i++)
			{
				ref=ref->next;
			}
			while(ref->next!=NULL)
			{
				ref=ref->next;
				mainp=mainp->next;
			}
			cout<<n<<"th value from back is "<<mainp->data<<endl;
		}

		//Middle element of list
		void middle()
		{
			node *temp=head;
			node *mid=head;
			int count=0;
			while(temp->next!=NULL)
			{
				temp=(temp->next);
				mid=mid->next;
				if(temp->next==NULL)
				{
					cout<<"It is a linked list with even length. So there is no middle element"<<endl;
					count=1;
					break;
				}
				temp=temp->next;
			}
			if(count==0)
			{
				cout<<"Middle value is "<<mid->data<<endl;
			}
		}


		//Count the occurances of a given number
		void count_int(int n)
		{
			node *temp=head;
			int count=0;
			while(temp!=NULL)
			{
				if(temp->data==n)
					count++;
				temp=temp->next;
			}
			cout<<n<<" occurs "<<count<<" times."<<endl;
		}

		//creating loop
		void create_loop()
		{
			head->next->next->next->next->next->next->next=head->next;
		}

		//Detect loop using hashing i.e storing addresses in set
		bool detect_loop_hash()
		{
			set<node *> s;
			node *temp=head;
			while(temp!=NULL)
			{
				if(s.find(temp)!=s.end())
				{
					size_loop(temp);
					head->next->next->next->next->next->next->next=NULL;	
					return true;
				}
				s.insert(temp);
				temp=temp->next;
			}
			return false;
		}

		//Detect loop using two pointers
		bool detect_loop_ptr()
		{
			node *fast=head;
			node *slow=head;
			while(fast->next!=NULL && fast->next->next!=NULL)
			{
				fast=fast->next->next;
				slow=slow->next;
				if(fast==slow)
				{
					size_loop(slow);
					head->next->next->next->next->next->next->next=NULL;
					return true;
				}
			}
			return false;
		}

		//size of the loop
		void size_loop(node *temp)
		{
			int count=1;
			node *n=temp;
			while(n->next!=temp)
			{
				count++;
				n=n->next;
			}
			cout<<"Size of loop is "<<count<<endl;
		}

		//Reverse full list
		void reverse_list()
		{
			node *newtail=head;
			node *temp=head;
			head=NULL;
			while(temp!=NULL)
			{
				insert_begin(temp->data);
				temp=temp->next;
			}
			tail=newtail;
		}

		//Reverse from a point using insertion at the end
		void reverse_point(int n,int m)
		{
			node *strhead=head;
			node *strtail=tail;
			node *temp1=new node;
			temp1=head;
			for(int i=1;i<n-1;i++)
				temp1=temp1->next;
			node *temp2=temp1;
			for(int i=n-1;i<m;i++)
				temp2=temp2->next;
			node *ch1=temp1;
			node *ch2=temp2->next;
			node *ch3=temp1->next;
			head=temp1->next;
			tail=temp2;
			tail->next=NULL;
			reverse_list();
			ch1->next=head;
			node *tem=new node;
			tem=head;
			while(tem->next!=NULL)
			{
				tem=tem->next;
			}
			tem->next=ch2;
			tail=strtail;
			head=strhead;
		}

		//reverse using inserting at the begin
		void reverse_point2(int n,int m)
		{
			node *temp=head;
			node *temp1=head;
			node *temp2=new node;
			while(temp1!=NULL && temp1->data!=n)
			{
				temp2=temp1;
				temp1=temp1->next;
			}
			node *temp3=temp1;
			node *temp4=temp3;
			while(temp3!=NULL && temp3->data!=m)
			{
				temp3=temp3->next;
			}
			while(temp1!=temp4)
			{
				temp3->next=temp2;
				temp1=temp2->next;
				temp3=temp3->next;
			}
			temp2->next=temp4;
		}

		//remove duplicates
		void remove_duplicate()
		{
			set<int> s;
			node *cur=head;
			node* pre=head;
			while(cur!=NULL)
			{
				if(s.find(cur->data)!=s.end())
				{
					pre->next=cur->next;
					delete cur;
				}
				else
				{
					pre=cur;
					s.insert(cur->data);
				}
				cur=pre->next;
			}
		}

		//Swapping the nodes
		void swap(int n,int m)
		{
			node *tempn=head;
			node *prevn=new node;
			while(tempn!=NULL&&tempn->data!=n)
			{
				prevn=tempn;
				tempn=tempn->next;
			}
			node *tempm=head;
			node *prevm=new node;
			while(tempm!=NULL&&tempm->data!=m)
			{
				prevm=tempm;
				tempm=tempm->next;
			}
			node *temp=new node;
			temp->next=prevn->next;
			prevn->next=prevm->next;
			prevm->next=temp->next;

			node *temp1=new node;
			temp1->next=tempn->next;
			tempn->next=tempm->next;
			tempm->next=temp1->next;
			display();
		}

		//rotate linked list left
		void rotate_left(int n)
		{
			for(int i=0;i<n;i++)
			{
				tail->next=head;
				tail=head;
				head=head->next;
				tail->next=NULL;
			}

		}

		//getting node just before the desired element
		void get_element_before_element(node **t)
		{
			node *temp=head;
			while(temp->next!=*t)
			{
				temp=temp->next;
			}
			*t=temp;
		}

		//rotate linked list right
		void rotate_right(int n)
		{
			for(int i=0;i<n;i++)
			{
				node* t=tail;
				get_element_before_element(&t);
				tail->next=head;
				head=tail;
				tail=t;
				tail->next=NULL;
			}
		}
};

int main()
{
	linked_list obj;
	obj.createnode(1);
	obj.createnode(2);
	obj.createnode(3);
	obj.createnode(6);
	obj.createnode(7);
	obj.createnode(10);
	obj.createnode(11);
	obj.insert_begin(4);
	obj.insert_point(3,2);
	obj.display();
	cout<<"Length of linked list is "<<obj.get_count()<<endl;
	obj.search_element(5);
	obj.nth_node(4);
	obj.nth_node_end(4);
	obj.middle();
	obj.count_int(6);
	//obj.create_loop();
	cout<<obj.detect_loop_ptr()<<endl;
	//obj.reverse_list();
	//obj.reverse_point(3,7);
	//obj.remove_duplicate();
	obj.rotate_left(3);
	obj.display();
	obj.rotate_right(3);
	obj.display();
	//obj.swap(4,6);

	obj.delete_begin();
	obj.delete_end();
	obj.delete_full();
	obj.display();
	return 0;
}