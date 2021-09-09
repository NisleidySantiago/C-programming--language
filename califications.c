/*****************************************************************************************
*                                                                                        *
*																						 *
*                                                                                        *
*                                                                                        *
*                                                                                        *
*                                 STUDENT DETAILS HERE                                   *
*                                                                                        *
*                                                                                        *
*                                                                                        *                                                                                  
*                                                                                        *
*                                                                                        * 
******************************************************************************************/

#include <stdio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <math.h>
#define SIZE 7

void Read_File();
void show_File();
void Menu_help();
void Options_Process();
void option_diploma();
void option_ordering_A();
float operation_average();
void save_New_File();

/////////////////////////////////////////////////////////////////////////////////////////

float a[SIZE];
float b[SIZE];
int j;
int i=0;
float temp;
char student_name[30];
int student_No;
double subject_A;
double subject_B;
char caracter1;
char c2;
float summation;
float s;
float average;
float average2;
float summation2;
float s2;
FILE *ptrCf;
FILE *ptrCf2;

////////////////////////MAIN//////////////////////////////////////

int main()
{
	/*PART I*/
char table[10];	
printf("\nPlease enter input file name\n");
scanf("%s", table);
printf("File %s", table);
/* ptrCf = file pointer lab1.txt */
/* fopen open the file; if the file cannot be opened, quit the
Program */

if ( ( ptrCf = fopen( table, "r" ) ) == NULL ) {
printf( "The file could not be opened\n" );
} //end if

else{
/* Read the student's name, student's number, Subject A and Subject B */
Read_File();
show_File();
rewind( ptrCf ); /* return ptrCf to the beginning of the file */	
printf("Please enter a command (enter h for help): ");	
getchar();
Options_Process();
fclose ( ptrCf );
fclose ( ptrCf2 );
}//end else
}//end main


//////////////////////FUNTIONS//////////////////////////////////////////////////////////////

/* Read the student's name, student's number, Subject A and Subject B */
void Read_File(){
printf( "%-10s%-13s%-13s%-13s\n", "\nSTUDENT NAME ", "STUDENT NO.", "SUBJECT A" , "SUBJECT B");
fscanf( ptrCf, "%s%d%lf%lf", student_name, &student_No, &subject_A, &subject_B );
}

////////////////////////////////////7//Show File///////////////////////////
void show_File(){
while ( !feof( ptrCf ) ) {
printf( "%-13s%5d%15.1f%15.1f\n", student_name, student_No, subject_A, subject_B );
fscanf( ptrCf, "%s%d%lf%lf", student_name, &student_No, &subject_A, &subject_B );
} /* end while */
}

/////////////////////////////////COMMAND HELP/////////////////////

	void Menu_help(){
		printf("a/1 to obtain all the students that got diploma\n");
		printf("b/2 to arrange subject A in ascending order\n");
		printf("c/3 to calculate the average and standard deviation\n");
		printf("d/4 to save all the above results in an output file\n");
		printf("e to exit\n");
		getchar();
	}

////////////OPTIONS PROCESS/////
void Options_Process(){

scanf("%c", &c2);
/* processes the user's query */
while (c2 != 'e') {

switch ( c2 ) {
case '1':
case 'a':
		printf("\nAll the students that have a diploma \n");
		option_diploma();
break;

case '2':
case 'b':
printf("Subject A in ascending order");
		option_ordering_A();
break;

case'3':
case 'c':
printf("The average and standard deviation");	
operation_average();				
break;

case'4':
case 'd':
printf("All the above results in an output file\n");
save_New_File();
break;

case'h':
Menu_help();
Options_Process();
break;

} /* end switch */
rewind( ptrCf ); /* return ptrCf to the beginning of the file */	
if(c2=='e'){
	break;
}
else{
printf( "\n " );
printf("Please enter a command (enter h for help): ");	
getchar();
scanf( "%c", &c2 );
}

}//end while
}

/////////////////////////   DIPLOMA  /////////////////

