#include<iostream>
using namespace std;

// long long int BS(int n){

//     int s = 0;
//     int e = n;
//     long long int mid = s + (e-s)/2;
//     long long int ans = -1;

//     while(s<=e){

//         long long int square = mid*mid;

//         if(square == n){
//             return mid;
//         }
//         if(square < n){
//             ans = mid;
//             s = mid + 1;
//         }
//         else{
//             e = mid - 1;
//         }
//         mid = s + (e-s)/2;
//     }
//     return ans;
// }


// int main(){
//     // int arr[6]={2, 4, 6, 8, 9, 12};
//     int n;
//     cout<<"Enter the vaue of n: ";
//     cin>>n;
//     int mySqrt= BS(n);
//     cout<< "Square root of "<<n<<" is " << mySqrt <<endl;

//     return 0;

// }


long long int BS_sqrtInteger(int n){

    int s = 0;
    int e = n;
    long long int mid = s + (e-s)/2;
    long long int ans = -1;

    while(s<=e){

        long long int square = mid*mid;

        if(square == n){
            return mid;
        }
        if(square < n){
            ans = mid;
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}
double morePrecision(int n, int precision, int tempSol){
    double factor = 1;
    double ans = tempSol;

    for(int i=0; i<precision; i++){
        factor = factor/10;
        for(double j =ans; j*j<n; j =j+factor){
            ans = j;
        }
    }
    return ans;
}

int main(){
    // int arr[6]={2, 4, 6, 8, 9, 12};
    int n;
    cout<<"Enter the vaue of n: ";
    cin>>n;

    int tempSol = BS_sqrtInteger(n);

    cout<< "Square root of "<<n<<" is " << morePrecision(n, 3, tempSol) <<endl;

    return 0;

}