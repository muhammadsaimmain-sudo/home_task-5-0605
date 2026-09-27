#include <stdio.h>

int main() {
    int device, mode, operation;

    int door = 1 << 0;
    int alarm = 1 << 1;
    int cctv = 1 << 2;
    int motion = 1 << 3;

    int status = 0;

    printf("Please enter your operation:\n");
    printf("1: Activate\n");
    printf("2: Deactivate\n");
    printf("3: Check Status\n");
    printf("4: Toggle\n");
    printf("5: Security Mode\n");

    scanf("%d", &operation);

    switch (operation) {
        case 1:
            printf("Enter your device:\n");
            printf("1: Door\n2: Alarm\n3: CCTV\n4: Motion\n");
            scanf("%d", &device);

            switch (device) {
                case 1: status = status | door; printf("The door is active\n"); break;
                case 2: status = status | alarm; printf("The alarm is active\n"); break;
                case 3: status = status | cctv; printf("The CCTV is active\n"); break;
                case 4: status = status | motion; printf("The motion sensor is active\n"); break;
                default: printf("Invalid device\n");
            }
            break;

        case 2:
            printf("Enter your device to deactivate:\n");
            printf("1: Door\n2: Alarm\n3: CCTV\n4: Motion\n");
            scanf("%d", &device);

            switch (device) {
                case 1: status = status & ~door; printf("The door is deactivated\n"); break;
                case 2: status = status & ~alarm; printf("The alarm is deactivated\n"); break;
                case 3: status = status & ~cctv; printf("The CCTV is deactivated\n"); break;
                case 4: status = status & ~motion; printf("The motion sensor is deactivated\n"); break;
                default: printf("Invalid device\n");
            }
            break;

        case 3:
            printf("Enter your device to check status:\n");
            printf("1: Door\n2: Alarm\n3: CCTV\n4: Motion\n");
            scanf("%d", &device);

            switch (device) {
                case 1: printf("Main Door Lock: %s\n", (status & door) ? "ACTIVE" : "INACTIVE"); break;
                case 2: printf("Alarm: %s\n", (status & alarm) ? "ACTIVE" : "INACTIVE"); break;
                case 3: printf("CCTV: %s\n", (status & cctv) ? "ACTIVE" : "INACTIVE"); break;
                case 4: printf("Motion Sensor: %s\n", (status & motion) ? "ACTIVE" : "INACTIVE"); break;
                default: printf("Invalid device\n");
            }
            break;

        case 4:
            printf("Enter your device to toggle:\n");
            printf("1: Door\n2: Alarm\n3: CCTV\n4: Motion\n");
            scanf("%d", &device);

            switch (device) {
                case 1: status = status ^ door; printf("The door is toggled\n"); break;
                case 2: status = status ^ alarm; printf("The alarm is toggled\n"); break;
                case 3: status = status ^ cctv; printf("The CCTV is toggled\n"); break;
                case 4: status = status ^ motion; printf("The motion sensor is toggled\n"); break;
                default: printf("Invalid device\n");
            }
            break;

        case 5:
            printf("Enter your security mode:\n");
            printf("1: Home Mode\n2: Away Mode\n3: Night Mode\n");
            scanf("%d", &mode);

            switch (mode) {
                case 1:
                    status = status | door | cctv;
                    printf("Home mode activated\n");
                    break;
                case 2:
                    status = status | door | alarm | cctv | motion;
                    printf("Away mode activated\n");
                    break;
                case 3:
                    status = status | door | alarm | motion;
                    printf("Night mode activated\n");
                    break;
                default:
                    printf("Invalid security mode\n");
            }
            break;

        default:
            printf("Invalid operation\n");
    }

    printf("\nDevice Status:\n");
    printf("Door (1): %s\n", (status & door) ? "ACTIVE" : "INACTIVE");
    printf("Alarm (2): %s\n", (status & alarm) ? "ACTIVE" : "INACTIVE");
    printf("CCTV (4): %s\n", (status & cctv) ? "ACTIVE" : "INACTIVE");
    printf("Motion Sensor (8): %s\n", (status & motion) ? "ACTIVE" : "INACTIVE");

    printf("\nBinary Status: ");
    printf("%d", (status & motion) ? 1 : 0);
    printf("%d", (status & cctv) ? 1 : 0);
    printf("%d", (status & alarm) ? 1 : 0);
    printf("%d\n", (status & door) ? 1 : 0);

    if ((status & door) && (status & alarm) &&
        (status & cctv) && (status & motion))
        printf("Security System: FULLY ARMED\n");
    else
        printf("Security System: NOT FULLY ARMED\n");

    return 0;
}
