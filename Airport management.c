#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FLIGHTS 100
#define MAX_PASSENGERS 100

typedef struct {
    int flightNumber;
    char destination[50];
    char departureTime[20];
} Flight;

typedef struct {
    int passengerID;
    char name[50];
    int flightNumber;
} Passenger;

Flight flights[MAX_FLIGHTS];
Passenger passengers[MAX_PASSENGERS];
int flightCount = 0;
int passengerCount = 0;

void addFlight() {
    if (flightCount >= MAX_FLIGHTS) {
        printf("Flight limit reached!\n");
        return;
    }
    Flight flight;
    printf("Enter Flight Number: ");
    scanf("%d", &flight.flightNumber);
    printf("Enter Destination: ");
    scanf("%s", flight.destination);
    printf("Enter Departure Time: ");
    scanf("%s", flight.departureTime);
    
    flights[flightCount++] = flight;
    printf("Flight added successfully!\n");
}

void displayFlights() {
    if (flightCount == 0) {
        printf("No flights available.\n");
        return;
    }
    printf("Flight Number\tDestination\tDeparture Time\n");
    for (int i = 0; i < flightCount; i++) {
        printf("%d\t\t%s\t\t%s\n", flights[i].flightNumber, flights[i].destination, flights[i].departureTime);
    }
}

void addPassenger() {
    if (passengerCount >= MAX_PASSENGERS) {
        printf("Passenger limit reached!\n");
        return;
    }
    Passenger passenger;
    printf("Enter Passenger ID: ");
    scanf("%d", &passenger.passengerID);
    printf("Enter Passenger Name: ");
    scanf("%s", passenger.name);
    printf("Enter Flight Number: ");
    scanf("%d", &passenger.flightNumber);
    
    passengers[passengerCount++] = passenger;
    printf("Passenger added successfully!\n");
}

void displayPassengers() {
    if (passengerCount == 0) {
        printf("No passengers available.\n");
        return;
    }
    printf("Passenger ID\tName\t\tFlight Number\n");
    for (int i = 0; i < passengerCount; i++) {
        printf("%d\t\t%s\t\t%d\n", passengers[i].passengerID, passengers[i].name, passengers[i].flightNumber);
    }
}

int main() {
    int choice;
    do {
        printf("\nAirport Management System\n");
        printf("1. Add Flight\n");
        printf("2. Display Flights\n");
        printf("3. Add Passenger\n");
        printf("4. Display Passengers\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addFlight();
                break;
            case 2:
                displayFlights();
                break;
            case 3:
                addPassenger();
                break;
            case 4:
                displayPassengers();
                break;
            case 5:
                printf("Exiting the system.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);
    
    return 0;
}