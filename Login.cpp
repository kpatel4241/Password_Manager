#include<iostream>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctime>

using namespace std;

int i;

class Login
{
    string user_name,user_password,new_user_name;
    string fname,lname,e_mail,c_email,dob,new_password,c_password,nn_pw,nn_pw1;
    string Web_site,web_username,web_password,Web_site1,comments;
    long long int contactno;

    public:

    void user_login();
    void user_signup();
    void display_details();
    void random_pw_gen();
    /*void update_details();*/
    void reset_password();
    void date_time();
    void saving_details();
    void input_web_details();
    void display_web_details();

    friend void write_details();
    friend void read_details();
    friend void read_web_details();
    friend void write_web_details();
};



void Login :: input_web_details()
{
	cout<<"\n Enter the Website Name/App name for which you want to save the password : ";
	cin>>Web_site;
	cout<<"\n Enter it's User_Name : ";
	cin>>web_username;
	cout<<"\n Enter it's Password : ";
	cin>>web_password;

	string temp = web_password;

	for(i = 0; (i < 100 && temp[i] != '\0'); i++)
    {
    	 temp[i] = temp[i] + 2;
    }
	cout<<"\n Encrypted Password = "<<temp;
	cout<<"\n Enter any Comments Regarding this ::..\n";
	cin>>comments;
}



void Login :: display_web_details()
{
	cout<<"\n Enter the Website Details that you want to retrive : ";
	cin>>Web_site1;

	if(Web_site == Web_site1)
	{
		cout<<"=========== Here are the Details ===================";
		cout<<"\n User_Name = "<<web_username;
		cout<<"\n Password = "<<web_password;
		cout<<"\n *********** Here are the Comments that you Entered ***********\n"<<comments<<endl;

	}
	else
	{
		cout<<"\n Details for this Website Dosen't Exist.";
	}
}


void Login :: user_login()
{
    cout<<"\n Enter the User_Name : ";
    cin>>user_name;
    cout<<"\n Enter the Password : ";
    cin>>user_password;
    if(new_password != user_password || user_name != new_user_name)
    {
    	cout<<"\n You have entered WRONG DETAILS !!! Login Failed.";
    	exit(0);
    }
    else
    {
    	cout<<"\n Login Success .!!!";
    }
}



void Login :: user_signup()
{
    cout<<"\n Enter your First Name : ";
    cin>>fname;
    cout<<"\n Enter your Last Name : ";
    cin>>lname;
    cout<<"\n Enter your new user_name : ";
    cin>>new_user_name;
    cout<<"\n Enter the Contact Number : ";
    cin>>contactno;
    cout<<"\n Enter your e-Mail ID : ";
    cin>>e_mail;
    cout<<"\n Enter e-Mail again for confirmation : ";
    cin>>c_email;
    if(e_mail == c_email)
        cout<<"\n e-Mail Confirmd."<<endl;
    else
        cout<<"\n e-Mail not Matched !"<<endl;

    cout<<"\n Enter your DOB : ";
    cin>>dob;
    cout<<"\n Enter your new Password : ";
    cin>>new_password;
    cout<<"\n Enter Password again for confirmation : ";
    cin>>c_password;

    if(new_password == c_password)
    {
        cout<<"\n Password Matched! "<<endl;
        cout<<"\n  Thankyou for SigningUp !!!"<<endl;
    }
    else
    {
    	cout<<"\n Password didn't Matched.";
    }
}



void Login :: display_details()
{
    cout<<"\n\n Here are the Details \n\n";
    cout<<"\n Name = "<<fname<< " "<<lname;
    cout<<"\n DOB = "<<dob;
    cout<<"\n e-Mail ID = "<<e_mail;
    cout<<"\n Contact No = "<<contactno;   
}



void Login :: reset_password()
{
    cout<<"\n Enter your new Password : ";
    cin>>nn_pw;
    cout<<"\n Enter your new password again for Confirmation : ";
    cin>>nn_pw1;
    if(nn_pw == nn_pw1)
    {
        cout<<"\n Password Matched!"<<endl;
        new_password = nn_pw;
    }
    else 
    cout<<"\n Password didn't Matched !!! "<<endl;
}


