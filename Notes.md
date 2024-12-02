# Notes cours théorique *LoRa*

## Intro

LoRa: couche physique
LoRaWAN: protocole

Il existe un serveur public : TTN ("The Things Network")
Afficher les données:
- Site en html
- Plateforme d'affichage existantes (par ex: DataKey)
>Invention française (avec SigFox)


ZigBee: populaire pour la domotique (systèmes alarmes, ...)

LPWAN: Pow Power Wide Area Network

SigFox et LoRa:
- Faibles débits
- Grande portée
- 


**SigFox** est un opérateur. Des antennes ont étées installées à certains endroits dans le monde. Il permet de **Roaming**.

**LoRa**: seulement quelques antennes en France et en Belgique. Contrairement à SigFox c'est libre de droits. On peut acheter le matos et setup son propre réseau **privé**.


Les deux utilisent une bande SubGigaHertz

SigFox: modulation ultra narrow band (permet d'être toujours au dessus du bruit)
LoRa: modulation large bande, étalement du spectre

>**LTE-M (Long Term Evolution - Mobile)**: Avantage avec le NB-IoT: les antennes GSM sont déjà là, on peut avoir une couverture mondiale. L'itinérance est donc possible. Toutefois le LoRa et SigFox sont plus opti pour des faibles consommations.

Avec la 5G on est sous la ms en temps de latence: ~temps réel

LoRa et SigFox peu adaptés au retour d'information.



## LoRa

>Contraintes de consommation fortes, faible débit, pas de contrainte de retour

Donnée codée en NRZ: Non retour à zéro.\
Emetteur et recepteur doivent êtres bien synchronisés.

Paquets entre 7 et 12 bits

>SF = Spreading Factor ( nombre de bits  par symbole ) de 7 à 12\
SF7: débit élevé mais portée la plus faible.\
SF12: débit le plus faible mais portée la plus grande (env 15km)\
LoRa propose une adaptation automatique du SF

>**A retenir**: lien débit / portée

>**BW**: Band Width (largeur de bande)


Bonne réception considrée jusqu'à -100dBm.\
Pour décoder il faut que la puissance reçue (RSSI) soit supérieure à la sensibilité du récepteur (puissance reçue min).




Le préambule permet de synchroniser émetteur et récepteur.

### Quizz

13 + 2 - 60 + 2v = -43 > -60dBm -> on reçoit

Bilan de laison: $P_E - P_R = P_{pertes}$ le tout en dBm:\
13 + 43 = 56

Bilan de liaison max du LoRa: 14 (log de 25mW: puissance d'émission max) + 148 = 162 dBm

SF7; BW=125kHz; CR=4/5\
Débit brut: $SF*\frac{BW}{2^{SF}}*CR = 7*\frac{125 000}{2^{7}}*4/5 = 5469 bauds$\
Avec SF12: 293 bauds



Periode minimale ? : on a le droit d'émettre que 1% du temps. Time on air: 25,86ms, 99% -> 2,5s. Avec un peu de marge on peut émettre toute les 3 secondes.



Combien de transmissions simultannées peut-on faire ?: 6 canaux et 8 SF: 48 trames. Avec un multiplexage temporel (on décale les émissions sur la période d'émission: x100): on peut avoir 4800 capteurs différents.



>Protocole père: ALOHA (ancien et très basique)



## LoRaWAN

- Classe A: plus économe, 2 slots de downlink
- Classe C: on est toujours à l'écoute entre deux uplink. On à l'avantage de pouvoir faire un downlink sans avoir de uplink auparavant

>**Beacon** : signal émis par le GateWay pour synchroniser 


SF et puissance d'émission de départ sont fixés dans le programme

>**MIC** : Message Integrity Control


Toujours valider le Frame Counter dans l'application.


Partage des clefs de chiffrage entre capteur et Serveur. best: OTAA.
Stocker le compteur en mémoire non volatile.

Dans le serveur: option de non prise en compte du compteur de frame pour la période de mise au point.



### Quizz

Avantage: LoRa est le réseau qui consomme le moins

La passerelle: elle fait l'interface avec internet

freq: 868mHz

pour équilibrer la portée et la conso: SF. Adaptatif avec le flag ADR (Adaptative Data Rate)

Mode d'activation: OTAA

Bit ADR: adaptative data rate. Pour mettre a jour le SF

Classe B
