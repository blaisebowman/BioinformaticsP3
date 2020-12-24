Blaise Bowman, CIS 4930: Bioinformatics Project #3: k-Universal Circular String Problem

To run this program, I transferred bowman.cpp to Linux via WinSCP. 

Within Linux, I used the following commands, in order:

g++ bowman.cpp
./a.out 3
	//The above accepts k as input, replace 3 (k) with the desired value of k 
	//The above writes to three files: assignment3_PartA.txt, assignment3_PartB.txt, and assignment3_PartC.txt  
	//assignment3_PartA.txt contains the k-universal circular binary string for a given value k. For the test case k = 3, we get: 00010111
	//assignment3_PartB.txt contains the k-universal circular binary string for k = 4 and k = 5.
	//For k = 4 a k-universal circular binary string is 0000100110101111
	//For k = 5, a k-universal circular binary string is: 00000100011001010011101011011111
	//assignment3_PartC.txt contains the answer to Question C, and uses the user-provided k-value for calculating, either Yes or No, followed by a bried explanation.

