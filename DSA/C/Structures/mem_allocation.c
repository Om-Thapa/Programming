#include<stdlib.h>
#include<stdio.h>
struct students
{
    int roll;
    char name[50];
    char department[50];
};

// void main(){
//     struct students *S=(struct students *)malloc(5*sizeof(struct students));
//     int i;
//     for(i = 0 ; i < 2 ; i++ ){
//         S[i].roll=i+1;
//         printf("Enter name and department : ");
//         gets(S[i].name);
//         gets(S[i].dep);
//     }
//     for( i = 0 ; i < 3 ; i++ ){
//         printf("Roll No : %d \n",S[i].roll);
//         printf("Name : %s \n",S[i].name);
//         printf("Department : %s \n",S[i].dep);
//     }
// }

void main(){
    int i;
    struct students *stud=(struct students *)malloc(3*sizeof(struct students)); 
    for(i=0;i<3;i++){
        stud[i].roll=i+1;
        sprintf(stud[i].name, "stud number %d", i + 1);
        sprintf(stud[i].department, "Department number %d", i + 1);
    }
    for (int i = 0; i < 3;i++)
    {
        printf("Student Name : %s\n",stud[i].name);
        printf("Student Roll : %d\n",stud[i].roll);
        printf("Student Department : %s\n\n",stud[i].department);
    }
    struct students *temp=(struct students *)realloc(stud,4*sizeof(struct students));
    temp[i].roll=i+1;
    sprintf(temp[i].name, "student number %d", i + 1);
    sprintf(temp[i].department, "Department number %d", i + 1);
    for(i=0;i<4;i++){
        printf("Student Name : %s\n",temp[i].name);
        printf("Student Roll : %d\n",temp[i].roll);
        printf("Student Department : %s\n\n",temp[i].department);
    }
}