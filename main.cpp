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
        void customer_menu();
        void buy();

};

void car :: admin_menu()
        {
            int pick, start = 0;

            while(start == 0)
            {
            cout << "\n\n\n\t\t\t\t\t\t 1. Add a new car" << endl;
            cout << "\n\t\t\t\t\t\t 2. Edit details of a car" << endl;
            cout << "\n\t\t\t\t\t\t 3. See all the cars" << endl;
            cout << "\n\t\t\t\t\t\t 4. Remove a car" << endl;
            cout << "\n\t\t\t\t\t\t 5. Log out" << endl;

            cout << "\t\t\t\t\t\t ", cin >> pick;

                    switch (pick)
                {
                    case 1:
                        system("cls");
                        add_car();
                        break;
                    case 2:
                        system("cls");
                        edit_car();
                        break;
                    case 3:
                        system("cls");
                        display();
                        break;
                    case 4:
                        system("cls");
                        rem();
                        break;
                    case 5:
                        system("cls");
                        start = 1;
                        break;
                    default:
                        cout << "\n\t\t\t\t\t\t Wrong input" << endl;
                        break;
                }
    }
}

void car :: add_car()
{
    system("cls");
    fstream data;
    data.open("database.txt", ios::app | ios::out);

    cout << "\n\n\t\t\t\t\t\t Enter id of the car : ", cin >> id;
    cout << "\n\t\t\t\t\t\t Enter car manufacturer : ", cin >> manufacturer;
    cout << "\n\t\t\t\t\t\t Enter car model : ", cin >> model;
    cout << "\n\t\t\t\t\t\t Enter price if the car : ", cin >> price;
    cout << "\n\t\t\t\t\t\t Enter the amount of cars you want to add : ", cin >> quantity;

    data << id << " " << manufacturer << " " << model << " " << price << " " << quantity << "\n";

    data.close();
    system("cls");
}

void car :: edit_car()
{
    fstream data, data1;
    int enid;
    string man, mod;
    int pri, quan;

    cout << "\n\t\t\t\t\t\t Here are all the cars" << endl;
    display();

    cout << "\n\t\t\t\t\t\t Enter the id of the car you want to edit : ", cin >> enid;

    data.open("database.txt", ios :: out| ios :: in);

    if (!data) cout << "\n\t\t\t\t\t\t No such file found" << endl;
    else
    {
        data1.open("database1.txt", ios :: app | ios :: out);

        while (!data.eof())
        {
            data >> id >> manufacturer >> model >> price >> quantity;
            if (data.eof()) break;
            if (enid == id)
            {
                cout << "\n\n\t\t\t\t\t\t Enter the new manufacturer : ", cin >> man;
                cout << "\n\t\t\t\t\t\t Enter the new model : ", cin >> mod;
                cout << "\n\t\t\t\t\t\t Enter the new price : ", cin >> pri;
                cout << "\n\t\t\t\t\t\t Enter the new amount of the cars : ", cin >> quan;

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
    system("cls");
}

void car :: display()
{
    fstream data;

    data.open("database.txt", ios::in);

    if (!data) cout << "\n\t\t\t\t\t\t No such file found" << endl;
    else
    {
        while (!data.eof())
        {
            data >> id >> manufacturer >> model >> price >> quantity;
            if (data.eof()) break;
            cout << "\t\t\t\t\t\t ---------------------------" << endl;
            cout << "\t\t\t\t\t\t " << id << " " << manufacturer << " " << model << " " << price << " " << quantity << "\n";
        }
    }

    data.close();
}

void car :: rem()
{
    fstream data, data1;

    int enid;

    cout << "\n\t\t\t\t\t\t Enter the id of a car that you want to remove : ", cin >> enid;

    data.open("database.txt", ios :: in);

    if (!data) cout << "No such file found" << endl;
    else
    {
        data1.open("database1.txt", ios :: app | ios :: out);

        while (!data.eof())
        {
            data >> id >> manufacturer >> model >> price >> quantity;
            if (id == enid)
            {
                cout << "\n\t\t\t\t\t\t Car was deleted" << endl;
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

void car :: customer_menu()
{
    int pick;
    cout << "\n\t\t\t\t\t\t\tWELCOME!!!\n\n" << endl;
    m:

    cout << "\n\n\t\t\t\t\t\t What would you like to do?" << endl;
    cout << "\n\t\t\t\t\t\t 1. see all the available cars" << endl;
    cout << "\n\t\t\t\t\t\t 2. Buy a car" << endl;
    cout << "\n\t\t\t\t\t\t 3. Exit" << endl;

    cout << "\n\t\t\t\t\t\t ", cin >> pick;

    switch (pick)
    {
    case 1:
        system("cls");
        display();
        goto m;
        break;
    case 2:
        system("cls");
        buy();
        break;
    case 3:
        exit(0);
        break;
    }
}

void car :: buy()
{
    display();
    fstream data, data1;

    int enid;

    cout << "\n\t\t\t\t\t\t Enter the id of a car that you want to buy : ", cin >> enid;

    data.open("database.txt", ios :: in);

    if (!data) cout << "\n\t\t\t\t\t\t No such file found" << endl;
    else
    {
        data1.open("database1.txt", ios :: app | ios :: out);

        while (!data.eof())
        {
            data >> id >> manufacturer >> model >> price >> quantity;
            if (id == enid && quantity <= 0)
            {
                if (data.eof()) break;
                cout << "\n\t\t\t\t\t\t Out of stock" << endl;
                data1 << id << " " << manufacturer << " " << model << " " << price << " " << quantity << "\n";

            }
            else if (id == enid && quantity > 0)
            {
                quantity--;
                if (data.eof()) break;
                cout << "\n\t\t\t\t\t\t You just bought a car!!!" << endl;
                data1 << id << " " << manufacturer << " " << model << " " << price << " " << quantity << "\n";
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
    customer_menu();
}

int main()
{
    system("color A");
    car c;

    string email = "aaa", email1;
    string password = "111", password1;
    int start = 0;
    int pick;

    while (1)
    {
        cout << "\n\n\t\t\t\t\t\t Who are you?" << endl;
        cout << "\n\t\t\t\t\t\t 1. Administrator" << endl;
        cout << "\n\t\t\t\t\t\t 2. Costomer" << endl;
        cout << "\n\t\t\t\t\t\t 3. Exit" << endl;
        cout << "\n\t\t\t\t\t\t ", cin >> pick;

        switch (pick)
        {
        case 1:

            cout << "\n\t\t\t\t\t\t You need to log in. Please enter your " << endl;
            cout << "\n\t\t\t\t\t\t Email: ", cin >> email1;
            cout << "\n\t\t\t\t\t\t Password: ", cin >> password1;

            if (email1 == email && password1 == password)
            {
                system("cls");
                c.admin_menu();
            }
            else
            {
                system("cls");
                cout << "\n\t\t\t\t\t\t Error: failed to log in. Check your email and password" << endl;
            }

            break;
        case 2:
            system("cls");
            c.customer_menu();
            break;
        case 3:
            exit(0);
            break;
        }
    }
    return 0;
}
