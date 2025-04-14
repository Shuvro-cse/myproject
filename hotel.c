#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int roomnumber;
    char customer_name[50];
    char nationality[50];
    char NID[50];
    char mobile_number[15];
    int stay;
    char from_date[15];
    char address[100];
    char room_type[20];
    int check;
} room;

room hotel[50];

void set_rooms() 
{
    for (int i=0;i<50;i++) 
    {
        hotel[i].roomnumber= i+1;
        hotel[i].check= 0; 
        if (i < 10)
            strcpy(hotel[i].room_type, "VIP Suite");
        else if (i < 30)
            strcpy(hotel[i].room_type, "Single Room");
        else
            strcpy(hotel[i].room_type, "Double Room");
    }
}

void check_available_rooms() 
{
    int vip_count = 0, single_count = 0, double_count = 0;

    printf("\nAvailable Rooms:\n");

    printf("VIP Suites (1-10): ");
    for (int i = 0; i < 10; i++) 
    {
        if (hotel[i].check != 1) 
        {
            printf("%d ", hotel[i].roomnumber);
            vip_count++;
        }
    }
    if (vip_count == 0)
    {
        printf("None");
        printf("\n");
    }

    printf("Single Rooms (11-30): ");
    for (int i = 10; i < 30; i++) 
    {
        if (hotel[i].check != 1) 
        {
            printf("%d ", hotel[i].roomnumber);
            single_count++;
        }
    }
    if (single_count == 0) 
    {
        printf("None");
        printf("\n");
    }

    printf("Double Rooms (31-50): ");
    for (int i = 30; i < 50; i++) 
    {
        if (hotel[i].check != 1) 
        {
            printf("%d ", hotel[i].roomnumber);
            double_count++;
        }
    }
    if (double_count == 0) printf("None");
    printf("\n");
}


void book_room() 
{
    int roomnum;
    printf("Enter room number to book (1-50): ");
    scanf("%d",&roomnum);
    if (hotel[roomnum - 1].check == 1) 
    {
        printf("Room no. %d is already BOOKED!\n", roomnum);
        check_available_rooms();
        return;
    }

    else if (roomnum<1 || roomnum>50) 
    {
        printf("Room is not available or invalid room number!\n");
        check_available_rooms();
        return;
    }
    printf("Enter customer name: ");
    scanf(" %[^\n]", hotel[roomnum-1].customer_name);
    printf("Nationality: ");
    scanf("%s",hotel[roomnum-1].nationality);
    printf("ID/Passport No.: ");
    scanf("%s",hotel[roomnum-1].NID);
    printf("Mobile Number: ");
    scanf("%s",hotel[roomnum-1].mobile_number);
    printf("Permanet Address: ");
    scanf(" %[^\n]",hotel[roomnum-1].address);
    printf("How many day(s) you want to stay: ");
    scanf("%d",&hotel[roomnum-1].stay);
    printf("Booking Date (dd/mm/yy): ");
    scanf("%s",hotel[roomnum-1].from_date);
    hotel[roomnum-1].check = 1;
    printf("Room no. %d booked successfully!!\n", roomnum);
}

void checkout_room()
{
    int roomnum;
    printf("Enter room number to checkout: ");
    scanf("%d", &roomnum);
    if (roomnum<1 || roomnum>50 || hotel[roomnum-1].check==0) 
    {
        printf("Invalid room number or room is not Booked yet!!\n");
        return;
    }
    hotel[roomnum-1].check = 0;
    printf("%s\n",hotel[roomnum-1].customer_name);
    printf("Room no. %d checked out successfully!\n",roomnum);
}

void display_rooms()
{
    printf("\nRoom Status:\n");
    for (int i=0; i<50; i++) 
    {
        printf("Room: %d (%s) ", hotel[i].roomnumber, hotel[i].room_type);
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

    if(roomnum<1 || roomnum>50)
    {
        printf("Invalid input! Please enter a valid room number.\n");
        return;
    }

    room *details = &hotel[roomnum-1];

    printf("\nRoom Details for Room no.%.2d:\n",details->roomnumber);
    if (details->check == 0) 
    {
        printf("Status: EMPTY!!\n");
    }
    else 
    {
        printf("Status: Booked\n");
        printf("Room Type: %s\n", details->room_type);
        printf("Customer Name: %s\n",details->customer_name);
        printf("Nationality: %s\n",details->nationality);
        printf("NID/Passport No.: %s\n",details->NID);
        printf("Mobile Number: %s\n",details->mobile_number);
        printf("Address: %s\n",details->address);
        printf("Booked on %s for %d day(s)\n",details->from_date,details->stay);
    }
}

void update_stay_duration()
{
    int roomnum;
    printf("Enter room number to update stay duration (1-50): ");
    scanf("%d", &roomnum);

    if (roomnum < 1 || roomnum > 50)
    {
        printf("Invalid room number!\n");
        return;
    }

    room *r = &hotel[roomnum - 1];

    if (r->check == 0)
    {
        printf("Room no. %d is not booked yet!\n", roomnum);
        return;
    }

    printf("Current stay duration for room %d: %d day(s)\n", roomnum, r->stay);
    printf("Enter new stay duration: ");
    scanf("%d", &r->stay);

    printf("Stay duration updated successfully for room %d.\n", roomnum);
}

int main()
{
    set_rooms();
    int choice;
    do
    {
        printf("\nWelcome to Hotel Management System(HMS)\n");
        printf("Main menu:\n");
        printf("1. Book Room\n");
        printf("2. Check Available Rooms\n");
        printf("3. Checkout Room\n");
        printf("4. Display Room Status\n");
        printf("5. Room Details\n");
        printf("6. Update Stay Duration\n");
        printf("7. Exit\n");
        printf("\nSelect an option: ");
        scanf("%d",&choice);
        switch (choice) 
        {
            case 1: book_room(); 
                    break;
            case 2: check_available_rooms();
                    break;
            case 3: checkout_room(); 
                    break;
            case 4: display_rooms(); 
                    break;
            case 5: room_details();
                    break;
            case 6: update_stay_duration();
                    break;
            case 7: printf("Exiting...\n"); 
                    break;
            default:printf("Invalid choice!\n");
        }
    }
        while (choice != 7);
    return 0;
}