void option_diploma(){
		printf( "%-10s%-13s%-13s\n", "STUDENT NAME ", "SUBJECT A" , "SUBJECT B");

		/* Read the data from the file.txt ( until eof) */
		while ( !feof( ptrCf ) ) {
			if ( subject_A >= 50 && subject_B>=50) {
				printf( "%-13s%8.1f%10.1f\n", student_name, subject_A, subject_B );
			} /* end if */
		/* Read student name, student NO, subject a and subject b*/
		fscanf( ptrCf, "%s%d%lf%lf", student_name, &student_No, &subject_A, &subject_B );
		} /* end while */
}
//////////////////Ordering Subject A////////////////////////////////////////
void option_ordering_A(){
	while ( !feof( ptrCf ) ) {
				//printf( "%.1f\n", subject_A );
				a[i]=subject_A;
				fscanf( ptrCf, "%s%d%lf%lf", student_name, &student_No, &subject_A, &subject_B );
				i=i+1;
				} /* end while */
				  for (i = 0; i < (SIZE - 1); i++) 
				  { 
				    for (j = i + 1; j < SIZE; j++) 
				    { 
				      if (a[j] < a[i]) 
				      { 
				        temp = a[j]; 
				        a[j] = a[i]; 
				        a[i] = temp; 
				      }
				    } 
				  }
				  /* Show Numbers Sorted */
				  rewind( ptrCf );

				  printf( "%-10s%-13s%-13s\n", "\nSTUDENT NAME ", "SUBJECT A" , "SUBJECT B");
				  fscanf( ptrCf, "%s%d%lf%lf", student_name, &student_No, &subject_A, &subject_B );
				  for (i = 0; i < SIZE; i++) 
				  { 
				  	printf( "%-13s%8.1f%12.1f\n", student_name, a[i], subject_B );
					fscanf( ptrCf, "%s%d%lf%lf", student_name, &student_No, &subject_A, &subject_B );
				    //printf("%.1f, ", a[i]); 
				  } 
				  printf("\n\n\n");

}

////////////////////////////////the average and standart devation//////////////////////////////////////
float operation_average(){ // defining average function
i=0; 
		average=0;
		s=0;
		average2=0;
		summation=0;
		summation2=0;
		s2=0;
		while ( !feof( ptrCf ) ) {
				//printf( "%.1f\n", subject_A );
				a[i]=subject_A;
				b[i]=subject_B;
				fscanf( ptrCf, "%s%d%lf%lf", student_name, &student_No, &subject_A, &subject_B );
				i=i+1;
				} /* end while */

				  for (i = 0; i < (SIZE); i++) 
				  { 
				    
				   average += (a[i]) / (SIZE); 
  				   summation += pow( (a[i] - average),2);
				   s = sqrt((summation) / (SIZE - 1));
				   
				   }

					for (i = 0; i < (SIZE); i++) 
				  {    
				   average2+=(b[i])/(SIZE);
					summation2+=pow((b[i]-average2),2);
				   s2 = sqrt((summation2)/(SIZE-1));
				   }

				  /* Print the average and standart devation of Subject A  */
				  printf ("Average subject A: %.1f\n", average); 
				  printf ("The Standart Deviation of A is: %.1f\n",s);
					///B///////
				/////* Print the average and standart devation of Subject B */
				  printf ("Average subject B: %.1f\n", average2); 
				  printf ("The Standart Deviation of B is: %.1f\n",s2); 
}

///////////////////////////////// SAVE NEW FILE ////////////////////

void save_New_File(){
    int data1 =1;
    char c[40];
    
    ptrCf = fopen ( "lab1.txt", "r" );
    ptrCf2 = fopen ( "New_Data.txt" , "w" );
	//fputs("STUDENT NAME STUDENT NO SUBJECT A SUBJECT B", ptrCf2);

    while ( (data1 = fgetc ( ptrCf )) != EOF ) {
    fputc ( data1, ptrCf2 );  
    }
    rewind( ptrCf2 );

    if ( ( ptrCf2 = fopen( "New_Data.txt", "r" ) ) == NULL ) {
	printf( "The file could not be opened\n" );
	} //end if

	else{

	printf( "%-10s%-13s%-13s%-13s\n", "\nSTUDENT NAME ", "STUDENT NO.", "SUBJECT A" , "SUBJECT B");
	fscanf( ptrCf2, "%s%d%lf%lf", student_name, &student_No, &subject_A, &subject_B );
////////////////////////////////////7//Show File///////////////////////////
	while ( !feof( ptrCf2 ) ) {
	printf( "%-13s%5d%15.1f%15.1f\n", student_name, student_No, subject_A, subject_B );
	fscanf( ptrCf2, "%s%d%lf%lf", student_name, &student_No, &subject_A, &subject_B );
} /* end while */

}/*end else*/
}