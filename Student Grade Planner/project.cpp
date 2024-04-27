#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <iomanip>


using namespace std;

void gpa();
void graph();
void login();
void students();
void registering();
void showAllData();
void name();
void check_reg(int);
void sem_reg();



int main(){
    int option_choosed;
    
    // Add delay for each line using Sleep(300)
    Sleep(200);
    cout << "\t\t*****************************************" << endl;
    Sleep(200);
    cout << "\t\t\t  Project made by:" << endl << endl;
    Sleep(200);
    cout << "\t\tTehman Hassan (23-CP-11)  Saira (23-CP-05) " << endl << endl;
    Sleep(200);
    cout << "\t\t********USER AUTENTICATION FORM**********" << endl << endl;
    Sleep(200);
    cout << "\t\t1. Login" << endl;
    Sleep(200);
    cout << "\t\t2. New Register" << endl;
    Sleep(200);
    cout << "\t\t3. Exit" << endl;
    Sleep(200);
    cout << "\t\tENTER YOUR CHOICE: ";

    cin >> option_choosed;

    cout << endl;


    switch (option_choosed)
    {
    case 1:
        login();
        break;
    
    case 2:
        registering();
        system("cls");
        name();
        break;

    default:
        system("cls");
        main();
    }
    
    // By using main(); the problem is that when we enter correct username and password than that will also go to the next function but will also show this main() function
    // again and when we don't use main(); in this then it is correct but will not repeat this main funtion again , as it exit's the program
    main();


    return 0;
}

void registering(){
    
    system("cls");

    
    string user_name;
    //cin.ignore(); 
    string password;
    cout<<"\t\tEnter the Username: ";
    cin>>user_name;
    //getline(cin, user_name);                      using getline enables us to get string with spaces, otherwise it won't accept string with spaces. we can use this feature but in the login() function I cannot understand how to fetch the whole string of username and password    
    cout<<"\t\tEnter Password for Account: ";       
    cin>>password;
    //getline(cin,password);

    ofstream tttout("security.txt", ios::app);
    tttout<<user_name<<"\t\t"<<password<<endl;
    cout<<"\t\tREGISTRATION SUCCESSFUL";

    system("cls");


}


void name(){
    
    
    string name,department;
    string roll;
    cout<<"\t\tAS YOU ARE A NEW STUDENT, PLEASE ENTER DETAILS BELOW:"<<endl<<endl;

    cout<<"\t\tPlease Enter Your First Name: ";
    cin>>name;
    cout<<"\t\tPlease Enter Roll Number: ";
    cin>>roll;

    cout<<"\t\tEnter your Department: ";
    cin>> department;


    ofstream namefile("names.txt", ios::app);
    namefile<<roll<<"\t"<<name<<"\t"<<department<<endl;

    system("cls");


}

void login(){
    int new_opening;

    string user_name;
    string password;
    string a;
    string b;
    cout<<"\t\tEnter your Username: ";
    cin >>user_name;
    cout<<"\t\tEnter your Password: ";
    cin>> password;

    // OPENING THE FILE AND CHECKING THAT DATA IS BEING MATCHED OR NOT

    ifstream input("security.txt");


    // Read username and password from the file line by line
    while (input >> a >> b) {
    // getline(password);
    // getline(user_name);



        if (a == user_name && b == password) {
            new_opening = 1;
            system("cls");
        }
    }

    input.close();

    // NOW JUST USING SIMPLE IF ELSE FOR CONTINUING OR NOT
    switch (new_opening)
    {
    case 1:
        system("cls");
        students();
        break;
    
    default:
        system("cls");
        cout<<"\t\tINCORRECT, NOT MATCHING WITH EXISTING DATABASE!!\n\n\t\tRUN THE SYSTEM AGAIN BY USING CTRL_R!!!!!"<<endl<<endl;
        break;
    }
    // if(new_opening==1){
    //     system("cls");
    //     students();
    // }

    // else{
    //     system("cls");
    //     cout<<"\t\tINCORRECT, NOT MATCHING WITH EXISTING DATABASE!!"<<endl<<endl;
    //     return;



    // }
}

void students(){

    int option_choosed;
    int new_sem=0;
    
    Sleep(200);
    cout << "\t\t*******************************************" << endl;
    Sleep(200);
    cout << "\t\t\tWELCOME TO STUDENT GRADE PLANNER" << endl << endl;
    Sleep(200);
    cout << "\t\t******* CHOOSE OPTIONS BELOW **************" << endl << endl;
    Sleep(200);
    cout << "\t\t1. Calculate GPA and send to Email Address" << endl;
    Sleep(200);
    cout << "\t\t2. Calculate Graph" << endl;
    Sleep(200);
    cout << "\t\t3. Show All Data in Terminal" << endl;
    Sleep(200);
    cout << "\t\t4. Register For New Semester" << endl;
    Sleep(200);
    cout << "\t\t5. Check that If you have Registered for New Semmester" << endl;
    Sleep(200);    
    cout << "\t\t6. Exit to Main Menu" << endl;
    Sleep(200);
    cout << "\t\tENTER YOUR CHOICE: ";

    cin >> option_choosed;

    cout << endl;

    switch (option_choosed)
    {
    case 1:
        system("cls");
        gpa();
        break;
    
    case 2:
        system("cls");
        graph();
        break;

    case 3:
        system("cls");
        showAllData();
        break;

    case 4:
        system("cls");
        sem_reg();
        break;


    case 5:
        system("cls");
        check_reg(new_sem);
        break;

    case 6:
        system("cls");
        main();
        break;

    
    default:
        system("cls");
        cout<<"\t\tInvalid Option! Please choose valid option."<<endl;
        break;
    }


    students();
}

