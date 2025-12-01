% Eduarda Tuboy Nardin 13732495
% Rafael Brazolin Alves Mansur 14604020

temVarinha(hermione).
temVarinha(harry).
temVassoura(harry).
jogadorQuadribol(X) :- temVassoura(X).
bruxo(X) :- temVassoura(X), temVarinha(X).
/*
1) 
a)false - Primeiro encontra a definição da  regra: bruxo(X),
depois a partir da regra ele confere se o ron tem vassoura, 
o que não esta nos fatos,  logo retorna falso.
b)false - Primeiro encontra a definição da  regra: bruxo(X), 
depois a partir da regra ele confere se a hermione tem vassoura, 
o que não está nos fatos,  logo retorna falso.
c)true - Primeiro encontra a definição da  regra: bruxo(X),
depois a partir da regra ele confere se o harry tem vassoura, 
o que está nos fatos,  então ele confere se tem varinha, o que também está nos fatos, logo retorna true.
d)Y=harry - O programa faz uma busca pelos fatos, 
buscando uma instância de uma variável que atende a todas as condições, retornando apenas  o harry.
2)
 */

classe(Numero, positivo) :- Numero > 0,!.
classe(Numero, negativo) :- Numero < 0,!.
classe(0, zero).

/*
 O programa passa pelas duas regras conferindo de a variável número é positiva ou negativa, 
se for 0 ela entra no fato zero*/

/*
3)
a) a estrutura de dados escolhida sera um grafo direcionado, e a forma de representá-lo é a seguinte matriz de adjacência
Araraquara = 	[0,0,0,0,0,0,0,1,0]
Barretos = 	[0,0,0,0,0,1,0,0,0]
Bauru = 	[0,0,0,1,0,0,0,0,0]
Botucatu = 	[0,0,0,0,0,0,0,0,1]
Franca = 	[0,0,0,0,0,0,1,0,0]
Marilia = 	[0,0,1,0,0,0,0,0,0]
Riberao Preto = [1,0,0,0,0,0,0,1,0]
São Carlos = 	[0,0,1,0,0,0,0,1,0]
Sorocaba = 	[0,0,0,0,0,0,0,0,0]
b) + c) + d)
*/

caminho(araraquara,sc).
caminho(barretos,franca).
caminho(bauru,botucatu).
caminho(botucatu,sorocaba).
caminho(franca,rb).
caminho(marilia,bauru).
caminho(rb,araraquara).
caminho(sc,bauru).


vi(X,Y):-
    caminho(X,Y);
    caminho(X,Z),
    viagemEntre(Z,Y),
    X \= Y.

viagemEntre(X,Y):-vi(X,Y);vi(Y,X).

/*
4)
*/
% aluno(nome,endereco,telefone,data_nasc,t1,p1,t2,p2,sub,rec,freq).

aluno("Carlos Silva", "Rua das Orquídeas, 32", "016966666666", "05/05/1955",
      7.5, 8.0, 6.0, 7.0, na, na, 80).

aluno("Maria Souza", "Av. das Palmeiras, 100", "011955555555", "12/09/1990",
      8.0, 7.5, 9.0, 8.5, na, na, 90).

aluno("João Pereira", "Rua das Acácias, 45", "019977777777", "23/03/1988",
      6.0, 1.0, 5.5, 4.9, na, na, 69).

aluno("Ana Costa", "Rua Central, 200", "017988888888", "30/07/1995",
      9.0, 8.5, 9.5, 9.0, na, na, 95).

aluno("Lucas Almeida", "Rua dos Pinheiros, 12", "018933333333", "15/01/1992",
      7.0, 7.5, 8.0, 7.0, na, na, 85).

aluno("Fernanda Lima", "Rua das Flores, 300", "016922222222", "10/11/1998",
      6.5, 10, 7.5, 10, 6.0, 6.5, 88).

aluno("Rafael Oliveira", "Av. Brasil, 500", "015911111111", "22/06/1985",
      10, 10, 10, 10,_,_, 10).

aluno("Beatriz Santos", "Rua Nova, 75", "017900000000", "19/08/1993",
      9.5, 9.0, 9.0, na, 8.0, na, 98).

aluno("Paulo Henrique", "Rua da Liberdade, 210", "014988888888", "07/02/1991",
      5.5,na, 6.5, 6.0,5.0,na, 72).

aluno("Juliana Mendes", "Rua Santo Antônio, 180", "013977777777", "25/04/1996",
      8.5, 10, 8.5, 10, na, na, 94).
% I

