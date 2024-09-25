rm -f results.csv
rm -f times.csv
for y in {1..10000};do
  for x in $(seq 1 $y);do
    if test $x -lt $y; then
      (time ./collatz 100000000 $x $y >> results.csv) 2>> times.csv
    fi
  done
done 