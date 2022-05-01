# Rapport concernant le SAE 1.01

*Groupe :  Capelier Mathieu – Ceccarelli Luca – Hugues Mélanie – Saadi Nils – Valls Marion – Vollaire Mathis*

## Travail effectué

### Répartition des tâches :
Nous avons chacun codé un ou deux mini-jeux : Mélanie s’est occupée du morpion, Mathieu du pierre papier 
ciseaux, Nils du pile ou face et de la roulette russe, Marion du puissance 4 et Luca du mémory.
De plus, Luca et Nils ont pris en charge la réalisation du système suisse et la composition des équipes.
Marion s’est occupée de la relecture générale des codes.

### Justification des choix concernant le code :
Nous avons décidé de commenter notre code en anglais (ainsi que les noms de variables et de fonctions) car s’il 
venait à être réutilisé il serait accessible à un grand nombre de personnes.
De plus, nous avons séparés chaque mini-jeu dans un fichier .cpp auquel est associé un header afin de les 
différencier plus facilement.
Enfin, nous avons créé un fichier input.cxx qui se charge de la lecture et écriture dans les fichiers oracles. Le fichier 
main.cpp permet de lancer le programme.
De plus, nous avons passé en commentaire les parties de codes qui ne s’avèrent pas utiles lorsqu’on utilise un fichier 
oracle (notamment dans le pierre-papier-ciseaux la fonction qui cache la saisie de l’utilisateur).
