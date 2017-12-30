Algorithme permettant d'effectuer une transaction sur réseau peer to peer.
Definition
  NPS signifit: Noeud Physique Source,
          NPD : Noeud Physique Destination,
          NPC : Noeud Physique Courant,
          NPV : Noued Physiue Voisins,
          NVS : Noeud Virtuel Source,
          NVD : Noeud Virtuel Destination,
          NVC : Noeud Virtuel Courant.
Un noeud virtuel (agent intelligent) dispose:
  -Un protocole de cryptographie assymétrique,
  -Une table de hachage,
  -Algorithme d'envoi de requette au reseau,
  -Algorithme de diffusion d'un message a ses voisins. etc ....
NB: le protocole utilisé par le réseau pour véhiculer les méssages FREENET.


Algo:
1- NPS envoie un méssage (transaction)
2- NVS détecte le message
  1- récupère la clé publique de NPD
  2- chiffre le méssage avec la clé publique du NPD
  3- signe le message avec la clé privé du NPS
  4- envoie une requette de diffusion du message aux NPVs
3- NPV récupère le message
  1- NVC réalise un test (si NPC == NP ayant effectuer la dernière transaction)
    1- chiffre le contenu de la transaction précédente avec la clé publique du NPD
    2- ajoute le méssage qu'il a chiffré a celui qu'il a recue
    3- appel l'algorithme des mineurs pour la validation du message complet
    4- date le message valider
    5- l'enregistre
    6- emet une requette de diffusion du méssage sur le reseau
    7-diffuse le message
4- chaque NP recupère le message 
5- NPV enregistre le méssage dans la chaine des transactions
6- NVD déchiffre le méssage successivement.
    
          
