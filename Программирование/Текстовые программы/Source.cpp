/*
	ѕрограмма ещЄ полность не усовершенствована, то есть ещЄ не предусмотрены:
	- если вклад рассчитываетс€ в дн€х
	- вклад в другой валюте, то есть имеетс€ ввиду, чтобы через switch() сделать выбор валюты, скорее валютного вклада.
	- ежемес€чное пополнение вручную
	

*/

#include <iostream>
#include <vector>

using namespace std;

vector <int> input_month()
{
	int days_in_month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; // учесть и високосные года условие и отдельный массив
	vector <int> month;
	cout << "¬ведите количество мес€цев: "; 
	int n; cin >> n;
	cout << "\n акой сейчас мес€ц?\n- ";
	int now_month = 4; cin >> now_month; now_month -= 1;
	for (n; n > 0; n--)
	{
		month.push_back(days_in_month[now_month]);
		if (now_month < 11)
			now_month++;
		else if (now_month == 11)
			now_month = 0;
	}
	cout << "¬ыплата будет совершена в " << now_month + 1 << "-м мес€це.\n";
	return month;
}

double input_precent()
{
	cout << "\n¬ведите процент вклада: ";
	double precent; cin >> precent;
	return precent;
}

double input_replenishment()
{
	cout << "\n¬ведите сумму ежемес€чного пополнени€: ";
	double rep; cin >> rep;
	return rep;
}

double input_deposit()
{
	cout << "\n¬ведите сумму первоначального вклада: ";
	double dep; cin >> dep;
	return dep;
}

double calculation_deposit(const vector<int>& mth, const double& dep_pcrt, const double& first_dep, const double& replen)
{
	double dep = first_dep;
	for (int i = 0; i < mth.size(); i++)
	{
		dep += (dep * dep_pcrt * mth[i]) / (365.00 * 100.00);
		cout << i + 1 << "-й мес€ц: " << dep << " + " << replen << "\n";
		dep += replen;
		
	}
	return dep;
}

int main()
{
	setlocale(LC_ALL, "rus");
	vector <int> month = input_month();
	double deposit_percentage = input_precent();
	double first_deposit = input_deposit();
	double replenishment = input_replenishment();
	cout << "\n–асчЄты по мес€цам:\n";
	double total  = calculation_deposit(month, deposit_percentage, first_deposit, replenishment);
	cout << "\n»тогва€ сумма: " << total << ".\n";
	system("pause");
	return 0;
}