#include<iostream>
using namespace std;

typedef struct node
{
	int data;
	struct node *next;
	struct node *prev;
}NODE,*PNODE;

class DoublyCL
{
private:
	PNODE frist;
	PNODE last;
	int size;

	public:
		DoublyCL()
	{
		frist=NULL;
		last=NULL;
		size=0;
     }


     void Display();
     int Count();
     void InsertFrist(int);
     void InsertLast(int);
     void InsertAtPos(int,int);
     void DeleteFrist();
     void DeleteLast();
     void DeleteAtPos(int,iPos);
}; 

// return_value class_Name::Function_name(parameter)
void DoublyCL::InsertFrist(int no)
{
	PNODE newn=new NODE;
	newn->data=no;
	new->next=NULL;
    newn->prev=NULL;

	if((frist==NULL)&&(last==NULL))
	{
		frist=newn;
		last=newn;
	}
	else
	{
		newn->next=frist;
		frist->prev=newn;
		frist=newn;
	}
	last->next=frist;
	frist->prev=last;
	size++;

}

void DoublyCL::InsertLast(int no)
{
	PNODE newn=new NODE;
	newn->data=no;
	new->next=NULL;
    newn->prev=NULL;

	if((frist==NULL)&&(last==NULL))
	{
		frist=newn;
		last=newn;
	}
	else
	{
		last->next=newn;
		newn->next=last;
		last=newn;
	}
	last->next=frist;
	frist->prev=last;
	size++;
}


void DoublyCL::Display()
{
	PNODE temp=frist;
	for(int i=1;i<=size;i++)

	{
		cout<<"|"<<temp->data<<"|->";
		temp=temp->next;
	}
	cout<<"\n";
}


int DoublyCL::Count()
{
	return size;

}

void DoublyCL::DeleteFrist()
{
	if((frist==NULL)&&(last==NULL))
	{
		return;

	}

	else if(frist==last)
	{
		delete frist;
		frist==NULL;
		last=NULL;
	

	}

	else
	{
		frist=frist->next;
		delete last->next;
        frist->prev=last;
	    last->next=frist;

	
	}
	size--;


}
void DoublyCL::DeleteLast()
{
	if((frist==NULL)&&(last==NULL))
	{
		return;

	}

	else if(frist==last)
	{
		delete frist;
		frist==NULL;
		last=NULL;

	}

	else
	{
		last=last->prev;
		delete last->next;
        frist->prev=last;
	    last->next=frist;
	}

	

	size--;
}


void DoublyCL::InsertAtPos(int no,int ipos)
{
    if((iops<1)||(ipos>size+1))
    {
    	return;

    }
    if(ipos==1)
    {
    	InsertFrist(no);
    }
    else if(ipos==size+1)
    {
    	InsertLast(no);
    }
    else
    {
    	PNODE newn=new NODE;

    	newn->data=no;
    	newn->next=NULL;
    	newn->prev=NULL;

    	PNODE temp=frist;

    	for(int i=1;i<ipos-1;i++)
    	{
    		temp=temp->next;
    	}
    	newn->next=temp->next
    	newn->next->prev=newn;
    	temp->next=newn;
    	newn->prev=temp;
    	size++;
    }
}

void DoublyCL::DeleteAtPos(int ipos)
{
   if((iops<1)||(ipos>size))
   {
   	return;
   }	
   if((ipos==NULL))
   {
       DeleteFrist(no);
   }
   else if(ipos==size)
   {
   	DeleteLast(no);
   }
   else
   {
   	

    PNODE temp=frist;
    for(int i=1;i<ipos-1;i++)
    	{
    		temp=temp->next;
    	}
    	temp->next=temp->next->next;
    	delete temp->next->prev;
    	temp->next->prev=temp;

    	size--;


   }
}


int main()
{
	DoublyCL obj;

	obj.InsertFrist(21);
	obj.InsertFrist(11);
	
	obj.InsertLast(51);
	obj.InsertLasT(101);

	obj.InsertAtPos(75,3);
	obj.Display();

	int iret=obj.Count();
	cout<<"Number of elements are:"<<iret<<\n";

	obj.DeleteAtPos(3);
	obj.DeleteFrist();
	obj.DeleteLast();

	obj.Display();
  return 0;
}