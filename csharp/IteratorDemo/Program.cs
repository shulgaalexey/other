using System;
using System.Collections;

namespace IteratorDemo
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");

						DaysOfWeek days = new DaysOfWeek();

						foreach (string day in days)
							Console.Write(day + " ");
						//Console.ReadKey();
						Console.WriteLine();

						MyStackDemo md = new MyStackDemo();
						md.DoDemo();
        }
    }

		class DaysOfWeek : IEnumerable {
			private string[] days = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

			public IEnumerator GetEnumerator() {
				for (int index = 0; index < days.Length; index++) {
					yield return days[index];
				}
			}
		}
}
