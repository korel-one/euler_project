// EulerProject.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Factorial.h"
#include <vector>
#include <iostream>
/*
#include "1_multiples_of_3_and_5.h"
#include "2_EvenFibonacciNumbers.h"
#include "3_LargestPrimeFactor.h"
#include "4_LargestPalindromeProduct.h"
#include "5_SmallestMultiple.h"
#include "6_SumSquareDifference.h"
#include "7_BigPrime.h"
#include "8_LargestProductInSeries.h"
#include "9_SpecialPythagoreanTriplet.h"
#include "10_SummationOfPrimes.h"
#include "11_LargestProductInGrid.h"
#include "12_HighlyDivisibleTriangularNumber.h"
#include "13_LargeSum.h"

//#include "14_LongestCollatzSequence.h"
//#include "15_LaticePath.h"
#include "16_PowerDigitSum.h"
//#include "17_NumberLetterCounts.h"
#include "18_MaximumPathSum.h"
#include "19_CountingSundays.h"
#include "20_FactorialDigitSum.h"
#include "21_AmicableNumbers.h"

#include "22_NamesScores.h"
#include "24_LexicographicPermutations.h"
#include "25_BigFibonacci.h"

#include "27_QuadraticPrimes.h"
#include "28_NumberSpiralDiagonals.h"
#include "30_DigitsFifthPowers.h"


*/

#include "31_CoinsSums.h"
//#include "BullsAndCows.h"
#include "23_NonAbundantSums.h"
#include "24_LexicographicPermutations.h"
#include "26_ReciprocalCycles.h"
#include "28_NumberSpiralDiagonals.h"
#include "32_PandigitalProducts.h"
#include "33_DigitCancellingFractions.h"
#include "35_CircularPrimes.h"
#include "36_DoubleBasePalindromes.h"
#include "37_TruncatablePrimes.h"
#include "38_PandigitalMultiples.h"
#include "39_IntegerRightTriangles.h"
#include "40_Champernowne_sConstant.h"
#include "41_PandigitalPrimes.h"
#include "42_CodedTriangleNumbers.h"
#include "43_SubStringDivisibility.h"
#include "45_TriangularPentagonalHexagonal.h"
#include "46_GoldbachOtherConjecture.h"

#include "48_SelfPowers.h"
#include "50_ConsecutivePrimeSum.h"

#include "52_PermutedMultiples.h"
#include "53_CombinatoricSelections.h"
#include "55_LychrelNumbers.h"

#include "47_DistinctPrimesFactors.h"
#include "49_PrimePermutations.h"
#include "60_PrimePairSets.h"

#include "58_SpiralPrimes.h"
#include "59_XOR_decryption.h"
#include "92_SquareDigitChains.h"

#include "LongestIncreasingSubsequence.h"
#include "LongestIncDecSubSeq.h"

#include "bulls_cows.h"
#include "stones_game.h"
#include "game_23.h"
#include "PurchaseNumSeq.h"

int _FF[1000][8];

bool F(int balance, int num, const std::vector<int>& coins) {
	if (balance < 0) return false;
	/*
	if(num == 0) {if(balance == 0) return true;else return false;}
	*/

	if (num == 1) {
		for (int i = 0; i < coins.size(); i++) if (balance == coins[i]) return true;
		return false;
	}
	if (_FF[balance][num] == -1) {
		bool ans = false;
		for (int i = 0; i < coins.size(); i++) ans |= F(balance - coins[i], num - 1, coins);
		_FF[balance][num] = ans ? 1 : 0;
	}
	return (_FF[balance][num] == 1) ? 1 : 0;
	
}

int rob_recursive(std::vector<int>& nums, std::vector<int>& rob_sum, int curr_i) {
	if (curr_i == 0)
		return nums[curr_i];

	if (curr_i == 1)
		return std::max(nums[0], nums[1]);

	if (rob_sum[curr_i] == -1) {

		rob_sum[curr_i] = std::max(rob_recursive(nums, rob_sum, curr_i - 2) + nums[curr_i]
			, rob_recursive(nums, rob_sum, curr_i - 1));
	}
	return rob_sum[curr_i];
}

int _tmain(int argc, _TCHAR* argv[])
{
	//execute_stones_game_23();
	execute_pns();
	return 0;
}