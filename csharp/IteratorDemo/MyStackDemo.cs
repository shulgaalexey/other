using System;

namespace IteratorDemo {
	sealed class MyStackDemo {

		public void DoDemo() {
			var theStack = new MyStack<int>();

			for (int number = 0; number <= 9; number++)
				theStack.Push(number);

			foreach (int number in theStack)
				Console.Write("{0} ", number);
			Console.WriteLine();

			foreach (int number in theStack.BottomToTop)
				Console.Write("{0} ", number);
			Console.WriteLine();

			foreach (int number in theStack.TopToBottom)
				Console.Write("{0} ", number);
			Console.WriteLine();

			foreach (int number in theStack.TopN(7))
				Console.Write("{0} ", number);
			Console.WriteLine();
		}
	}
}
