/*
Q4: Two dates are given in a 8 node single linked list form,where each node
has one digit only, dates 01-31, months 01-12, year 0000-9999.

Find the number of days in between those two dates .[Exclusive]

Ex : Date1:  0->1->0->1->2->0->0->4 .
     Date2 : 0->5->0->1->2->0->0->4 should return 3 .
As there are 3 days between Jan1st 2004 and Jan 5th 2004.

Ex 2 : Date1 : 3->1->1->2->2->0->1->2.
       Date2 : 0->2->0->1->2->0->1->3 should return 1 .
(There is only one day between 31st Dec 2012 and 2nd  Jan 2013 .)

Note : Consecutive Days and Same Days should return 0;
->Return -1 for NULL Inputs .
->Between Days have to be calculated by not including start and end date .
->The SLL will have 8 Nodes in all cases . Month 9 will be represented as 09.

Difficulty : Hard 
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct node{
	int data;
	struct node *next;
};

int* GetDate(struct node *datehead)
{
	int date[3] = { 0, 0, 0 };

	
	date[0] = datehead->data * 10;
	datehead = datehead->next;
	date[0] += datehead->data;
	datehead = datehead->next;

	date[1] = datehead->data * 10;
	datehead = datehead->next;
	date[1] += datehead->data;
	datehead = datehead->next;

	date[2] = datehead->data * 1000;
	datehead = datehead->next;
	date[2] += datehead->data * 100;
	datehead = datehead->next;
	date[2] = datehead->data * 10;
	datehead = datehead->next;
	date[2] += datehead->data;
	
	return date;
}

int isLeap(int yy) {
	if (yy % 4 == 0 && yy % 400 != 0) return 1;
	else return 0;
}

int checkDate(int dd, int mm, int yy){
	if (dd && mm && yy) {
		if (dd <= 0 || dd>31) return 0;

		if (mm>0 && mm <= 12){
			if (mm == 4 || mm == 6 || mm == 9 || mm == 11){
				if (dd>30) return 0;
			}
			else if (mm == 2){
				if (isLeap(yy)){
					if (dd>29) return 0;
				}
				else{
					if (dd>28) return 0;
				}
			}
		}

		return 1;
	}
	else return 0;
}

int GetDays(int *date)
{
	int i;
	int daysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (isLeap(date[2]) == 1)
	{
		daysInMonth[1]++;
	}

	int daysInMon = 0;
	for (i = 0; i < date[1] -1; i++)
		daysInMon += daysInMonth[i];

	int yy = date[2] % 400;
	int daysInYr = yy * 365 + (yy - 1) / 4;


	return date[0] + daysInMon + daysInYr;
}

int between_days(struct node *date1head, struct node *date2head){
	
	if (date1head == NULL || date2head == NULL)
		return -1;

	int *date1 = GetDate(date1head);
	int *date2 = GetDate(date2head);

	if (checkDate(date1[0], date1[1], date1[2]) == 1 && checkDate(date2[0], date2[1], date2[2]) == 1)
		return (GetDays(date1) - GetDays(date2)) - 1;

	return -1;


}