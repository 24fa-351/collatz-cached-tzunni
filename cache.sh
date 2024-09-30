rm -f results.csv

TIMEFORMAT=%U

# for x in {180..200};do
#   for y in {0..10};do
#     cache_size=$((x * 1000))
#     echo "LFU,$(./main 500000 1 500000 LFU $cache_size),$cache_size" >> results.csv
#   done
# done
for x in {180..200};do
  for y in {0..10};do
    cache_size=$((x * 1000))
    echo "LRU,$(./main 500000 1 500000 LRU $cache_size),$cache_size" >> results.csv
  done
done