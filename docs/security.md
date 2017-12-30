
Protocole cryptographique pour assurer la communication entre deux noeuds

==> Diffie-Hellman :
  Dans ce cas,Deux noeuds en association peer-to-peer s'entendent sur des parametres publics globals tel que p,g(tous des entiers g<p avec p un nombre premier tres grand) et relativement chacun dispose de deux clés une privé et l'autre public ;ainsi simmulons le partage d'une clé secrete(clé de session) entre les deux noeuds :soit un Noeud A (genère une clé private x qui lui est sécrète et une clé public N1=(g^x)Mod(p)) et Noeud B (genère une clé private y qui lui est sécrète et une clé public N2=(g^y)Mod(p)) => A envoie N1 chez B et B a son tour envoie N2 chez A;chacun ayant la clé public de l'autre,pour avoir la clé de session chacun de son coté doit effectuer l'opération modulo de la clé publique du l'autre qu'il a recu en fonction de sa clé privé ie pour A calcul Key_session=(N2^x)Mod(p) et B Key_session=(N1^y)Mod(p).Ainsi les deux noeuds possède pour secrèt commun la clé de session Key_session(clé de chiffrement);Il pourons ainsi effectuer un Algorithme symétrique pour assurer le chiffrement et le déchiffrement des données;Pour ainsi assurer la confidentialité des données et de plus bénéficié de la rapidité,et la robustesse des algorithme de chiffrement/dechriffrement symetrique.Remarque il est a noter que les paramètres de communication tel que les clés privées devront etre générer en fonction des communications a un instant t et un noeud N donné pour ainsi assurer la complexité de resoudre un systeme d'equation aux Logarithme discret tres compliqer pour un adversaire (Key_session=(N2^x)Mod(p)=(((g^y)Mod(p))^x)Mod(p)=((g^(yx))Mod(p))=(((g^x)Mod(p))^y)Mod(p)=(N1^y)Mod(p)).il est a noter que chaque Noeud pourra signé ces données lors de l'envoie a travers sa propre clé privé pour assurer l'authenticité des informations partagées.
 
 ==> Elliptic curve:
   Dans ce protocole crypthographique nous nous basons sur les courbes dites elliptiques ;pour quoi elliptique ?Parce que le problème du Logarithme discrèt prononcé dans Diffie-Hellmann est effectuer sur  un Corps entier facilement demonbrables(Aux adversaires qui pouront casser la sécurite) et Bien definir de caractéristique 0.Dans cette methode,nous prenons comme ensemble des valeurs un corps mathématiques(K) de caracteristiques différent de 2 et 3 qui contient les points situé sur la courbe elliptique qui sera choisir au préalable par les deux Noeuds tout en respectant les contraintes des paramètres de base de celle-ci. En somme il faut donc comprendre qu'il suffit de reprendre l'algorithme ou le protocole de Diffie-Hellman expliquer ci-dessus, mais pas dans un corps classique plutot sur une courbe elliptique(y^2 =x^3 + ax + b :la forme d'equation) dont l'ensemble des points constitue notre univers des points qui contiennent des coordonnées qui structure les informations utilisable dans notre système.Face à cela, la complexité de la resolution du problème de logarithme discrèt devient tres complexe(ce qui nous arrange pour assurer la force de notre sécurité).Nous appelons cet Algorithme hybride entre le protocole Diffie-Hellmann et les courbes elliptiques Elliptic Curve Diffie-Hellman (ECDH).Exécution => Entre deux noeuds A et B,voici le principe: Les deux Noeuds s'entendent sur une courbe elliptique d'equation E definir sur un corps fini F tel que le Logarithme discrèt soit difficile à resoudre.Il choisissent aussi un point P situer sur La courbe E tel que le sous-groupe généré par P soit d'ordre Maximal ou de grande taille de préference un grand nombre premier,A initie la communication en choisissant un entier sécret x et envoie N1=x*P (un point de la courbe) au noeud B ;le noeud B choisir un entier sécret y et envoie N2=y*P au noeud A;le A calcul Key_session=x*N2=xyP;le noeud B de son coté calcul Key_session=y*N1=yxP.Ainsi les deux Noeuds on en commun une clé de session ou une clé sécrete qui doit leur permettre de chiffré ou déchiffré les données.Il pourront s'entendre sur une stratégie d'extraction de la clée de session dans les coordonnées  du point xyP(extrait les 512 premier bit d'un des coordonnées du point xyP et bien d'autres ....).
   
   ==> Annalyse et discussion
    Les deux approches sont tous pertinentes mais Elliptic Curve avec sa variante ECDH(Elliptic Curve Diffie-Hellman) est hybride car elle hérite des deux methodes cryptographique (Diffie-Hellman et Courbe elliptique).quel serait les avantages d'un tel cryptosysteme? Elle tient les avantages d'un cryptosysteme Assymétrique au vue de son protocole d'echange de la clé de chiffrement/Dechiffrement (Clé de session ou clé sécret commune) a utiliser dans les algorithmes(Crypto-système symétrique) qui vont assurer la confidentialité des messages.Les messages seront signé a travers les clés privées de chaque Noeud qui initie l'envoie des données.Le caractère asymétrique de EDCH resoud le problème de transport des clées de session(clé de chiffrement/dechiffrement) qu'on rencontre dans des cryptosystèmes symétrique;De plus nous pouvons utiliser le chriffrement/dechiffrement symétrique ayant a notre disposition une clé de session qui est sécret et commune au deux noeuds.Utilisant les algorithmes symétrique(cruptographie symétrique) ECDH nous donne la rapidité ,la robustesse et la simplicité de nos algorithmes de chriffrement/dechiffrement de données.

   ==> Proposition:ECDH
   En l'utilisant nous garantissons la minimalisation en complexité de nos algorithmes de chifrement/déchiffrement en question de temps d'exécution qu'en espace mémoire;de plus nous assurons la sécurité de la transmission de la clé de chifrement/déchifrement a travers le logarithme discret tres complexe a resoudre.Nous Assurons ainsi l'authentification des données avec la signature a l'aide des clés privées,l'intégrité des données avec le hachage (sha;md5;...);confidentialite a travers le chifrement du message grace a la clé de session ou clé sécret.
  Thanks you ....waiting your question and new idea to update this method....