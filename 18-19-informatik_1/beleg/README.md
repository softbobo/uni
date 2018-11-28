## Beleg für Grundlagen der Informatik 1 WS 18/19

Das Programm _beleg_ soll eine Matrix  mit teilweise vordefinierten Parametern nutzen, um verschiede Rechenoperationen damit auszuführen. Die Matrix repräsentiert eine Fliesenwand und soll als folgender eigener Datentyp implementiert werden:

```c++
struct fliese{
    float x;  /* Breite (x-Richtung) in cm */
    float y;  /* Laenge (y-Richtung) in cm */
};
```

### Eingabe:
Breite sowie Länge des Raumes sind auf __max 8m__ festgelegt, Breite und Länge der Fliesen auf __min 10 cm__. Fugen sind zu vernachlässigen. Wand- sowie Fliesengröße werde vom User festgelegt. Die Ausrichtung der Fliesen orientiert sich an der Ecke oben links. Fliesen sind entweder quasratisch. Falls sie nicht quadratisch sein sollten, beginnt jede zweite Fliesenreihe mit einer halben Fliese. Außerdem ist bei nichtquadratischen Fliesen die Breite einer Fliese (x-Achse) immer ein _ganzzahliges Vielfaches_ ihrer Länge (y-Achse).
Die Fliesen selbst kosten 0,01€/cm², wobei jedoch nur ganze Fliesen oder Pakete á 10 Fliesen erhältlich sind, die wiederum 75% der Summe des Einzelpreises der 10 Fliesen kosten.

### Ausgabe:
Zum einen soll die Matrix als graphische Repräsentation der gefliesten Wand dargestellt werden. Weiterhin benötigt wird die Gesamtzahl der benötigten Fliesen, sowie der günstigst mögliche Preis (Einzelfliesen, Pakete á 10 Stk + Rest als Einzelfliesen, nur Pakete und Rest weghauen).

### Abgabe
Lediglich die Datei _beleg.cpp_ soll, unarchiviert, über http://if-belege.informatik.tu-chemnitz.de/ bis zum 13.01.2019 hochgeladen werden. Der Zugang zu dieser URL funktioniert nur über VPN und Campusnetz. Getestet werden kann die Kompilierbarkeit per ssh unter rotuma.informatik.tu-chemnitz.de .
Die Formalen Parameter müssen zwingend eingehalten werden

Alle Informationen auch unter https://www.tu-chemnitz.de/informatik/friz/Grundl-Inf/Beleg/texte/beleg118.php