% A
mediaProvas(Nome, Media) :-
    aluno(Nome, _, _, _, _, P1, _, P2, _, _, _),
    number(P1), number(P2),
    Media is (2*P1 + 3*P2) / 5, !.

mediaProvas(Nome, Media) :-
    aluno(Nome, _, _, _, _, P1, _, _, Sub, _, _),
    number(P1), number(Sub),
    Media is (2*P1 + 3*Sub) / 5, !.

mediaProvas(Nome, Media) :-
    aluno(Nome, _, _, _, _, _, _, P2, Sub, _, _),
    number(P2), number(Sub),
    Media is (2*Sub + 3*P2) / 5.


% B
mediaTrabalho(Nome, Media) :-
    aluno(Nome, _, _, _, T1, _, T2, _, _, _, _),
    number(T1), number(T2),
    Media is (T1 + 3*T2) / 4.
% C
mediaFinal(Nome,Media) :- 
    mediaProvas(Nome,MP),
    mediaTrabalho(Nome,MT),
    Media is (MP + MT)/2.

% D
aprovado(Nome) :- 
   aluno(Nome, _, _, _, _, _, _, _, _, _, Freq),
   mediaFinal(Nome,Media),
   Media > 5,
   Freq > 70.

% II

% A
?- aluno(Nome,_,_,_,_,10,_,10,_,_,_).
/*
Nome = "Fernanda Lima"
Nome = "Rafael Oliveira"
Nome = "Juliana Mendes"
*/

% B
?- aluno(Nome,_,_,_,10,_,10,_,_,_,_).
/*
Nome = "Rafael Oliveira"
*/

% C
?- aluno(Nome,_,_,_,_,X,_,Y,_,_,_), number(X),number(Y),X < 5, Y < 5.
/*Nome = "João Pereira",
X = 1.0,
Y = 4.9
false
*/

% D
?- aluno(Nome,_,_,_,_,_,_,_,_,_,Freq), Freq < 70.
/*Freq = 69,
Nome = "João Pereira"
Freq = 10,
Nome = "Rafael Oliveira"
false
*/

% E
? - aprovado(Nome). 
/*
Nome = "Carlos Silva"
Nome = "Maria Souza"
Nome = "Ana Costa"
Nome = "Lucas Almeida"
Nome = "Fernanda Lima"
Nome = "Beatriz Santos"
Nome = "Paulo Henrique"
Nome = "Juliana Mendes"*/

% F
reprovado(Nome):-
   aluno(Nome, _, _, _, _, _, _, _, _, _, _),
   mediaFinal(Nome,Media),
   Media < 5.

reprovado(Nome):-
   aluno(Nome, _, _, _, _, _, _, _, _, _, Freq),
   Freq < 70.

?- reprovado(Nome).
% Nome = "João Pereira" ;
% Nome = "João Pereira" ;
% Nome = "Rafael Oliveira" ;
% false.

% III
% A + B + C + D + E 

% alunoMod(
%     nomeMod(Primeiro, Sobrenome),
%     enderecoMod(CEP, Rua, Numero),
%     Telefone,
%     dataNascMod(Dia, Mes, Ano),
%     T1, P1, T2, P2, Sub, Rec, Freq
% ).

alunoMod(
    nomeMod("Carlos", "Silva"),
    enderecoMod("14020-000", "Rua das Orquídeas", 32),
    "016966666666",
    dataNascMod(5, 5, 1955),
    7.5, 8.0, 6.0, 7.0, na, na, 80
).

% exemplos:
% A. ?- alunoMod(nomeMod("Carlos",Sobrenome),enderecoMod(CEP, Rua, Numero),Telefone, dataNascMod(Dia, Mes, Ano),T1,P1,T2,P2,Sub,Rec,Freq).

% B. ?- alunoMod(nomeMod(Nome,"Silva"),enderecoMod(CEP, Rua, Numero),Telefone, dataNascMod(Dia, Mes, Ano),T1,P1,T2,P2,Sub,Rec,Freq).

% C. ?- alunoMod(nomeMod(Nome,Sobrenome),enderecoMod(CEP, Rua, Numero),Telefone, dataNascMod(Dia, Mes, 1955),T1,P1,T2,P2,Sub,Rec,Freq).

% D. ?- alunoMod(nomeMod(Nome,Sobrenome),enderecoMod("14020-000", Rua, Numero),Telefone, dataNascMod(Dia, Mes, Ano),T1,P1,T2,P2,Sub,Rec,Freq).

% E. ?- alunoMod(nomeMod(Nome,Sobrenome),enderecoMod(CEP, Rua, 32),Telefone, dataNascMod(Dia, Mes, Ano),T1,P1,T2,P2,Sub,Rec,Freq).
