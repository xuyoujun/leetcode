
#include <stdio.h>
#include <stdlib.h>
int main(void)
{

	int n;

	int count = 1;
	int x, y, round;

	scanf("%d", &n);
	int a[100][100];

	if (n == 1) {
		a[0][0] = count;
	}
	else {

		for (round = 0; round<n / 2; round++) {


			x = round;
			for (y = round; y<n - round; y++) {
				a[x][y] = count;
				count++;
			}

			y = n - round - 1;
			for (x = round + 1; x<n - round - 1; x++) {
				a[x][y] = count;
				count++;
			}


			x = n - round - 1;
			for (y = n - round - 1; y >= round; y--) {
				a[x][y] = count;
				count++;
			}


			y = round;
			for (x = n - round - 1 - 1; x>round; x--) {
				a[x][y] = count;
				count++;
			}
		}
		if (n % 2 == 1) {

			a[n / 2][n / 2] = count;
		}
	}
	for (x = 0; x<n; x++) {
		for (y = 0; y<n; y++) {
			printf("%d ", a[x][y]);
		}
	}
//	system("pause");
	return 0;
}
