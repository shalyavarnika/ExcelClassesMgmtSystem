//Excel Class Management System

//Header Files.....
#include <iostream.h>
#include <fstream.h>
#include <iomanip.h>
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <dos.h>
#include <process.h>
#include <time.h>
#include <stdlib.h>
//#include <unistd.h>
void menu();
void database();

class student
{

	char fname[20],lname[20];
	int age;
	char add[50],id[50];
	long long int no;
	char school_name[50];
	float cgpa;
	char guardian_name[20];
	long long int gno;

	char batch;
	int pmode;
	char bname[20];
	double amt;
	long long int cno;

	public:
	int rollno;
	//Member Functions
	void getData();
	void showData();
	void reserve();
	void receipt();
	void payment();
	int retrollno();
};

int  student :: retrollno()
{
	return rollno;

}

void student :: reserve()
{

	time_t t;
	//srand(unsigned &t);
	student st;
	fstream outFile;
	outFile.open("student.dat",ios::binary|ios::app);
	//outFile.seekg(0);
	//st.getData();
       //	while(outFile.read((char *) &st,sizeof(st)))
	//{
			srand((signed) time(&t));
			//srand(time(NULL));
			st.rollno=rand()%100;
			outFile.write((char *) & st,sizeof(student));
       //	}
	cout<<"\n\tEnrollment number generated: "<<st.rollno;
	outFile.close();
	getch();

}

void student :: getData()
{
	clrscr();
	cin.ignore();
	cout<<"\n\n\n\n\t\t''ENROLLMENT''\n";
	cout<<"\n\tEnter the details as follows...\n";
	cout<<"\n\tEnter your First name: "; gets(fname);
	cout<<"\tEnter your Last name: "; gets(lname);
	cout<<"\tEnter your Address: "; gets(add);
	cout<<"\tEnter your Email Id: "; gets(id);
	cout<<"\tEnter your School Name: "; gets(school_name);
	cout<<"\tEnter your Guardian Name: "; gets(guardian_name);
	cout<<"\tEnter your Guardian's contact no: "; cin>>gno;
	cout<<"\tEnter your Age: "; cin>>age;
	cout<<"\tEnter your Personal contact no: "; cin>>no;
	cout<<"\tEnter your CGPA: "; cin>>cgpa;

	clrscr();
	cout<<"\n\n\t\t\t''BATCH INFORMATION''\n";

	cout<<"\n\t1.MORNING BATCH\n";
	cout<<"\n\t  Time Slot: 10:00 am to 2:00 pm ";
	cout<<"\n\t  Physics By: Mr. Prateek Narang";
	cout<<"\n\t  Chemistry By: Mr. Anushray Gupta";
	cout<<"\n\t  Maths By: Mr. Ajay Mittal";

	cout<<"\n\n\t2.EVENING BATCH\n";

	cout<<"\n\t  Time Slot: 3:00 am to 7:00 pm ";
	cout<<"\n\t  Physics By: Mr. Sanjay Bansal";
	cout<<"\n\t  Chemistry By: Ms. Konika Sen";
	cout<<"\n\t  Maths By: Ms. Sanjana Kakkar";

	do
	{
		cout<<"\n\n\tEnter your choice 'MORNING - M', 'EVENING-E' :"; cin>>batch;
	}while(batch!='M' && batch!='E' && batch!='m'&& batch!='e');


}


void student :: receipt()
{
	clrscr();
	cout<<"\n\n\t\t\t''FINAL RECEIPT''\n";
	cout<<"\n\tEnrollment Number :"<<rollno;
	cout<<"\n\n\tName: "<<fname<<" "<<lname;
	cout<<"\n\tEmail Id: "<<id;
	cout<<"\n\tContact no: "<<no;

	if(pmode==1)
	{
		cout<<"\n\tAmount Paid: "<<amt;
	}
	else if(pmode==2)
	{
		cout<<"\n\tCheque Details: ";
		cout<<"\n\t\tBank Name: "<<bname;
		cout<<"\n\t\tAmount Paid: "<<amt;
		cout<<"\n\t\tCheque Number: "<<cno;
	}

	cout<<"\n\n\tDate of Joining: 1st April 2018 ";
	cout<<"\n\n\tBatch Allotted: ";
	if(batch=='M' || batch=='m')
		cout<<"Morning ('10:00 am to 2:00 pm')";
	else if(batch=='E' || batch=='e')
		cout<<"Evening ('3:00 am to 7:00 pm')";

	cout<<"\n\n\tTHANKYOU FOR JOINING ";
	cout<<"\n\tSEE YOU SOON!! ";
	//menu();
}

