echo "Enter no. of elements: "
read n
# taking input from user
echo "Enter  Numbers in array:"
i=0
while [ $i -lt $n ]
do
        read a[$i]
        let i=i+1
done
#printing the number before sorting
echo "  Numbers in an array are:"
for (( i = 0; i < $n; i++ ))
do
        echo ${a[$i]}
done
# Now do the Sorting of numbers
for (( i = 0; i < $n ; i++ ))
do
        for (( j = 0; j < $n-1; j++ ))
        do
                let j1=j+1
                if [ ${a[$j]} -le ${a[$j1]} ];
                then
                        t=${a[$j]}
                        a[$j]=${a[$j1]}
                        a[$j1]=$t
                fi
        done
done
# Printing the sorted number in descending order
echo "\nSorted Numbers in descending order: "
echo ${a[@]}