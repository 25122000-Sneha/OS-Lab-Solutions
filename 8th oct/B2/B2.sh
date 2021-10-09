echo "Enter file name: "
read file
echo "Enter starting line number: "
read start
echo "Enter no. of lines to be displayed: "
read number
#remainder=$(expr $start + $number)
remainder=$(expr $start + $number - 1)
head -$remainder $file | tail +$start 

