#include<bits/stdc++.h>
using namespace std;
static int cont = 0;

class Vehicle
{
    string name;
    string phone;
    string carNo;
    string type;
    int charges;
    int ticketNo;
    int hh1,mm1;
    int hh2,mm2;
public:
    Vehicle(string n,string pho,string cn,int h1,int m1,int h2,int m2,int ty)
    {
        name = n;
        phone = pho;
        carNo = cn;
        hh1 = h1;
        mm1 = m1;
        hh2 = h2;
        mm2 =m2;
        if(ty == 1)
            type = "Car";
        else
            type = "Bike";
        cont++;
        ticketNo = cont;
        int time1=(hh1*60)+mm1;
        int time2=(hh2*60)+mm2;
        int time=time2-time1;
        if(time<=120 && ty == 1) charges=20;
        else if(time<=120 && ty == 2) charges=10;
        else if(time>120 && ty == 1) charges=(time/60)*50;
        else charges=(time/60)*30;
    }
    bool search(string n, string cn)
    {
        if(n == name && cn == carNo)
        {
            cout << "\nThe vehicle is found\n" << endl;
            show();
            searchDisplay();
            return true;
        }
        return false;
    }
    int ticket(string x, string y, int h1,int m1,int h2,int m2,int ty)
    {
        charges = 0;
        if(x == name && y == carNo)
        {
            int s1,s2,totals=0;
            s1 = h1*60*60+m1*60;
            s2 = h2*60*60+m2*60;
            totals = s2-s1;
            int mins = totals/60;
            int hours = mins/3600;
            if(mins<=120 && ty == 1) charges=20;
            else if(mins<=120 && ty == 2) charges=10;
            else if(mins>120 && ty == 1) charges=(mins/60)*50;
            else charges=(mins/60)*30;
        }
        return charges;
    }
    void searchDisplay()
    {
        cout << "Ticket number : " << ticketNo << endl;
        cout << "Vehicle type : "<< type << endl;
        cout << "Vehicle Number : " << carNo << endl;
        if(mm1 < 10)
            cout << "Entry Time : " << hh1 << " : " << 0 << mm1 << endl;
        else
            cout << "Entry Time : "  << hh1 << " : "  << mm1 << endl;
        if(mm2 < 10)
            cout << "Exit Time" << hh2 << " : " << 0 << mm2 << endl;
        else
            cout << "Exit Time" << hh2 << " : " << mm2 << endl;
        cout << "Total Charges" << charges<<"/-" << endl;


    }
    friend void display(Vehicle r);
    void show()
    {
        cout<<"                      ********************** PARKING BILL **********************"<<endl;
        cout << setw(20) << "Ticket number ";
        cout << setw(20) << "Vehicle type ";
        cout << setw(20) << "Vehicle Number";
        cout << setw(20) << "Entry Time";
        cout << setw(20) << "Exit Time";
        cout << setw(20) << "Total Charges";
        cout << endl;
    }

};
void display(Vehicle r)
{
    cout << setw(18) << r.ticketNo;
    cout << setw(18) <<  r.type;
    cout << setw(18) << r.carNo;
    if(r.mm1 < 10)
        cout << setw(18) << r.hh1 << " : " << 0 << r.mm1;
    else
        cout << setw(18) << r.hh1 << " : "  << r.mm1;
    if(r.mm2 < 10)
        cout << setw(18) << r.hh2 << " : " << 0 << r.mm2;
    else
        cout << setw(18) << r.hh2 << " : " << r.mm2;
    cout << setw(18) << r.charges <<"/-";
    cout << endl;
}

int main()
{
    int i,q;
    vector<Vehicle> v;
    cout<<"          *************************** PARKING MANAGEMENT SYSTEM ***************************";
    while(true)
    {
        string name;
        string phone;
        string carNo;
        int tickettNo, charges,ty;
        int hh1,mm1;
        int hh2,mm2;
        fflush(stdin);
        cout<<"\n\n1. New vehicle";
        cout<<"\n2. Searching of a vehicle";
        cout<<"\n3. Charges";
        cout<<"\n4. Display details";
        cout<<"\n5. Exit";
        cout<<"\nSelect an option (1,2,3,4,5): ";
        int choice;
        cin>>choice;
        fflush(stdin);
        if(choice == 1)
        {
            cout << "\nNew vehicle\n";
            cout << "Enter type(1 for car / 2 for bike) :";
            cin >> ty;
            cout << "Enter name :";
            fflush(stdin);
            getline(cin,name);
            cout << "Enter phone :";
            fflush(stdin);
            getline(cin,phone);
            cout << "Enter plate no :";
            fflush(stdin);
            getline(cin,carNo);
            cout << "Enter arrival time(in 24 format) :";
            fflush(stdin);
            cin >> hh1 >> mm1;
            cout << "Enter departure time(in 24 format) :";
            fflush(stdin);
            cin >> hh2 >> mm2;
            Vehicle veh(name,phone,carNo,hh1,mm1,hh2,mm2,ty);
            v.push_back(veh);
            //v[count].how_charge();
            //cont++;

        }
        else if(choice == 2)
        {
            cout << "\nSearching\n";
            cout<<"\nEnter name : ";
            fflush(stdin);
            getline(cin,name);
            cout<<"Enter plate no : ";
            fflush(stdin);
            getline(cin,carNo);
            q = v.size();
            for(i = 0; i < q; i++)
            {
                if(v[i].search(name,carNo)) break;
            }
            if(i == q) cout << "Vehicle is not available\n";

        }
        else if(choice == 3)
        {
            q = v.size();
            //cout << "/nCharge/n";
            cout << "Enter name:";
            fflush(stdin);
            getline(cin,name);
            cout << "Enter plate no:";
            fflush(stdin);
            getline(cin,carNo);
            cout << endl;
            q = v.size();
            for(i = 0; i < q; i++)
            {
                double d = v[i].ticket(name,carNo,hh1,mm1,hh2,mm2,ty);
                if(d == 0)
                {
                    cout << "\nno charge\n";
                    break;
                }
                else if(d)
                {
                    cout << "Total charge : " << d << endl;
                    break;
                }
                else
                    continue;
            }
            if(i == q) cout << "\nThe vehicle is not available\n" << endl;
        }
        else if(choice == 4)
        {
            v[0].show();
            q = v.size();
            for(i = 0; i < q; i++)
            {
                display(v[i]);
                cout << endl;
            }
        }
        else if(choice == 5)
        {
            cout << "Thank you" << endl;
            break;
        }

    }
}
