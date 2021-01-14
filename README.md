# Projet_MNT
Génération d'image en niveaux de couleur à partir d'un MNT

Pour compiler le projet :
	- Vérifier que le repertoire est composé du répertoire src, du fichier CMakeLists.txt et de l'executable build.sh
	- Executer le script build.sh : $./build.sh

Pour tester le code :
	- Aller dans le répertoire build : $cd build
	- Lancer l'executable "create_raster" suivi du path du fichier .txt contenant les données MNT et de la largeur de l'image : $./create_raster <PATH_TO_DATA_FILE> <largeur>

Une fois l'executable lancé, 3 images seront crééent : Une image de test 5x5 en PGM ASCII ; Une image en PGM ASCII du lac de Guerledan ; Une image en PGM binaire du lac de Guerledan

Les 2 images du lac ne fonctionnent pas. Je n'ai pas réussi à trouver l'origine du problème...

Je n'ai pas utilisé la librairie PROJ à cause de difficulté lors de l'installation. J'ai cependant utilisé un header WGS84toCartesian.hpp pour réaliser la projection (README_WGS84.md également dans le fichier).
