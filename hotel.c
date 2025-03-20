#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int roomNumber;
    char customerName[50];
    int age;
    int mobile_number;
    char address[100];
    int check;
} Room;

Room hotel[50];

void initializeRooms() {
    for (int i = 0; i < 50; i++) {
        hotel[i].roomNumber = i + 1;
        hotel[i].check = 0; 
    }
}

void bookRoom() {
    int roomNum;
    printf("Enter room number to book (1-50): ");
    if (scanf("%d", &roomNum) != 1) {
        printf("Invalid input!\n");
    }

    if (roomNum<1 || roomNum>50 || hotel[roomNum-1].check) 
    {
        printf("Room is not available or invalid room number!\n");
        return;
    }
    printf("Enter customer name: ");
    scanf(" %[^\n]", hotel[roomNum-1].customerName);
    printf("Age: ");
    scanf("%d",&hotel[roomNum-1].age);
    printf("Mobile Number: ");
    scanf("%d",&hotel[roomNum-1].mobile_number);
    printf("Address: ");
    scanf(" %[^\n]",hotel[roomNum-1].address);
    hotel[roomNum-1].check = 1;
    printf("Room no. %d booked successfully!!\n", roomNum);
}

void checkAvailableRooms() {
    int count= 0;
    printf("Available rooms: ");

    for (int i = 0; i < 50; i++) {
        if (hotel[i].check!=1) 
        {
            printf("%d ", hotel[i].roomNumber);
            count=1;
        }
    }

    if (count==0) 
    {
        printf("No Room is Available!!");
    }
    printf("\n");
}

void checkoutRoom() {
    int roomNum;
    printf("Enter room number to checkout: ");
    scanf("%d", &roomNum);

    if (roomNum < 1 || roomNum > 50 || hotel[roomNum-1].check==0) {
        printf("Invalid room number or room is not Booked yet!!\n");
        return;
    }

    hotel[roomNum-1].check = 0;
    printf("%s\n",hotel[roomNum-1].customerName);
    printf("Room no. %d checked out successfully!\n", roomNum);
}

void displayRooms() {
    printf("\nRoom Status:\n");
    for (int i = 0; i < 50; i++) 
    {
        printf("Room: %d ", hotel[i].roomNumber);
        if(hotel[i].check == 0)
        {
            printf("Status: Available.\n");
        }
        else
        {
            printf("Status: Not Available! (Booked by '%s')\n",hotel[i].customerName);
        }
    }
}

void RoomDetails() {
    int roomNum;
    printf("Enter room number to view details (1-50): ");
    scanf("%d", &roomNum);
    if(roomNum!= 1 || roomNum < 1 || roomNum > 50) 
    {
        printf("Invalid input! Please enter a valid room number.\n");
    }

    printf("\nRoom Details for Room no.%.2d :\n", hotel->roomNumber);
    if (hotel->check == 0) 
    {
        printf("EMPTY!!\n");
    } 
    else 
    {
        printf("Status: Booked\n");
        printf("Customer Name: %s\n", hotel->customerName);
        printf("Age: %d\n", hotel->age);
        printf("Mobile Number: %d\n", hotel->mobile_number);
        printf("Address: %s\n", hotel->address);
    }
}

int main()
{
    initializeRooms();
    int choice;
        do{
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
            case 1: bookRoom(hotel); 
                    break;
            case 2: checkAvailableRooms(hotel); 
                    break;
            case 3: checkoutRoom(); 
                    break;
            case 4: displayRooms(); 
                    break;
            case 5: RoomDetails();
                    break;
            case 6: printf("Exiting...\n"); 
                    break;
            default: printf("Invalid choice!\n");
        }
        }
        while (choice != 6);
    
    return 0;
}