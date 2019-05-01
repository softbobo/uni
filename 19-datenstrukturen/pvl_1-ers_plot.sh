#!/usr/bin/gnuplot
# softbobo 30 Apr 2019
# simple plotting script for the first lab assignment for data structures

# set the correct output - at the beginning - super important
set term pdf size 21.0cm, 29.7cm
set output "pvl_1-ers.pdf"

# set the layout of the plot
set multiplot layout 2,1 rowsfirst                       # enter multiplot mode
set grid
set logscale xy                     # set both scales logarithmic

# --- plot a for the number of primes 'p' in interval [2,n]
set title "Sieb des Erastosthenes - P in Abhängigkeit von N"
set xlabel "N (obere Grenze im Intervall [2, N])"
set ylabel "P (Anzahl der Primzahlen im Intervall [2,N])"
plot "<(sed -n '2,20p' ers.txt)" using 1:2 with lines notitle # first plot for number of primes

# --- plot b for the number of strikestroughs 's' needed to calculate 'p' 
set title "Sieb des Erastosthenes - S in Abhängigkeit von N"
set xlabel "N (obere Grenze im Intervall [2, N])"
set ylabel "S (Anzahl der Streichungen im Sieb)"
plot "<(sed -n '2,20p' ers.txt)" using 1:3 with lines notitle # second plot number of strokes

# specify the input
unset multiplot                     # exit multiplot mode in order to display the output

