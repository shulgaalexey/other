using System;
using System.Threading;

/*
 * Expected result:
 *
 *  Enter main
 *  Hello finally!
 *   0
 *     aaaaaaa
 *   1
 *
 * Unhandled Exception:
 */

namespace final_unbreakable_exec
{
    class Program
    {
        static void finally_demo()
        {
            Console.WriteLine("  Hello finally!");

			try {
				// empty
			} catch (Exception) {
				Console.WriteLine("   Catch in func");
			} finally {
				// Nothing can interrupt/break this block???
				//
				// Only Thread.Abort/AppDomain.Unload can not halt this
				//

				Thread t = new Thread(() => {
						Thread.Sleep(1000);
						Console.WriteLine("     aaaaaaa");
						throw new Exception(); // This will interrupt it
						});
				t.Start();


				for (int i = 0; i < 10; i++) {
					Console.WriteLine("   " + i);
					Thread.Sleep(1000);
				}
			}
			Console.WriteLine("end");
        }

		static void Main(string[] args)
		{
			Console.WriteLine("Enter main");
			try {
				finally_demo();
			} catch (Exception) {
				Console.WriteLine("Exception caught in main");
			} finally {
				Console.WriteLine("Finally in main");
			}
			Console.WriteLine("Exit main");
		}
    }
}
