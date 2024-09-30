rm -f results.csv
rm -f times.csv

TIMEFORMAT=%U
for y in {1..300};do
  for x in $(seq 1 $y);do
    if test $x -lt $y; then
      echo "$((time ./main 1000000 $x $y LFU 2000) 2>&1 >/dev/null | sed 's/\\n$//g'),$x,$y" >> times.csv
    fi
  done
done