void student :: showData()
{
	clrscr();
	cout<<"\n\tEnrollment Number :"<<rollno;
	cout<<"\n\n\tFirst name: "<<fname;
	cout<<"\n\tLast name: "<<lname;
	cout<<"\n\tAge: "<<age;
	cout<<"\n\tAddress: "<<add;
	cout<<"\n\tEmail Id: "<<id;
	cout<<"\n\tPersonal contact no: "<<no;
	cout<<"\n\tSchool Name: "<<school_name;
	cout<<"\n\tCGPA: "<<cgpa;
	cout<<"\n\tGuardian Name: "<<guardian_name;
	cout<<"\n\tGuardian's contact no: "<<gno;

	cout<<"\n\n\tBatch Allotted: ";
	if(batch=='M' || batch=='m')
		cout<<"Morning ('10:00 am to 2:00 pm')";
	else if(batch=='E' || batch=='e')
		cout<<"Evening ('3:00 am to 7:00 pm')";
}

class record: public student
{
	public:
	void write_student();
	void display_all();
	void display_sp();
	void modify();
	void delete_rec();
	void final_statement();

}r1;

void student :: payment()
{
	clrscr();
	cout<<"\n\n\n\n\t\t\t''PAYMENT''\n";

	cout<<"\n\t1.Cash";
	cout<<"\n\t2.Cheque";
	cout<<"\n\tEnter your mode of payment: ";	cin>>pmode;

	if(pmode==2)
	{
		cin.ignore();
		cout<<"\n\n\t''Cheque Details''\n";
		cout<<"\tBank Name: "; gets(bname);
		cout<<"\tTotal Amount Paid: "; cin>>amt;
		cout<<"\tCheque Number: "; cin>>cno;
	}
	else if(pmode==1)
	{
		cin.ignore();
		cout<<"\n\n\t''Cash Details''\n";
		cout<<"\tTotal Amount Paid: "; cin>>amt;
	}
}

void record ::write_student()
{
	student st;
	time_t t;
	fstream outFile;
	outFile.open("student.dat",ios::binary|ios::app);
	st.getData();
	srand((signed) time(&t));
	st.rollno=rand()%100;
	//st.reserve();

	cout<<"\n\tEnrollment number generated: "<<st.rollno;
	st.payment();
	outFile.write((char *) &st, sizeof(student));

	outFile.close();
	cout<<endl<<"\n\tStudent record Has Been Created.";
	getch();
	r1.final_statement();
	cin.ignore();
	//getch();
}

void record :: final_statement()
{
	student st;
	ifstream inFile;
	inFile.open("student.dat",ios::binary);

	if(!inFile)
	{
		cout<<endl<<"\n\tFile could not be open !! Press any Key...";
		getch();
		//return;
	}

	while(inFile.read((char *) &st, sizeof(student)))
	{

	}
	cout<<"\n\n\t\t======================================\n";
		st.receipt();
	cout<<"\n\n\t\t======================================\n";

	inFile.close();
	//menu();
}

void record ::display_all()
{
	clrscr();
	student st;
	ifstream inFile;
	inFile.open("student.dat",ios::binary);
	inFile.seekg(0);
	if(!inFile)
	{
		cout<<endl<<"\n\tFile could not be open !! Press any Key...";
		getch();
		return;
	}

	cout<<"\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";

	while(inFile.read((char *) &st, sizeof(student)))
	{
		st.showData();
		cout<<"\n\n\t\t\t====================================\n";
	}

	inFile.close();
	//database();
	//getch();
}

void record :: display_sp()
{
	clrscr();
	int flag=0;
	int num;
	student st;
	ifstream inFile;
	inFile.open("student.dat",ios::binary);

	inFile.seekg(0);
	if(!inFile)
	{
		cout<<endl<<"\tFile could not be open !! Press any Key...";
		getch();
		return;

	}
	cout<<"\n\n\tPlease Enter The roll number: ";
	cin>>num;
	//cout<<st.retrollno();
	while(inFile.read((char *) &st, sizeof(student)))
	{
		if(st.rollno==num)
		{
			 st.showData();
			 cout<<"\n\n\t\t====================================\n";
			 flag=1;
			 break;
		}

	}

	if(flag==0)
	{
		cout<<endl<<"\n\tRecord not exist...";
	}
	inFile.close();
	//database();
	//getch();

}

