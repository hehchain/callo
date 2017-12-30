# PROTOCOLE DE COMMUNICATION

Dans le système de communication du réseau **SPHYX** on compte deux principales composantes :
- Le registre principal,
- Les nœuds du réseau.

On aura ainsi deux principaux type de communications entre les composantes :
- Le registre principal et un noeud,
> o	**un appel** : du noeud vers le régistre;
> o	**une réponse** : du régistre vers le noeud en réponse à l'appel;
- entre deux nœuds du réseau.
> o	**un message** : du noeud vers un autre;
> o	**un acquitement** : notification de reception d'un message;

## I.	LE REGISTRE PRINCIPALE ET UN NOEUD
Le registre principal à pour principalement pour rôle de fournir des clés de sessions aux différents nœuds qui souhaitent se connecter au réseau.

### PROCEDURE D’AUTHENTIFICATION :

-	Le nœud demande à travers une identification d’être authentifié et ajouté au réseau décentralisé ;
-	Si le registre principal valide que ce n’est pas un parasite alors il est authentifié ;
-	Une fois authentifié on retient des données sur le nœud :

> o	**IP ADDRESSE** : Pour pouvoir contacter le nœud en question ;
> o	**SESSION_ID** : qui représente une position dans le réseau ;
> o	**PRIVATE_KEY** : qui est générée à chaque attribution de SESSION_ID, et permet de chiffrer les messages ;
> o	**PUBLIC_KEY** : qui est générée pour que l’on puisse chiffrer les des données avec le nouveau nœud et qui sera visible de tous.
> o	**SERVER_PUBLIC_KEY** : est la clé publique du registre pour permettre aux nœuds authentifiés d’effectuer d’éventuelles requêtes.

### CONTRUCTION DE LA TABLE DE ROUTAGE :
![](http://cric.grenoble.cnrs.fr/Administrateurs/Documentations/SiteWebAuthentification/ListeACL.jpg)
-	Un nœud déjà authentifié émet un appel vers le serveur et empaquète les données suivantes ;

> o	 **SESSION_ID** : son identifiant dans le réseau ;
> o	**OPERATION_ID** : représentant la macro à utiliser pour l’opération de constitution de la table de routage ;

-	Ces données sont cryptées avec à la fois avec la **SERVER_PUBLIC_KEY** du serveur ;
-	Ensuite elles sont cryptées par le **PRIVATE_KEY** du nœud ;
-	Le serveur renvoie un tableau de valeurs des nœuds directement voisin et connectés :

> o	**PUBLIC_KEY** : pour pouvoir crypter ;
> o	**IP ADDRESS** : pour pouvoir contacter le nœud ;
![](https://lh5.googleusercontent.com/wNJL_sAWb4LjsTyFOIbZNhSnLCnLFxeJhDUgwasakfDq8n6gl2MdXacLPKav9SY-RyO4Is5Q3n3qZHqwzlcP=w1360-h623-rw)

## II.	ENTRE LES NŒUDS DU RESEAU

![](https://upload.wikimedia.org/wikipedia/commons/thumb/4/40/Chiffrement_asym%C3%A9trique.jpg/800px-Chiffrement_asym%C3%A9trique.jpg)
Les premières communications sont celles entre un nœud et ses voisins directs a ce moment on aurait pas besoin du registre vu que l’on a déjà cette adresse dans notre liste de routage.
La procédure générale pour la communication est la suivante :
ENVOYER UN MESSAGE :
-	Les données du message à transmettre sont :

> o	**OPERATION_ID** : Le nœud qui envoie le message doit émettre ;
> o	**OPERATION_VALUE** : La valeur du message à transmettre ;

-	Elles sont cryptées par le **PUBLIC_KEY** du nœud destinataire ; 
-	Ensuite elles sont cryptées par le **PRIVATE_KEY** du nœud ;
-	Enfin on envoie à l’**ADDRESS IP** du nœud destinataire. 

### RECEPTION DU MESSAGE :
-	Déchiffrement du message reçu avec la **PRIVATE_KEY** du récepteur ;
-	Identification de la **PUBLIC_KEY** de l’émetteur à partir de son **IP_ADDRESS** ;

> o	S’il n’existe pas au niveau de notre table locale de routage ;
> o	Faire la requête auprès du registre central 

-	Authentification du message avec le **PUBLIC_ID** de l’émetteur ;

> o	En cas d’authentification ajout du nœud dans la table de routage locale au cas ou elle n’y était pas.
> o	En cas d’échec en référer au registre principal de la potentielle intrusion du réseau avec **IP_ADDRESS** de l’émetteur.

-	Une fois le message reçu envoyer un message de confirmation de lecture à l’émetteur.
### DEMANDE DE CONNEXION : 
-	Les données du message à transmettre sont :

> o	**OPERATION_ID** : Le nœud qui envoie le message doit émettre ;
> o	**OPERATION_VALUE** : La valeur du message à transmettre ;

-	Elles sont cryptées par le **PUBLIC_KEY** du nœud destinataire ; 
-	Ensuite elles sont cryptées par le **PRIVATE_KEY** du nœud ;
-	Enfin on envoie à l’**ADDRESS IP** du nœud destinataire. 

