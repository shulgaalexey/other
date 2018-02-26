using System;
using System.Collections.Generic;
using System.Linq;

namespace StudyCollections {

	internal sealed class Element {
		public string Symbol { get; set; }
		public string Name { get; set; }
		public int AtomicNumber { get; set; }
	}

	internal sealed class DemoDictionary {
		private Dictionary<string, Element> BuildDictionary() {
			var elements = new Dictionary<string, Element>();

			AddToDictionary(elements, "K", "Potassium", 19);
			AddToDictionary(elements, "Ca", "Calcium", 20);
			AddToDictionary(elements, "Sc", "Scandium", 21);
			AddToDictionary(elements, "T", "Titanium", 22);

			return elements;
		}

		private Dictionary<string, Element> BuildDictionary2() {
			return new Dictionary<string, Element> {
				{"K",
					new Element() {Symbol = "K", Name = "Potassium", AtomicNumber = 19}},
				{"Ca",
					new Element() {Symbol = "Ca", Name = "Calcium", AtomicNumber = 20}},
				{"Sc",
					new Element() {Symbol = "Sc", Name = "Scandium", AtomicNumber = 21}},
				{"Ti",
					new Element() {Symbol = "Ti", Name = "Titanium", AtomicNumber = 22}}
			};
		}

		private void AddToDictionary(Dictionary<string, Element> elements,
				string symbol, string name, int atomicNumber) {
			Element theElement = new Element() {
				Symbol = symbol,
				Name = name,
				AtomicNumber = atomicNumber };

			elements.Add(key: theElement.Symbol, value: theElement);
		}

		private void IterateThruDictionary() {
			Dictionary<string, Element> elements =
				//BuildDictionary();
				BuildDictionary2();

			foreach (KeyValuePair<string, Element> kvp in elements) {
				Element theElement = kvp.Value;

				Console.Write("key: " + kvp.Key + "  ===  ");
				Console.WriteLine("values: " + theElement.Symbol + " " +
						theElement.Name + " " + theElement.AtomicNumber);
			}
		}

		private void FindInDictionary(string symbol) {
			var elements = BuildDictionary();

			if (elements.ContainsKey(symbol) == false)
				Console.WriteLine(symbol + " not found");
			else {
				Element theElement = elements[symbol];
				Console.WriteLine("Found: " + theElement.Name);
			}
		}

		private void FindInDictionary2(string symbol) {
			var elements = BuildDictionary();

			Element theElement = null;
			if (elements.TryGetValue(symbol, out theElement) == false)
				Console.WriteLine(symbol + " not found");
			else
				Console.WriteLine("Found: " + theElement.Name);
		}

		private static List<Element> BuildList() {
			return new List<Element> {
				{ new Element() { Symbol="K", Name="Potassium", AtomicNumber=19}},
					{ new Element() { Symbol="Ca", Name="Calcium", AtomicNumber=20}},
					{ new Element() { Symbol="Sc", Name="Scandium", AtomicNumber=21}},
					{ new Element() { Symbol="Ti", Name="Titanium", AtomicNumber=22}}
			};
		}

		private void PrintLINQResults() {
			/*var elements = BuildDictionary();

			var subset = from theElement in elements
				where theElement.AtomicNumber < 22
				orderby theElement.Name
				select theElement;*/

			List<Element> elements = BuildList();

			// LINQ Query.
			var subset = from theElement in elements
				where theElement.AtomicNumber < 22
				orderby theElement.Name
				select theElement;


			foreach (var theElement in subset)
				Console.WriteLine(theElement + " " + theElement.AtomicNumber);
		}

		public void DoDemo() {
			Console.WriteLine("Demo Dictionary");

			IterateThruDictionary();

			FindInDictionary("Mg");
			FindInDictionary("Ca");
			FindInDictionary2("Au");
			FindInDictionary2("K");

			PrintLINQResults();
		}
	}
}
