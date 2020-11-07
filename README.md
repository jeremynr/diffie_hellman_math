Just some sample code to show the basics of Diffie-Hellman math

			User5
			  |
			  |
			  |
	User1--------------------User2
	
Step 1: User1 and User2 publicly agree on base and modulus
		3 mod 17
		
Step 2: User1 selects private random number and sends result publicly to User2
		15
		3 ^ 15 mod 17 = 6
		
		User1 knows 3, 17, 15, 6
		User2 knows 3, 17, 6
		User5 knows 3, 17 from both User1 and User2
				6 from User1
		
Step 3: User2 selects private random number and sends result publicly to User1
		13
		3 ^ 13 mod 17 = 12
		
		User1 knows 3, 17, 15, 6, 12
		User2 knows 3, 17, 6, 12
		User5 knows 3, 17 from both User1 and User2
				6 from User1
				12 from User2
		
*** Here is where the magic happens and where the confusion comes in (for me anyway)***
		
Step 4: User1 takes User2's result and raises it to the power of User1's private number
		to obtain the SHARED SECRET 

		User2 takes User1's result and raises it to the power of User2's private number
		to reach the same SHARED SECRET
		
		User1: 12 ^ 15 mod 17 = 10
		User2:  6 ^ 13 mod 17 = 10
		
		*** OR ***
		
		User1: (3 ^ 13) ^ 15 mod 17 = (3 ^ 15) ^ 13 mod 17
		
		User5 cannot decrypt because exponents used to generate shared secret are never sent publicly 
		
Result: User1 and User2 are only ones that know shared secret

			User5
			  |
			  |
			  |
	User1====================User2
		
		
