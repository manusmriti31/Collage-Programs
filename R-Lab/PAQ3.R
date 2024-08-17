x <- seq(5,10, by = 0.1)

m <- 3
c <- 4

eqn <- m*x + c
eqn1 <- x^2
eqn2 <- x^3
eqn3 <- sqrt(abs(x))

plot(x,eqn,col = 'blue', type = 'l', lty = 2,
     main = 'Graph between lianear and non-linear equations',
     xlab = 'x', ylab = 'y',
     ylim = c(0,1000))

lines(x,eqn1,col = 'red')
lines(x,eqn2,col = 'green')
lines(x,eqn3,col = 'purple')

legend('topright', legend = c('Linear (y = 3x + 4)','Non-Linear (x^2)','Non-Linear (x^3)','Non-linear (sqrt|x|)'),
       col = c('blue','red','green','purple'),
       lty = c(2,1,1,1),
       cex = 0.8)