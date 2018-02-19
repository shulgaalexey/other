using System;
using System.Threading;

namespace timer_and_gc
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");
						Timer t = new Timer(TimerCallback, null, 0, 2000);

						Console.WriteLine(GC.MaxGeneration);

						Console.ReadLine();
        }

				static void TimerCallback(Object o) {
					Console.WriteLine("Timer callback" + DateTime.Now);

					GC.Collect();
				}
    }
}
