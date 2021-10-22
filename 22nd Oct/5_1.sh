echo "Enter n: "
read n
echo "Enter numbers in array: "
i=0
while [ $i -lt $n ]
do
	read a[$i]
	echo ${a[$i]} >> 5file.txt
	let i=i+1

done
echo "Sorted numbers in descending order: "
sort -r 5file.txt
rm 5file.txt

