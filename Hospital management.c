#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATIENTS 100
#define MAX_DOCTORS 100

typedef struct {
    int patientID;
    char name[50];
    int age;
    char ailment[100];
} Patient;

typedef struct {
    int doctorID;
    char name[50];
    char specialization[50];
} Doctor;

Patient patients[MAX_PATIENTS];
Doctor doctors[MAX_DOCTORS];
int patientCount = 0;
int doctorCount = 0;

void addPatient() {
    if (patientCount >= MAX_PATIENTS) {
        printf("Patient limit reached!\n");
        return;
    }
    Patient patient;
    printf("Enter Patient ID: ");
    scanf("%d", &patient.patientID);
    printf("Enter Patient Name: ");
    scanf("%s", patient.name);
    printf("Enter Patient Age: ");
    scanf("%d", &patient.age);
    printf("Enter Ailment: ");
    scanf("%s", patient.ailment);
    
    patients[patientCount++] = patient;
    printf("Patient added successfully!\n");
}

void displayPatients() {
    if (patientCount == 0) {
        printf("No patients available.\n");
        return;
    }
    printf("Patient ID\tName\t\tAge\tAilment\n");
    for (int i = 0; i < patientCount; i++) {
        printf("%d\t\t%s\t\t%d\t%s\n", patients[i].patientID, patients[i].name, patients[i].age, patients[i].ailment);
    }
}

void addDoctor() {
    if (doctorCount >= MAX_DOCTORS) {
        printf("Doctor limit reached!\n");
        return;
    }
    Doctor doctor;
    printf("Enter Doctor ID: ");
    scanf("%d", &doctor.doctorID);
    printf("Enter Doctor Name: ");
    scanf("%s", doctor.name);
    printf("Enter Specialization: ");
    scanf("%s", doctor.specialization);
    
    doctors[doctorCount++] = doctor;
    printf("Doctor added successfully!\n");
}

void displayDoctors() {
    if (doctorCount == 0) {
        printf("No doctors available.\n");
        return;
    }
    printf("Doctor ID\tName\t\tSpecialization\n");
    for (int i = 0; i < doctorCount; i++) {
        printf("%d\t\t%s\t\t%s\n", doctors[i].doctorID, doctors[i].name, doctors[i].specialization);
    }
}

int main() {
    int choice;
    do {
        printf("\nHospital Management System\n");
        printf("1. Add Patient\n");
        printf("2. Display Patients\n");
        printf("3. Add Doctor\n");
        printf("4. Display Doctors\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addPatient();
                break;
            case 2:
                displayPatients();
                break;
            case 3:
                addDoctor();
                break;
            case 4:
                displayDoctors();
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