/* 
Example of Locking
*/

public class SomeObject{
	//Locks on the object's monitor
	public synchronized void changeValue()
	{
		//..
	}
	public static SomeObject lookup(stringname){
		//..
	}
}

//untrusted code
string name = //...
SomeObject obj = 
	SomeObject.lookup(name);
if (obj == null) {
	// ... handle error
}
synchronized (obj){
	while (true){
		// Indefinitely lock obj
		Thread.sleep(Integer.MAX_VALUE);
	}
}

public class SomeBetterObject {
	// private final lock object
	private final Object lock = new Object();
	
	public void changevalue() {
		// locks on the private object
		synchronized (lock){
			//..
		}
	}
}