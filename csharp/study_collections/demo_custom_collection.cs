using System;
using System.Collections.Generic;

namespace StudyCollections {
	internal sealed class DemoCustomCollection {
		public void DoDemo() {
			Console.WriteLine("Demo custom collection");

			var colors = new AllColors();

			foreach (Color theColor in colors) {
				Console.Write(theColor.Name + " ");
			}
			Console.WriteLine();
		}
	}

	internal sealed class Color {
		public string Name { get; set; }
	}

	internal sealed class AllColors : System.Collections.IEnumerable {
		Color[] _colors = {
			new Color() { Name = "red" },
			new Color() { Name = "blue" },
			new Color() { Name = "green" }
		};

		public System.Collections.IEnumerator GetEnumerator() {
			return new ColorEnumerator(_colors);

			// we can also use for the same purposes the following
			// return _colors.GetEnumerator();
		}
	}

	// Custom enumerator
	internal sealed class ColorEnumerator : System.Collections.IEnumerator {
		private Color[] _colors;
		private int _position = -1;

		public ColorEnumerator(Color[] colors) {
			_colors = colors;
		}

		object System.Collections.IEnumerator.Current {
			get {
				return _colors[_position];
			}
		}

		bool System.Collections.IEnumerator.MoveNext() {
			_position++;
			return (_position < _colors.Length);
		}

		void System.Collections.IEnumerator.Reset() {
			_position = -1;
		}
	}
}
