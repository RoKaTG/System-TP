# System-TP

## Compilation
Ce projet consiste à implémenter les commandes copy et paste en C. Il permet de copier un fichier existant vers un autre fichier, et également de coller le contenu du presse-papier dans un nouveau fichier.Le projet peut être compilé en utilisant la commande `gcc` sous Linux ou macOS, ou en utilisant MinGW sous Windows. Pour compiler le projet, utilisez la commande suivante :
```bash
gcc MSILINI_Yassine.c -o copypaste
```

## Utilisation 
Une fois le projet compilé, vous pouvez exécuter la commande `copypaste` Une fois le projet compilé, vous pouvez exécuter la commande :
```bash
./copypaste -c fichier_source fichier_destination
```
Pour coller le contenu du presse-papier dans un nouveau fichier, utilisez la commande suivante :
```bash
./copypaste -p fichier_destination
```

## Exemple 
Voici un exemple d'utilisation de la commande copy et paste :
```bash
./copypaste -c fichier_source.txt fichier_destination.txt
./copypaste -p nouveau_fichier.txt
```
Dans cet exemple, le contenu du fichier `fichier_source.txt` sera copié dans le fichier `fichier_destination.txt` puis le contenu du presse-papier sera collé dans le nouveau fichier `nouveau_fichier.txt`.

Notez que le presse-papier doit contenir du texte pour que la commande paste fonctionne.
