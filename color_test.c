#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 10; // number of steps
    char start_color[] = "#0a3d4a";
    char end_color[] = "#1688a3";
    int r_start, g_start, b_start;
    int r_end, g_end, b_end;
    int r_diff, g_diff, b_diff;
    float r_step, g_step, b_step;
    int i, r, g, b;
    char hex_code[8];
    
    // Convert start color to RGB values
    sscanf(start_color, "#%2x%2x%2x", &r_start, &g_start, &b_start);
    
    // Convert end color to RGB values
    sscanf(end_color, "#%2x%2x%2x", &r_end, &g_end, &b_end);
    
    // Calculate color differences
    r_diff = r_end - r_start;
    g_diff = g_end - g_start;
    b_diff = b_end - b_start;
    
    // Calculate color steps
    r_step = (float) r_diff / n;
    g_step = (float) g_diff / n;
    b_step = (float) b_diff / n;
    
    // Generate gradient
    for (i = 0; i < n; i++) {
        r = (int) (r_start + r_step * i);
        g = (int) (g_start + g_step * i);
        b = (int) (b_start + b_step * i);
        
        // Convert RGB values to hexadecimal color code
        sprintf(hex_code, "#%02x%02x%02x", r, g, b);
        
        // Print color code
        printf("%s\n", hex_code);
    }
    
    return 0;
}