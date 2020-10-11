#include <iostream>
///#include <stdlib.h>
#include <string>
#include <cctype>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <iomanip>
#include<stdio.h>
#define max 10

using namespace std;
//the header file

class medicineType	//base class
{
public:

    void take_order();//to  take_order
    void delete_order(); //to delete the order
    void modify(); //to modify the order
    void order_list(); //to display the order_list
    void daily_summary(); //to display daily_summary
    void exit();  //function to exit system
    medicineType();//constuctor

};

medicineType::medicineType ()
{

}		//constructor for class CarType


struct node //constract node
{
    int reciept_number;
    string customerName;
    string date;
    int quantity[10];
    int x;
    double price[10];
    string medicine_name[10]
    double total;

}*q, *temp;				//pointer declaration


int main()	// Main function
{

    medicineType medicine;
    int menu;
    do
    {
        /// system("cls");
        cout<<"\t\t\t    Pharmacy Management System \n";
        cout<<"\t\t==================================================\n\n";
        cout<<"\t\t--------------------------------------------------\n";
        cout<<"\t\t||\t1. Take new Medicine order \t\t ||\n";
        cout<<"\t\t||\t2. Delete latest Medicine order\t\t ||\n";
        cout<<"\t\t||\t3. Modify Order List \t\t\t ||\n";
        cout<<"\t\t||\t4. Print the Reciept and Make Payment \t ||\n";
        cout<<"\t\t||\t5. Daily Summary of total Sale \t\t ||\n";
        cout<<"\t\t||\t6. Exit\t\t\t\t\t ||\n";
        cout<<"\t\t--------------------------------------------------\n";
        cout<<"Enter choice: ";

        cin>>menu;

        switch (menu)
        {
            case 1:
            {
                medicine.take_order();	//function add
                break;
            }	//end case 1


            case 2:
            {
                medicine.delete_order();	//function delete
                break;
            }	//end case 2

            case 3:
            {
                medicine.modify();	//function modify
                break;
            }	//end case 3

            case 4:
            {
                medicine.order_list();	//function order
                break;
            }	//end case 4
            case 5:
            {
                medicine.daily_summary();	//function daily_summary
                system("PAUSE");
                break;
            }	//end case 5
            case 6:
            {
                medicine.exit();	//function exit
                cout<<"thank you"<<endl;
                return 0;
                break;
            }	//end case 6


            default:
            {
                cout<<"You enter invalid input\nre-enter the input\n"<<endl;
                break;
            }//end defeault
        }//end Switch
    }while(menu!=6);//end do
}//end  main function


void medicineType::take_order()		//function to take_order
{
    int i,total_price=0;
    int choice, quantity, price,None;


    cout <<"\nAdd Order Details\n";
    cout <<"_____________ \n\n";

    node *temp;
    temp=new node;

    temp = new node;
    cout << "Type Order no: ";
    cin >> temp->reciept_number;
    cout<< "Enter Customer Name: ";
    cin>> temp->customerName;
    cout<<"Enter Date : ";
    cin>>temp->date;
    cout << "How many Medicine would you like to order:"<< endl;
    cout<<"( Maximum is 10 order for each transaction ) \n";
    cout << "  " ;
    cin >> temp->x;
    if (temp->x >10)
    {
        cout << "The Medicine you order is exceed the maximum amount of order !";
    }
    else{
        for (i=0; i<temp->x; i++)
        {
            void read_order();
        }

        temp->total = total_price;

        cout<<"==========================================================================="<<endl;
        cout << "Order Taken Successfully"<<endl;

        void store_order();
    }
}//End function take_order


void medicineType::order_list()		//Function to display receipt
{
    int i, num, num2;
    bool found;			//variable to search
    system("cls");
    node *temp;

    temp=start_ptr;
    found = false;

    cout<<" Enter the Reciept Number To Print The Reciept\n";
    cin>>num2;
    cout<<"\n";
    cout<<"==========================================================================="<<endl;
    cout <<"\t\tHere is the Order list\n";
    cout<<"==========================================================================="<<endl;


    if(temp == NULL) //Invalid receipt code
    {
        cout << "\tThere is no Order to show\n\t\t\tSo The List is Empty\n\n\n";
    }
    while(temp !=NULL && !found)
    {
        if (temp->reciept_number==num2)
        {
            found = true;
        }
        else
        {
            temp = temp -> next;
        }
        if (found)	//print the receipt
        {
            cout <<"Reciept Number : "<<temp->reciept_number;
            cout <<"\n";
            cout<<"Customer Name: "<<temp->customerName<<endl;

            cout<<"Order Date : "<<temp->date<<endl;

            cout<<"___________________________"<<endl;

            cout << "===============================================================================" << endl;
            cout << "|  Medicine Type |     Medicine Name    |  	Quantity     |    Total Price |" << endl;
            cout << "=======++==================++================++===============++===============" << endl;
            for (i=0;i<temp->x;i++)
            {
                cout << temp->type <<"  \t\t";
                cout<<temp->medicineName[temp->menu2[i]-1]<<"\t\t\t  ";
                cout<<temp->quantity[i] <<"\t\t";
                cout<< temp->amount[i]<<" RM"<<endl;
                cout<<"___________________________"<<endl;
            }

            temp->total = temp->amount[0]+temp->amount[1]+temp->amount[2]+temp->amount[3]+temp->amount[4]+temp->amount[5]+temp->amount[6]+temp->amount[7]
                          +temp->amount[8]+temp->amount[9];
            cout<<"Total Bill is : "<<temp->total;
            cout<<"\n";
            cout << "Type the exact amount You need to pay: ";
            cin >> num;

            cout <<"\n";
            cout <<"\n";
            cout<<"Payment Done\nThank You\n";
            cout <<"\n___________________________\n";
        }


    }
}	//End function order_list


