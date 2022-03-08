#include <stdio.h>
#include <stdlib.h>

int value_check(char subject[], int min, int max);
int grade_check(float avg);
#define NUM  3

int main(void)
{
	int flag = 0; //거짓
	char name[10] = " "; //" ";로 null 값을 준다.(배열값 초기화)
	int num = 0, age = 0, php = 0, c = 0, html = 0;
	float total = 0.0;
	float avg = 0.0;
	char grade = 0;

	int count = 0;
	int i = 1;

	while (i < 3) {
		
		printf("input name: ");
		scanf_s("%s", name, 10);

		num = value_check("num", 1, 50);
		age = value_check("age", 20, 40);
		php = value_check("php point", 0, 100);
		html = value_check("html point", 0, 100);
		c = value_check("c point", 0, 100);

		total = php + html + c;
		avg = total / NUM;
		
		grade = grade_check(avg);

		printf("%s %d %d %d %d %d %f %f %c\n", name, num, age, php, html, c, total, avg, grade);

		i++;

		/*count += 1;
		if (count >= 5) {
			flag = 1;
		}*/
	}
	return 0;

}

int value_check(char subject[], int min, int max) {
	int input_value = 0;
	int flag = 0;

	while (!flag) {
		printf("%s input(%d~%d): ", subject, min, max);
		scanf_s("%d", &input_value);
		if (input_value <= max && input_value >= min) {
			flag = 1;
		}
	}
	flag = 0;

	return input_value;
}

int grade_check(float avg) {

	char grade = 0;

	if (avg >= 90) {
		grade = 'A';
	}
	else if (avg >= 80 && avg < 90) {
		grade = 'B';
	}
	else if (avg >= 70 && avg < 60) {
		grade = 'C';
	}
	else if (avg >= 60 && avg < 70) {
		grade = 'D';
	}
	else
		grade = 'F';

	return grade;
}