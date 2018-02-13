// https://docs.microsoft.com/en-us/dotnet/api/system.idisposable?view=netframework-4.7.1
using System;

namespace study_dispsable
{
	class MyResource : IDisposable {
		protected IntPtr handle;
		private bool disposed = false;

		public MyResource(IntPtr handle) {
			Console.WriteLine($"ctor: {handle}");
			this.handle = handle;
		}

		// Implement IDisposable
		public void Dispose() { // DO NOT MAKE virtual
			Console.WriteLine("Dispose with no params");
			Dispose(true);

			// Remove this from GC to prevent finalization second time
			GC.SuppressFinalize(this);
		}

		// If disposing is TRUE, it is called by the user
		// If disposing is FALSE, it is called by the runtime
		protected virtual void Dispose(bool disposing) {
			Console.WriteLine($"Dispose with param {disposing}");
			if (!this.disposed) { // Check if disposed already

				//if (disposing)
				//	Console.WriteLine("Disposing by user: dispose managed resources");
				//else
				//	Console.WriteLine("Disposing by the runtime");

				//Console.WriteLine("Disposing only unmanaged resources");
				//CloseHandle(handle);
				handle = IntPtr.Zero;
				disposed = true;
			}
		}

		// DTor will run only if Dispose doesn't get called.
		// DO NOT provide destructor in derived from this class
		~MyResource() {
			Console.WriteLine("dtor");
			Dispose(false);
		}
	}

	class DerivedResource : MyResource {
		bool disposed = false;

		//SafeHandle handle = new SafeHandle(IntPtr.Zero, true);

		public DerivedResource() : base(new IntPtr(42)) {
			Console.WriteLine($"   Derived ctor: {handle}");
		}

		protected override void Dispose(bool disposing) {
			Console.WriteLine($"   Derived dispose with param {disposing}");

			if (disposed)
				return;

			if (disposing) {
				//handle.Dispose();
			}

			disposed = true;

			base.Dispose(disposing);
		}
	}

	class Program {
		static void Main(string[] args) {
			Console.WriteLine("Hello World!");

			/*
			// Neither Dispose, nor dtor
			var obj = new MyResource(new IntPtr());
			*/

			/*
			{ // Neither Dispose, nor dtor
				Console.WriteLine("Enter block");
				var obj = new MyResource(new IntPtr());
				Console.WriteLine("Exit block");
			}
			*/

			/*
			// Dispose with no params, etc
			{
				MyResource obj = null;
				try {
					obj = new MyResource(new IntPtr(42));
				} catch (Exception ex) {
					Console.WriteLine(ex);
				} finally {
					obj.Dispose();
					//obj.Finalize();
				}
			}
			*/

			/*
			// Dispose with no params, etc
			using (var obj = new MyResource(new IntPtr(42))) {
				Console.WriteLine("Inside using block");
			}
			*/

			// Dispose derived class obj with no params, etc
			using (var obj = new DerivedResource()) {
				Console.WriteLine("     Inside using block");
			}


			Console.WriteLine("End main");
		}
	}

}
