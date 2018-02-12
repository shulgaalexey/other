using System;


/* Finally block is executed first in the function which throws the
 * exception. Then other finally blocks are executed.
 * And only after it, the suitable catch block is executed.
 *
 * The expected output of the program is following:
 *
 * main
 * try main
 * -func1
 * --func2
 * --try2
 * --finally2
 * -finally1
 * caught main
 * finally main
 * exit main
 */

namespace study_exceptions
{
	class Program
	{
		static void func1() {
			Console.WriteLine("-func1");
			try {
				func2();
			} catch(NullReferenceException) { // Can not catch the excptn
				Console.WriteLine("-catch1");
			} finally {
				Console.WriteLine("-finally1");
			}
			Console.WriteLine("-exit func1");
		}

		static void func2() {
			Console.WriteLine("--func2");
			try {
				Console.WriteLine("--try2");
				throw new Exception();
			} catch (NullReferenceException) { // Can not catch the excptn
				Console.WriteLine("--catch2");
			} finally {
				Console.WriteLine("--finally2");
			}
			Console.WriteLine("--exit func2");
		}

		static void Main(string[] args)
		{
			Console.WriteLine("main");
			try {
				Console.WriteLine("try main");
				func1();
			} catch (Exception) {
				//Console.WriteLine("caught main:\n" + ex);
				Console.WriteLine("caught main");
			} finally {
				Console.WriteLine("finally main");
			}
			Console.WriteLine("exit main");
		}
	}
}
