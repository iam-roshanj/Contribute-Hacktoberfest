package main

import "fmt"

func GenCombinations(set []int, k int) [][]int {
	var j, i int
	combs := [][]int{}
	tailCombs := [][]int{}
	head := []int{}

	if k > len(set) || k <= 0 {
		return combs // []
	} else if k == len(set) {
		return [][]int{set}
	} else if k == 1 {
		for i = 0; i < len(set); i++ {
			combs = append(combs, []int{set[i]})
		}
		return combs // [[1], [2], [3], [4], [5]]
	} else {

		for i = 0; i < len(set)-k+1; i++ {
			setClone := append(set[:0:0], set...)
			head = setClone[i : i+1]
			tailCombs = GenCombinations(setClone[i+1:], k-1)

			for j = 0; j < len(tailCombs); j++ {
				val := append(head, tailCombs[j]...)
				valClone := append(val[:0:0], val...)
				combs = append(combs, valClone)
			}

		}
	}

	return combs

}
func main() {
	// example
	arr := []int{1, 2, 3, 4, 5}
	combinations := GenCombinations(arr, 3)
	fmt.Println(combinations) // [[1 2 3] [1 2 4] [1 2 5] [1 3 4] [1 3 5] [1 4 5] [2 3 4] [2 3 5] [2 4 5] [3 4 5]]

}
