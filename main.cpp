#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class car
{
    private:
        string manufacturer, model;
        float price;
        int quantity;

    public:
        void admin_menu();
        void add_car();

};

void car :: admin_menu()
        {
            int pick, start = 0;

            while(start == 0)
            {
            cout << "1. Add a new car" << endl;
            cout << "2. Edit details of a car" << endl;
            cout << "3. See all the cars" << endl;
            cout << "4. Log out" << endl;

            cin >> pick;

                    switch (pick)
                {
                    case 1:
                        add_car();
                        break;
                    case 2:
                        break;
                    case 3:
                        break;
                    case 4:
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

    cout << "enter price" << endl;
    cin >> price;
    cout << "added" << endl;

    data.close();

    cout << "OK" << endl;

}

int main()
{
    car c;

    string email = "admin@gmail.com", email1;
    string password = "12345", password1;
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
