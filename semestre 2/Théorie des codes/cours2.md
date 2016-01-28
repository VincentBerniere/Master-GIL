**Exemple de calcul de la suite des restes droits associée à un code**

C={ab,abcd,cdab}

R<sub>0</sub>=C<sup>-1</sup>C\{EPSILON}={cd}
R<sub>1</sub> = C<sup>-1</sup>R<sub>0</sub> U R<sub>0</sub><sup>-1</sup>C=VIDE U {ab}={ab}
R<sub>2</sub> = C<sup>-1</sup>R<sub>1</sub> U R<sub>1</sub><sup>-1</sup>C=VIDE U {EPSILON,cd}={ESPILON,cd}
R<sub>3</sub> = C<sup>-1</sup>R<sub>2</sub> U R<sub>2</sub><sup>-1</sup>C=VIDE U C = C
R<sub>4</sub> = C<sup>-1</sup>R<sub>3</sub> U R<sub>3</sub><sup>-1</sup>C=C<sup>-1</sup>C={EPSILON,cd}=R<sub>2</sub>
La suite {R1}<sub>i=0</sub> est périodique
R<sub>0</sub>-->R<sub>1</sub>-->R<sub>2</sub>-->R<sub>3</sub>

*Pb La suite des restes droits est elle toujours périodique ? (En td)*

On remarque que R<sub>1</sub> INTERSECTION C != VIDE
Cela implique qu'il existe
Un mot de C<sup>+</sup> qui admet deux factorisations différentes comme produit de mots de C.

**Preuve :** R<sub>1</sub> INTERSECTION C = {ab}. On sait que R<sub>1</sub> = ab ∈ r<sub>0</sub><sup>-1</sup>C
Donc, il existe r<sub>0</sub> ∈ R<sub>0</sub> tel que r<sub>0</sub>r<sub>1</sub> ∈ C (R<sub>0</sub><sup>-1</sup>C = {u ∈ A<sup>\*</sup>/∃ r ∈ R<sub>0</sub> : ru ∈ C})
Ce mot r<sub>0</sub> = cd. On a r<sub>0</sub>r<sub>1</sub> = cdab ∈ C
Le mot r<sub>0</sub> ∈ R<sub>0</sub> = C<sup>-1</sup>C\{EPSILON}. Cela implique qu'il existe c ∈ C tel que cr<sub>0</sub> ∈ C. On a c=ab.
On obtient (c)(r<sub>0</sub>r<sub>1</sub>) = (cr<sub>0</sub>)(r<sub>1</sub>). Le mot cr<sub>0</sub>r<sub>1</sub> = abcdab admet deux factorisations différentes comme produit de mots de C.

**Exemple :** Le code C={0,01,10} est ambigu car le mot 010 admet deux factorisation différentes comme produit de mots de C.
Cela implique qu'il existe un entier i>=0 tel que
R<sub>i</sub> INTERSECTION C != VIDE
Preuve : De (0)(10)=(01)(0) on déduit qu'il existe un mot de C qui est préfixe
d'un autre mot de C (0 est préfixe de 01)
Nous obtenons r<sub>0</sub>=1 ∈ R<sub>0</sub> = C<sup>-1</sup>C\{EPSILON}
On note c=0. On peut écrire l'égalité c(10)=cr<sub>0</sub>(0)
On obtient (10) = r<sub>0</sub>(0) ∈ C
Donc, 0 ∈ R<sub>0</sub><sup>-1</sup>CcR<sub>1</sub>
On obtient, R<sub>1</sub> INTERSECTION C != VIDE

 ## Théorème de Sardinas et Pattersons

---------------------------------------------------------------
 Soit CcA<sup>+</sup> un code fini. Alors C est uniquement déchiffrable ssi R<sub>i</sub> INTERSECTION C = VIDE, ∀ i >= 0

 ---------------------------------------------------------------

 On peut déduire de ce théorème un algorithme qui permette de tester si un code fini est uniquement déchiffrable à condition que la suite {R<sub>i</sub>}<sub>i>=0</sub> soit composée par un nombre fini d'ensemble (suite finie). (en Td)

 ## Graphe préfixe ou graphe de Sardinas et Pattersons

 On peut associer à tout code fini CcA<sub>+</sub>, un graphe orienté et étiquetté appelé graphe préfixe et note SP(C). Il est défini par SP(C) = <S,A> où

