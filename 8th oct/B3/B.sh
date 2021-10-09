while :
do
	echo "*************MENU*************"
	echo "1. Number of presently active users."
	echo "2. Displaying some desired number of lines from top of a file."
	echo "3. Updating the access time of a given file to current time."
	echo "4. Exit"
	echo "Enter choice(1-4): "
	read choice
	case $choice in
		1) 
			echo "No. of presently active users: "
			whoami | wc -l
			;;
		2)
			echo "Enter file name: "
			read file
			echo "Enter no. of lines to be displayed from top: "
			read number
			head -$number $file 
			;;
		3)
			echo "Enter file name whose access time is to be changed to current time: "
			read file
			touch -a $file
			stat $file
			;;
		4) 
			echo "Exit...."
			exit
			;;
		*)
			echo "Invalid Option"
			;;
	esac
done