void sem_reg() {
    int curr;
    float calc_sum = 0.0;
    
    cout << "\t\tEnter Your Current Semester: ";
    cin >> curr;

    // Dynamically allocate an array for GPA storage
    float *calc = new float[curr];

    for (int i = 1; i < curr; i++) {
        cout << "\t\tEnter Semester " << i << " GPA: ";
        cin >> calc[i];
        calc_sum += calc[i]; // Calculate sum of previous GPAs
    }

    int new_sem;
    cout << "\t\tEnter Semester you want to Enroll: ";
    cin >> new_sem;
    
    ofstream outFile("gpa_reg.txt");
    outFile << new_sem;
    outFile.close();

    float avg = calc_sum / (curr - 1); // Calculate average of previous GPAs
    cout << "\t\tYour Cumulative GPA for Previous Semesters is " << avg << endl;

    // Deallocate memory for the GPA array
    delete[] calc;
}

void check_reg(int new_sem) {
    // Read the new semester value from the file or database
    ifstream inFile("gpa_reg.txt");
    inFile >> new_sem;
    inFile.close();

    string roll;
    bool found = false;

    cout << "Enter your roll number: ";
    cin >> roll;

    // Check if the roll number exists in the names.txt file
    ifstream namesFile("names.txt");
    string line;

    while (getline(namesFile, line)) {
        if (line.find(roll) != string::npos) {
            found = true;
            break;
        }
    }

    if (found) {
        cout << "You are registered for semester " << new_sem << "." << endl;
    } else {
        cout << "You are not registered for any semester ";
    }

    namesFile.close();
}


void calculate_gpa(string email) {

    cout<<endl<<endl;
 	cout<<"\t\t----------------------------------------------------"<<endl;
 	cout<<"\t\t|		Grade Point Table                  |"<<endl;
 	
 	cout<<"\t\t----------------------------------------------------"<<endl;
 	cout<<endl<<endl;
 	cout<<"\t\tGrade\t\t\tPoints"<<endl;
 	cout<<endl;
 	cout<<"\t\tA\t\t\t4.0"<<endl;
 	cout<<"\t\tA-\t\t\t3.7"<<endl;
 	cout<<"\t\tB+\t\t\t3.3"<<endl;
 	cout<<"\t\tB\t\t\t3.0"<<endl;
 	cout<<"\t\tB-\t\t\t2.7"<<endl;
 	cout<<"\t\tC+\t\t\t2.3"<<endl;
 	cout<<"\t\tC\t\t\t2.0"<<endl;
 	cout<<"\t\tC-\t\t\t1.7"<<endl;
 	cout<<"\t\tD+\t\t\t1.3"<<endl;
 	cout<<"\t\tD\t\t\t1.0"<<endl;
 	cout<<"\t\tD-\t\t\t0.7"<<endl;
 	cout<<"\t\tF\t\t\t0.0"<<endl;
 	cout<<endl<<endl<<endl;


    int NoOfSubs;
	double credits[NoOfSubs];
	double points[NoOfSubs];
	double sum=0;
	double total;
	double totalCredits=0;

 	cout<<"Enter number of subjects of current Semester: ";
 	cin>>NoOfSubs;
 	cout<<endl;
 	
 	for(int i=1;i<=NoOfSubs;i++)
 	{
 		cout<<"Enter Credit Hours of Subject "<<i<<" : ";
 		cin>>credits[i];
 		cout<<"Enter Points(Grade Points) of Subject "<<i<<" : ";
 		cin>>points[i];
 		cout<<endl;
 		cout<<"-------------------------------"<<endl;
 		
	 }


     
    for(int i=1;i<=NoOfSubs;i++){
    	total=credits[i]*points[i];
    	sum +=total;
    	
	}
	for(int i=1;i<=NoOfSubs;i++){
		totalCredits +=credits[i];
	}
	cout<<endl<<endl;

    int final_gpa= sum/totalCredits;
	cout<<"Total Points: "<<sum<<endl;
	cout<<"Total Credit Hours: "<<totalCredits<<endl;
	cout<<"Total GPA: "<<final_gpa<<endl<<endl<<endl<<endl;

    ofstream gpa("database.txt", ios::app);
    gpa<<"Your Total Points are: "<<sum<<endl<<"Your Total Credit Hours are: "<<totalCredits<<endl<<"Your Total GPA is: "<<final_gpa<<endl<<endl;
    string command = "python send_email.py " + to_string(sum) + " " + to_string(totalCredits) + " " + to_string(final_gpa) + " " + email;
    system(command.c_str());
	
    system("cls");

    return;
}


void gpa() {
    string email;
    cout << "Enter your email address: ";
    cin >> email;

    cout << "Calculating GPA..." << endl;
    calculate_gpa(email);
}

void showAllData() {
    string r;
    
    string roll;
    string name;
    string department;
    cout<<"\t\tEnter your Roll Number: ";
    cin>>r;
    system("cls");

    // // OPENING THE FILE AND CHECKING THAT DATA IS BEING MATCHED OR NOT

    ifstream input("names.txt", ios::app);
    ifstream gpa("database.txt", ios::app);

    // // Read username and password from the file line by line
    while (input >>roll>>name>>department) {



        if (r == roll) {
            cout << "*******************************************" << endl;

            cout<<"Your Name is: "<<name<<endl;
            cout<<"Your Roll Number is: "<<roll<<endl<<endl;
            cout <<"All data from the database:" << endl<<endl;
            cout <<gpa.rdbuf()<<endl;
            cout <<"********************************************" << endl<<endl<<endl;


            gpa.close();
            
        }

        else{
            cout<<"\t\tThe Roll Number "<<r<<" is not in the Database"<<endl<<endl;
        }
    }

    input.close();
    


}


void graph(){
    cout<<"You have entered graph";
}
