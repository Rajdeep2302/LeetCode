package main

import (
	"fmt"
	"math"
)

func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	if len(nums1) > len(nums2) {
		nums1, nums2 = nums2, nums1
	}

	m := len(nums1)
	n := len(nums2)

	low := 0
	high := m

	for low <= high {
		partitionX := (low + high) / 2
		partitionY := (m+n+1)/2 - partitionX

		maxLeftX := math.Inf(-1)
		if partitionX != 0 {
			maxLeftX = float64(nums1[partitionX-1])
		}

		minRightX := math.Inf(1)
		if partitionX != m {
			minRightX = float64(nums1[partitionX])
		}

		maxLeftY := math.Inf(-1)
		if partitionY != 0 {
			maxLeftY = float64(nums2[partitionY-1])
		}

		minRightY := math.Inf(1)
		if partitionY != n {
			minRightY = float64(nums2[partitionY])
		}

		if maxLeftX <= minRightY && maxLeftY <= minRightX {
			if (m+n)%2 == 0 {
				return (math.Max(maxLeftX, maxLeftY) + math.Min(minRightX, minRightY)) / 2.0
			} else {
				return math.Max(maxLeftX, maxLeftY)
			}
		} else if maxLeftX > minRightY {
			high = partitionX - 1
		} else {
			low = partitionX + 1
		}
	}

	return 0.0
}

func main() {
	nums1_1 := []int{1, 3}
	nums2_1 := []int{2}
	fmt.Printf("Nums1: %v, Nums2: %v -> Median: %f\n", nums1_1, nums2_1, findMedianSortedArrays(nums1_1, nums2_1))

	nums1_2 := []int{1, 2}
	nums2_2 := []int{3, 4}
	fmt.Printf("Nums1: %v, Nums2: %v -> Median: %f\n", nums1_2, nums2_2, findMedianSortedArrays(nums1_2, nums2_2))

	nums1_3 := []int{0, 0}
	nums2_3 := []int{0, 0}
	fmt.Printf("Nums1: %v, Nums2: %v -> Median: %f\n", nums1_3, nums2_3, findMedianSortedArrays(nums1_3, nums2_3))

	nums1_4 := []int{}
	nums2_4 := []int{1}
	fmt.Printf("Nums1: %v, Nums2: %v -> Median: %f\n", nums1_4, nums2_4, findMedianSortedArrays(nums1_4, nums2_4))

	nums1_5 := []int{2}
	nums2_5 := []int{}
	fmt.Printf("Nums1: %v, Nums2: %v -> Median: %f\n", nums1_5, nums2_5, findMedianSortedArrays(nums1_5, nums2_5))

	nums1_6 := []int{1, 2, 3, 4, 5, 6}
	nums2_6 := []int{7, 8, 9, 10}
	fmt.Printf("Nums1: %v, Nums2: %v -> Median: %f\n", nums1_6, nums2_6, findMedianSortedArrays(nums1_6, nums2_6))

	nums1_7 := []int{1, 5, 9, 10}
	nums2_7 := []int{2, 3, 6, 7}
	fmt.Printf("Nums1: %v, Nums2: %v -> Median: %f\n", nums1_7, nums2_7, findMedianSortedArrays(nums1_7, nums2_7))
}
