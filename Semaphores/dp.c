do { 
      wait (chopstick[i] );
	  wait (chopStick[ (i + 1) % 5] );
	
	             //  eat

	  signal (chopstick[i] );
	  signal (chopstick[ (i + 1) % 5] );
	
                 //  think

} while (TRUE);
