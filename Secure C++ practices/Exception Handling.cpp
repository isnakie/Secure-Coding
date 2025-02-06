/*
Below reveals sensitive info about error
*/

try {
	// ...
	
} catch (SecurityException se) {
	System.err.println(se);
	// Recover from exception
}

// rather use the following:
// Log the error
try {
	//..
} catch (SecurityException se) {
	logger.log(Level.SEVERE, se);
	// Recover from exception
}

// Handle the specific error
volatile boolean validFlag = false;
do {
	try{
		//open file if it exists
		validFlag = true;
	} catch (FileNotFoundException e){
		// ask for another file
	}
} while (validFlag != true);
// use the file