void record :: modify()
{
	clrscr();
	int flag=0;
	int num;
	student st;
	fstream inFile;
	inFile.open("student.dat",ios::binary|ios::in|ios::out);

	inFile.seekg(0);
	if(!inFile)
	{
		cout<<endl<<"\tFile could not be open !! Press any Key...";
		getch();
		return;

	}
	cout<<"\n\n\tPlease Enter The roll number: ";
	cin>>num;
	//cout<<st.retrollno();
	while(inFile.read((char *) &st, sizeof(student)) && flag==0)
	{
		if(st.rollno==num)
		{
			 st.showData();
			 cout<<"\n\nPlease enter the new details of student"<<endl;
			 st.getData();
			 int pos=(-1)*sizeof(st);
			 inFile.seekp(pos,ios::cur);
			 inFile.write((char *) &st, sizeof(student));
			 cout<<"\n\tRecord Updated.";
			 flag=1;
		}

	}
	inFile.close();

	if(flag==0)
	{
		cout<<endl<<"\n\tRecord not exist...";
	}
	//database();
	//getch();

}

void record :: delete_rec()
{
	clrscr();
	int flag=0;
	int num;
	student st;
	fstream inFile,outFile;
	inFile.open("student.dat",ios::binary|ios::in|ios::out);

	//inFile.seekg(0);
	if(!inFile)
	{
		cout<<endl<<"\tFile could not be open !! Press any Key...";
		getch();
		return;

	}
	cout<<"\n\n\tPlease Enter The roll number: ";
	cin>>num;
	//cout<<st.retrollno();
	outFile.open("Temp.dat",ios::out);
	inFile.seekg(0,ios::beg);

	while(inFile.read((char *) &st, sizeof(student)))
	{
		if(st.rollno!=num)
		{
			 outFile.write((char *) &st, sizeof(student));
			 //st.showData();
			 //cout<<"\n\n\t\t====================================\n";
			 //flag=1;
			 //break;
		}
		outFile.close();
		inFile.close();
		remove("student.dat");
		rename("Temp.dat","student.dat");
		cout<<endl<<"\n\tRecord Deleted successfully.";
		flag=1;
	}

	if(flag==0)
	{
		cout<<endl<<"\n\tRecord not exist...";
	}
	//inFile.close();
	//database();
	//getch();
}

int student_register()
{
	clrscr();
	cout<<"\n\t\t\tEXCEL CLASSES\n";
	cout<<"\t\tIIT JEE Entrance exam Crash Course\n";

	cout<<"\nOur goal is to provide knowledge and thereby create an environment";
	cout<<"that guides \nstudents to the path of success, and ";
	cout<<"inspires them to explore their own \npotential.";
	cout<<"\nExcel Classes is run by a group of Ex-IITians,";
	cout<<"who have over the years, guided \nthousands of IIT ";
	cout<<"aspirants to fulfill their dream of getting into ";
	cout<<"the \nprestigious IITs.\n";

	cout<<"\n''Necessary Details''";
	cout<<"\nDuration: 90 days ";
	cout<<"\nClasses : Thrice a week";
	cout<<"\nSubjects: Physics,Chemistry and Maths";
	cout<<"\nFees    : 50,000 /-";
	char choice;
	cout<<"\n\nDo you want to enrol? (y/n)";
	cin>>choice;

	if(choice=='Y' || choice=='y'){
		r1.write_student();
	}
	else
	{
	       menu();
	}

	return 0;
}

//ADMINISTRATOR MENU
void database()
{
	clrscr();
	char *password;
	char *pass="12345678";
	student st;
	int ch;
	cout<<endl<<endl;
	password=getpass("Enter the administrator password:");
	//cout<<"\n\nEnter the ad	mininistrator password:";
	//cin>>password;


	if(strcmp(pass,password)!=0)
	{
		cout<<"\n\nEnter the password correctly \n";
		cout<<"You are not permitted to log into this mode.\n";
		//database();
	}
	if(strcmp(pass,password)==0)
	{
			clrscr();
			cout<<"\n\t\t\tADMINISTRATOR MENU\n";

			cout<<"\n\t1.Display all student details";
			cout<<"\n\t2.Display specific student details";
			cout<<"\n\t3.Modify specific record";
			cout<<"\n\t4.Delete specific record";
			cout<<"\n\t5.Exit";

			cout<<"\n\n\tEnter your choice:";cin>>ch;
			cout<<endl;
			switch(ch)
			{
				case 1:	r1.display_all();
						break;

				case 2:	r1.display_sp();
						break;

				case 3: r1.modify();
						break;

				case 4: r1.delete_rec();
						break;

				case 5: menu();
						break;

				default :
						break;
			}
	}
	return;

}

void main()
{
	menu();
	getch();//return 0;
}

void menu()
{
	clrscr();
	cout<<"\n\t\t\tWelcome to EXCEL CLASSES\n";
	cout<<"\t\t\t  (Path to Success)\n";

	int ch;
	cout<<"\n1.Admin\n2.User\n3.Exit\n";
	cout<<"\nEnter your choice:";
	cin>>ch;

	switch(ch)
	{
		case 1: database();
				break;

		case 2: student_register();
				break;

		default : break;
	}

}
