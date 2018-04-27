


prime(X, Y, F):-
	F =:= 0,
	write('End').

prime(X, Y, F):-
	X =:= Y,
	Z \== 0,
	M is F - 1,
	N is X + 1,
	write('prime'),
	prime(N, Y, M).
	
prime(X,Y, F):-
	Z is X mod Y,
	X =\= Y,
	Z =:= 0,
	write('not prime'),
	M is F - 1,
	N is X + 1,
	prime(N, Y, M).
	
prime(X,Y, F):-
	Z is X mod Y,
	X =\= Y,
	Z =\= 0,
	prime(X,Y+1).
	





pattern(X, Y, N):-
	X =:= N,
	Y =:= N,
	write(Y).

pattern(X, Y, N):-
	X =:= Y,
	X \== N,
	write(Y),
	nl, M is X+1, S is 1, pattern(M,S,N).

pattern(X, Y, N):-
	X \== Y,
	write(Y),
	Z is Y+1,
	pattern(X,Z, N).

