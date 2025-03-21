#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int roomnumber;
    char customer_name[50];
    int age;
    int mobile_number;
    char address[100];
    int check;
} room;

room hotel[50];

void set_rooms() 
{
    for (int i=0;i<50;i++) 
    {
        hotel[i].roomnumber= i+1;
        hotel[i].check= 0; 
    }
}

void book_room() 
{
    int roomnum;
    printf("Enter room number to book (1-50): ");
    if (scanf("%d", &roomnum) != 1) {
        printf("Invalid input!\n");
    }
    if (roomnum<1 || roomnum>50 || hotel[roomnum-1].check) 
    {
        printf("Room is not available or invalid room number!\n");
        return;
    }
    printf("Enter customer name: ");
    scanf(" %[^\n]", hotel[roomnum-1].customer_name);
    printf("Age: ");
    scanf("%d",&hotel[roomnum-1].age);
    printf("Mobile Number: ");
    scanf("%d",&hotel[roomnum-1].mobile_number);
    printf("Address: ");
    scanf(" %[^\n]",hotel[roomnum-1].address);
    hotel[roomnum-1].check = 1;
    printf("Room no. %d booked successfully!!\n", roomnum);
}

void check_available_rooms() 
{
    int count= 0;
    printf("Available rooms: ");
    for (int i = 0; i < 50; i++) 
    {
        if (hotel[i].check!=1) 
        {
            printf("%d ",hotel[i].roomnumber);
            count= 1;
        }
    }
    if (count==0) 
    {
        printf("No Room is Available!");
    }
    printf("\n");
}

void checkout_room()
{
    int roomnum;
    printf("Enter room number to checkout: ");
    scanf("%d", &roomnum);
    if (roomnum < 1 || roomnum > 50 || hotel[roomnum-1].check==0) 
    {
        printf("Invalid room number or room is not Booked yet!!\n");
        return;
    }
    hotel[roomnum-1].check = 0;
    printf("%s\n",hotel[roomnum-1].customer_name);
    printf("Room no. %d checked out successfully!\n", roomnum);
}

void display_rooms()
{
    printf("\nRoom Status:\n");
    for (int i = 0; i < 50; i++) 
    {
        printf("Room: %d ", hotel[i].roomnumber);
        if(hotel[i].check == 0)
        {
            printf("Status: Available.\n");
        }
        else
        {
            printf("Status: Not Available! (Booked by '%s')\n",hotel[i].customer_name);
        }
    }
}

void room_details()
{
    int roomnum;
    printf("Enter room number to view details (1-50): ");
    scanf("%d", &roomnum);
    if(roomnum!= 1 || roomnum < 1 || roomnum > 50) 
    {
        printf("Invalid input! Please enter a valid room number.\n");
    }

    printf("\nRoom Details for Room no.%.2d:\n",hotel->roomnumber);
    if (hotel->check == 0) 
    {
        printf("Status: EMPTY!!\n");
    } 
    else 
    {
        printf("Status: Booked\n");
        printf("Customer Name: %s\n",hotel->customer_name);
        printf("Age: %d\n",hotel->age);
        printf("Mobile Number: %d\n",hotel->mobile_number);
        printf("Address: %s\n",hotel->address);
    }
}

int main()
{
    set_rooms();
    int choice;
    do
    {
        printf("\nHotel Management System\n");
        printf("1. Book Room\n");
        printf("2. Check Available Rooms\n");
        printf("3. Checkout Room\n");
        printf("4. Display Room Status\n");
        printf("5. Room Details\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch (choice) 
        {
            case 1: book_room(hotel); 
                    break;
            case 2: check_available_rooms(hotel);
                    break;
            case 3: checkout_room(); 
                    break;
            case 4: display_rooms(); 
                    break;
            case 5: room_details();
                    break;
            case 6: printf("Exiting...\n"); 
                    break;
            default:printf("Invalid choice!\n");
        }
    }
        while (choice != 6);
    return 0;
}
