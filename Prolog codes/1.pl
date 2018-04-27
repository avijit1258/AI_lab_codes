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

%patter(1,1, 10). here 10 is N