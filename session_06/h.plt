# plot file for diffeq_test_exp_back
set timestamp

set xlabel 'h'
set ylabel 'error''
set logscale
set xrange[.00001:.015]


set title 'Comparing Differential Equation Algorithms'

plot \
  "diffeq_test2.dat" using ($1):(abs($2-$4)/($4))  title 'Euler error', \
  "diffeq_test2.dat" using ($1):(abs($3-$4)/($4)) title '4th order Runge-Kutta error'


