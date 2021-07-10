/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h> //for malloc & free functions
#include <time.h>
#define N 10
/*
 * We will use head pointer to always point at the beginning of the list
 * and the last element of the list will always be pointing to NULL
 * (if head points to NULL that means the list is empty)
 */



//A structure that holds the data of students.
struct student_data{
	char name[50];
	int ID;
	int day;
	int month;
	int year;
	int score;
};


//------------------------------------Array Part------------------------------------------

struct student_data *create_dynarr(int n){
    struct student_data *start;
    start=(struct student_data*)malloc(n*sizeof(struct student_data));
    for (int i=1;i<=n;++i){

        (start+i)->name[0] = "a";
        (start+i)->ID = i;
        (start+i)->day = 17;
        (start+i)->month = 9;
        (start+i)->year = 2000;
        (start+i)->score = 150;
    }
    return start;
};



struct student_data *insert(int num,struct student_data*ptr,int index)
{
	num=num+1;
	ptr=(struct student_data*)realloc(ptr,num*sizeof(struct student_data));
	if(index!=(num-1)){
		for(int i=num-1;i>=index;i--)
		{
			strcpy((ptr+i)->name,(ptr+i-1)->name);
			(ptr+i)->ID=(ptr+i-1)->ID;
			(ptr+i)->day=(ptr+i-1)->day;
			(ptr+i)->month=(ptr+i-1)->month;
			(ptr+i)->year=(ptr+i-1)->year;
			(ptr+i)->score=(ptr+i-1)->score;
		}
		(ptr+index)->name[0] = "a";
		(ptr+index)->ID =18;
		(ptr+index)->day = 15;
		(ptr+index)->month = 4;
		(ptr+index)->year = 2000;
		(ptr+index)->score = 150;
	}
	return ptr;
};








//----------------------------------Linked List Part-----------------------------------------


struct node *head = NULL; //A pointer that always points to the first element of the list.
struct node *tail = NULL;//A pointer that always points to the last element of the list.
struct node *current = NULL; //A pointer mainly used to sweep through the list.
struct node *prev = NULL; /* A pointer that always lags from current pointer with one position
(used in inserting at a certain position in the list)*/



struct node
{
	struct student_data st_data;
	struct node *next;
};


void fillStudentData(struct student_data *ptr)
{
	printf("Enter the following data with the same order \n");
	printf("name:\t");
	printf("ID: \t");
	printf("birth data[day,month,year]\t");
	printf("score\n");
	gets(ptr->name);
	scanf("%d",&ptr->ID);
	scanf("%d%d%d",&ptr->day,&ptr->month,&ptr->year);
	scanf("%d",&ptr->score);
	return;
}



//insert link at the beginning of the list
void insertAtFirst(struct student_data *data)
{
	// Allocate memory for new node
	struct node *link = (struct node*) malloc(sizeof(struct node));

	//store data in the node
	link->st_data = *data;

	//In case the list was empty
	if(head == NULL){
		tail = link;
		link->next = NULL;
	}

	//point the next pointer to the old head node
	link->next = head;

	//point the head to the new first node
	head = link;
}

//insert link at the end of the list
void insertAtLast(struct student_data *data)
{
	// Allocate memory for new node
	struct node *link = (struct node*) malloc(sizeof(struct node));

	// insert the data to the new node and make the next point to null
	link->st_data = *data;

	// If head is empty, create new list
	if(head==NULL)
	{
		head = link;
	}else{
		tail->next = link;
	}
	tail = link;
	link->next = NULL;

	return;
}


void insertNodeInsideList(struct student_data *data,int position)
{
	// Allocate memory for new node;
	struct node *link = (struct node*) malloc(sizeof(struct node));
	int pos = 0;
	// If head is empty, create new list
	if(head==NULL)
	{
		link->st_data = *data;
		link->next = NULL;
		head = link;
		tail = link;
		return;
	}
	//check if the array size smaller than in the input position
	if(position > sizeOfList())
	{
		printf("Invalid Index Number\n");

		return;
	}
	//check the first node in the linked list
	if(position == 0)
	{
		link->next = head;
		link->st_data = *data;
		head = link;
		return;
	}
	current = head;
	while(pos < position)
	{
		prev = current;
		current = current->next;
		pos++;
	}
	link->st_data = *data;
	link->next = current;
	prev->next = link;
}


// calculate the list size
int sizeOfList(void)
{
	int size = 0;

	// check if the linked list is empty
	if(head==NULL)
	{
		printf("List size : %d ", size);
		return -1;
	}
	current = head;
	size = 1;
	while(current->next != NULL)
	{
		current = current->next;
		size++;
	}
	return size;
}



void searchForStudent(int id)
{
	if(head == NULL)
	{
		printf("list is empty\n");
	}
	struct node* link = head;
	while(link != NULL)
	{
		if(id == link->st_data.ID)
		{
			printf("name: %s\n",link->st_data.name);
			printf("ID: %d\n",link->st_data.ID);
			printf("birth date: %d/%d/%d\n",link->st_data.day,link->st_data.month,link->st_data.year);
			printf("score: %d\n",link->st_data.score);
			return;
		}
		link = link->next;
	}
	printf("student not found");

	return;
}

void deleteList(void)
{
	struct node* current = head;
	struct node* next;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	head = NULL;
}


void main(void)
{
	/*
	 * These two lines help flush after every printf
	 */
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	printf("Welcome to the students archive \n");

	int start;
	int finish;

    printf("size of student data structure is %d\n",sizeof(struct student_data));
    printf("size of node of our linked list is %d\n",sizeof(struct node));



	struct student_data ST_DATA={0};

	for(int i = 1; i<=N; i++)
	{
		ST_DATA.ID = i;
		ST_DATA.name[0] = 'a';
		ST_DATA.day = 8+i;
		ST_DATA.month = 2+i;
		ST_DATA.year = 2000;
		ST_DATA.score = 150;
		insertAtFirst(&ST_DATA);
		if( i == N){
		    start = clock();
		    insertAtFirst(&ST_DATA);
		    finish = clock();
		}
	}
	printf("time spent with linked list is %d \n",(finish-start));
	deleteList();



	//-----------------------Array Part--------------------------------------
	struct student_data *student_arr;
	student_arr = create_dynarr(N);

	start = clock();
	student_arr = insert(N,student_arr,N);
	finish = clock();

	printf("time spent with array is %d \n",finish-start);
	free(student_arr);

}








