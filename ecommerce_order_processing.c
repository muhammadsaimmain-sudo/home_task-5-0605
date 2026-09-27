#include <stdio.h>

int main() {
    int product, customer, orderNumber;
    float orderAmount, distance;
    float discountRate, discountAmount, finalAmount;
    float deliveryCharge, priorityCharge, totalAmount;
    int freeShipping, priority;

    printf("Enter product category:\n");
    printf("1: Electronics\n2: Clothing\n3: Books\n4: Household\n");
    scanf("%d", &product);

    printf("Enter customer category:\n");
    printf("1: Regular\n2: Premium\n3: Corporate\n");
    scanf("%d", &customer);

    printf("Enter order amount: ");
    scanf("%f", &orderAmount);

    printf("Enter delivery distance: ");
    scanf("%f", &distance);

    printf("Enter order number: ");
    scanf("%d", &orderNumber);

    switch (product) {
        case 1:
            switch (customer) {
                case 1: discountRate = 5; break;
                case 2: discountRate = 10; break;
                case 3: discountRate = 15; break;
                default: printf("Invalid customer category\n"); return 0;
            }
            break;
        case 2:
            switch (customer) {
                case 1: discountRate = 10; break;
                case 2: discountRate = 15; break;
                case 3: discountRate = 20; break;
                default: printf("Invalid customer category\n"); return 0;
            }
            break;
        case 3:
            switch (customer) {
                case 1: discountRate = 8; break;
                case 2: discountRate = 12; break;
                case 3: discountRate = 18; break;
                default: printf("Invalid customer category\n"); return 0;
            }
            break;
        case 4:
            switch (customer) {
                case 1: discountRate = 7; break;
                case 2: discountRate = 14; break;
                case 3: discountRate = 20; break;
                default: printf("Invalid customer category\n"); return 0;
            }
            break;
        default:
            printf("Invalid product category\n");
            return 0;
    }

    discountAmount = orderAmount * discountRate / 100;
    finalAmount = orderAmount - discountAmount;

    if (finalAmount >= 5000 || customer == 2 || customer == 3) {
        freeShipping = 1;
        deliveryCharge = 0;
    } else {
        freeShipping = 0;
        if (distance <= 10)
            deliveryCharge = 200;
        else if (distance <= 20)
            deliveryCharge = 400;
        else
            deliveryCharge = 600;
    }

    priority = (customer == 2 || customer == 3) && orderAmount >= 10000;
    priorityCharge = priority ? 500 : 0;

    totalAmount = finalAmount + deliveryCharge + priorityCharge;

    printf("\n========== FINAL ORDER REPORT ==========\n");

    printf("Product Category: ");
    switch (product) {
        case 1: printf("Electronics\n"); break;
        case 2: printf("Clothing\n"); break;
        case 3: printf("Books\n"); break;
        case 4: printf("Household\n"); break;
    }

    printf("Customer Category: ");
    switch (customer) {
        case 1: printf("Regular\n"); break;
        case 2: printf("Premium\n"); break;
        case 3: printf("Corporate\n"); break;
    }

    printf("Original Order Amount: Rs. %.2f\n", orderAmount);
    printf("Discount Percentage: %.0f%%\n", discountRate);
    printf("Discount Amount: Rs. %.2f\n", discountAmount);
    printf("Final Payable Amount: Rs. %.2f\n", finalAmount);
    printf("Delivery Distance: %.2f km\n", distance);
    printf("Shipping Status: %s\n", freeShipping ? "FREE SHIPPING" : "CHARGED");
    printf("Delivery Charges: Rs. %.2f\n", deliveryCharge);
    printf("Priority Delivery: %s\n", priority ? "YES" : "NO");
    printf("Priority Charges: Rs. %.2f\n", priorityCharge);

    printf("Processing Group: ");
    if (orderNumber % 4 == 0)
        printf("A\n");
    else if (orderNumber % 4 == 1)
        printf("B\n");
    else if (orderNumber % 4 == 2)
        printf("C\n");
    else
        printf("D\n");

    printf("Total Amount Payable: Rs. %.2f\n", totalAmount);

    return 0;
}
