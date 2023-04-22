//Code Written by Bharathi Shankar J and Benny Abhishek

#include <iostream>
#include <string.h>
#include <fstream>
#include <ctime>
#include <iomanip>
using namespace std;

string displaygender(char);
struct date
{
    int d,m,y;
    void setDate()
    {
        cin>>d>>m>>y;
        if(d>31 || d<1 || m>12 || m<1 || y<1900 || y>2022)
        {
            cout<<"Invalid date! Enter date(dd mm yyy) again: ";
            setDate();
        }
    }
    void getDate()
    {
        cout<<d<<"/"<<m<<"/"<<y;
    }
    int findDifference(date a)
    {
        int res;
        if(a.m>m && a.d>d)
        {
            res=a.y-y;
        }
        else
        {
            res=(a.y-y)-1;
        }
        return res;
    }
};
class person
{
public:
    char name[30];
    int age;
    char gender;
    float weight;
    float height;
    date DOB;
public:
    void details();
    void display();
    string getName();
    void displayf();
};
void person::displayf()
{
    cout<<name<<setw(10)<<age<<setw(10)<<displaygender(gender)<<setw(10)<<height<<setw(10)<<weight<<setw(10);DOB.getDate();cout<<setw(15);
}
/*string person::getName()
{
    return name;
}*/
void person::details()
{
    cin.ignore(1);
    cout<<"Enter Name: ";
    cin.getline(name,30);
    l1:cout<<"Enter age: ";
    cin>>age;
    if(age<18)
    {
        cout<<"Person is a minor! Re-enter age"<<endl;
        goto l1;
    }
    l2:cout<<"Enter Gender(m/f/t): ";
    cin>>gender;
    if(gender!='f'&& gender!='m'&& gender!='t')
    {
        cout<<"Invalid gender!"<<endl;
        goto l2;
    }
    l3:cout<<"Enter height(in cms):";
    cin>>height;
    cout<<"Weight(in kgs): ";
    cin>>weight;
    if(height<0 || weight<0)
    {
        cout<<"Invalid Height And Weight.. Re enter"<<endl;
        goto l3;
    }
    cout<<"Enter Date of Birth(dd mm yyyy): ";
    DOB.setDate();
}
void person::display()
{
    cout<<"              DETAILS             \n";
    cout<<"-------------------------------------"<<endl;
    cout<<"Name    :"<<name<<endl;
    cout<<"Age     :"<<age<<endl;
    cout<<"Gender  :"<<displaygender(gender);cout<<endl;
    cout<<"Height  :"<<height<<" cms"<<endl;
    cout<<"Weight  :"<<weight<<" kgs"<<endl;
    cout<<"DOB     :";DOB.getDate();
    cout<<endl;
}
string displaygender(char m)
{
    string s;
    switch(m)
    {
        case 'm':s="Male";return s;
        case 'f':s="Female";return s;
        case 't':s="Transgender";return s;
        default:return s;
    }
}
class prisoner:virtual public person
{
protected:
    int prisoner_id;
    int years_of_imprisonment;
    date DOI;
    int yearsleft;
    char crime[20];
public:
    prisoner(){yearsleft=0;}
    void details();
    void prisoner_search();
    void update_sentence();
    int getid();
    void calcyearsLeft()
    {
        time_t t = time(NULL);
        tm* tPtr = localtime(&t);
        date temp;
        int tp;
        temp.d=tPtr->tm_mday;
        temp.m=tPtr->tm_mon+1;
        temp.y=tPtr->tm_year+1900;
        tp=DOI.findDifference(temp);
        yearsleft=years_of_imprisonment-tp;
        if(yearsleft<0)
        {
           yearsleft=0;
        }
    }
    void display()
    {
        person::display();
        cout<<"Prisoner ID:"<<prisoner_id<<endl;
        cout<<"Cause of imprisonment:"<<crime<<endl;
        cout<<"Date of entry: ";DOI.getDate();cout<<endl;
        cout<<"Years of imprisonment: "<<years_of_imprisonment<<endl;

    }
    void displayf()
    {
        cout<<prisoner_id<<"\t";
        person::displayf();
        DOI.getDate();
        cout<<setw(20)<<crime;
        cout<<setw(20)<<yearsleft<<endl;
    }
    int getyears()
    {
        return yearsleft;
    }
    char* getcrime()
    {
        return crime;
    }
};
int prisoner::getid()
{
    return prisoner_id;
}
void prisoner::update_sentence()
{
    years_of_imprisonment-=2;
}
void prisoner::prisoner_search()
{
    char name1[20];
    cout<<"Enter name you want to search: ";
    cin>>name1;
}
void prisoner::details()
{
    person::details();
    cout<<"Enter Prisoner ID: ";
    cin>>prisoner_id;
    cout<<"Enter date of entry(dd mm yyyy): ";DOI.setDate();
    cout<<"Enter Cause of imprisonment:";
    cin.ignore(1);
    cin.getline(crime,20);
    cout<<"Enter Years of Punishment: ";
    cin>>years_of_imprisonment;
    calcyearsLeft();
}

