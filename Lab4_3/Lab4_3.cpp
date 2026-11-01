
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    double a, b, c, xp, xk, dx, x, F;

    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;
    cout << "Enter c: ";
    cin >> c;

    cout << "Enter xp: ";
    cin >> xp;
    cout << "Enter xk: ";
    cin >> xk;
    cout << "Enter dx: ";
    cin >> dx;

    if (dx <= 0 || xp > xk)
    {
        cout << "Invalid interval or step." << endl;
        return 0;
    }

    cout << fixed << setprecision(4);
    cout << "------------------------------" << endl;
    cout << "|     x     |       F        |" << endl;
    cout << "------------------------------" << endl;

    for (int i = 0; xp + i * dx <= xk + 1e-9; i++)
    {
        x = xp + i * dx;

        if (a < 0 && c != 0)
            F = a * x * x + b * x + c;
        else if (a > 0 && c == 0)
        {
            if (abs(x - b) < 1e-9)
            {
                cout << "|" << setw(10) << x
                    << " |   undefined    |" << endl;
                continue;
            }

            F = -a / (x - b);
        }
        else
            F = a * (x + c);

        cout << "|" << setw(10) << x
            << " |" << setw(15) << F << " |" << endl;
    }

    cout << "------------------------------" << endl;

    return 0;
}
