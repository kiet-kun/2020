#include<bits/stdc++.h>
using namespace std;

int n;
string s;

int main(){
    int t;
    cin>>t;
    while (t--){
        cin>>n>>s;
        if ((s=="Mar" && n>=21) || (s=="Apr" && n<=20)) cout<<"Aries\n";
        if ((s=="Apr" && n>=21) || (s=="May" && n<=20)) cout<<"Taurus\n";
        if ((s=="May" && n>=21) || (s=="Jun" && n<=21)) cout<<"Gemini\n";
        if ((s=="Jun" && n>=22) || (s=="Jul" && n<=22)) cout<<"Cancer\n";
        if ((s=="Jul" && n>=23) || (s=="Aug" && n<=22)) cout<<"Leo\n";
        if ((s=="Aug" && n>=23) || (s=="Sep" && n<=21)) cout<<"Virgo\n";
        if ((s=="Sep" && n>=22) || (s=="Oct" && n<=22)) cout<<"Libra\n";
        if ((s=="Oct" && n>=23) || (s=="Nov" && n<=22)) cout<<"Scorpio\n";
        if ((s=="Nov" && n>=23) || (s=="Dec" && n<=21)) cout<<"Sagittarius\n";
        if ((s=="Dec" && n>=22) || (s=="Jan" && n<=20)) cout<<"Capricorn\n";
        if ((s=="Jan" && n>=21) || (s=="Feb" && n<=19)) cout<<"Aquarius\n";
        if ((s=="Feb" && n>=20) || (s=="Mar" && n<=20)) cout<<"Pisces\n";
    }
    return 0;
}
