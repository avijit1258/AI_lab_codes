% loop

countdown(X) :-
number(X),
X < 0.


countdown(X):-
number(X),
X >= 0,
write(X), nl,
NX is X - 1,
countdown(NX).


even(X) :-
number(X),
X < 0.


even(X):-
number(X),
X >= 0,
NX is X - 1,
Z is X mod 2,
Z =:= 0,
write(X), nl,
even(NX).

even(X):-
number(X),
X >= 0,
NX is X - 1,
even(NX).



fibonacci(1, 1).
fibonacci(2, 1).
fibonacci(M, N) :-
M > 2,
M1 is M - 1, fibonacci(M1, N1),
M2 is M - 2, fibonacci(M2, N2),
N is N1 + N2, write(M), nl, write(N), nl.
%for calling fibonacci(10, F) result is 55


max(A, B, A):- A >= B.
max(A, B, B):- A < B.

%max(100, 200, X)

min(A, B, A):- A < B.
min(A, B, B):- A >= B.

maxlist([],Z):-
    write(Z).

maxlist([H|T],Z):-
	H > Z,
    N is H,
    maxlist(T,N).

maxlist([H|T],Z):-   
    maxlist(T,Z).
%maxlist([1,3,2], -10).





