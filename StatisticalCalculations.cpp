#include"StatisticalCalculations.h"
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<fstream>
using namespace std;
template<typename T>
StatisticalCalculations<T>::StatisticalCalculations(int sz){

    size=sz;
    data=new T[size];
    readfromfile=false;
    inputfilestream=nullptr;
}
template<typename T>
StatisticalCalculations<T>::~StatisticalCalculations() {
    delete[]data;
}
template<typename T>
void StatisticalCalculations<T>::setfile(std::ifstream *fileStream) {
    inputfilestream=fileStream;
    readfromfile=true;
}
template<typename T>
void StatisticalCalculations<T>::inputData() {
    if(readfromfile)
    {
        for(int i=0;i<size;i++)
        {
            (*inputfilestream)>>data[i];
        }
    }
}
template<typename T>
void StatisticalCalculations<T>::displayArray() {
    Sort();
    cout<<"The array Elements Are: ";
    for(int i=0;i<size;i++)
    {
        cout<<data[i]<<" ";
    }
    cout<<endl;
}
template<typename T>
void StatisticalCalculations<T>::StatisticalMenue() {
    int choice;
    do{
        cout<<"Select an Statistical Calculation:\n";
        cout<<"1)Find Median\n";
        cout<<"2)Find Minimun\n";
        cout<<"3)Find Maximun\n";
        cout<<"4)Find Mean\n";
        cout<<"5)Find Summation\n";
        cout<<"6)Exist\n";
        cout<<"Enter Your Choice(1-6)\n";
        cin>>choice;
        switch (choice) {
            case 1:Findmedian();break;
            case 2:FindMin();break;
            case 3:FindMax();break;
            case 4:FindMean();break;
            case 5:Findsummation();break;
            case 6:cout<<"Existing...";break;
            default:cout<<"Invalid choice Try Again\n";break;


        }
    } while (choice!=6);

}
template<typename T>
void StatisticalCalculations<T>::Sort() {

    for (int i = 0; i < size - 1; i++) {
        int least = i;
        for (int j = i + 1; j < size; j++) {
            if (data[j] < data[least]) {
                least = j;
            }
        }

        if (least != i) {
            swap(data[i], data[least]);
        }
    }
}


template<typename T>
T StatisticalCalculations<T>::FindMin() {
    Sort();
    if(size==0)
    {
        cout<<"Error the Array is empty until now\n";
        return T();
    }
    else
    {
        cout<<"The Minimum Element is: "<<data[0]<<endl;
        return data[size-1];
    }

}
template<typename T>
T StatisticalCalculations<T>::FindMax() {
    Sort();
    if(size==0)
    {
        cout<<"Error the array is empty until now\n";
        return T();
    }
    else
    {
        cout<<"The Maximum Element is: "<<data[size-1]<<endl;
        return data[size-1];
    }

}
template<typename T>
T StatisticalCalculations<T>::Findsummation() {
    double sum=0;

    for (int i = 0; i < size ; i++) {
        sum += data[i];
    }

    cout<<"The Summation is: "<<sum<<endl;
    return sum;

}
template<typename T>
double StatisticalCalculations<T>::FindMean() {
    if(size==0){
        cout<<"Error the Array is Empty\n";
        return 0;
    }
    double sum=Findsummation();
    double mean=sum/size;
    cout<<"The Mean equal "<<mean<<endl;
    return mean;

}
template<typename T>
double StatisticalCalculations<T>::Findmedian() {
    Sort();
    double median=0.0;
    if(size==0)
    {
        cout<<"Error the array is empty\n";
        return T();
    }
    else if(size%2==0 && size!=0)
    {
        int s=size/2;
        median=(data[s]+data[s-1])/2.0;
        cout<<"The Median equal "<<median<<endl;
        return median;

    }
    else if(size%2!=0 && size!=0)
    {
        int s=size/2;
        median=data[s];

        cout<<"The Median equal "<<median<<endl;
        return median;


    }

}

int main() {
    cout << "Enter the file name including extension: ";
    string file_name;
    cin >> file_name;

    ifstream inputFile(file_name);
    if (!inputFile) {
        cout << "Error: cannot open the file." << endl;
        return 1;
    }

    string datatype;
    while (inputFile >> datatype) {
        int size;
        inputFile >> size;

        if (size <= 0) {
            cout << "Error: The size must be greater than zero." << endl;
            continue;
        }


        if (datatype == "int") {
            StatisticalCalculations<int> obj(size);
            obj.setfile(&inputFile);
            obj.inputData();
            obj.displayArray();
            obj.StatisticalMenue();
        } else if (datatype == "double") {
            StatisticalCalculations<double> obj(size);
            obj.setfile(&inputFile);
            obj.inputData();
            obj.displayArray();
            obj.StatisticalMenue();
        } else if (datatype == "float") {
            StatisticalCalculations<float> obj(size);
            obj.setfile(&inputFile);
            obj.inputData();
            obj.displayArray();
            obj.StatisticalMenue();
        } else {
            cout << "Invalid data type: " << datatype << endl;
            continue;
        }

        cout << "------------------- Next Test Case -------------------\n";
    }

    inputFile.close();
    return 0;
}
