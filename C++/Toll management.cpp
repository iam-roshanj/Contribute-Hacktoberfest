#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<conio.h>
#include<fstream>
using namespace std;

class fare_details
{
protected:
    int fee;
public:
    void category1(char jtype)
     {
         switch(jtype)
         {
            case '1': fee=50;
                        break;
            case '2': fee=100;
                        break;
            case '3': fee=2000;
                        break;
        }
     }
     void category2(char jtype)
     {
         switch(jtype)
         {
            case '1': fee=100;
                        break;
            case '2': fee=200;
                        break;
            case '3': fee=2500;
                        break;
        }
     }
     void category3(char jtype)
     {
         switch(jtype)
         {
            case '1': fee=150;
                        break;
            case '2': fee=300;
                        break;
            case '3': fee=6500;
                        break;
        }
     }
     void category4(char jtype)
     {
         switch(jtype)
         {
            case '1': fee=200;
                        break;
            case '2': fee=400;
                        break;
            case '3': fee=7000;
                        break;
        }
     }
     void category5(char jtype)
     {
         switch(jtype)
         {
            case '1': fee=300;
                        break;
            case '2': fee=500;
                        break;
            case '3': fee=10000;
                        break;
        }
     }
     void category6(char jtype)
     {
         switch(jtype)
         {
            case '1': fee=500;
                        break;
            case '2': fee=800;
                        break;
            case '3': fee=12000;
                        break;
        }
     }
    void category7(char jtype)
     {
         switch(jtype)
         {
            case '1': fee=0;
                        break;
            case '2': fee=0;
                        break;
            case '3': fee=0;
                        break;
        }
     } 
    fare_details(){}
    fare_details(char category, char jtype)
    {
        switch(category)
        {
            case '1': category1(jtype);
                    break;

            case '2': category2(jtype);
                    break;

            case '3': category3(jtype);
                    break;

            case '4': category4(jtype);
                    break;

            case '5': category5(jtype);
                    break;

            case '6': category6(jtype);
                    break;
                    
            case '7': category7(jtype);
                        break;


            }
    }

};
class tollbooth: public fare_details
{

    static int num_vehicles;
    static int total_cash;
    static char catgry;
    static char j_type;
    static int amount;
public:
    tollbooth()
    {
    }
    tollbooth(char cat, char jtype): fare_details(cat,jtype)
    {

        num_vehicles++;
        total_cash=total_cash+fee;
        cout<<endl<<endl;
        cout<<"Number of vehicles so far: "<<num_vehicles<<endl;
        cout<<"Total cash for today: "<<total_cash<<endl<<endl;
        catgry=cat;
        j_type=jtype;
        amount=fee;

    }
    void newday() {num_vehicles=0; total_cash=0; catgry='0'; j_type='0'; amount=0;}
    void friend generate_receipt();
    void friend print_date();
};
int tollbooth::num_vehicles=0;
int tollbooth::total_cash=0;
char tollbooth::catgry='0';
char tollbooth::j_type='0';
int tollbooth::amount=0;

