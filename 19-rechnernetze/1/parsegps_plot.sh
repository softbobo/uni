#!/usr/bin/env gnuplot

set grid
set nologscale x
set nologscale y
set xlabel "Strecke in km"
set ylabel "Hoehe in m"
set terminal png
set output "track.png"
plot "output.plt" using 3:7 notitle with lines linetype 3
