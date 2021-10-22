echo "Enter string:"
read string
echo "Enter substring to be searched for: "
read sub
string_len=${#string}
sub_len=${#sub}
for ((i=0; i<$string_len; i++))
do
	sub_str=${string:$i:$sub_len}
	if [ $sub_str == $sub ]
	then
		echo "Position of substring $sub : $i"
		break
	fi
done