void generate_receipt()
{
    switch(tollbooth::catgry)
    {
        case '1':   cout<<"Vehicle type: [CATEGORY 1]Car/Jeep/Three Wheeler/LMV"<<endl;
                    static ofstream fileout1;
                    fileout1.open("Record.txt", ios::out | ios::app);
                    if (fileout1.is_open())
                        {
                            fileout1<< "Vehicle type: [CATEGORY 1]Car/Jeep/Three Wheeler/LMV \n";
                            fileout1.close();
                        }

                    else
                        {
                            cout<<"Unable to open file."<<endl;
                            exit(1);
                        }
                    break;
        case '2':   cout<<"Vehicle type: [CATEGORY 2]LCV/Tractor with Triller/LGV or Mini Bus"<<endl;
                    static ofstream fileout2;
                    fileout2.open("Record.txt", ios::out | ios::app);
                    if (fileout2.is_open())
                        {
                            fileout2<< "Vehicle type: [CATEGORY 2]LCV/Tractor with Triller/LGV or Mini Bus \n";
                            fileout2.close();
                        }

                    else
                        {
                            cout<<"Unable to open file."<<endl;
                            exit(1);
                        }
                    break;
        case '3':   cout<<"Vehicle type: [CATEGORY 3]Bus/Truck/Road Roller(Two Axles)"<<endl;
                    static ofstream fileout3;
                    fileout3.open("Record.txt", ios::out | ios::app);
                    if (fileout3.is_open())
                        {
                            fileout3<< "Vehicle type: [CATEGORY 3]Bus/Truck/Road Roller(Two Axles) \n";
                            fileout3.close();
                        }

                    else
                        {
                            cout<<"Unable to open file."<<endl;
                            exit(1);
                        }
                    break;
        case '4':   cout<<"Vehicle type: [CATEGORY 4]Three Axles Commercial Vehicle"<<endl;
                    static ofstream fileout4;
                    fileout4.open("Record.txt", ios::out | ios::app);
                    if (fileout4.is_open())
                        {
                            fileout4<< "Vehicle type: [CATEGORY 4]Three Axles Commercial Vehicle \n";
                            fileout4.close();
                        }

                    else
                        {
                            cout<<"Unable to open file."<<endl;
                            exit(1);
                        }
                    break;
        case '5':   cout<<"Vehicle type: [CATEGORY 5]MAV(Four to Six Axles)"<<endl;
                    static ofstream fileout5;
                    fileout5.open("Record.txt", ios::out | ios::app);
                    if (fileout5.is_open())
                        {
                            fileout5<< "Vehicle type: [CATEGORY 5]MAV(Four to Six Axles) \n";
                            fileout5.close();
                        }

                    else
                        {
                            cout<<"Unable to open file."<<endl;
                            exit(1);
                        }
                    break;
        case '6':   cout<<"Vehicle type: [CATEGORY 6]Oversized vehicle(Seven or more axles)"<<endl;
                    static ofstream fileout6;
                    fileout6.open("Record.txt", ios::out | ios::app);
                    if (fileout6.is_open())
                        {
                            fileout6<< "Vehicle type: [CATEGORY 6]Oversized vehicle(Seven or more axles) \n";
                            fileout6.close();
                        }

                    else
                        {
                            cout<<"Unable to open file."<<endl;
                            exit(1);
                        }
                    break;
        case '7':   cout<<"Vehicle type: [CATEGORY 7]Exempted vehicles"<<endl;
                    static ofstream fileout7;
                    fileout7.open("Record.txt", ios::out | ios::app);
                    if (fileout7.is_open())
                        {
                            fileout7<< "Vehicle type: [CATEGORY 7]Exempted vehicles \n";
                            fileout7.close();
                        }

                    else
                        {
                            cout<<"Unable to open file."<<endl;
                            exit(1);
                        }
                    break;
    }
    switch(tollbooth::j_type)
    {
        case '1':   cout<<"Journey type: Single"<<endl;
                    static ofstream fileout8;
                    fileout8.open("Record.txt", ios::out | ios::app);
                    if (fileout8.is_open())
                        {
                            fileout8<< "Journey type: Single \n";
                            fileout8.close();
                        }

                    else
                        {
                            cout<<"Unable to open file."<<endl;
                            exit(1);
                        }
                    break;
        case '2':   cout<<"Journey type: Return"<<endl;
                    static ofstream fileout9;
                    fileout9.open("Record.txt", ios::out | ios::app);
                    if (fileout9.is_open())
                        {
                            fileout9<< "Journey type: Return \n";
                            fileout9.close();
                        }

                    else
                        {
                            cout<<"Unable to open file."<<endl;
                            exit(1);
                        }
                    break;
        case '3':   cout<<"Journey type: Monthly_Pass"<<endl;
                    static ofstream fileout10;
                    fileout10.open("Record.txt", ios::out | ios::app);
                    if (fileout10.is_open())
                        {
                            fileout10<< "Journey type: Monthly_Pass \n";
                            fileout10.close();
                        }

                    else
                        {
                            cout<<"Unable to open file."<<endl;
                            exit(1);
                        }
                    break;

    }
    cout<<"Amount collected: Rs."<<tollbooth::amount;
    static ofstream fileout11;
    fileout11.open("Record.txt", ios::out | ios::app);
                    if (fileout11.is_open())
                        {
                            fileout11<< "Amount collected: Rs."<<tollbooth::amount<<"\n\n";
                            fileout11.close();
                        }

                    else
                        {
                            cout<<"Unable to open file."<<endl;
                            exit(1);
                        }

}
void print_date()
{
    static ofstream p_date;
    p_date.open("Record.txt", ios::out | ios::app);
    if(p_date.is_open())
    {
        p_date<<"\n\n";
        p_date<<"Total number of vehicles: "<<tollbooth::num_vehicles<<"\n";
        p_date<<"Total cash collected: Rs."<<tollbooth::total_cash<<"\n\n\n\n";

        static int cnt_date=1;
        p_date<<"DATE: "<<cnt_date<<" AUGUST 26, 2021"<<"\n\n";
        cnt_date++;
        p_date.close();
    }
    else
    {
        cout<<"Unable to open file."<<endl;
        exit(1);
    }
}
int main()
{
    tollbooth o1;
    HOME:
        system("cls");
        cout<<setw(100)<<setfill('>')<<""<<endl; 
        cout<<setw(65)<<setfill(' ')<<"WELCOME TO TOLL MANAGMENT SYSTEM     "<<endl<<endl;
        cout<<setw(65)<<setfill(' ')<<"NAUBISE-MUGLING ROAD PRITHVI HIGHWAY "<<endl<<endl;
        cout<<setw(65)<<setfill(' ')<<"DESIGNED BY: ROSHAN JHA             "<<endl<<endl;
        cout<<setw(100)<<setfill('>')<<""<<endl;
        char choice;
        cout<<endl<<endl<<endl<<endl;
        
        
         cout<<setw(45)<<setfill('_')<<(' ')<<"MAIN MENU";
        for(int i=0;i<45;i++)
        {
            cout<<"_";
        }
        cout<<endl<<endl;
        
         cout<<setw(65)<<setfill(' ')<<" ENTER 1 FOR FARE DETAILS     "<<endl<<endl;
         cout<<setw(65)<<setfill(' ')<<" ENTER 2 TO START NEW DAY     "<<endl<<endl;
         cout<<setw(65)<<setfill(' ')<<" ENTER 3 TO ADD NEW VEHICLE   "<<endl<<endl;
         cout<<setw(65)<<setfill(' ')<<" ENTER 4 TO CLEAR RECORD      "<<endl<<endl;
         cout<<setw(65)<<setfill(' ')<<" ENTER 5 TO PRINT RECORD      "<<endl<<endl;
         cout<<setw(65)<<setfill(' ')<<" ENTER 6 FOR EXEMPTED VEHICLE "<<endl<<endl;
         cout<<setw(65)<<setfill(' ')<<" ENTER 7 TO EXIT              "<<endl<<endl;
         cout<<setw(100)<<setfill('_')<<""<<endl; 
         cout<<"     SELECT:";
         system("color E0");
         
    // cout<<"***********MANIN MENU**************\n"<<endl;
       
choice=getch();
        switch(choice)
        {
            case '1':    system("cls");
                        static string line1;
                        static ifstream filein1;

                        filein1.open("Fare.txt");
                        if(filein1.is_open())
                        {
                            while(getline(filein1,line1))
                            {
                                cout<<line1<<endl;
                            }
                            filein1.close();

                    
                            cout<<" ENTER 1 TO MAIN MENU "<<endl;
                            cout<<" ENTER 2 TO EXIT       "<<endl;
                            cout<<" SELECT:";
                            
                            char choice1;
                            choice1=getch();
                            switch(choice1)
                            {
                                case '1': goto HOME;
                                break;
                                case '2': exit(0);
                            }

                        }
                        else
                        {
                            cout<<"Unable to open file."<<endl;
                            exit(1);
                        }
                        break;
			case '2' :
                                print_date();
                                o1.newday();
                                goto HOME;
                                break;

           case '3' : system("cls");
           
        cout<<setw(100)<<setfill('>')<<""<<endl;
        cout<<setw(65)<<setfill(' ')<<"WELCOME TO TOLL MANAGMENT SYSTEM"<<endl;
        cout<<setw(65)<<setfill(' ')<<"DESIGNED BY: TEAM SUROSU        "<<endl<<endl;
        cout<<setw(100)<<setfill('>')<<"";
        cout<<endl<<endl;
        

                        static string line3;
                        static ifstream filein3;

                        filein3.open("Fare.txt");
                        if(filein3.is_open())
                        {
                            while(getline(filein3,line3))
                            {
                                cout<<line3<<endl;
                            }
                            filein3.close();

                            
                            cout<<setw(100)<<setfill('>')<<""<<endl;
                        char cat, jtype;
                            cout<<"Enter vehicle category: ";
                            cat=getche();
                            cout<<"\n\n******ENTER JOURNEY TYPE******"<<endl;
                            cout<<"     ENTER 1 FOR SINGLE      "<<endl;
                            cout<<"     ENTER 2 FOR RETURN      "<<endl;
                            cout<<"     ENTER 3 FOR MONTHLY PASS"<<endl;
                            cout<<"     SELECT:";
							jtype=getche();
                            tollbooth obj(cat, jtype);
                            generate_receipt();
                            cout<<endl<<endl<<endl;
                            cout<<"  ENTER 1 TO MAIN MENU "<<endl;
                            cout<<"  ENTER 2 TO EXIT       "<<endl;
                            cout<<"  SELECT:";
                            char choice1;
                            choice1=getch();
                            switch(choice1)
                            {
                                case '1': goto HOME;
                                break;
                                case '2': exit(0);
                            }

                        }
                        else
                        {
                            cout<<"Unable to open 'Fare Details' data file."<<endl;
                            exit(1);
                        }
                        break;
                case '4': system("cls");
                          cout<<"Are you sure you want to clear all system records?"<<endl;
                          cout<<"ENTER 1 FOR YES"<<endl;
                          cout<<"ENTER 2 FOR NO"<<endl;
                          cout<<"SELECT:";
                          char chc;
                          chc=getch();
                          switch(chc)
                          {
                              case '1':  static ofstream clearr;
                                         clearr.open("Record.txt", ios::out);
                                         clearr.close();
                                         goto HOME;
                                         break;

                              case '2': goto HOME;
                                        break;
                          }
                          break;
                case '5': system("cls");
                            static string line_by_line;
                            static ifstream print_rec;
                            print_rec.open("Record.txt");
                            if(print_rec.is_open())
                            {
                                while(getline(print_rec,line_by_line))
                                {
                                    cout<<line_by_line<<endl;
                                }
                                print_rec.close();
                            cout<<endl<<endl;
                            cout<<"**********************"<<endl;
                            cout<<" ENTER 1 TO MAIN MENU "<<endl;
                            cout<<" ENTER 2 TO EXIT       "<<endl;
                            cout<<" SELECT:";
                            
                            char choice1;
                            choice1=getch();
                            switch(choice1)
                            {
                                case '1': goto HOME;
                                break;
                                case '2': exit(0);
                            }
                            }
                        else
                        {
                            cout<<"Unable to open file."<<endl;
                            exit(1);
                        }
                        break;
                case '6':    system("cls");
                        static string line2;
                        static ifstream filein2;

                        filein2.open("Exempted_Vehicles.txt");
                        if(filein2.is_open())
                        {
                            while(getline(filein2,line2))
                            {
                                cout<<line2<<endl;
                            }
                            filein2.close();

                            cout<<" ENTER 1 TO MAIN MENU "<<endl;
                            cout<<" ENTER 2 TO EXIT       "<<endl;
                            cout<<" SELECT:";
                            
                            char choice1;
                            choice1=getch();
                            switch(choice1)
                            {
                                case '1': goto HOME;
                                break;
                                case '2': exit(0);
                            }
                        }
                        else
                        {
                            cout<<"Unable to open file."<<endl;
                            exit(1);
                        }
                        break;

                case '7': exit(0);
                                break;
                default:
                    cout<<"PLEASE ENTER VALID OPTION"<<endl;
                    break;                
        }
return 0;
}
