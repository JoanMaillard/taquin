# ASD Labo 9 - Rapport Taquin
Il est important de noter qu'au moment du rendu, notre solution ne fonctionne pas.

## Algorithme
Afin de rendre la représentation en graphe possible, nous avons décidé de prendre
l'approche qui nous a semblée la meilleure: une mise en oeuvre de l'algorithme A*.

Cependant, suite à un problème que nous ne parvenons pas à diagnostiquer, ainsi
que plusieurs essais infructueux de modification des structures de données utilisées,
notamment, notre algorithme semble incapable de donner des solutions aux problèmes compliqués
(plus de 4 mouvements). Cela nous rend donc incapables de répondre aux questions posées dans
le __handout__ du laboratoire.

Nous pouvons tout de même vous dire que dans le pire des cas (ou il faudrait calculer tout les états possible du puzzle) il y aurait `(n*n)!` (n carré factoriel) sommets au graphe. Dans le cas 3x3 cela représente `9! = 362880` sommets mais dans le cas 4x4 cela devient `16! =~ 2,1 * 10^13` sommets.
Sachant que chaque sommet représente un états du taquin qui est un array de array n x n donc `24 octets + n * 24 octets + n^2 * 4 octets` rien que pour stocker (sans rien d'autre) un cas; cela donne pour 3x3 `132 octets` pour un états du taquin donc `132 * 362880 = 47900160` bytes ou 47 _megabytes_ de data et dans le cas 4*4 `184 octets` donc `~3.864 * 10^15` bytes ou 3864 _**terabyte**_. 
Tout cela sans compter les liens entre les sommets ou d'autre data à l'interieur des sommets concerné ce qui rajoute du coût à la mémoire. Le pire cas ne doit donc jamais arrivé il faut donc que le code cherche la solution de façon inteligente (en utilisnat un score représentant à quel point un état du taquin est proche de la solution) et non à tâton dans toutes les "directions" possible.
