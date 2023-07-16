#git fsck --lost-found
revertBlobs() {
  echo "revertBlob $1 , $2"
  git show $1 >$2
}

revertTrees() {
  local tree_id=$1
  local current_path=$2
  mkdir $current_path
  # shellcheck disable=SC2207
  local trees=($(git ls-tree $tree_id | awk '{print$2, $3, $4}'))
  local length=${#trees[@]}

  local i=0
  while [ $i -lt ${#trees[@]} ]; do #当变量（下标）小于数组长度时进入循环体
    type=${trees[$i]}
    let i++
    local hash=${trees[$i]}
    let i++
    local path="$current_path/${trees[$i]}"
    let i++

    echo "type: $type,hash: $hash,path: $path"
    #
    if [ "$type" = "tree" ]; then
      revertTrees $hash $path
    else
      revertBlobs $hash $path
    fi

  done
  return 0
}

# shellcheck disable=SC2034
lost_found=$(git fsck --lost-found)
# shellcheck disable=SC2207
trees=($(git fsck --lost-found | awk '/tree/{print$3}'))

path=$1
# shellcheck disable=SC2128
echo $trees
revertTrees "${trees[3]}" $path