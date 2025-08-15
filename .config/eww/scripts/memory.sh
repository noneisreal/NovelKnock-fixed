#!/usr/bin/env bash

export LC_ALL=C
export LC_NUMERIC=C

while true; do
    # human-readable
  freeH=$(free -h --si | awk '/^Mem:/')
  swapfreeH=$(free -h --si | awk '/^Swap:/')
    # non-human-readable
  freeN=$(free --mega | awk '/^Mem:/')
  swapfreeN=$(free --mega | awk '/^Swap:/')

  total=$(awk '{print $2}' <<<"$freeH")
  used=$(awk '{print $3}' <<<"$freeH")
    # total="$(echo "$freeH" | awk '{ print $2 }')"
    # used="$(echo "$freeH" | awk '{ print $3 }')"
  # If have any error when $t and $u return null, it will be 0
  t=${t:-0}
  u=${u:-0}

  t=$(awk '{print $2}' <<<"$freeN")
  u=$(awk '{print $3}' <<<"$freeN")
    # t="$(echo "$freeN" | awk '{ print $2 }')"
    # u="$(echo "$freeN" | awk '{ print $3 }')"

  swaptotal=$(awk '{print $2}' <<<"$swapfreeH")
  swapused=$(awk '{print $3}' <<<"$swapfreeH")
    # swaptotal="$(echo "$swapfreeH" | awk '{ print $2 }')"
    # swapused="$(echo "$swapfreeH" | awk '{ print $3 }')"
  swapt=$(awk '{print $2}' <<<"$swapfreeN")
  swapu=$(awk '{print $3}' <<<"$swapfreeN")
    # swapt="$(echo "$swapfreeN" | awk '{ print $2 }')"
    # swapu="$(echo "$swapfreeN" | awk '{ print $3 }')"

  free_g=$(bc -l <<< "scale=1; ($t - $u) / 1000")
  free=$(printf '%.1fG' "$free_g")

  #perc=$(printf '%.1f' "$(free -m | rg Mem | awk '{print ($3/$2)*100}')")
  perc=$(printf '%.1f' "$(free -m | awk '/^Mem:/ { printf "%f", ($3/$2)*100 }')")

  swapfree_g=$(bc -l <<< "scale=1; ($swapt - $swapu) / 1000")
  swapfree=$(printf '%.1fG' "$swapfree_g")

  #swapperc=$(printf '%.1f' "$(free -m | rg Swap | awk '{print ($2!=0) ? ($3/$2)*100 : 0}')")
  
  perc=$(printf '%.1f' "$(free -m | awk '/^Mem:/ { printf "%f", ($3/$2)*100 }')")
  swapperc=$(printf '%.1f' "$(free -m | awk '/^Swap:/ { if ($2>0) printf "%f", ($3/$2)*100; else print 0 }')")
  ##### this is my idea, not good #####
    # total_num=$(echo "$total" | sed 's/[^0-9.]//g')
    # used_num=$(echo "$used" | sed 's/[^0-9.]//g')
    # swaptotal_num=$(echo "$swaptotal" | sed 's/[^0-9.]//g')
    # swapused_num=$(echo "$swapused" | sed 's/[^0-9.]//g')
    # free_num=$(echo "$free" | sed 's/[^0-9.]//g')
    # swapfree_num=$(echo "$swapfree" | sed 's/[^0-9.]//g')

    # jq -n \
    #  --argjson total "$total_num" \
    #  --argjson used "$used_num" \
    #  --argjson free "$free_num" \
    #  --argjson swaptotal "$swaptotal_num" \
    #  --argjson swapused "$swapused_num" \
    #  --argjson swapfree "$swapfree_num" \
    #  --argjson percentage "$perc" \
    #  --argjson swappercentage "$swapperc" \
    # '{
    #  total: $total,
    # used: $used,
    #  free: $free,
    #  swaptotal: $swaptotal,
    #  swapused: $swapused,
    #  swapfree: $swapfree,
    #  percentage: $percentage,
    #  swappercentage: $swappercentage
    # }'

  echo '{"total": "'"$total"'", "used": "'"$used"'", "free": "'"$free"'", "swaptotal": "'"$swaptotal"'", "swapused": "'"$swapused"'", "swappercentage": '"$swapperc"', "swapfree": "'"$swapfree"'", "percentage": '"$perc"' }'

  sleep 3
done