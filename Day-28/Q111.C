#include <stdio.h>

#define TOTAL_SEATS 10

int main() {
    int seats[TOTAL_SEATS] = {0}; // 0 = Available, 1 = Booked
    int choice, seatNo, i;

    do {
        printf("\n===== TICKET BOOKING SYSTEM =====\n");
        printf("1. View Available Seats\n");
        printf("2. Book Ticket\n");
        printf("3. Cancel Ticket\n");
        printf("4. Display Booking Status\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {

        case 1:
            printf("\nAvailable Seats:\n");
            for(i = 0; i < TOTAL_SEATS; i++) {
                if(seats[i] == 0)
                    printf("Seat %d : Available\n", i + 1);
            }
            break;

        case 2:
            printf("Enter Seat Number (1-%d): ", TOTAL_SEATS);
            scanf("%d", &seatNo);

            if(seatNo >= 1 && seatNo <= TOTAL_SEATS) {
                if(seats[seatNo - 1] == 0) {
                    seats[seatNo - 1] = 1;
                    printf("Ticket Booked Successfully!\n");
                } else {
                    printf("Seat Already Booked!\n");
                }
            } else {
                printf("Invalid Seat Number!\n");
            }
            break;

        case 3:
            printf("Enter Seat Number to Cancel: ");
            scanf("%d", &seatNo);

            if(seatNo >= 1 && seatNo <= TOTAL_SEATS) {
                if(seats[seatNo - 1] == 1) {
                    seats[seatNo - 1] = 0;
                    printf("Ticket Cancelled Successfully!\n");
                } else {
                    printf("Seat is Already Available!\n");
                }
            } else {
                printf("Invalid Seat Number!\n");
            }
            break;

        case 4:
            printf("\nBooking Status:\n");
            for(i = 0; i < TOTAL_SEATS; i++) {
                printf("Seat %d : %s\n", i + 1,
                       seats[i] ? "Booked" : "Available");
            }
            break;

        case 5:
            printf("Thank You for Using the Ticket Booking System!\n");
            break;

        default:
            printf("Invalid Choice!\n");
        }

    } while(choice != 5);

    return 0;
}