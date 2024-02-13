#include <iostream>
#include <cmath>
#include <string>
 
using namespace std;

string a[50],b[50],c[50],d[50];
int total_sum =0;

void adding(){
    int choice=0;
    cout<<"How much students you want to enter? ";
    cin >>choice;

    if(total_sum==0){
        total_sum = choice+total_sum;
        
        for(int i=0; i<choice; i++){
            cout<<"Below, Enter details of Student: "<<i+1<<endl;
            cout<<"Enter Name ";
            cin>>a[i];

            cout<<"Enter Roll Number ";
            cin >>b[i];

            cout<<"Enter Department ";
            cin >>c[i];

            cout<<"Enter Contact ";
            cin >>d[i];


        }


    }

}
void showing(){
    if(total_sum==0){
        cout<<"YOU HAVEN'T ENTERED ANY DATA!!"<<endl;
    }

    else{
        for(int i=0;i<total_sum; i++){
            cout<<"Student "<<i+1<<endl;
	    	cout<<"Name "<<a[i]<<endl;
	    	cout<<"Roll no "<<b[i]<<endl;
	    	cout<<"Department "<<c[i]<<endl;
	    	cout<<"Contact "<<d[i]<<endl<<endl;
        }
    }

}
void searching(){
    if(total_sum==0){
        cout<<"YOU HAVEN'T ENTERED ANY DATA!!"<<endl;
    }

    else{
        string roll;
        cout<<"Enter Roll Number of Student: ";
        cin >>roll;

        for (int i=0; i<total_sum; i++){

            if(roll == b[i]){
                cout<<"Name "<<a[i]<<endl;
                cout<<"Roll Number" <<b[i]<<endl;
                cout<<"Department "<<c[i]<<endl;
                cout<<"Contact "<<d[i]<<endl<<endl;            

            }
            else{
                cout<<"No Roll Number is Entered in our Record "<<endl<<endl;
            }
        }
    }
}
void deleting(){
    if(total_sum==0){
        cout<<"YOU HAVEN'T ENTERED ANY DATA!!"<<endl;
    }

    else{
        int option;
        cout<<"WARNING! IF YOU WANT TO DELETE ALL RECORD ENTER 1 ";
        cin >>option;

        if(option==1){
            total_sum=0;
            cout<<"All of Your RECORD IS deleted! "<<endl;
        }
    }

}

 
main(){
    int value;

    while(true){
    cout <<"WELCOME TO ATTENDENCE SYSTEM!!"<<endl;
    cout<<"Choose any Option's from below:"<<endl;
    cout<<"1. Add Student Data"<<endl;
    cout<<"2. Show all the Data"<<endl;
    cout<<"3. Search Data"<<endl;
    cout<<"4. Delete Data"<<endl;
    cout<<"5. TO EXIT!!!"<<endl;

    cin >> value;

    switch (value)
    {
    case 1:
        adding();
        break;
    case 2:
        showing();
        break;
    case 3:
        searching();
        break;
    case 4:
        deleting();
        break;
    case 5:
        exit(0);
        break;
    default:
        cout<<"Choose Options from 1-5.";
        break;
    }
}

return 0;
}