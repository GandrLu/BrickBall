# BrickBall

### Hinweise
#### Ausführen des Projektes mit QT Creator
1. QT Creator starten und mit "Open Project" BrickBall.pro öffnen
2. Passendes Konfigurations Kit auswählen
3. "Build Project" ausführen
4. "Run" ausführen

#### Ausführen des Projektes mit Visual Studio + Qt VS Tools Extension
1. Visual Studio starten ohne ein Projekt zu öffnen "Continue without code"
2. Über "Extensions -> Qt VS Tools -> Open Qt Project File" auswaählen und BrickBall.pro öffnen
3. In der gewünschten Konfiguration den "Local Windows Debugger" starten (Qt VS Tools müssen eingerichtet sein)

#### Bedienung der Anwendung
**Mausbewegung**: Steuern des Paddles
**Beliebiger Mausklick**: Ball der auf Paddle liegt wird abgeschossen
**Escape im Spiel**: Rückkehr ins Hauptmenü

#### Bekannte Bugs / Probleme
- Beim Verlassen des Spiels ins Hauptmenü läuft das Spiel im Hintergrund weiter, Sounds sind zu hören
    - Ich wollte `m_Game` (die Game Szene) in diesem Fall deleten, leider hat das zu Fehlern geführt die ich nicht nachvollziehen konnte
    - Beim einem neuen Spiel wird die Game Szene aber überschrieben darum ist dann nicht das vorherige Spiel da (könnte natürlich auch gewollt sein).
- Der Mauscursor wird nicht in der Anwendung gefangen, falls er das Spiel verlässt (bei z.B. mehreren Monitoren) bewegt sich das Paddle nicht
    - Ich hatte erst den Cursor ausgeblendet, habe ihn jetzt eingeblendet damit man ihn besser im Spielfenster behalten kann