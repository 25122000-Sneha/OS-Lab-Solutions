while :
do
        echo "~~~~~~~~~~~~~~~"
        echo "MENU"
        echo "~~~~~~~~~~~~~~~"
        echo "1. Merge 2 files into another"
        echo "2. Search pattern in file"
        echo "3. EXIT"

        echo -n "Enter your choice(1-3): "
        read choice
        case "$choice" in
                1)
                        echo "Merging"
                        echo "Enter file name 1: "
                        read f1
                        echo "Enter file name 2: "
                        read f2
                        echo "Enter new file name: "
                        read f
                        cat $f1 $f2 > $f
			echo "Contents of $f after merging $f1 and $f2: "
			cat $f
                        ;;
                2)
                        echo "Searching"
			echo "Enter file name: "
			read file
                        echo "Enter pattern: "
                        read pattern
			grep $pattern $file
                        ;;
                3)
                        echo "Exit...."
                        exit
                        ;;
                *)
                        echo "Invalid option"
                        ;;
        esac
done
