echo "Enter file name: "
read file
if test -f $file;
then
	echo "File exists"
	ls -l $file | cut -d " " -f 1
else
	touch $file
	echo "File created."
	echo "Permissions associated with $file: "
	ls -l $file | cut -d " " -f 1
fi


