Codes à délai de déchiffrage fini
===

L'encodage des messages émis par une source par un code préfixe, permet de décoder le message reçu avant la fin de sa réception

source -> codage -> canal -> decodage -> recepteur

source : B-alphabet de source m ∈ B<sup>+</sup>

codage : A = alphabet de canal XcA<sup>+</sup> (X code) avec |X|=|B|

Codage

α : B<sup>+</sup> --> A<sup>+</sup>

 b1 --> x1
 b2 --> x2

 ...

 bn --> xn

 B = {b1,b2,...,bn}

 X = {x1,x2,...,xn}

 on ettend à un morphisme α(bi1,bi2...bik) = α(bi1)α(bi2)...α(bik)

 α = morsphisme de codage

 ##Cas d'un code préfixe

 X={a,ba,bb}

 B={b1,b2,b3}

 α(b1) = a; α(b2) = ba; α(b3) = bb

 On reçoit le début d'un message codé selon α. Par exemple ab...

 Puisque X est préfixe et a ∈ X, on sait que le message envoyé par la source commence par b1.

**On dit qu'un code préfixe est un code à délai de déchiffrage zéro.**

Cela veut dire qu'il suffit l'apparition d'un mot du code pour commence à effectuer le décodage.

*Exemple*

X={ab,abb,baab}

B={b1,b2,b3}

X n'est pas préfixe car abb ∈ X

Commence par ab ∈ X

Supposons de recevoir un message encodé par X qui commence par abb

*voir schema feuille*

Codes à délai de déchiffrage fini
===

Pour décoder un message encodé par X, l'apparition d'un mot de X ne suffit pas. Il faut atteindre l'apparition d'au plus **2** mots de X pour pouvoir décoder.

**On dit que X est un code à dékai de déchiffrage 1**

Tous les codes ne sont pas à délai de déchiffrage fini.

*Exemple*  Y={aa,b,ba}

Si le début d'un message encodé par Y est b(aa)<sup>n</sup>, on ne peut pas commencer le décodage car le message peut commencer par b ou bien par ba.

*voir schema feuille*

Dans le message b(aa)<sup>n</sup>, on a l'apparition de n+1 mots de X.

Cela veut dire, que ∀ n>=1, on ne peut pas commencer le décodage de ce message.

On est obligé d'attendre la fin du message.

*voir schema feuille*

**On dit que Y est un code à délai de déchiffrage infini ou un code sans délai**

**Définition**  Soit CcA<sup>+</sup> un code.

C est un code à délai de déchiffrage d>=0 ssi à chaque fois que le mot f=x<sub>1</sub>x<sub>2</sub>....x<sub>α+1</sub>, x<sub>i</sub> ∈ C, ∀ 1<=i<=α+1, est préfixe d'un mot g=y<sub>1</sub>...y<sub>m</sub>, y<sub>i</sub> ∈ C, ∀ 1<= j <= m alors x<sub>1</sub> = y<sub>1</sub>.

*voir schema feuille*

Autrement dit, le début de la décomposition d'un mot composé par au moins α+1 mots de C est uniquement déterminé.

On dit qu'un code C est à délai de déchiffrage fini (ddf) s'il existe un entier d >= 0 tel que C soit à délai de déchiffrage d.

**Remarque** Si un code est à délai de déchiffrage d alors il est à délai de déchiffrage k pour tout k>=d.

Le délair de déchiffrage de C est le plus petit entier d pour lequel C est à délai de déchiffrage d.

**Théorème** Soit CcA<sup>+</sup> un code ddf. Alors C est uniquement déchiffrable.

**Preuve** Supposons par l'absurde que C soit aimbigu. Soit D l'ensemble de tous les mots de C<sup>+</sup> qui admettent une double factorisation D!=∅ car C est ambigu. Soit w ∈ D

w = x<sub>1</sub>x<sub>2</sub>...x<sub>n</sub> = y<sub>1</sub>...y<sub>m</sub>,

x<sub>i</sub> ∈ C, ∀ 1<=i<=n, y<sub>j</sub> ∈ C, ∀ 1<=j<=m

( ddf | sans délai ) Codes

Soit n=d+1. Puisque C est à délai de déchiffrage d, on a x<sub>1</sub>=y<sub>1</sub>. Cela implique qu'il existe un mot de longueur strictement inférieur  à celle de w, qui admet une double factorisation.

Cela est impossible car v ∈ D est de longueur minimale.

Soit n<d+1. Soit x ∈ C et soit k un entier tel que n+k=d+1

wx<sup>k</sup> = x<sub>1</sub>...x<sub>n</sub><sup>k</sup>=y<sub>1</sub>...y<sub>m</sub>x<sup>k</sup>

Puisque C est à délai de déchiffrage fini d, on obtient x<sub>1</sub>=y<sub>1</sub>

Cela implique x<sub>1</sub>...<sub>n</sub>=y<sub>1</sub>...y<sub>m</sub>

Ce qui est impossible car w ∈ D est de longueur minimale.

**Pb** Comment savoir si un codes est ud ?

On utilise pour cela, le graphe préfixe associé au code.

**Proposition** Soit CcA<sup>+</sup> un code C est à délai de déchiffrage fini ssi dans SP(C) il n'existe aucun chemin issu d'un mot de C qui possède un circuit.

*voir schema feuille barré*

*Exemple* Z={ab,aba,bba}

SP(Z = < S,A<sub>c</sub> U A<sub>av</sub> >

S = {a,b,ab,bb,aba,bba}

A<sub>c</sub> = {(u,ɛ,v)|u,v ∈ S, uv  ∈ Z}

A<sub>c</sub> = {(a,ɛ,b),(ab,ɛ,a),(bb,ɛ,a)}

A<sub>av</sub> = ∅

*voir schema feuile*

Suite de mots associée à ce chemin {baa<sup>n</sup>}<sub>n=1</sub>

C'est une suite de mots qui prouve que Y est sans délai.

On considère que n=2k

On a : *voir feuille*