- S = Pref(C)\{EPSILON}
- A=A<sub>c</sub> U A<sub>av</sub>

Ac = {(u,EPSILON,v)|u,v ∈ S et uv ∈ C}

Ac est l'ensemble des **arcs croisés**

A<sub>av</sub> = {(u,x,v)|u,v ∈ S, x ∈ C et ux=v}

A<sub>av</sub> est l'ensemble des arcs avant.

Le graphe SP(C) permet de tester certaines propriétés de C (en autre, l'unique déchiffrabilité)

**Exemple** C = {a,bb,abbba, babab}

SP(C) = < Pref(C), A<sub>c</sub> U A<sub>av</sub> >

Pref(C) = {a,b,ab,ba,bb,abb, bab, abbb, baba, abbba, babab}

A<sub>c</sub> = {(b,EPSILON,b), (abb,EPSILON,ba), (abbb,EPSILON,a), (baba, EPSILON,b), (bab, EPSILON, ab), (ba, EPSILON, bab)}

A<sub>av</sub> = {(abbb,a,abbba),(a,bb,abb),(ab,bb,abbb),(b,a,ba),(bab,a,baba)}

## Graphe préfixe ou graphe de Sardinas et Pattersons

**Déf** Soit CcA<sup>+</sup> un code. Une **C-factorisation** d'un mot v ∈ A<sup>+</sup> est une factorisation de la forme

sx<sub>1</sub>x<sub>2</sub>...x<sub>n</sub>

où s,t ∈ Pref(C), x<sub>i</sub> ∈ C, ∀ 1 < i <= n.

**Exemple** C  {a,bb,abbba,babab}

baabbabbbaab

  **Def** Soit CcA<sup>+</sup> un code.
  Deux C-factorisations (s,x<sub>1</sub>,...,x<sub>n</sub>,t) et (s-,y<sub>1</sub>)...y<sub>m</sub>, t-), s-,t,s,t- ∈ Pref(C), x<sub>i</sub>, y<sub>j</sub> ∈ C, POURT TOUT 1<=i<=n et ∀ 1<=j<=m, sont **disjointes** ssi
  - s != s
  - sx<sub>1</sub>...x<sub>i</sub> != sy<sub>1</sub>...y<sub>j</sub>, ∀ 1<=i<=n et ∀ 1<=j<=m

** voir feuille C-factorisation disjointes/jointes **

** Lemme ** Il existe dans SP(C) un chemin de longueur n>=1 du sommet s au sommet t ssi ils existent des mots de C x<sub>1</sub>, x<sub>2</sub> , ..., < <sub>k</sub>, y<sub>1</sub>,y<sub>2</sub>,..., y<sub>l</sub> tels que

(1) sy<sub>1</sub>...y<sub>l</sub> t=x<sub>1</sub>...x<sub>k</sub>

** voir feuille **

ou

(2) sy<sub>1</sub>...y<sub>2</sub> = x<sub>1</sub>...x<sub>k</sub>- [ ]

** voir feuille **

où n=l+k et les C-factorisations sont disjointes

**Exemple** Dans le graphe préfixe de l'exemple précédent

abb -EPSILON-> ba -EPSILON-> bab -EPSILON-> ab -bb-> abbb

| abb      | babab     | abbb       |
| :------------- | :------------- |
| abbba       | babab       | bb |

l=1,k=3,n=l+k=4 (le chemin est de longueur 4)

On a toujours une égalité de type (1) quand le nombre d'arcs croisés est impair.

On considère le chemin

abb -EPSILON-> ba -EPSILON-> bab -a-> baba

| abb | babab     | a |
| :------------- | :------------- |
| abbba    | baba       |
l=2,k=1,n=l+k=3

On a une égalité de type (2) quand le nombre d'arcs croisés est pair.

Considérons maintenant le chemin

** voir feuille graphe **

Ce chemin donne l'égalité suivante

| a    | bb    | babab | abbba |
| :------------- | :------------- |
| abbba   | babab         | bb | a |
Comme s,t ∈ C, on obtient un mot de C<sup>+</sup> qui admet une double factorisation. Donc, C est ambigu.

-----------------------

**Théorème** Soit CcA<sup>+</sup> un code

C est ambigu ssi il existe dans SP(C) un chemin qui relie deux de C.

-------------------------
