#include <iostream>
#include <string>
using namespace std;

struct ThongTin
{
    string Hoten;
    float Can_nang, Chieu_cao;
};
void Cong_thuc_BMI(ThongTin tt)
{
    float BMI = tt.Can_nang / (tt.Chieu_cao * tt.Chieu_cao);
    string KQ;
    cout << "Ket qua BMI cua ban " << tt.Hoten << " la: " << BMI;
    cout << KQ << endl;
    if (BMI >= 18.5 && BMI <= 25)
    {
        cout << " Nguoi can doi!! Good! Congratulation!! ";
    }
    else if (BMI >= 25 && BMI <= 30)
    {
        cout << " Ulatr beo phi roi ma oi :(( TAP THE DUC DI ";
    }
    else
    {
        cout << "Om qua an nhieu do di @@ Co da thit chut moi xinh ";
    }
}
int main()
{
    ThongTin tt;
    cout << "\n Ten cua ban la:";
    getline(cin, tt.Hoten);
    cout << "\n Can nang cua ban la:";
    cin >> tt.Can_nang;
    cout << "\n Chieu cao cua ban la:";
    cin >> tt.Chieu_cao;
    Cong_thuc_BMI(tt) ;
    // system("pause");         
}
