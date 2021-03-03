
set title 'Maxtix size vs time'
set xlabel 'Dimenson'
set ylabel 'Time'

set logscale
f(x) = a*x+b
fit [300:400] f(x) "eigen.dat" using ($1):($2) via a,b
fit_title = sprintf("%-+4.1f*x %-+4.1f",a,b)

plot "eigen.dat" using ($1):($2) title 'dim vs time', a*x+b title fit_title

set out "eigen.ps"
set term postscript color enhanced
replot




