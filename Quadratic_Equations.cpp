#include <iostream>
#include <cmath>
#include <complex>
using namespace std;
int main()
{
    cout << "\t\t\tSolving quadratic equations";
    double a, b, c;
    cout << "\nWrite the values of a,b and c: ";
    cin >> a >> b >> c;
    double discriminant, p_root, n_root;
    discriminant = b * b - 4 * a * c;
     if (discriminant < 0)
    {
        complex<double> sqrt_dis = sqrt(complex<double>(discriminant, 0));
        complex<double> root1 = (-b + sqrt_dis) / (2* a);
        complex<double> root2 = (-b - sqrt_dis) / (2* a);
        cout << "The equation has two complex roots:\n";
        cout << "1st root: " << root1 <<"i"<< endl;
        cout << "2nd root: " << root2 <<"i"<< endl;
    }
    else if (discriminant == 0)
    {
        double root = -b / (2 * a);
        cout << "The equation has one real root: " << root << endl;
    }
    else
    {
        double sqrt_dis = sqrt(discriminant);
        cout << "The roots exist: \n";
        p_root = (-b + (sqrt_dis)) / (2 * a);
        n_root = (-b - (sqrt_dis)) / (2 * a);
        cout << "The 1st roots are: " << p_root << endl;
        cout << "The 2nd roots are: " << n_root;
    }
}
