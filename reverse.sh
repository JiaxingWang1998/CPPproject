lost_found=$(git fsck --lost-found)
# shellcheck disable=SC2207
trees=($(git fsck --lost-found | awk '/tree/{print$3}'))
for tree in $trees
do
  echo "tree $tree"
  git read-tree --prefix=$1 $tree
  git checkout "$1"
done
