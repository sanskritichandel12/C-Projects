#include<iostream>
using namespace std;

class hotel
{
	private:
		struct node
		{
			int id,date;
			string name,roomtype;
			node*next;
		};
	public:
		node*head=NULL;
		void insert();
		void menu();
		void update();
		void search();
		void del();
		void sort();
		void show();
};
void hotel::menu()
{
	int choice;
	cout<<"\n";
	cout<<"\t Welcome to hotel management system";
	cout<<"\n\t________Hotel management system_______";
	cout<<"\n Na  function   description   ";
	cout<<"\n1\t allocate room \t\t\t inset new room";
	cout<<"\n2\t search room \t\t\t insert new room";
	cout<<"\n3\t update room \t\t\t update new room";
	cout<<"\n4\t delete room\t\t\t delete room";
	cout<<"\n5\t show room records \t\t\t show room record";
	cout<<"\n6\t exit";
	
	cout<<"enter your choice";
	cin>>choice;
	switch(choice)
	{
		case 1:
			insert();
			menu();
			
		case 2:
			search();
			menu();
			
		case 3:
			update();
			menu();
		
		case 4:
		 	del();
		 	menu();
		 	
		case 5:
			sort();
			show();
			menu();
			default:
				cout<<"invalid";
	}
}
void hotel::insert()
{
	cout<<"\n\t_____Hotel management system_____";
	node *new_node=new node;
	cout<<"\n enter room id";
	cin>>new_node->id;
	cout<<"\n enter customer name";
	cin>>new_node->name;
	cout<<"\n enter allocated date";
	cin>>new_node->date;
	cout<<"\n enter roomtype(single/double/twin)";
	cin>>new_node->roomtype;
	
	if(head==NULL)
	{
		head=new_node;
	}
	else
	{
		node*ptr=head;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=new_node;
	}
	cout<<"\n\n\t\t new room insrted";
}
void hotel::search()
{
	cout<<"\n\t_____Hotel management system_____";
	int t_id;
	if(head==NULL)
	{
		cout<<"\n\n linked list is empty";
	}
	else
	{
		cout<<"\n\n room id";
		cin>>t_id;
		node*ptr=head;
		while(ptr!=NULL)
		{
			if(t_id==ptr->id)
			{
				cout<<"\n\n room id"<<ptr->id;
				cout<<"\n\n customer name"<<ptr->name;
				cout<<"\n\n allocated room date"<<ptr->date;
				cout<<"\n\n room type"<<ptr->roomtype;
			}
			ptr=ptr->next;
		}
	}
}
void hotel::update()
{
	cout<<"\n\t_____Hotel management system_____";
	int t_id;
	if(head==NULL)
	{
		cout<<"\n\n linked list is empty";
	}
	else 
	{
		cout<<"\n room id";
		cin>>t_id;
		node*ptr=head;
		while(ptr!=NULL)
		{
			if(t_id==ptr->id)
			{
				cout<<"\n\n room id";
				cin>>ptr->id;
				
				cout<<"\n\n customer name";
				cin>>ptr->name;
				
			    cout<<"\n\n allocated date";
				cin>>ptr->date;
				
				cout<<"\n\n room type";
				cin>>ptr->roomtype;
				
				cout<<"\n\n\t\t update record successfully";
			}
			ptr=ptr->next;
		}
	}
}
void hotel::del()
{
	cout<<"\n\t_____Hotel management system_____";
	int t_id;
	if(head==NULL)
	{
		cout<<"\n\n linked list is empty";
	}
	else 
	{
		cout<<"\n room id";
		cin>>t_id;
		if(t_id==head->id)
		{
			node*ptr=head;
			head=head->next;
			delete ptr;
			cout<<"delete room record successfully\n";
		}
		else
		{
		  node*pre=head;
		  node*ptr=head;
		  while(ptr!=NULL)
		  {
		  	if(t_id==ptr->id)
		  	{
		  		pre->next=ptr->next;
		  		delete ptr;
		  		cout<<"delete room record successfully\n";
		  		break;
		    }
		    pre=ptr;
		    ptr=ptr->next;
		}	
		}
}
}
void hotel::show()
{
	node*ptr=head;
	while(ptr!=NULL)
	{
		cout<<"\n\n room id"<<ptr->id;
		
		cout<<"\n\n customer name"<<ptr->name;
			
		cout<<"\n\n allocated date"<<ptr->date;
				
		cout<<"\n\n room type"<<ptr->roomtype;
		ptr=ptr->next;
    }
}
void hotel::sort()
{
	if(head==NULL)
	{
		cout<<"\n\n linked list is empty";
		menu();
	}
	int count=0,t_date,t_id;
	string t_name,
	 t_roomtype;
	node*ptr=head;
	while(ptr!=NULL)
	{
		count++;
		ptr=ptr->next;
	}
	for(int i=1;i<=count;i++)
	{
		node*ptr=head;
		for(int j=1;j<count;j++)
		{
			if(ptr->id>ptr->next->id)
			{
				t_id=ptr->id;
				t_name=ptr->name;
				t_date=ptr->date;
				t_roomtype=ptr->roomtype;
				//save date into current node
				ptr->id=ptr->next->id;
				ptr->name=ptr->next->name;
				ptr->date=ptr->next->date;
				ptr->roomtype=ptr->next->roomtype;
				//save data into next node
				ptr->next->id=t_id;
				ptr->next->name=t_name;
				ptr->next->date=t_date;
				ptr->next->roomtype=t_roomtype;

			}
			ptr=ptr->next;
		}
	}
	
}
main()
{
	hotel h;
	h.menu();

}		
		
		
		
		
		
		
	


	


