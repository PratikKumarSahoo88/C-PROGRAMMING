#include <stdio.h>

int main() {
    FILE *gnuplotPipe = popen("gnuplot -persistent", "w");
    if (gnuplotPipe) {
        fprintf(gnuplotPipe, "set title 'Number of Elements vs Time Taken'\n");
        fprintf(gnuplotPipe, "set xlabel 'Number of Elements (n)'\n");
        fprintf(gnuplotPipe, "set ylabel 'Time Taken (seconds)'\n");
        fprintf(gnuplotPipe, "plot '-' with linespoints title 'Time Complexity'\n");
        fprintf(gnuplotPipe, "5000 0.000000\n");
        fprintf(gnuplotPipe, "10000 0.000000\n");
        fprintf(gnuplotPipe, "15000 0.004000\n");
        fprintf(gnuplotPipe, "20000 0.003000\n");
        fprintf(gnuplotPipe, "25000 0.000000\n");
        fprintf(gnuplotPipe, "30000 0.000000\n");
        fprintf(gnuplotPipe, "35000 0.003000\n");
        fprintf(gnuplotPipe, "40000 0.010000\n");
        fprintf(gnuplotPipe, "45000 0.0030000\n");
        fprintf(gnuplotPipe, "50000 0.0040000\n");
        fprintf(gnuplotPipe, "e\n");
        pclose(gnuplotPipe);
    } else {
        printf("Error opening pipe to gnuplot.\n");
    }
    return 0;
}
