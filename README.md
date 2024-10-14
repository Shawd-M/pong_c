# Pong Multiplayer - Projet

## Description

Ce projet consiste en la création d'un clone du célèbre jeu **Pong** avec un **support multijoueur en réseau**. Le projet est compilable sous **Debian 10 (Buster)** et utilise un **Makefile** pour gérer la compilation et la génération de l'exécutable.

L'exécutable généré sera nommé **`pong`**, et il sera capable de fonctionner à la fois en tant que client et serveur. Le jeu permet à deux joueurs de s'affronter dans une partie de Pong avec un rendu graphique.

## Fonctionnalités

- **Rendu graphique** : Le jeu propose une interface visuelle simple pour représenter le jeu de Pong.
- **Multijoueur** : Deux joueurs peuvent se connecter à la même partie pour jouer l'un contre l'autre.
- **Hébergement et connexion** : Chaque joueur peut héberger une partie ou rejoindre une partie existante avec le même exécutable.
- **Exécutable unique** : Le même fichier exécutable est utilisé pour le client et le serveur.

## Compilation et Exécution

### Compilation

Pour compiler le projet, vous devez être sous **Debian 10 (Buster)**. Assurez-vous d'avoir installé les outils de développement nécessaires, notamment `gcc` et `make`.

Pour compiler le projet, exécutez simplement la commande suivante :

```bash
make

# Joseph Dhierry