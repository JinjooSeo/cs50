#include <stdio.h>
#include <string.h>
#include <stdbool.h> //need to use the boolean

bool print_menu(char* day_input);

int main(){
	char *day;  //define input
	bool flag = true; //initialize the flag which will be used in wrong case

	while (flag == true){ //ask the question until correct case comes out
		printf("요일을 입력하세요: ");
		scanf("%s", day);
		flag = print_menu(day);
	}
}

bool print_menu(char* day_input){
	//define array of days and foods
	const char *day[7] = { "월요일", "화요일", "수요일", "목요일", "금요일", "토요일", "일요일"};
	const char *food[7] = { "청국장", "비빔밥", "된장찌개", "칼국수", "냉면", "소불고기", "오삼불고기"};

	int index = -1; //initalize the index of array

	for(int i=0; i<7; i++){ //i is the kind of index of array
		if(strcmp(day_input, day[i]) == 0){ //if input value(day_input) and defined value(component of day array) are consistant,
			index = i;  //save the index
			break; //and break the loop
		}
		else continue; //if input value(day_input) and defined value(component of day array) are not consistant, rerun the loop with next i
	}

	if(index != -1) {
		printf("%s : %s\n", day[index], food[index]); //if index have a value (not -1), print out the day and food
		return false; //return the flag of correct case
	}
	else {
		printf("요일을 확인해주세요.\n"); //if index have a wrong value(such as -1), request the check of day
		return true; //return the flag of wrong case
	}
}
