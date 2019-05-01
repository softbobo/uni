# softbobo 30 Apr 2019
# simple plotting script for the first lab assignment for data structures

#!/usr/bin/gnuplot

# set the layout of the plot
set multiplot                       # enter multiplot mode
set title "Sieb des Erastosthenes - P und S in Abhängigkeit von Eingangsgröße N"
set grid
set xlabel "N (obere Grenze im Intervall [2, N]"
set ylabel ""
set logscale xy                     # set both scales logarithmic

unset multiplot                     # exit multiplot mode in order to display the output

# specify the input


# set the correct output
# set term pdfcairo
# set output "pvl_1-ers.pdf"