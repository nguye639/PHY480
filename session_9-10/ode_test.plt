

set xrange[-1:101]



plot "ode_test_x0_-1.5_v0_2.dat" using 1:2,\
 "ode_test_x0_0.1_v0_0.dat" using 1:2,\
"ode_test_x0_1_v0_0.dat" using 1:2
