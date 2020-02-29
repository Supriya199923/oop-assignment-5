//Name: Supriya Das   Roll-301910501008
//4.	Each cricketer has name, date of birth and matches played. Cricketer may be a bowler or batsman. For a bowler, number of wickets taken, average economy is stored. For a batsman, total runs scored, average score is stored.  A double wicket pair is formed taking a bowler and a batsman. An all-rounder is both a bowler and batsman. Support must be there to show the details of a cricketer, bowler, batsmen, all-rounder and the pair.
//Design the classes and implement.

#include<iostream>
using namespace std;

class Cricketer
{
    public:
    char  name[31];
    char  dob[31];
    int matches;
    Cricketer()
    {

    }
    virtual void  show_details()
    {
        cout<<"Name:"<<name<<" "<<"DOB: "<<dob<<" "<<"\nMatches Played : "<<matches<<endl;
    }
    virtual void get_details()
    {
        cout<<"\nEnter name : ";
        cin>>name;
        cout<<"Enter Date of Birth (ddmmyyyy) : ";
        cin>>dob;
        cout<<"Enter Matches Played : ";
        cin>>matches;

    }
};

class Bowler: public virtual Cricketer
{
    public:
    int wickets_taken;
    float economy;
    Bowler()
    {
    }
    void get_details()
    {
        Cricketer::get_details();
        cout<<"\nEnter Wickets Taken : ";
        cin>>wickets_taken;
        economy=float(wickets_taken)/matches;
    }
    void show_details()
    {
        Cricketer::show_details();
        cout<<"\nNo. Of Wickets Taken : "<<wickets_taken<<"\tEconomy : "<<economy<<endl;
    }
};

class Batsman:public virtual Cricketer
{
    public:
    int total_score;
    float avg_score;
    Batsman()
    {}
    void get_details()
     {   Cricketer::get_details();
        cout<<"\nEnter Total Score :";
        cin>>total_score;
        avg_score=float(total_score)/matches;
    }
    void show_details()
    {
        Cricketer::show_details();
        cout<<"\nTotal Runs : "<<total_score<<"\nAverage : "<<avg_score<<endl;
    }
};

class paired:public Batsman,public Bowler
{
public:
    paired():Batsman(),Bowler()
    {

    }
    void get_details()
    {
        Batsman::get_details();
        Bowler::get_details();
    }

    void show_details()
    {
        Batsman::show_details();
        Bowler::show_details();
    }
};

class All_rounder:public Batsman,public Bowler
{
    public:
  /*  All_rounder():Batsman(),Bowler()
    {

    }*/
    void get_details()
    {
        Cricketer::get_details();
        cout<<"\nEnter wickets taken:";
        cin>>wickets_taken;
        economy=float(wickets_taken)/matches;
        cout<<"\nEnter total_score:";
        cin>>total_score;
        avg_score=float(total_score)/matches;

    }

    void show_details()
    {
        Cricketer::show_details();
        cout<<"\nNo of wickets taken "<<wickets_taken<<" Average economy is "<<economy<<endl;
        cout<<"\nTotal runs scored "<<total_score<<" Average score is "<<avg_score<<endl;       
    }
};


int main()
{
    Cricketer *arr[100];
    int count=0;
    int choice;
    while(1)
    {
        cout<<"\n1.New Batsman\n2.New Bowler\n3.Double Wicket Pair\n4.New All Rounder\n0.Terminate\n\t\t\tEnter Your Choice : ";
        cin>>choice;
        if(choice==0)
        {
            break;
        }
        else
        {
            switch(choice)
            {
                case 1:
                arr[count]=new Batsman;
                arr[count]->get_details();
                arr[count]->show_details();
                count++;
                break;
                case 2:
                arr[count]=new Bowler;
                arr[count]->get_details();
                arr[count]->show_details();
                count++;
                break;
                case 3:
                arr[count]=new paired;
                arr[count]->get_details();
                arr[count]->show_details();
                count++;
                break;
                case 4:
                arr[count]=new All_rounder;
                arr[count]->get_details();
                arr[count]->show_details();
                count++;
                break;              
            }
        }
    }
    return 0;
}

