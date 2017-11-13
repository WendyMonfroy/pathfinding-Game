#           Projet de Pathfinding

##  But du Projet

Réliser un jeu mettant en œuvre un ou plusieurs algorithmes de pathfinding tel que le jeu du chat et de la souris.

Le jeu se presentera en 2D vue du dessus, le terrain sera généré aléatoirement à chaque nouvelle partie et chaque changement de niveau. Avec un maximum de 25 cases sur 25 cases.

Le joueur incarnerait donc une souris et les algorithmes de pathfinding serait appliqueé au chat (controlé donc par l’ordinateur). L’idée serait de faire chercher (si possible en temps réel) le plus court chemin du « chat » et l’adapter en fonction des déplacements de la souris.

Il y aurait sur le terrain des obstacles à éviter comme des murs ou des trous par lesquels seul la « souris » pourrait passer, éventuellement implémentés aléatoirement. Et chaque type de case aurrait un cout en deplacement different.

# Algorithmes envisgés

Bellman-Ford
Dijkstra
A*

# Démarche

On envisage d’utiliser le langage C pour coder ces algorithmes en y associant SDL2 pour l’affichage graphique.

Il est possible de gérer la recherche par des graphes ou des matrices donc nous pourrons étudier les different cas pour voir s’il y a une méthode meilleure qu’une autre ou un algorithme plus performant (dans ceux cité ci-dessus).
On pourra également, dans le jeu final, comparer l’efficacité ou la complexité des différents algorithmes en changeant celui qu’utilise le chat.
Dans une seconde partie du projet nous tenterons de créer un algorithme de pathfinding (en se basant sur un des trois algorithme ci dessus) qui prévoira les mouvements de la souris (par exemple si la souris se déplace vers un trou, le chat essayera d’en faire le tour avant qu’elle l’ait franchit)

# Jalons

On envisage ce projet en trois parties réparties de façon suivante :

- création de l’environement : génértion de la map et déplacemets de la souris
- intégration du pathfinder et test des algorithmes
- amélioration du pathfinder pour anticiper les dépacements de la souris
