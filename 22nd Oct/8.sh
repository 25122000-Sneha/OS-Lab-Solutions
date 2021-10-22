echo "Enter no. of elements: "
read n 
echo "Enter the elements one by one: "
i=0
while [ $i -lt $n ]
do
        read a[$i]
        let i=i+1
done
i=0
j=0
for((i=0; i<$n; i++))
do
        for((j=0; j<$n-1; j++))
        do
                let j1=j+1
                if [ ${a[$j]} -ge ${a[$j1]} ]
                then
                        t=${a[$j]}
                        a[$j]=${a[$j1]}
                        a[$j1]=$t
                fi 
        done
done 
echo "Sorted elements in order: " 
echo ${a[@]}