#include <stdio.h>

//define scores and grades
const int NUM_OF_ARG = 9;
const int SCORES[NUM_OF_ARG] = { 95, 90, 85, 80, 75, 70, 65, 60, 0 };
const char* GRADES[NUM_OF_ARG] = { "A+", "A", "B+", "B", "C+", "C", "D+", "D", "F" };

void printGradeTable();
int setScore();
const char* getGrade(int score);

int main(int argc, char *argv[]) {
  printf("학점 프로그램\n");
  printf("종료를 원하면 ""999"" 를 입력\n");

  printGradeTable(); //print grade table

  int score = -1; //intialize the score
  score = setScore(); //set score from external input

  while(score!=999){ //print out the grade until score equals to 999
    if (score >100 || score < 0) printf("** %d 성적을 올바르게 입력하세요. 범위는 0 ~ 100입니다.\n", score);
    else printf("학점은 %s 입니다.\n", getGrade(score)); //assgin the grade by score and print it
    score = setScore();  //get grade by score
  }

  printf("학점 프로그램을 종료합니다.\n"); //EOS

  return 0;
}

// TO DO..? : print grades and scores within table
void printGradeTable(){
  printf("[ 학점 테이블 ]\n");

  printf("점수 : ");
  for (int i=0; i<NUM_OF_ARG; i++) {
    printf("%i\t",SCORES[i]);
  }

  printf("\n학점 : ");
  for (int i=0; i<NUM_OF_ARG; i++) {
    printf("%s\t",GRADES[i]);
  }
  printf("\n");

}

//set score from external input
int setScore(){
  int input;

  printf("성적을 입력하세요 (0 ~ 100): ");
  scanf("%i", &input);

  return input;
}

//assgin the grade by score
const char* getGrade(int score){
  if (score >= 95) return GRADES[0];
  else if (score >= 90 && score < 95) return GRADES[1];
  else if (score >= 85 && score < 90) return GRADES[2];
  else if (score >= 80 && score < 85) return GRADES[3];
  else if (score >= 75 && score < 80) return GRADES[4];
  else if (score >= 70 && score < 75) return GRADES[5];
  else if (score >= 65 && score < 70) return GRADES[6];
  else if (score >= 60 && score < 65) return GRADES[7];
  else return GRADES[8];
}
