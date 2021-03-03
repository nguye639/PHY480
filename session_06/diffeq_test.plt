# plot file for diffeq_test_exp_back
set timestamp

set xlabel 't'
set ylabel 'y(t)'
set logscale

set title 'Comparing Differential Equation Algorithms'
set xrange[.5:3]

plot \
  "diffeq_test.dat" using ($1):(abs($2-$4)/($4))  title 'Euler error, h = .1', \
  "diffeq_test.dat" using ($1):(abs($3-$4)/($4)) title '4th order Runge-Kutta error, h =.1', \
  "diffeq_test2.dat" using ($1):(abs($2-$4)/($4))  title 'Euler error, h = .01', \
  "diffeq_test2.dat" using ($1):(abs($3-$4)/($4)) title '4th order Runge-Kutta error, h = .01'

