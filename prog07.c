//Dan Cocking
//dbcockin
//Program to compare the sort times of bubble and insertion sorts in the worst case
/*
 * Insertion Sort 
 * Pass 1 {5,9,6,7,3,2,1} operations 0
 * Pass 2 {5,9,6,7,3,2,1} Operations 0
 * Pass 3 {5,6,9,7,3,2,1} Operations 1
 * Pass 4 {5,6,7,9,3,2,1} Operations 1
 * Pass 5 {3,5,6,7,9,2,1} Opeartions 4
 * Pass 6 {2,3,5,6,7,9,1} Operations 5
 * Pass 7 {1,2,3,5,6,7,9} Operations 6 / Sorted Array
 */

#include<stdio.h>
#include<time.h>



void PopulateArrayDes(int A[], int n){//Populate the Arrays
  int a= 10000, b = 0;
  while(b<10001){
    A[1] = a;//set the array
    a--;
    A++;
    b++;
  }
}
void CopyArray(int B[], int n, int A[])//Copy Array 
{
  int c = n;//for keeping track of the array
  while(c>0){
  B[1] = A[1];
  c--;
  A++;
  B++;
  }
}
void BubbleSortAsc(int list[], int n)//bubble sort array a
{
  int c, d, t;//ints for swapping
 
  for (c = 0 ; c < ( n - 1 ); c++)//loop control for swaps
  {
    for (d = 0 ; d < n - c - 1; d++)//Loop control for swaps
    {
      if (list[d] > list[d+1])//swap if less, do not swap if not less
      {
        /* Swapping */
 
        t         = list[d];
        list[d]   = list[d+1];
        list[d+1] = t;
      }
    }
  }
}
void InsertionSort(int list[], int size)//.01 secs faster
{
 int i,j,tmp;//ints for insertion sort
 for(i=0; i<size; i++)
 {
   for(j=i-1; j>=0; j--) 
   {
    if(list[j]>list[j+1])//swap if less
    {
      tmp=list[j];
      list[j]=list[j+1];
      list[j+1]=tmp;
    }
    else
      break;
   }
 }
}


void DisplayArray(int A[], int n){//print array to screen
  int b = 1;
  while(b<10){
    printf("\n\t%d", A[b]);
    b++;
    
  }
  
}


int main (void){//main and user menu
  printf("\nWelcome to Dan's HomeWorks Solution #7");
  
  int a[10001], b[10001];//array creation
  a[0] = 0;//set the sentinal
  b[0]= 0;//set the sentinal
  int n = 10001;//for the functions
  int Menu = 0, loopmenu= 0;//menu control
  while(loopmenu==0){//loop menu for user
  printf("\n\n\t1. Exit \n\t2. Populate array \n\t3. Copy array"
	"\n\t4. Display Array (10 items) \n\t5. Bubble Sort"
	"\n\t6. Insertion Sort \n\t7. Calculate time: Bubble Sort"
	"\n\t8. Calculate Time: Insertion Sort\n\t\tPlease enter your choice: ");
  scanf("%d", &Menu);
    switch (Menu){
	case 1: printf("\n\n\t\tThank You!\n\n");
		//system.exit(0); 
		loopmenu++;//exit program 
		break;
	case 2: printf("\n\tPopulating array\n");
		PopulateArrayDes(a, n);
		loopmenu = 0;
		break;
	case 3:	//printf("\n\tArray 1 copied to Array 2\n");
		CopyArray(b, n, a);
		printf("\n\tArray 1 copied to Array 2\n");
		loopmenu = 0;
		break;
	case 4: printf("\n\tDisplaying\n");
		DisplayArray(a, n);//display a
		printf("\n\n\tArray b equals: \n");
		DisplayArray(b, n);//display b
		loopmenu = 0;
		break;
	case 5: printf("\n\tbubble sorting!\n");
		BubbleSortAsc(a, n);//send to bubble sort
		loopmenu = 0;
		break;
	case 6: printf("\n\tInsertion Sorting!\n");
		InsertionSort(b, n);//send to insert sort
		loopmenu = 0;
		break;
	case 7: printf("\n\tTime for Bubble sort \n");//will Redo the sort so It can be timed
		PopulateArrayDes(a, n);//set up array again for timing
		clock_t start1 = clock();//start time using cpu time
		BubbleSortAsc(a, n);
		clock_t end1 = clock();
		printf("\n\tElapsed time: %.2f seconds\n", (double)(end1 - start1) / CLOCKS_PER_SEC);
		loopmenu = 0;
		break;
	case 8: printf("\n\tTime for Insertion Sort was \n");
		PopulateArrayDes(b, n);//set up array again for timing
		clock_t start = clock();//use cpu clock for time
		InsertionSort(b, n);
		clock_t end = clock();//stop time
		printf("\n\tElapsed time: %.2f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);
		loopmenu = 0;
		break;
	default: printf("Please Enter a Valid Choice");//if not one of ints
	
    }
}
return 0;
}