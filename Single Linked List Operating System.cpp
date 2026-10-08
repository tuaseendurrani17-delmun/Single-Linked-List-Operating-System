#include<iostream>
using namespace std;
int count=0;

struct node
{
    int data;
    node* next;
};

	node*head=NULL;
	node*tail=NULL;
	node*nn;
	node*temp;

void create_list(int a)
{
    if(head==NULL)
    {
        nn= new node;
        nn->data=a;
        nn->next=NULL;
        head=nn;
        tail=nn;
        count=count+1;
    }
    else
    {
        cout<<"list already created"<<endl;
    }
}

void insert_at_next(int a)
{
    if(head==NULL)
    {
        cout<<"create the list first"<<endl;
    }
    else
    {
        nn=new node;
        nn->data=a;
        nn->next=head;
        head=nn;
        count=count+1;
    }
}

void inser_at_last(int a)
{
    if(head==NULL)
    {
        cout<<"create the list"<<endl;
    }
    else
    {
        nn=new node;
        nn->data=a;
        nn->next=NULL;
        tail->next=nn;
        tail=nn;
        count=count+1;
    }
}

void insert_at_specific_pos(int pos,int a)
{
    if(head==NULL)
    {
        cout<<"create the list first"<<endl;
    }
    else if(pos<1 || pos>count+1)
    {
        cout<<"Invalid position"<<endl;
    }
    else if(pos==1)
    {
        insert_at_next(a);
    }
    else if(pos==count+1)
    {
        inser_at_last(a);
    }
    else
    {
        int first=1;
        temp=head;

        while(temp!=NULL)
        {
            if(pos-1==first)
            {
                nn=new node;
                nn->data=a;
                nn->next=temp->next;
                temp->next=nn;
                count=count+1;
                break;
            }
            first++;
            temp=temp->next;
        }
    }
}

void display()
{
    if(head==NULL)
    {
        cout<<"List is empty"<<endl;
        return;
    }

    temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

void delete_f_node()
{
    if(head==NULL)
    {
        cout<<"List is empty"<<endl;
    }
    else
    {
        temp=head;
        head=head->next;
        delete temp;
        count=count-1;

        if(head==NULL)
        {
            tail=NULL;
        }
    }
}

void delete_lst()
{
    if(head==NULL)
    {
        cout<<"List is empty"<<endl;
    }
    else if(head==tail)
    {
        delete head;
        head=NULL;
        tail=NULL;
        count=count-1;
    }
    else
    {
        temp=head;

        while(temp->next!=tail)
        {
            temp=temp->next;
        }

        delete tail;
        temp->next=NULL;
        tail=temp;
        count=count-1;
    }
}

void del_pos(int pos)
{
    if(head==NULL)
    {
        cout<<"List is empty"<<endl;
    }
    else if(pos<1 || pos>count)
    {
        cout<<"Invalid position"<<endl;
    }
    else if(pos==1)
    {
        delete_f_node();
    }
    else
    {
        int first=1;
        node* temp2;
        temp=head;

        while(first<pos-1)
        {
            temp=temp->next;
            first++;
        }

        temp2=temp->next;
        temp->next=temp2->next;

        if(temp2==tail)
        {
            tail=temp;
        }

        delete temp2;
        count--;
    }
}

void searching(int no)
{
    int found=0;
    int first=1;
    temp=head;

    while(temp!=NULL)
    {
        if(temp->data==no)
        {
            found=1;
            break;
        }

        temp=temp->next;
        first++;
    }

    if(found!=0)
    {
        cout<<"value found at the position "<<first<<endl;
    }
    else
    {
        cout<<"value not found"<<endl;
    }
}
void Update_Val(int pos,int data)
{
	
	if(head==NULL)
    {
        cout<<"create the list first"<<endl;
    }
    else if(pos<1 || pos>count)
    {
        cout<<"Invalid position"<<endl;
    }
    else
    {
        int first=1;
        temp=head;

        while(temp!=NULL)
        {
            if(pos==first)
            {
                temp->data=data;
                break;
            }
            first++;
            temp=temp->next;
        }
    }	
}
void count_nodes()
{
    cout<<"Total number of nodes: "<<count<<endl;
}
int main()
{
    int x,a,pos,no;

    do
    {
        cout<<"\n Single Linked List Operating System";
        cout<<"\n----------";
        cout<<"\nAddition to List";
        cout<<"\n----------";
        cout<<"\n1.Create a linked List:";
        cout<<"\n2.Add Beginning of List:";
        cout<<"\n3.Add End of List:";
        cout<<"\n4.Add at Specific Position of List:";
        cout<<"\n----------";
        cout<<"\nDeletion to List";
        cout<<"\n----------";
        cout<<"\n5.Delete First Node of List:";
        cout<<"\n6.Delete End Node of List:";
        cout<<"\n7.Delete Specific Position of List:";
        cout<<"\n----------";
        cout<<"\nSearching in List";
        cout<<"\n----------";
        cout<<"\n8.Search Node in List:";
        cout<<"\n9.Display List:";
        cout<<"\n10.Update Value at Specific Position:";
       	cout<<"\n11.Count Nodes:";
		cout<<"\n12.Exit";
        cout<<"\nEnter Your Choice:";
        cin>>x;

        if(x==1)
        {
            cout<<"Enter value: ";
            cin>>a;
            create_list(a);
        }
        else if(x==2)
        {
            cout<<"Enter value: ";
            cin>>a;
            insert_at_next(a);
        }
        else if(x==3)
        {
            cout<<"Enter value: ";
            cin>>a;
            inser_at_last(a);
        }
        else if(x==4)
        {
            cout<<"Enter position: ";
            cin>>pos;
            cout<<"Enter value: ";
            cin>>a;
            insert_at_specific_pos(pos,a);
        }
        else if(x==5)
        {
            delete_f_node();
        }
        else if(x==6)
        {
            delete_lst();
        }
        else if(x==7)
        {
            cout<<"Enter position to delete: ";
            cin>>pos;
            del_pos(pos);
        }
        else if(x==8)
        {
            cout<<"Enter value to search: ";
            cin>>no;
            searching(no);
        }
        else if(x==9)
        {
            display();
        }
       else if(x==10)
		{
		    cout<<"Enter position to update: ";
		    cin>>pos;
		
		    cout<<"Enter new value: ";
		    cin>>a;
		
		    Update_Val(pos,a);
		}
		else if(x==11)
		{
		    count_nodes();
		}
			else if(x==12)
		{
		    cout<<"Program ended"<<endl;
		    break;
		}
        else
        {
            cout<<"Invalid choice"<<endl;
            cout<<"\n\n\n";
        }

    }while(true);

    return 0;
}
