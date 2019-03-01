#include <stdio.h>

void convert(char* id15, char* id18){
	int i, j, k;
	int power[] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
	for (i = 0; i < 6; i++)
		id18[i] = id15[i];
	id18[6] = '1'; id18[7] = '9';
	for (i = 6; i < 15; i++)
		id18[i+2] = id15[i];
	k = 0;
	for (i = 0; i < 17; i++)
		k += (id18[i] - '0')*power[i];
	k = (12 - k % 11) % 11;
	id18[17] = k == 10 ? 'x' : k + '0'
	//if (k == 10)
	//	id18[17] = 'X';
	//else
	//	id18[17] = k + '0';
	//id18[18] = 0;
}

int main(){
	char id15[20];
	char id18[20];
	int i, j, k;

	while (1) {
		printf("Please input a 15 digits id number, 000 to exit.\n");
		scanf("%s", id15);
		if (id15[0] == '0' && id15[1] == '0' && id15[2] == '0')
			return 0;
		convert(id15, id18);
		printf("18 digits id number is: %s\n", id18);
	}

	return 0;
}
