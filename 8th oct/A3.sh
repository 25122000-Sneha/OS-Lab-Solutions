echo "Enter 1st num: "
read num1
echo "Enter 2nd num: "
read num2
if [ $num1 -gt $num2 ]
then
	echo "Greatest is "$num1
else
	echo "Greatest is "$num2
fi
