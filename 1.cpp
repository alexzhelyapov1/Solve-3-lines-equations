#include <stdio.h>

double Determinant3 (int *a1, int *a2, int *a3);
double Determinant2 (int *a1, int *a2);

int main () {
	int a[4][3];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			scanf ("%d", &a[j][i]); // имеем массив а (номер столбца) (номер строки), т.е. по массивам - столбцам
		}
	}
	double det = Determinant3 (a[0], a[1], a[2]);
	if (det == 0) {
		printf ("NO\n");
		return 0;
	}
	double detX = Determinant3 (a[3], a[1], a[2]);
	double detY = Determinant3 (a[0], a[3], a[2]);
	double detZ = Determinant3 (a[0], a[1], a[3]);
	printf ("%lg\n%lg\n%lg\n", detX / det, detY / det, detZ / det);
	return 0;
}


double Determinant3 (int *a1, int *a2, int *a3) {
	return a1[0] * Determinant2 (a2 + 1, a3 + 1) - a2[0] * Determinant2 (a1 + 1, a3 + 1) + a3[0] * Determinant2 (a1 + 1, a2 + 1);
}

double Determinant2 (int *a1, int *a2) {
	return a1[0] * a2[1] - a1[1] * a2[0];
}