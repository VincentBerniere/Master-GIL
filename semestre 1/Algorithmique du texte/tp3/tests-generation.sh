#!/bin/bash

# Constantes
EXEC=./genere-texte
FILES_DIR=./out

TAILLE_TEXTE=5000000

# On teste si le dossier d'export existe
if [ ! -d $FILES_DIR ]
then
  mkdir $FILES_DIR
fi

# Fichier utilisé pour la génération des mots

# Pour les 4 tailles d'alphabet différentes
for TAILLE_ALPHABET in 2 4 20 70; do
  echo "Génération du texte pour un alphabet de taille ${TAILLE_ALPHABET}..."
  $EXEC $TAILLE_TEXTE $TAILLE_ALPHABET > ${FILES_DIR}/tmp-${TAILLE_ALPHABET}.txt
done