void medicineType::delete_order()	//function to delete_order
{
    system("cls");
    int i, num, count;
    cout<<"Enter the data you want to delete \n";
    cin>>num;
    node *q;
    node *temp;
    bool found;

    if(start_ptr == NULL)
        cerr<<"Can not delete from an empty list.\n";
    else
    {
        if(start_ptr->reciept_number == num)
        {
            q = start_ptr;
            start_ptr = start_ptr->next;
            count--;
            if(start_ptr == NULL)
                last = NULL;
            delete q;
            cout<<"The Reciept is Deleted Successfully"<<endl;
        }
        else
        {
            found = false;
            temp = start_ptr;
            q = start_ptr->next;

            while((!found) && (q != NULL))
            {
                if(q->reciept_number != num)
                {
                    temp = q;
                    q = q-> next;
                }
                else
                    found = true;
            }

            if(found)
            {
                temp->next = q->next;
                count--;

                if(last == q)
                    last = temp;
                delete q;
                cout<<"The Reciept is Deleted Successfully"<<endl;
            }
            else
                cout<<"Item to be deleted is not in the list."<<endl;
        }
    }
}	//End function delete_order



void medicineType::modify()		//function to modify order
{
    system("cls");
    int i, ch, sid;
    bool found;
    found = false;
    temp = start_ptr;
    cout<<"Enter Receipt Number To Modify: ";
    cin>>sid;
    if (temp==NULL && sid==0)
    {
        cout<<"NO RECORD TO MODIFY..!"<<endl;
    }

    else
    {
        while(temp !=NULL && !found)
        {
            if (temp->reciept_number==sid)
            {
                found = true;
            }
            else
            {
                temp = temp -> next;
            }
            if (found)
            {
                cout << "Change  Order Number: ";
                cin >> temp->reciept_number;
                cout<< "Change Customer Name: ";
                cin>> temp->customerName;
                cout<<"Change Date : ";
                cin>>temp->date;
                cout << "How many New Medicine would you like to Change:"<< endl;
                cout<<"( Maximum is 10 order for each transaction ) \n";
                cout << "  " ;
                cin >> temp->x;
                if (temp->x >10)
                {
                    cout << "The Medicine you order is exceed the maximum amount of order !";
                    system("pause");
                }
                else{
                    for (i=0; i<temp->x; i++)
                    {

                        cout << "Please enter your selection to Change: "<<endl;
                        cin>> temp->menu2[i];
                        cout<< "Change Medicine Name: " <<temp->medicineName[temp->menu2[i]-1]<<endl;
                        cout << "How many New medicine do you want: ";
                        cin >> temp->quantity[i];
                        temp->amount[i] = temp->quantity[i] * temp->Medicine[temp->menu2[i]-1];
                        cout << "The amount You need to pay After Modify  is: " << temp->amount[i]<<" RM"<<endl;
                        system("PAUSE");
                    }
                    temp = temp->next;
                    system("cls");

                }

                cout<<"RECORD MODIFIED....!"<<endl;
            }
            else
            {
                if(temp != NULL && temp->reciept_number != sid)
                {
                    cout<<"Invalid Reciept Number...!"<<endl;
                }
            }
        }
    }
}		//End modify function



void medicineType::daily_summary()		//Function to display Daily Summary
{
    int i,num;
    system("cls");
    node *temp ;

    temp=start_ptr;


    if(temp == NULL) //Invalid receipt code
    {
        cout << "\t\t\tThere is no Order to show\n\t\t\tSo The List is Empty\n\n\n";
    }
    else
    {
        cout<<"\n";
        cout<<"==========================================================================="<<endl;
        cout <<" \t\tHere is the Daily Summary of All Orders \n"; //print all receipt
        cout<<"==========================================================================="<<endl;

        while(temp!=NULL)
        {

            cout <<"Reciept Number : "<<temp->reciept_number;
            cout <<"\n";
            cout<<"Customer Name: "<<temp->customerName<<endl;

            cout<<"Order Date : "<<temp->date<<endl;

            cout<<"__________________________"<<endl;

            cout << "==========================================================================" << endl;
            cout << "|  Medicine Type |   Medicine Name    |    Quantity     |    Total Price |" << endl;
            cout << "=======++==================++================++===============++==========" << endl;
            for (i=0;i<temp->x;i++)
            {
                cout << temp->type <<"  \t\t";
                cout<<temp->medicineName[temp->menu2[i]-1]<<"\t\t";
                cout<<temp->quantity[i] <<"\t\t";
                cout<< temp->amount[i]<<" RM"<<endl;
                cout<<"___________________________"<<endl;
            }

            temp->total = temp->amount[0]+temp->amount[1]+temp->amount[2]+temp->amount[3]+temp->amount[4]+temp->amount[5]+temp->amount[6]+temp->amount[7]
                          +temp->amount[8]+temp->amount[9];
            cout<<"Total Bill is : "<<temp->total;

            cout <<"\n";
            cout <<"\n";
            cout <<"\n___________________________\n";

            temp=temp->next;
        }
    }
}		//End daily summary
void medicineType::exit() //Function to exit
{
    cout<<"\nYou choose to exit.\n"<<endl;
}	//end function exit