void Login :: random_pw_gen()
{
char alphanum[] =
"0123456789"
"!@#$%^&*"
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"abcdefghijklmnopqrstuvwxyz";

int stringLength = sizeof(alphanum) - 1;


    srand(time(0));
    std::string Str;
    for(unsigned int i = 0; i < 20; ++i)
    {
    Str += alphanum[rand() % stringLength];

    }
    cout << Str << endl;
}



void Login :: date_time()
{ 
	time_t tt; 
    struct tm * ti;  
	time (&tt); 
 
	ti = localtime(&tt); 

	cout<< asctime(ti);
}

fstream f_write,f_read;
Login l;


void write_details()
{
	char ch;
	f_write.open("psw_manager.dat",ios::out|ios::app);
	do
	{
		l.user_signup();
		f_write.write((char*)&l,sizeof(Login));
		cout<<"\n\nDo you want to add more record..(y/n?)";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
	f_write.close();
}


void read_details()
{
	cout<<"\nLOGIN DETAILS\n";
	int flag=0;
	f_read.open("psw_manager.dat",ios::in);
	while(f_read.read((char*)&l,sizeof(Login)))
	{
		
		
			l.display_details();
		 	flag=1;
	}
	
	f_read.close();
	if(flag==0)
		cout<<"\n\nUser doesn't exist";
}


void write_web_details()
{
	char ch;
	f_write.open("web_details.dat",ios::out|ios::app);
	do
	{
		l.input_web_details();
		f_write.write((char*)&l,sizeof(Login));
		cout<<"\n\nDo you want to add more record..(y/n?)";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
	f_write.close();
}



void read_web_details()
{
	cout<<"\nLOGIN DETAILS\n";
	int flag=0;
	f_read.open("web_details.dat",ios::in);
	while(f_read.read((char*)&l,sizeof(Login)))
	
			l.display_web_details();
		 	flag=1;
	
	f_read.close();
	if(flag==0)
		cout<<"\n\nUser doesn't exist";
}



int main()
{
    
    char ch1,ch2;
    int n,i;

    cout<<"\n+------------------------------------------------------------------------+";
    cout<<"\n|                                                                        |";
    cout<<"\n|     ************** WELCOME TO THE LOGIN SYSTEM *****************       |";
    cout<<"\n|                                                                        |";
    cout<<"\n+------------------------------------------------------------------------+\n";

    cout<<"\n Enter the Size : ";
    cin>>n;

    
    do
    {
        cout<<"\n***************** MENU ******************\n\n";
        cout<<"\n 1.LogIn";
        cout<<"\n 2.SignUp";
        cout<<"\n 3.Display Details";
        cout<<"\n 4.Generate Random Password";
        cout<<"\n 5.Reset Password";
        cout<<"\n 6.Input Details of your Website that you want to Save.";
        cout<<"\n 7.Display the Details of Saved Passwords";
        cout<<"\n 8.Exit.";

        cout<<"\n Enter your Choice : ";
        cin>>ch1;


        switch(ch1)
        {
            case '1':
            
            {
                l.user_login();
                break;
            }
            break;

            case '2':
            
            {
                write_details();
            }
            break;            

            case '3':
            {
            	read_details();
            }
            break;

            case '4':
            
            {
                l.random_pw_gen();
            }
            break;

            case '5':
            
            {
                l.reset_password();
                break;
            }
            break;
            
            case '6' : 
            
            {
                write_web_details();
            }
            break;
            
            case '7' : 
            read_web_details(); 
            break;

            case '8':
            exit(0);
            break;

            default : cout<<"\n Wrong Choice !!! "; break;
        }

        cout<<"\n Wanna go to MAIN MENU ? [Y/N] : ";
        cin>>ch2;
    }while(ch2 == 'y' || ch2 == 'Y');

    return 0;
}