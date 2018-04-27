father(akram, jamal).
mother(rahima, jamal).

father(akram, kamal).
mother(rahima, kamal).

father(jamal, karim).
mother(rehana, karim).

father(jamal, rahim).
mother(rehana, rahim).


parent(X, Y):-
	mother(X, Y).
	
parent(X, Y):-
	father(X, Y).


grandparent(X, Z):-
	parent(Y, Z),
	parent(X, Y).
	
add2(X,Y):-
	X is 5 mod 2,
	Z is X / 2,
	Y is Z+2.
	
odd(X):-
	Y is X mod 2,
	Y =:= 1.


sum(X,Y):-
	X =:= 0,
	write(Y).

sum(X,Y):-
	Z is Y + X,
	sum(X-1,Z).
	
	
prime(X, Y):-
	X =:= Y,
	write('prime').
	
prime(X,Y):-
	Z is X mod Y,
	X =\= Y,
	Z =:= 0,
	write('not prime').
	
prime(X,Y):-
	Z is X mod Y,
	X =\= Y,
	Z =\= 0,
	prime(X,Y+1).
	
primecheck(X):-
	prime(X,2).
	
test.
	