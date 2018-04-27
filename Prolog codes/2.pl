


prime(X, Y, F):-
	F =:= 0,
	write('End').

prime(X, Y, F):-
	X =:= Y,
	M is F - 1,
	N is X + 1,
	write(X),
	prime(N, 2, M).
	
prime(X,Y, F):-
	Z is X mod Y,
	X =\= Y,
	Z =:= 0,
	M is F - 1,
	N is X + 1,
	prime(N, 2, M).
	
prime(X,Y, F):-
	Z is X mod Y,
	X =\= Y,
	Z =\= 0,
	prime(X,Y+1, F).


%prime(2, 2, 10) here 10  is N
	