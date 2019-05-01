#!/usr/bin/gnuplot
# softbobo 30 Apr 2019
# simple plotting script for the first lab assignment for data structures

# set the correct output 
set term pdf
set output "pvl_1-ers.pdf"

# set the layout of the plot
set multiplot                       # enter multiplot mode
set title "Sieb des Erastosthenes - P und S in Abhängigkeit von Eingangsgröße N"
set grid
set logscale xy                     # set both scales logarithmic
set xlabel "N (obere Grenze im Intervall [2, N]"
set ylabel ""

# specify the input
plot "<(sed -n '2,20p' ers.txt)" using 1:2 with lines # first plot for number of primes
plot "<(sed -n '2,20p' ers.txt)" using 1:3 with lines # second plot number of strokes
unset multiplot                     # exit multiplot mode in order to display the output

