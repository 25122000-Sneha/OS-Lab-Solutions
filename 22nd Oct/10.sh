while :
do
	echo "----------M E N U------------"
	echo "1. Display contents of whole file."
	echo "2. Display info of student with specified roll no."
	echo "3. Delete entry of student with specific roll no."
	echo "4. Add new entry."
	echo "5. Update existing entry with specified roll no."
	echo "6.-------E X I T-------------"
	echo "Enter choice(1-6): "
	read choice
	case $choice in
		1)
			echo "Entire content: "
			cat 10file.txt
			;;
		2)
			echo "Enter reqd roll no : "
			read roll
			grep $roll 10file.txt
			;;
		3)
			echo "Enter roll no. whose entry is to be deleted: "
			read roll
			sed -i /$roll/d 10file.txt
			echo "Record deleted successfully."
			;;
		4)
			echo "Enter Roll: "
			read roll
			echo "Enter new Student name: "
			read name
			echo "Enter city: "
			read city
			echo "$roll |  $name | $city">>10file.txt
			echo "New Entry added."
			;;
		5)
			echo "Enter roll no. whose entry is to be updated: "
			read roll
			dbs1=$(grep -v $roll 10file.txt)
			echo $dbs1 > 10file.txt
			echo "Enter new student name: "
			read name
			echo "Enter city: "
			read city
			echo "$roll |  $name  |  $city">>10file.txt
			;;
		6)
		        echo "Exit...."
		        exit
		        ;;
		*)
			echo "Invalid Choice!"
	esac
done
