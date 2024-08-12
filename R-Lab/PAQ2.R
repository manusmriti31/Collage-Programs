queue <- c("Steve","Russell","Alison","Liam")
queue <- c(queue,"Barry")
queue <- queue[queue != "Steve"]
queue <- c("Pam",queue)
queue <- queue[queue != "Barry"]
queue <- queue[queue != "Alison"]
which(queue == "Russell")
print(queue)