#include<iostream>
#include<fstream>
#include<cstdlib>

using std::fstream;
using std::ofstream;
using std::ifstream;
using std::ios;
using std::cout;
using std::cin;
using std::endl;

class bankAccount
{
private:
    char accountNumber[20];
    char firstName[10];
    char lastName[10];
    float Balance;
    
public:
    void dataInput(); 		//for getting datas from the user 
    void dataPrint();		//for showing datas
    void recordWrite();		//writing record informations in file operation
    void recordRead();		//reading record information
    void recordFind();		//for searching through accounts 
    void recordEdit();		//for rearrange the accouns (delete,update,etc...)
    void recordDelete();    //for removing existing account informations
};
void bankAccount::dataInput()
{
    cout<<"\n Please Enter The Account Number: ";
    cin>>accountNumber;
    cout<<"Please Enter First Name: ";
    cin>>firstName;
    cout<<"Please Enter Last Name: ";
    cin>>lastName;
    cout<<"Please Enter The Balance: ";
    cin>>Balance;
    cout<<endl;
}
void bankAccount::dataPrint()
{
    cout<<"Account Number: "<<accountNumber<<endl;  // printing account informations
    cout<<"First Name: "<<firstName<<endl;
    cout<<"Last Name: "<<lastName<<endl;
    cout<<"Net Balance:   $"<<Balance<<endl;
    cout<<"-------------------------------"<<endl;
}
void bankAccount::recordWrite()
{
    ofstream outfile;
    outfile.open("bank.account", ios::binary|ios::app); 	// Open in binary mode and All output operations are performed at the end of the file, 
    dataInput();                                        	//appending the content to the current content of the file.
    outfile.write(reinterpret_cast<char *>(this), sizeof(*this));  //casting operator for changing pointer to character
    outfile.close();
}
void bankAccount::recordRead()
{
    ifstream infile;
    infile.open("bank.account", ios::binary); // open file in binary mode
    if(!infile)
    {
        cout<<"Error in Opening! File Not Found!!"<<endl;
        return;
    }
     
    cout<<"\n****Data from file****"<<endl;
    
    while(!infile.eof())                  // while infile is not reach end of file
    {
        if(infile.read(reinterpret_cast<char*>(this), sizeof(*this))>0)   //casting operator for changing pointer to character
        {
            dataPrint();
        }
    }
    infile.close();
}
void bankAccount::recordFind()
{
    int temp;
    ifstream infile;
    infile.open("bank.account", ios::binary);
    if(!infile)
    {
        cout<<"\n Error while file opening! File Not Found!"<<endl;
        return;
    }
    infile.seekg(0,ios::end);
    int count = infile.tellg()/sizeof(*this);
    cout<<"\n There are "<<count<<" record in the file";
    cout<<"\n -Please Enter The Order Of The Account You Want To Search: ";
    cin>>temp;
    infile.seekg((temp-1)*sizeof(*this));
    infile.read(reinterpret_cast<char*>(this), sizeof(*this));  //casting operator for changing pointer to character
    dataPrint();
}
void bankAccount::recordEdit()
{
    int temp;
    fstream iofile;
    iofile.open("bank.account", ios::in|ios::binary);
    if(!iofile)
    {
        cout<<"\n Error! File Not Found!"<<endl;
        return;
    }
    iofile.seekg(0, ios::end);
    int count = iofile.tellg()/sizeof(*this);
    cout<<"\n There are "<<count<<" record in the file";
    cout<<"\n -Please Enter The Order Of The Account You Want To Update: ";
    cin>>temp;
    iofile.seekg((temp-1)*sizeof(*this));
    iofile.read(reinterpret_cast<char*>(this), sizeof(*this));
    cout<<"Record "<<temp<<" has following data"<<endl;
    dataPrint();
    iofile.close();
    iofile.open("bank.account", ios::out|ios::in|ios::binary);
    iofile.seekp((temp-1)*sizeof(*this));
    cout<<"\nPlease Enter Data To Modify "<<endl;
    dataInput();
    iofile.write(reinterpret_cast<char*>(this), sizeof(*this));
}
void bankAccount::recordDelete()
{
    int temp;
    ifstream infile;
    infile.open("bank.account", ios::binary);
    if(!infile)
    {
        cout<<"\nError in opening! File Not Found!!"<<endl;
        return;
    }
    infile.seekg(0,ios::end);
    int count = infile.tellg()/sizeof(*this);
    cout<<"\n There are "<<count<<" record in the file";
    cout<<"\n -Please Enter The Order Of The Account You Want To Delete: ";
    cin>>temp;
    fstream tmpfile;
    tmpfile.open("tmpfile.bank", ios::out|ios::binary);
    infile.seekg(0);
    for(int i=0; i<count; i++)
    {
        infile.read(reinterpret_cast<char*>(this),sizeof(*this));
        if(i==(temp-1))
            continue;
        tmpfile.write(reinterpret_cast<char*>(this), sizeof(*this));
    }
    infile.close();
    tmpfile.close();
    remove("bank.account");
    rename("tmpfile.bank", "bank.account");
}
int main()
{
    bankAccount Account;
    int choice;
    cout<<"---Welcome To Bank Acount Management System ---"<<endl;
    while(true)
    {
    	cout<<"Please Select One Of The Option Below ";
        cout<<"\n\tOption1-->Add Bank Record To The  System";
        cout<<"\n\tOption2-->Show record from file";
        cout<<"\n\tOption3-->Search Record from file";
        cout<<"\n\tOption4-->Update Record";
        cout<<"\n\tOption5-->Delete Record";
        cout<<"\n\tOption6-->Quit";
        cout<<"\nPlease Enter Your Choice: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            Account.recordWrite();
            break;
        case 2:
            Account.recordRead();
            break;
        case 3:
            Account.recordFind();
            break;
        case 4:
            Account.recordEdit();
            break;
        case 5:
            Account.recordDelete();
            break;
        case 6:
            exit(0);
            break;
        default:
            cout<<"\nYour choice is incorrect ! Please Enter Proper Choice";
            exit(0);
        }
    }
    system("pause");
    return 0;
}
