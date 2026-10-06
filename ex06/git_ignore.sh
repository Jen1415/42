ignore_files=($(git status --ignored --porcelain | awk '/^!!/ {print $2 "$"}'))
for file in ${ignore_files[@]};
do
	echo $file
done;

