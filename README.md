# Projet ESP32 -  HAI912I 

Un projet simple pour mesurer la température et la lumière avec un petit ordinateur ESP32. Il peut contrôler une lumière LED et vous pouvez le surveiller depuis votre téléphone ou ordinateur.

## Ce que fait le projet

- Mesure la température de la pièce
- Mesure la luminosité (la quantité de lumière)
- Allume ou éteint une LED automatiquement selon les mesures
- Affiche les informations sur un petit écran
- Permet de tout contrôler depuis une page web

## Ce dont vous avez besoin

- Une carte ESP32 TTGO (avec écran)
- Un capteur de température
- Un capteur de lumière
- Une LED verte
- Quelques résistances

## Comment l'utiliser

1. Branchez les capteurs comme montré sur l'image
2. Mettez vos codes WiFi dans le fichier `config.h`
3. Téléversez le programme
4. Regardez l'écran pour voir l'adresse web
5. Ouvrez la page web pour contrôler l'appareil

## Deux modes de fonctionnement

1. Mode température : la LED s'allume quand il fait trop chaud
2. Mode lumière : la LED s'allume quand il fait trop sombre

## Pour les développeurs

La page web permet de :
- Voir les mesures en direct
- Allumer/éteindre la LED
- Changer le mode de fonctionnement