class worker:virtual public person
{
protected:
    int id;
    float salary;
    char position[20];
public:
    void details();
    void show();
    int getempid();
    void displayf()
    {
        cout<<id<<"\t";
        person::displayf();
        cout<<position<<"\t"<<salary<<endl;
    }
    void increaseSalary(float sal)
    {
        salary+=sal;
    }
};
int worker::getempid()
{
    return id;
}
void worker::details()
{
    person::details();
    cout<<"Enter Emp Id: ";
    cin>>id;
    cout<<"Enter salary: ";
    cin>>salary;
    cout<<"Enter Position: ";
    cin>>position;
}
void worker::show()
{
    person::display();
    cout<<"Empid   :"<<id<<endl;
    cout<<"Salary  :"<<salary<<endl;
    cout<<"Positon :"<<position<<endl;
}
class prisonerworker:public virtual prisoner,public virtual worker
{
public:
    prisonerworker(){strcpy(position,"labourer");salary=500;}
    void displaypw()
    {
        person::display();
        cout<<"Prisoner ID:"<<prisoner_id<<endl;
        cout<<"Date of entry: ";DOI.getDate();cout<<endl;
        cout<<"Years of imprisonment: "<<years_of_imprisonment<<endl;
        cout<<"Salary  :"<<salary<<endl;
        cout<<"Positon :"<<position<<endl;
    }
    void details()
    {
        person::details();
        cout<<"Enter Prisoner ID: ";
        cin>>prisoner_id;
        cout<<"Enter date of entry(dd mm yyyy): ";DOI.setDate();
        cout<<"Enter Years of Punishment: ";
        cin>>years_of_imprisonment;
        calcyearsLeft();
    }
    void displaypwf()
    {
        cout<<prisoner_id<<"\t";
        person::displayf();
        DOI.getDate();
        cout<<setw(20)<<yearsleft<<setw(10)<<position<<setw(10)<<salary;
    }
};
fstream file;
void addprecord()
{
    //fstream file;
    prisoner p;
    file.open("prisoner.bin",ios::binary|ios::out|ios::app);
    if(!file)
    {
        cout<<"Cannot Open File!"<<endl;
        exit(1);
    }
    else
    {
        p.details();
        file.write((char*)&p,sizeof(p));
    }
    file.close();
    cout<<"Record Added Successfully!"<<endl;
}
void searchprecord()
{
    fstream file;
    prisoner p;
    int pid;
    cout<<"Enter prisoner ID to find: ";
    cin>>pid;
    file.open("prisoner.bin",ios::binary|ios::in);
    while(file.read((char*)&p,sizeof(p)))
    {
        if(p.getid()==pid)
        {
            p.display();
            break;
        }
    }
    file.close();
}
void displayprecords()
{
    //fstream file;
    prisoner p;
    file.open("prisoner.bin",ios::binary|ios::in);
    if(!file)
    {
        cout<<"Cannot Open File!"<<endl;
    }
    cout<<"\t\tPRISONER RECORDS"<<endl;
    cout<<"================================================================================================================================"<<endl;
    cout<<"ID"<<setw(10)<<"Name"<<setw(10)<<"Age"<<setw(10)<<"Gender"<<setw(10)<<"Height"<<setw(10)<<"Weight"<<setw(20)<<"Date of Birth"<<setw(20)<<"Date of Entry"<<setw(20)<<"Crime"<<setw(20)<<"Years Left"<<endl;
    cout<<"---------------------------------------------------------------------------------------------------------------------------------"<<endl;
    while(file.read((char*)&p,sizeof(p)))
    {
        p.displayf();
    }
    file.close();
}
void deleteprecord()
{
    int pid;
    prisoner p;
    ofstream fout;
    ifstream fin;
    cout<<"Enter ID of prisoner to delete from record: ";
    cin>>pid;
    fout.open("prisoner_new.bin",ios::binary);
    fin.open("prisoner.bin",ios::binary);
    //validation
    while(fin.read((char*)&p,sizeof(p)))
    {
        if(p.getid()!=pid)
        {
            fout.write((char*)&p,sizeof(p));
        }
    }
    fout.close();
    fin.close();
    remove("prisoner.bin");
    rename("prisoner_new.bin","prisoner.bin");
}
void increment()
{
    fstream file;
    worker w;
    int size,wid;
    float s;
    cout<<"Enter ID of worker to provide incerement: ";
    cin>>wid;
    cout<<"Enter increment amount: ";
    cin>>s;
    file.open("worker.bin",ios::binary|ios::out|ios::in);
    if (!file)
    {
        cerr<<endl<<"Error opening File!";
        exit(1);
    }
    else
    {
        while(!file.eof())
        {
            size=file.tellg();
            file.read((char*)&w,sizeof(w));
            if(w.getempid()==wid)
            {
                w.increaseSalary(s);
                file.seekp(size);
                file.write((char*)&w,sizeof(w));
                break;
            }
        }
    }
}
void updateprecords()
{
    ofstream fout;
    ifstream fin;
    prisoner p;
    fin.open("prisoner.bin",ios::binary|ios::in);
    fout.open("prisoner_new.bin",ios::binary|ios::out);
    //validation
    while(fin.read((char*)&p,sizeof(p)))
    {
        if(p.getyears()!=0)
        {
            fout.write((char*)&p,sizeof(p));
        }
    }
    fout.close();
    fin.close();
    rename("prisoner.bin","old_prisoners.bin");
    rename("prisoners_new","prisoner.bin");
}
void checkbehaviour()
{
    int flag=0,pid,pts=0;
    fstream f1;
    fstream f2;
    prisoner p;
    prisonerworker pw;
    cout<<"Enter ID of prisoner to check behaviour: ";
    cin>>pid;
    f1.open("prisoner.bin",ios::binary|ios::in);
    f2.open("prisonerworker.bin",ios::binary|ios::in);
    //validation
    while(f1.read((char*)&p,sizeof(p)))
    {
        if(p.getid()==pid)
        {
            while(f2.read((char*)&pw,sizeof(pw)))
            {
                if(strcmp(p.name,pw.name)==0)
                {
                    pts+=1;
                    cout<<"1.Prisoner works as a labourer.."<<endl;
                    break;
                }
            }
            if(pts==0)
            {
                cout<<"1.Prisoner does not work for prison.."<<endl;
            }
            f2.close();
            if(strcmp(pw.getcrime(),"theft")==0||strcmp(pw.getcrime(),"underagedriving")==0||strcmp(pw.getcrime(),"trespassing")==0)
            {
                pts+=1;
                cout<<"2.Prisoner was arrested for a petty crime.."<<endl;
                break;
            }
            else
            {
                cout<<"2.Prisoner was arrested for a serious crime.."<<endl;
                break;
            }
        }
    }
    if(pts==2)
    {
        cout<<endl<<"Prisoner shows good behaviour..Reduced sentence by 2 years.."<<endl;
        p.update_sentence();
    }
    else
        cout<<endl<<"Prisoner does not show good behaviour.."<<endl;
    f2.close();
}
void managePrisoner()
{
    int pc;
    do
    {
        cout<<endl<<"-----------------------------------"<<endl;
        cout<<"\tPRISONERS"<<endl;
        cout<<"-----------------------------------"<<endl;
        cout<<"1.Add record\n2.Display all records\n3.Search Prisoner\n4.Check prisoner behaviour\n5.Refresh Prison records\n6.Delete record\n7.Back to Main menu"<<endl;
        cout<<"Enter your choice: ";
        cin>>pc;
        switch(pc)
        {
        case 1:addprecord();break;
        case 2:displayprecords();break;
        case 3:searchprecord();break;
        case 4:checkbehaviour();break;
        case 5:updateprecords();break;
        case 6:deleteprecord();break;
        }
    }while(pc!=7);

}
void addwrecord()
{
    fstream file;
    worker w;
    file.open("worker.bin",ios::binary|ios::out|ios::app);
    if(!file)
    {
        cout<<"Cannot Open File!"<<endl;
        exit(1);
    }
    else
    {
        w.details();
        file.write((char*)&w,sizeof(w));
    }
    file.close();
    cout<<"Record Added Successfully!"<<endl;
}
void displaywrecords()
{
    fstream file;
    worker w;
    file.open("worker.bin",ios::binary|ios::in);
    if(!file)
    {
        cout<<"Cannot Open File!"<<endl;
    }
    cout<<"\t\tWORKER RECORDS"<<endl;
    cout<<"=========================================================================================="<<endl;
    cout<<"ID\tName\tAge\tGender\tHeight\tWeight\tDate of Birth\tPosition\tSalary"<<endl;
    cout<<"------------------------------------------------------------------------------------------"<<endl;
    while(file.read((char*)&w,sizeof(w)))
    {
        w.displayf();
    }
    file.close();
}
void searchwrecord()
{
    fstream file;
    worker w;
    int wid;
    cout<<"Enter worker ID to find: ";
    cin>>wid;
    file.open("worker.bin",ios::binary|ios::in);
    while(file.read((char*)&w,sizeof(w)))
    {
        if(w.getempid()==wid)
        {
            w.show();
            break;
        }
    }
    file.close();
}
void deletewrecord()
{
    int wid;
    worker w;
    ofstream fout;
    ifstream fin;
    cout<<"Enter ID of worker to delete from record: ";
    cin>>wid;
    fout.open("worker_new.bin",ios::binary|ios::app);
    fin.open("worker.bin",ios::binary);
    //validation
    while(fin.read((char*)&w,sizeof(w)))
    {
        if(w.getempid()!=wid)
        {
            fout.write((char*)&w,sizeof(w));
        }
    }
    fout.close();
    fin.close();
    remove("worker.bin");
    rename("worker_new.bin","worker.bin");
}
void manageWorker()
{
    int wc;
    do
    {
        cout<<endl<<"-----------------------------------"<<endl;
        cout<<"\tWORKERS"<<endl;
        cout<<"-----------------------------------"<<endl;
        cout<<"1.Add record\n2.Display all records\n3.Search Worker\n4.Increment Salary\n5.Delete record\n6.Back to Main menu"<<endl;
        cout<<"Enter your choice: ";
        cin>>wc;
        switch(wc)
        {
        case 1:addwrecord();break;
        case 2:displaywrecords();break;
        case 3:searchwrecord();break;
        case 4:increment();break;
        case 5:deletewrecord();break;
        default:
            break;
        }
    } while (wc!=6);
}

