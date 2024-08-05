#include "Contact.h"
int main(int argc, char** argv) {
while(1){
	int ch;
	Contact c1;
	cout<<"Select choice:"<<endl;
	cout<<"1. Add Contact \n2. Display All \n3. Search Contact \n4. Delete Contact \n5. Exit"<<endl;
	cout<<"Enter choice: ";
	cin>>ch;
	switch(ch){
		case 1:
			{
				int id;
				float phone;
				char name[50],email[50],fbID[50],city[40];
				cout<<"Enter ID: ";
				cin>>id;
				cout<<"Enter name: ";
				cin>>name;
				cout<<"Enter email: ";
				cin>>email;
				cout<<"Enter Phone: ";
				cin>>phone;
				cout<<"Enter fbID: ";
				cin>>fbID;
				cout<<"Enter city: ";
				cin>>city;
				Contact c1(id,name,email,phone,fbID,city);
				addContact(c1);
}
break;
case 2:{
	dispAll();
}
break;
case 3:
{
	int id;
	cout<<"Enter the id searched for: ";
	cin>>id;
	search(id);
}
break;
case3:
	{
		int id;
		cout<<"Enter the id Searched for: ";
		cin>>id;
		search(id);
	}
	break;
case 4:{
	    int id;
		cout<<"Enter the id to be deleted: ";
		cin>>id;
	    deleteRecord(id);		
}
break;
case 5:{
	exit(0);
}
break;
}
}
}
