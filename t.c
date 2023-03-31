#include <stdio.h>

// Function to calculate a gradient between two RGB colors
void generateGradient(int startColor[], int endColor[], int steps) {
    // Calculate the difference between the start and end colors
    int diff[3];
    for (int i = 0; i < 3; i++) {
        diff[i] = endColor[i] - startColor[i];
    }
    
    // Generate the gradient by interpolating between the start and end colors
    for (int i = 0; i < steps; i++) {
        // Calculate the RGB components for the current step
        int currentColor[3];
        for (int j = 0; j < 3; j++) {
            currentColor[j] = startColor[j] + (diff[j] * i / steps);
        }
        
        // Print the RGB color code for the current step
        printf("RGB(%d, %d, %d)\n", currentColor[0], currentColor[1], currentColor[2]);
    }
}

// Example usage
int main() {
    // Define the start and end colors
    int startColor[] = {255, 0, 0};  // Red
    int endColor[] = {0, 0, 255};    // Blue
    
    // Generate the gradient between the start and end colors in 1000 steps
    generateGradient(startColor, endColor, 1000);
    
    return 0;
}