void addpwrecord()
{
    //fstream file;
    prisonerworker pw;
    file.open("prisonerworker.bin",ios::binary|ios::out|ios::app);
    if(!file)
    {
        cout<<"Cannot Open File!"<<endl;
        exit(1);
    }
    else
    {
        pw.details();
        file.write((char*)&pw,sizeof(pw));
    }
    file.close();
    cout<<"Record Added Successfully!"<<endl;
}
void searchpwrecord()
{
    fstream file;
    prisonerworker pw;
    int pid;
    cout<<"Enter prisoner ID to find: ";
    cin>>pid;
    file.open("prisonerworker.bin",ios::binary|ios::in);
    while(file.read((char*)&pw,sizeof(pw)))
    {
        if(pw.getid()==pid)
        {
            pw.displaypw();
            break;
        }
    }
    file.close();
}
void displaypwrecords()
{
    //fstream file;
    prisonerworker pw;
    file.open("prisonerworker.bin",ios::binary|ios::in);
    if(!file)
    {
        cout<<"Cannot Open File!"<<endl;
    }
    cout<<"\t\tPRISONER RECORDS"<<endl;
    cout<<"==============================================================================================================================="<<endl;
    cout<<"ID"<<setw(10)<<"Name"<<setw(10)<<"Age"<<setw(10)<<"Gender"<<setw(10)<<"Height"<<setw(10)<<"Weight"<<setw(20)<<"Date of Birth"<<setw(20)<<"Date of Entry"<<setw(20)<<"Years Left"<<setw(10)<<"Position"<<setw(10)<<"Salary"<<endl;
    cout<<"-------------------------------------------------------------------------------------------------------------------------------"<<endl;
    while(file.read((char*)&pw,sizeof(pw)))
    {
        pw.displaypwf();
    }
    file.close();
}
void deletepwrecord()
{
    int pid;
    prisonerworker pw;
    ofstream fout;
    ifstream fin;
    cout<<"Enter ID of prisoner to delete from record: ";
    cin>>pid;
    fout.open("prisonerworker_new.bin",ios::binary);
    fin.open("prisonerworker.bin",ios::binary);
    //validation
    while(fin.read((char*)&pw,sizeof(pw)))
    {
        if(pw.getid()!=pid)
        {
            fout.write((char*)&pw,sizeof(pw));
        }
    }
    fout.close();
    fin.close();
    remove("prisonerworker.bin");
    rename("prisonerworker_new.bin","prisonerworker.bin");
}

void managepw()
{
    int pwc;
    do
    {
        cout<<endl<<"-----------------------------------"<<endl;
        cout<<"\tPRISONER WORKERS"<<endl;
        cout<<"-----------------------------------"<<endl;
        cout<<"1.Add record\n2.Display all records\n3.Search Prisoner worker\n4.Delete record\n5.Back to Main menu"<<endl;
        cout<<"Enter your choice: ";
        cin>>pwc;
        switch(pwc)
        {
        case 1:addpwrecord();break;
        case 2:displaypwrecords();break;
        case 3:searchpwrecord();break;
        case 4:deletepwrecord();break;
        }
    }while(pwc!=5);
}
int main()
{
    int ch;
    do
    {
        cout<<"PRISON MANAGMENT SYSTEM"<<endl;
        cout<<"------------------------------------"<<endl;
        cout<<"1.Manage Prisoners\n2.Manage Workers\n3.Manage prisoner workers\n4.Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1:managePrisoner();break;
            case 2:manageWorker();break;
            case 3:managepw();break;
        }
    }while(ch!=4);

}

