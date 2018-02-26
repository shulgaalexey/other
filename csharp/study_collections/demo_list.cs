using System;
using System.Collections.Generic;

namespace StudyCollections {
	internal sealed class DemoList {
		public void DoDemo() {
			Console.WriteLine("Demo List");

			/*var salmons = new List<string>();
			salmons.Add("chinook");
			salmons.Add("coho");
			salmons.Add("pink");
			salmons.Add("sockeye");*/
			var salmons = new List<string> {
				"chinook",
					"coho",
					"pink",
					"sockeye" };

			foreach (var salmon in salmons) {
				Console.Write(salmon + " ");
			}
			Console.WriteLine("");
		}

		public void DoDemo2() {
			var numbers = new List<int> { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

			// Removie odd numbers
			for (var index = numbers.Count - 1; index >= 0; index--) {
				if (numbers[index] % 2 == 1)
					numbers.RemoveAt(index);
			}

			numbers.ForEach(number => Console.Write(number + " "));
			Console.WriteLine();
		}

		class Galaxy {
			public string Name { get; set; }
			public int MegaLightYears { get; set; }
		}

		public void DoDemo3() {
			var theGalaxies = new List<Galaxy> {
				new Galaxy() { Name = "Tadpole", MegaLightYears = 400 },
				new Galaxy() { Name = "Pinwheel", MegaLightYears = 25 },
				new Galaxy() { Name = "Milky Way", MegaLightYears = 0 },
				new Galaxy() { Name = "Andromeda", MegaLightYears = 3 }
			};

			foreach(Galaxy theGalaxy in theGalaxies) {
				Console.WriteLine(theGalaxy.Name + " " + theGalaxy.MegaLightYears);
			}
		}
	}
}
