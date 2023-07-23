#include <iostream>  // Input/Output Library
#include <fstream>   // File Handling Library
using namespace std;


// Declaration of total entities such as humans and items that a GYM can afford
const int total_members = 60;
const int total_equipments = 120;


// Declaration of arrays
string Member_Names[total_members];
string Member_Contacts[total_members];

string Equipment_Names[total_equipments];
string Equipment_Details[total_equipments];


// Initially, there is no members and equipments so, member and equipment count is ZERO
int Member_Count = 0;
int Equipment_Count = 0;    




void Add_New_Member(){
    
    ifstream count_members;
    count_members.open("Members Records.txt");
    string data;
    int count = 0;
    while(getline(count_members, data)){
        count++;
    }
    Member_Count = count;
     
     
    if(Member_Count == total_members){
        cout << "Maximum member limit has been reached!" << endl;
    }

    cout << "Enter the member name = ";
    cin.ignore(); 
    getline(cin, Member_Names[Member_Count]); // To include spaces in the names
    
    cout << "Enter the member contact number = ";
    cin >> Member_Contacts[Member_Count];
    Member_Count++;

    cout << "DONE! Member has been added successfully!" << endl;
    


    
    ofstream Member_File;  // To write data on the file
    Member_File.open("Members Records.txt", ios::app);  // Opening the file plus to stop overwriting --> ios::app is used; means to move the cursor to the next line in the file after entering the data
    
    Member_File <<"Sr # = " << Member_Count <<" --- ";
    Member_File <<"Name = " << Member_Names[Member_Count - 1] << " --- ";    // [Member_Count-1] because Member_Count++ increments 0th to 1th location in array and at 1th other data will be present or may be some garbage value
    Member_File <<"Contact # = " << Member_Contacts[Member_Count - 1] << endl;
    
    Member_File.close();  // Closing the file
}




void Display_All_Members(){
    
    ifstream Member_File;  // To read data from the file
    Member_File.open("Members Records.txt");   // Opening the file
    
    string data_print;
    cout << "All Member's Records are: " << endl << endl;
    
    while(getline(Member_File, data_print)){   // Loop to read each line present in the file and to print it
        cout << data_print << endl;
    }
    
    Member_File.close();  // Closing the file
}




void Add_New_Equipment(){
    
    ifstream count_Equipment;
    count_Equipment.open("Equipments Records.txt");
    string data;
    int count = 0;
    while(getline(count_Equipment, data)){
        count++;
    }
    Equipment_Count = count;
    
    
    if(Equipment_Count == total_equipments){
        cout << "Maximum equipment limit has been reached!" << endl;
    }

    cout << "Enter the equipment name = ";
    cin.ignore();
    getline(cin, Equipment_Names[Equipment_Count]);
    
    cout << "Enter the equipment details = ";
    cin.ignore();
    getline(cin, Equipment_Details[Equipment_Count]);
    
    Equipment_Count++;

    cout << "DONE! Equipment has been added successfully!" << endl;
    
    
    
    
    ofstream Equipment_File;  // To write data on the file
    Equipment_File.open("Equipments Records.txt", ios::app);  // Opening the file plus to stop overwriting --> ios::app is used; means to move the cursor to the next line in the file after entering the data
    
    Equipment_File <<"Sr # = " << Equipment_Count <<" --- ";
    Equipment_File <<"Name = " << Equipment_Names[Equipment_Count - 1] <<" --- ";    // [Equipment_Count-1] because Member_Count++ increments 0th to 1th location in array and at 1th other data will be present or may be some garbage value
    Equipment_File <<"Details = " << Equipment_Details[Equipment_Count - 1] <<endl;
 
    Equipment_File.close();  // Closing the file
}




void Display_All_Equipments(){
    
    ifstream Equipment_File;
    Equipment_File.open("Equipments Records.txt");
    
    string data;
    cout<<"All Equipments Records are: "<<endl<<endl;
    
    while(getline(Equipment_File, data)){
        cout<<data<<endl;
    }
    
    Equipment_File.close();
}




void Member_Statistics(){
    cout << "Member Statistics is given below...." << endl;
    
    ifstream count_members;
    count_members.open("Members Records.txt");
    
    string data;
    int count = 0;
    
    while(getline(count_members, data)){
        count++;
    }
        
    cout << "Total Members are = " << count << endl;
}




void Equipment_Statistics(){
    cout << "Equipment Statistics is given below...." << endl;
     
    ifstream count_Equipment;
    count_Equipment.open("Equipments Records.txt");
    
    string data;
    int count = 0;
    
    while(getline(count_Equipment, data)){
        count++;
    }
        
    cout << "Total Equipments are = " << count << endl;
}




void login(){
    string pass;
    const string security_key = "120";
    
    cout<<"Checking the security credentials..."<<endl;
    cout<<" Firstly... Please enter the password to log into the system = ";
    cin>>pass;
    
    while(pass != security_key){
        cout<<"OOPS! It's the wrong password. Please enter the password again = ";
        cin>>pass;
    }
    
    cout<<endl;
    cout<<"                    Welcome......."<<endl;
    cout<<"Within shortly, you will be redirected towards the main screen"<<endl<<endl;
}




void Main_Menu(){
    
    cout << "    **** GYM Management System ****" << endl;
    
    cout<<"       Developed by Talha Khalid" <<endl <<endl;
    
    cout << "1. Add a New Member" << endl;
    cout << "2. Display All Members" << endl;
    cout << "3. Add a New Equipment" << endl;
    cout << "4. Display All Equipments" << endl;
    cout << "5. Show Member Statistics" << endl;
    cout << "6. Show Equipment Statistics" << endl;
    cout << "7. Exit" << endl <<endl;
    
}




int main(){
    int choice;
    
    login();

    do{
        
        Main_Menu();
        
        cout << "Dear user! Please select the option = ";
        cin >> choice;

        switch(choice){
            case 1:
                Add_New_Member();
                break;
            case 2:
                Display_All_Members();
                break;
            case 3:
                Add_New_Equipment();
                break;
            case 4:
                Display_All_Equipments();
                break;
            case 5:
                Member_Statistics();
                break;
            case 6:
                Equipment_Statistics();
                break;
            case 7:
                cout << "OK as you wish..." << endl;
                break;
            default:
                cout << "OOPS! You've entered an invalid option. PLease try again....." << endl;
                break;
        }

        cout << endl;

    }
    while (choice != 7);
    
    cout<<"Thank you so much for using the software. Have a lovely day :) "<<endl;  
    
    return 0;
}
