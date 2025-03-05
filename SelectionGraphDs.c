#include <stdio.h>

int main() {
    FILE *gnuplotPipe = popen("gnuplot -persistent", "w");
    if (gnuplotPipe) {
        fprintf(gnuplotPipe, "set title 'Number of Elements vs Time Taken'\n");
        fprintf(gnuplotPipe, "set xlabel 'Number of Elements (n)'\n");
        fprintf(gnuplotPipe, "set ylabel 'Time Taken (seconds)'\n");
        fprintf(gnuplotPipe, "plot '-' with linespoints title 'Time Complexity'\n");
        fprintf(gnuplotPipe, "5000 0.0190\n");
        fprintf(gnuplotPipe, "10000 0.0820\n");
        fprintf(gnuplotPipe, "15000 0.1880\n");
        fprintf(gnuplotPipe, "20000 0.3320\n");
        fprintf(gnuplotPipe, "25000 0.5280\n");
        fprintf(gnuplotPipe, "e\n");
        pclose(gnuplotPipe);
    } else {
        printf("Error opening pipe to gnuplot.\n");
    }
    return 0;
}
