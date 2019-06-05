Robert Schulze
Matrikelnummer 555625

# Zeitkomplexitäten für die Teilaufgaben von PVL 3

## 1. Einlesen der Datei/Kontrollausgabe:
Die erste Teilaufgabe benötigt einen Schritt, um je einen Listeneintrag für jeden virtuellen Dominostein anzulegen. Das einlesen der Elemente sowie das anlegen der Liste besitzt also eine Komplexität von $f(n) = \mathcal{O}(n)$ mit $n \hat{=}  Anzahl der Dominosteine$. 
Gleiches gilt für die Ausgabe der Liste (es ist je ein Schritt notwendig, um jeden Dominostein auszugeben): $g(n) = \mathcal{O}(n)$ Somit ergibt für sich diese Teilaufgabe eine Gesamtkomplexitätsklasse von:
$\mathcal{O}(f(n) + g(n)) = \mathcal{O}(n + n) = \mathcal{O}(n)$
