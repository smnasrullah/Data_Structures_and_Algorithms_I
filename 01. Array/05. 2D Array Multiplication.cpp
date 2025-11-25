#include <iostream>
using namespace std;

int main()
{
    int m, n, p, q, c, d, k, sum = 0;

    cout << "Enter number of rows and columns of first matrix" << endl;
    cin >> m >> n;
    int first[m][n], second[m][n], multiply[m][n];

    cout << "Enter elements of first matrix" << endl;
    for (c = 0; c < m; c++)
        for (d = 0; d < n; d++)
            cin >> first[c][d];

    cout << "Enter number of rows and columns of second matrix" << endl;
    cin >> p >> q;
    if (n != p)
        cout << "The multiplication isn't possible." << endl;
    else
    {
        cout << "Enter elements of second matrix" << endl;
        for (c = 0; c < p; c++)
            for (d = 0; d < q; d++)
                cin >> second[c][d];
        for (c = 0; c < m; c++)
        {
            for (d = 0; d < q; d++)
            {
                for (k = 0; k < p; k++)
                {
                    sum = sum + first[c][k]*second[k][d];
                }
                multiply[c][d] = sum;
                sum = 0;
            }
        }
        cout << "Product of the matrices:" << endl;
        for (c = 0; c < m; c++)
        {
            for (d = 0; d < q; d++)
                cout << multiply[c][d] << "\t";
            cout << endl;
        }
    }
    return 0;
}
