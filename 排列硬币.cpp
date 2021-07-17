#include <iostream>
using namespace std;
class Arrange {
	private:
		double sqrt(double x, int n)
		{
			double res = (x + (2 * 1.0 * n - x) / x) / 2;
			if (res == x) {
				return res;
			}
			return sqrt(res, n);
		}

	public:
		int arrange(int n)
		{
			if (n == 0) {
				return 0;
			}
			return (int)sqrt(n, n);
		}
};
int main()
{
	Arrange ar;
	int n;
	cout << "ÊäÈëÒ»¸öÊý:" << endl;
	cin >> n;
	int res = ar.arrange(n);
	cout << res << endl;
	return 0;
}
