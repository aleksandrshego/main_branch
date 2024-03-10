#include <iostream>
#include <vector>
#include <Windows.h>
#include <iomanip>

using namespace std;

void sum_matrix(vector<vector<int>>& matr, const int& num_need_string, const int& num_sum_string)
{
    for (int i = 0; i < matr[num_need_string-1].size(); ++i)
        matr[num_need_string-1][i] = (matr[num_need_string-1][i] + matr[num_sum_string-1][i]) % 2;
}

void matrix_output(const vector<vector<int>>& matr)
{
    cout << "\nOutput matrix:\n";
        for (int i = 0; i < matr.size(); ++i){
            cout << fixed <<  setw(4) << i + 1 << " | ";
            for (const auto& r : matr[i])
                cout << r << " ";
            cout << "\n";
        }
}

void matrix_input(vector<vector<int>>& matr)
{
    cout << "Input values:\n";
        for (auto& s : matr)
            for (auto& r : s)
                cin >> r;
}

int main(){
    cout << "Input number strings: "; int strings; cin >> strings; cout << "\n";
    cout << "Input number rows: "; int rows; cin >> rows; cout << "\n";

    vector<vector<int>> matrix(strings, vector<int>(rows));
    
    matrix_input(matrix);
    matrix_output(matrix);
    
    while (true){
        int need_string; cout << "Nedeed string: "; cin >> need_string;
        int sum_string; cout << "Sum string: "; cin >> sum_string; 
        if (need_string < 1 || need_string > matrix.size() || sum_string < 1 || sum_string > matrix.size())
            break;
        sum_matrix(matrix, need_string, sum_string);
        matrix_output(matrix);
    }
    
    return 0;
}