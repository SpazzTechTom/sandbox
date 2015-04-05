/***********************************************************************
 * SpazzTech Tutorials
 * Learn C Programming on Raspberry Pi
 * 11 - Comparison Operators and Decision Making
 * 12 - Logical Operators
 * ********************************************************************/
 
 #include <stdio.h>
 
 int main(){
	 int hobbits = 10;
	 int elves = 5;
	 int dwarves = 15;
	 int orcs = 10;
	 
	 if(hobbits == elves || hobbits == orcs)printf("Hobbits = Elves or Hobbits = Orcs\n");
	 
	 
	 if(dwarves > orcs && dwarves > hobbits)
	 {
		 printf("There are more dwarves than orcs and more dwarves than hobbits!\n");
	 }else
	 {
		 printf("There are not more dwarves than orcs.\n");
	 }
	 
	 if(!(hobbits == elves)) printf("Hobbits DO NOT = elves\n");
	 
	 //if(hofbbits < orcs)
	 //{
		 //printf("There are fewer hobbits than orcs.\n");
	 //}else if(hobbits > orcs)
	 //{
		 //printf("There are more hobbits than orcs.\n");
	 //}else if(hobbits <= orcs)
	 //{
		 //if(hobbits == orcs)
		 //{
			 //printf("Hobbits = Orcs\n");
		 //}
	 //}else
	 //{
		 //printf("There are more orcs than hobbits.\n");
	 //}
	 
	 //if(hobbits+elves+dwarves > orcs){
		 //printf("Good guys outnumber bad guys.\n");
	 //}else if(hobbits+elves+dwarves < orcs){
		 //printf("Bad guys outnumber good guys.\n");
	 //}else{
		 //printf("It looks like an even fight.\n");
	 //}
	 
	 return 0;
 }
