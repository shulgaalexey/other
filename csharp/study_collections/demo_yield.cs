using System;
using System.Collections.Generic;

namespace StudyCollections {
	internal sealed class DemoYield {
		public void DoDemo() {
			Console.WriteLine("Demo yield");

			foreach (int number in EvenSequence(5, 18)) {
				Console.Write(number.ToString() + " ");
			}
			Console.WriteLine();
		}

		private IEnumerable<int> EvenSequence(int firstNumber, int lastNumber) {
			for (var number = firstNumber; number <= lastNumber; number++) {
				if (number % 2 == 0)
					yield return number;
			}
		}
	}
}
