#include <iostream>
using namespace std;

int main() {
    double weight, height;
    double BMI;
    
    cout<<"Enter you weight(kg):";
    cin>>weight;
    cout<<"Enter you height(m):";
    cin>>height;
    
    BMI=weight/(height*height);
    cout<<"Your BMI is: "<< BMI << " ";
    
    if(BMI<18.5){
        cout << "(UNDERWEIGHT)";
    }
    else if(BMI<25){
        cout << "(NORMAL)";
    }
    else if(BMI<30){
        cout << "(OVERWEIGHT)";
    }
    else if(BMI>=30){
        cout << "(OBESE)";
    }
    
    return 0;
}


