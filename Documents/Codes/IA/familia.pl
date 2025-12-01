% Fatos
fem(lucia).
fem(eduarda).
fem(laura).
fem(isaura).
fem(maria).
fem(dejanira).
fem(aparecida).
fem(leonilda).

masc(luizCarlos).
masc(marcel).
masc(ze).
masc(natalin).
masc(albino).

genitor(lucia,eduarda).
genitor(lucia,laura).
genitor(luizCarlos,eduarda).
genitor(luizCarlos,laura).

genitor(isaura,lucia).
genitor(isaura,aparecida).
genitor(albino,lucia).
genitor(albino,aparecida).

genitor(dejanira,luizCarlos).
genitor(dejanira,leonilda).
genitor(natalin,luizCarlos).
genitor(natalin,leonilda).
genitor(dejanira,ze).
genitor(natalin,ze).

casal(lucia,luizCarlos).
casal(isaura,albino).
casal(dejanira,natalin).
casal(aparecida,marcel).
casal(maria,ze).

% Regras
mae(X,Y):-genitor(X,Y),fem(X).
pai(X,Y):-genitor(X,Y),masc(X).
avo(W,Z):-pai(W,X),genitor(X,Z). % avô
avoh(W,Z):-mae(W,X),genitor(X,Z). % avó
ir(X,Y):-genitor(Z,X),genitor(Z,Y),X\=Y.
irmaos(X,Y):-ir(X,Y);ir(Y,X).
tio(X,W):-irmaos(X,Y),genitor(Y,W),masc(X). % tio irmão do pai ou da mãe
tio(X,W):-casados(X,Y),irmaos(Y,Z),genitor(Z,W). % tio por casamento
tia(X,W):-irmaos(X,Y),genitor(Y,W),fem(X). % tia irmã do pai ou da mãe
tia(X,W):-casados(X,Y),irmaos(Y,Z),genitor(Z,W). % tia por casamento
casados(X,Y):-casal(X,Y);casal(Y,X).