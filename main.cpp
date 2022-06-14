#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class car
{
    private:
        string manufacturer, model;
        long long int price;
        int id, quantity;

    public:
        void admin_menu();
        void add_car();
        void edit_car();
        void display();
        void rem();
        void buy();

};

void car :: admin_menu()
        {
            int pick, start = 0;

            while(start == 0)
            {
            cout << "1. Add a new car" << endl;
            cout << "2. Edit details of a car" << endl;
            cout << "3. See all the cars" << endl;
            cout << "4. Remove a car" << endl;
            cout << "5. Log out" << endl;

            cin >> pick;

                    switch (pick)
                {
                    case 1:
                        add_car();
                        break;
                    case 2:
                        edit_car();
                        break;
                    case 3:
                        display();
                        break;
                    case 4:
                        rem();
                        break;
                    case 5:
                        start = 1;
                        break;
                    default:
                        cout << "Wrong input" << endl;
                        break;
                }

    }
            }


void car :: add_car()
{

    fstream data;
    data.open("database.txt", ios::app | ios::out);

    cout << "Enter id of the car : ", cin >> id;
    cout << "Enter car manufacturer : ", cin >> manufacturer;
    cout << "Enter car model : ", cin >> model;
    cout << "Enter price if the car : ", cin >> price;
    cout << "Enter the amount of cars you want to add : ", cin >> quantity;

    data << id << " " << manufacturer << " " << model << " " << price << " " << quantity << "\n";

    data.close();

}

void car :: edit_car()
{
    fstream data, data1;
    int enid;
    string man, mod;
    int pri, quan;

    cout << "Here are all the cars" << endl;
    display();

    cout << "Enter the id of the car you want to edit : ", cin >> enid;


    data.open("database.txt", ios :: out| ios :: in);

    if (!data) cout << "No such file found" << endl;
    else
    {
        data1.open("database1.txt", ios :: app | ios :: out);

        //data >> id >> manufacturer >> model >> price >> quantity;

        while (!data.eof())
        {
            data >> id >> manufacturer >> model >> price >> quantity;
            if (data.eof()) break;
            if (enid == id)
            {
                cout << "Enter the new manufacturer : ", cin >> man;
                cout << "Enter the new model : ", cin >> mod;
                cout << "Enter the new price : ", cin >> pri;
                cout << "Enter the new amount of the cars : ", cin >> quan;

                data1 << id << " " << man << " " << mod << " " << pri << " " << quan << "\n";
            }
            else
            {
                data1 << id << " " << manufacturer << " " << model << " " << price << " " << quantity << "\n";
            }

        }
    }



    data.close();
    data1.close();

    remove("database.txt");
    rename("database1.txt", "database.txt");
}

void car :: display()
{
    fstream data;

    data.open("database.txt", ios::in);

    if (!data) cout << "No such file found" << endl;
    else
    {

        while (!data.eof())
        {

            data >> id >> manufacturer >> model >> price >> quantity;
            if (data.eof()) break;
            cout << id << " " << manufacturer << " " << model << " " << price << " " << quantity << "\n";

        }
    }

    data.close();
}

void car :: rem()
{
    fstream data, data1;

    int enid;

    cout << "Enter the id of a car that you want to remove : ", cin >> enid;

    data.open("database.txt", ios :: in);

    if (!data) cout << "No such file found" << endl;
    else
    {
        data1.open("database1.txt", ios :: app | ios :: out);


        while (!data.eof())
        {
            data >> id >> manufacturer >> model >> price >> quantity;
            //if (data.eof()) break;
            if (id == enid)
            {
                cout << "Car was deleted" << endl;
            }
            else
            {
                if (data.eof()) break;
                data1 << id << " " << manufacturer << " " << model << " " << price << " " << quantity << "\n";
            }
        }
    }
    data.close();
    data1.close();

    remove("database.txt");
    rename("database1.txt", "database.txt");
}

int main()
{
    car c;

    string email = "aaa", email1;
    string password = "111", password1;
    int start = 0;
    int pick;



    while (1)
    {
        cout << "Who are you?" << endl;
        cout << "1. Administrator" << endl;
        cout << "2. Costomer" << endl;
        cout << "3. Exit" << endl;

        cin >> pick;

        switch (pick)
        {
        case 1:

            cout << "You need to log in. Please enter your " << endl;
            cout << "Email: ", cin >> email1;
            cout << "Password: ", cin >> password1;

            if (email1 == email && password1 == password)
            {
                c.admin_menu();
            }
            else cout << "Error: failed to log in. Check your email and password" << endl;

            break;
        case 2:
            break;
        case 3:
            exit(0);
            break;
        }

    }


    return 0;
}
