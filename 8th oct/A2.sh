echo "Enter a: "
read a
echo "Enter b: "
read b
c=`echo $a + $b | bc`
echo "The sum is "$c
c=`echo $a - $b | bc`
echo "The difference is "$c
c=`echo $a \* $b | bc`
echo "The product is "$c
c=`echo $a / $b | bc`
echo "The quotient is "$c

