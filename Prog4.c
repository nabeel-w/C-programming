#include<stdio.h>
#include<stdlib.h>
typedef struct Student
{
    char *name,*batch;
    int id,tot_marks;
}Student;

int main(){
    int n;
    printf("Enter the number of students: ");
    scanf("%d",&n);
    Student *class[n];
    for (int i = 0; i < n; i++)
    {
        class[i]=malloc(sizeof(Student));
        printf("Enter name for student %d: ",i+1);
        scanf("%s",class[i]->name);
        printf("Enter id for student %d: ",i+1);
        scanf("%d",class[i]->id);
        printf("Enter batch for student %d: ",i+1);
        scanf("%s",class[i]->batch);
        printf("Enter marks for student %d",i+1);
        scanf("%d",class[i]->tot_marks);
    }
    /*for(int i=0; i < n; i++)
    {
        printf("Students : %s",class[i]->name);
    }*/

}
