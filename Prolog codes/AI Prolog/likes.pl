%% Demo coming from http://clwww.essex.ac.uk/course/LG519/2-facts/index_18.html
%%
%% Please load this file into SWI-Prolog
%%
%% Sam's likes and dislikes in food
%%
%% Considering the following will give some practice
%% in thinking about backtracking.
%%
%% You can also run this demo online at
%% http://swish.swi-prolog.org/?code=https://github.com/SWI-Prolog/swipl-devel/raw/master/demo/likes.pl&q=likes(sam,Food).

/** <examples>
?- likes(sam,dahl).
?- likes(sam,chop_suey).
?- likes(sam,pizza).
?- likes(sam,chips).
?- likes(sam,curry).
*/

likes(sam,Food) :-
    indian(Food),
    mild(Food).

likes(sam,Food) :-
    chinese(Food).

likes(sam,Food) :-
    italian(Food).

likes(sam,chips).

indian(curry).
indian(dahl).
indian(tandoori).
indian(kurma).

mild(dahl).
mild(tandoori).
mild(kurma).

chinese(chow_mein).
chinese(chop_suey).
chinese(sweet_and_sour).
italian(pizza).
italian(spaghetti).



mother(gmother, mchild1).
father(gfather, mchild1).
mother(gmother, fchild2).
father(gfather, fchild2).

mother(fchild3, mch1).
father(mchild1, mch1).
mother(fchild3, fch2).
father(mchild1, fch2).

parent(X,Y):-
    mother(X,Y).

parent(X,Y):-
    father(X,Y).

grandparent(X,Y):-
    parent(X,Z),
    parent(Z,Y).

add(X,Y):-
    Z is X + Y,
    write(Z).

seriesadd(X,Y):-
    X =:= 0,
    write(Y).

seriesadd(X,Y):-
    Z is Y + X,
    W is X-1,
    seriesadd(W,Z).

sum(X):-
    seriesadd(X,0).

mylist([],Z):-
    write('not found').

mylist([H|T],Z):-
    H =:= Z,
    write('found').

mylist([H|T],Z):-
    mylist(T,Z).
















