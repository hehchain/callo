# SPHYX


## I. PRESENTATION



## II. TOPOLOGIE
**Sphyx** est un système distribué, constitué de plusieurs nœuds qui s’échangent des données et chacun fonctionnant de manière indépendante de sorte à ce que l’absence de l’un ne paralyse pas le réseau.
Il est donc nécessaire d’avoir une topologie de ce réseau qui ne soit ni totalement linéaire, ni totalement circulaire. 

On  peut envisager une topologie en maille.

![Reseau en maille](https://lh5.googleusercontent.com/DEk0VdITx5N1gDbCm1t9EwBn2xauPkMa6aLAENQcWKQsielkoA6Q58QhSFDQG0A7t0OdiUluDPKUTgEuDz9n=w1360-h672)
> _Figure 1 Reseau en maille_

Mais nous n’utiliserons pas toutes ces arrêtes un nœud n’a pas à connaitre tous les autres nœuds du réseau. Il faut donc un réseau qui privilégie les liaisons entre les nœuds voisins mais rendant l’accès aux nœuds éloignés possible. 

On obtient donc un réseau en hypercube. 

![Hypercube taille 4](https://lh4.googleusercontent.com/iVpaFlppqhSG-kxMB39MeAjU8hS5ZaLrlrOUXxSqy44xdpoQSluG0B8aWhJ_O9oSbsl3Y1rWtezQnLY2oY_c=w1360-h672)
> _Figure 2 Hypercube taille 4_

```
ATTRIBUT	                VALEUR
Nombre de sommets	2n
Nombre d’arrêtes	        2n-1n
Diamètre	                        n
```

## III.TOPOLOGIE TAILLE 6
![Hypercube Taille](https://lh3.googleusercontent.com/Ztxp_q_-2Ne2ZfLBosL5yOea4jlzCZFHnt-z9aiJeACyz1VMVdm01OWD6q_76hSE-G9AdfTffHwGiMvbHAOc=w1360-h672)
> _Figure 3 Hypercube Taille_

```
ATTRIBUT	VALEUR
Nombre de sommets	64
Nombre d’arrêtes	192
Diamètre	6
```

Pour chaque hypercube de taille 6 formé dans le réseau, on a un diamètre de 6 ainsi les nœuds les plus éloignés se lient en 6 sauts.

## IV. AJOUT D’UN NOEUD

![Hypercube Taille 6](https://lh4.googleusercontent.com/Gyijmw62N3lZgmjVLeGjMfJt6fHIwlnZXOh0NBsFJZVk1H6BjMOAi8XP0NFUMPC5WzzBDV6oQ-NCtuQZk9W6=w1360-h672)
> Figure 4 Hypercube Taille 6
Chaque nœud a des attributs qui maintiennent le réseau en place :

- **Un identifiant ID,**

- **Une table de routage des voisins direct.**

### 1.CONNEXION ENTRE DEUX NOEUDS

Pour qu’il existe une connexion entre deux nœuds il faut que leurs équivalents en binaire de leurs ID ne diffèrent que d’un bit.
**Exemple :** (xxx**x**, xxx**y**) ; (xyx**x**, xyx**y**).

### 2.TABLE DES VOISINS
La table des voisins est constituée de tous les nœuds connectés qui ont une connexion avec le nœud courant.
**Exemple :** XXXXX a pour voisins (**Y**XXXX, X**Y**XXX, XX**Y**XX, XXX**Y**X, XXXX**Y**)

### 3.NOMBRE DE VOISINS
Pour **un hypercube de taille n** chaque nœud doit avoir **n nœuds**.
### 4.SUPPRESSION D’UN NOEUD
Lorsqu’un nœud se déconnecte il laisse son identifiant vide et celui-ci peut être pris par un nouveau et ainsi mettre à jour la table de routage de ses n voisins.

Une fois que l’on a attribué l’identifiant et mis à jour les tables de routages des nœuds alors on obtient un hypercube équivalent au nombre de nœuds.
Et cas de déconnexion de certains nœuds l’équilibrage du réseau se fait à l’arrivée de nouveaux et non par la modification des nœuds déjà connectés.
![Hypercube taille 3](https://lh3.googleusercontent.com/1gRM9YCeAffjEQYE5PN1NzwP2BYQzVxP6SFvTTwCLFHULgbsASAwm5Hrkgg-aUIks75-jbzmpZiVJMO92syc=w1360-h672)
> _Figure 5 Hypercube taille 3_

## IV.SECURITE DU RESEAU
### 1.CONNEXION D’UN NOEUD
Pour se connecter à nœud il faut se connecter à partir du registre central avec une interface de connexion.
Une fois que ce nœud est autorisé à intégrer le groupe on lui attribut un identifiant du réseau, ainsi que sa clés privé les communications.
![interconnexion de noeuds par id](https://lh5.googleusercontent.com/5Qu0VGjddh7L3op09bn5m8UGfYbiD2CCK5vLWFbqgxUv8_ohIhkyAvc15Z1qeInFbBaSoRht4t4uTanWGPZk=w1360-h672)
> _Figure 6 interconnexion de noeuds par id_

### 2.COMMUNICATION DU RESEAU
Après la connexion la clé privée est envoyé au nœud et la clé publique est gardée au niveau de registre principale qui va rendre la clé publique disponible sur l’annuaire afin que les autre nœuds entrent en communication.  
![Systeme asymetrique](https://lh6.googleusercontent.com/LTh-oPqmPclwcMihYgAVk1WJh-2rWK1ynFBcspzFphZQ9D8tTuq3NluMb9YlURdiXQ8bChIjvuha1gxHwNiQ=w1360-h672)
> _Figure 7 Systeme asymetrique_
### 2.SECURITE REGISTRE
Lorsqu'un hôte est identifié comment valide par le registreprincipal il ya une instance qui est créée au niveau celui ci

> ID	|  PUBLIC_KEY  |	PRIVATE_KEY  | ADRESS_KEY

Ensuite pour que A se connecter à un hôte B il faudrai avoir: 

- **PUBLIC_KEY de B** fournit par le registre principal aux noeuds identifiés

- **PRIVATE_KEY de A** fournit par le registre principal au noeud A lorsde l'identification

- **ADDRESS de B** fournit par le registre principal au noeud A lorsde l'identification et la construction de sa table locale (A) de voisins.
