//Patient Records Management System...
//Team_ERROR404

#include<stdio.h>
#include<string.h>

//a structure of patient details
struct patientinfo
{
    char name[100];
    int age;
    char sex[10];
    int contactno;
    char medical_history[100];
};

//All functions
void addpatient(struct patientinfo patient[],int *count);
void readinfo(struct patientinfo patient[], int count);
void search(struct patientinfo patient[],int count);
void update(struct patientinfo patient[],int count);

//main body
int main(){
    struct patientinfo pa[100];
    int count=0;
    int choice;
    do{
    printf("1.Add Patient Information\n2.Display All Patients\n3.Search Patient\n4.Update Patient\n5.Exit\nSelect an option: ");
    scanf("%d", &choice);
    switch(choice){ 
            case 1: 
                    addpatient(pa, &count);
                    break;
            case 2: readinfo(pa, count);
                    break;
            case 3: search(pa, count); 
                    break;
            case 4: update(pa, count);
                    break;
            case 5: printf("Exiting...\n");
                    break;
            default:
                printf("Invalid option.\n");
            }
        } while (choice != 5);
return 0;
}

void addpatient(struct patientinfo patient[],int *count){

    if(*count<100)
    {
        printf("Patient ID: %.3d\n",*count+1);
        printf("Patient's Name: ");
            scanf("%s", patient[*count].name);
        printf("Age: ");
            scanf("%d", &patient[*count].age);
        printf("Gender: ");
            scanf("%s", patient[*count].sex);
        printf("Contact Number: ");
            scanf("%d", &patient[*count].contactno);
        printf("Medical History (Yes/No): ");
            scanf("%s", patient[*count].medical_history);
        (*count)++;
    }
    else if(*count>100){
        printf("Patient record is Full.\n");
        return;}
}

//----------------------------------------------------------------
void readinfo(struct patientinfo patient[], int count){
    for(int i=0; i<count; i++){
    printf("All Patients Details:\n");
    printf("Patient's Name: %s\n",patient[i].name);
    printf("Age: %d\n",patient[i].age);
    printf("Gender: %s\n",patient[i].sex);
    printf("Contuct Num:+88 %d\n",patient[i].contactno);
    printf("Medical History: %s\n",patient[i].medical_history);
    }
}
//----------------------------------------------------------------
void search(struct patientinfo patient[],int count){
    char search_name[100];
    int search_contact;
    int search_type;

    printf("Search By Name,press (1)\nSearch By Contact Number, Press(2)\n Select: ");
    scanf("%d", &search_type);

    if(search_type == 1)
    {
        scanf("%s", search_name);
        for(int i=0; i<count; i++)
        {
            if(strcmp(patient[i].name, search_name) == 0){
            printf("Patient's Name: %s\n",patient[i].name);
            printf("Age: %d\n",patient[i].age);
            printf("Gender: %s\n", patient[i].sex);
            printf("Contuct Num:+88 %d\n",patient[i].contactno);
            printf("Medical History: %s\n", patient[i].medical_history);
            }
        }
    }
    if(search_type == 2)
    {
    scanf("%d",&search_contact);
    for(int i=0; i<100; i++)
    {
        if(patient[i].contactno == search_contact)
        {
            printf("Patient's Name: %s\n",patient[i].name);
            printf("Age: %d\n",patient[i].age);
            printf("Gender: %s\n",patient[i].sex);
            printf("Contuct Num:+88 %d\n",patient[i].contactno);
            printf("Medical History: %s\n",patient[i].medical_history);
        }
    }
    }
}
//--------------------------------------------------------------------

void update(struct patientinfo patient[], int count){
    int serchtoupdateID;
    printf("Enter Patient ID: ");
    scanf("%d",&serchtoupdateID);
    for(int i=0 ; i<count; i++){
        if((i+1)==serchtoupdateID){
        printf("Patient ID: %.3d\n",i+1);
        printf("Update Patient's Name: ");
        scanf("%s", patient[i].name);
        printf("Update Age: ");
        scanf("%d",&patient[i].age);
        printf("Update Gender: ");
        scanf("%s", patient[i].sex);
        printf("Update Contuct Number: ");
        scanf("%d",&patient[i].contactno);
        printf("Update Medical History (Yes/No): ");
        scanf("%s", patient[i].medical_history);
        }
    }
}