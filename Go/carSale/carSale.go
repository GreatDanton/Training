/* A man has a rather old car being worth $2000. He saw a secondhand
car being worth $8000. He wants to keep his old car until he can
buy the secondhand one.

He thinks he can save $1000 each month but the prices of his old car
and of the new one decrease of 1.5 percent per month. Furthermore the
percent of loss increases by a fixed 0.5 percent at the end of every
two months.

Example of percents lost per month:
If, for example, at the end of first month the percent of loss is 1,
end of second month percent of loss is 1.5, end of third month still 1.5, end of 4th month 2 and so on ...

Can you help him? Our man finds it difficult to make all these
calculations.

How many months will it take him to save up enough money to
 buy the car he wants, and how much money will he have left over?
*/

package main

import (
	"fmt"
)

func main() {
	fmt.Println(NumberOfMonths(2000, 8000, 1000, 1.5))
	//	fmt.Println(NumberOfMonths(12000, 8000, 1000, 1.5))
	//	fmt.Println(NumberOfMonths(8000, 12000, 500, 1.0))
}

// returns [number of months, money left over]
func NumberOfMonths(
	startPriceOld,
	startPriceNew,
	savingPerMonth int,
	percentLossByMonth float64) [2]int {

	priceOld := float64(startPriceOld)
	priceNew := float64(startPriceNew)

	var moneyLeft float64
	var months int

	if priceOld >= priceNew {
		moneyLeft = priceOld - priceNew
	} else {
		months++
		for {
			priceOld -= float64(priceOld) * percentLossByMonth / 100
			priceNew -= float64(priceNew) * percentLossByMonth / 100
			money := priceOld + float64(months*savingPerMonth)
			if money > priceNew {
				moneyLeft = money - priceNew
				break
			}

			months++

			if months%2 == 0 {
				percentLossByMonth += 0.5
			}

		}
	}

	money := int(moneyLeft + 0.5) // rounding
	return [2]int{months, money}
}
