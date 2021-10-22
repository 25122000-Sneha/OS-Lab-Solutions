echo "Enter no. of elements: "
read n
echo "Enter elements: "
i=0
while [ $i -lt $n ]
do
	read a[$i]
	let i=i+1
done
echo "Enter index: "
read p
temp=${a[$p]}
for ((i=$p; i<$n-1; i++))
do
	let i1=i+1
	a[$i]=${a[$i1]}
done

echo "Printing array after deletion from position $p: "
for ((j=0; j<$n-1; j++))
do
        echo ${a[$j]} 
done	
