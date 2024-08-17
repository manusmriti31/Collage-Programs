subjects <- c("A","B","C","D","E","F")
marks <- c(91,73,65,45,54,32)
avg <- mean(marks)

par(mfrow = c(1,2))

barplot(marks, names.arg = subjects, col = 'skyblue', main = "Bar plot of marks",
        xlab = 'Subjects', ylab = 'marks')

pie(marks,labels = subjects, col = rainbow(length(marks)), main = "Pie chart of performace")

par(mfrow = c(1,1))

cat("The average marks of student: ", avg, "\n")
cat("Qualitative analysis:\n")
for(i in 1:length(marks)){
  cat(subjects[i],":",ifelse(marks[i] >= avg, "Good\n", "Needs Improvement\n"))
}

