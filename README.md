# Tietoliikenteen sovellusprojekti 2024 syksy

## Projektiin osallistujat: Juho Kupila ja Jaakko Lukkari

## Kuvaus
Tässä projektissa kehitetään järjestelmä, jossa käytetään nRF5340 kehitysalustaa, Kiihtyvyysanturia, Raspberry PItä, sekä Linux-serveriä.
nRF5340-DK -laite lähettää siihen kiinnitetyn kiihtyvyysanturin dataa bluetooth yhteydellä Rasberry Pi:lle. Rasberry siirtää vastaanotetun datan Linux-serverillä sijaitsevaan MySQL -tietokantaan.

#### Projektin tavoite
![Tietoliikenneprojektin arkkitehtuuritaulu](https://github.com/user-attachments/assets/95631cea-6bd1-427b-b753-c2572d411573)


## Projektissa käytettävät teknologiat ja opittavat taidot

### Laitteistot ja alustat
- **nRF5340-DK**: Kiihtyvyysnturin (GY-61 ADXL335) datan, kuten kiihtyvyyden ja asennon mittaus, sekä langaton tiedonsiirto Rasberrylle 433Mhz Bluetooth yhteyttä käyttäen.
- **Raspberry Pi 3 model b v1.2**: Välittää nRF3540-DK:lta vastaanotettua dataa koulun verkossa olevalle MySQL palvelimelle HTTP-protokollaa käyttäen.
- **Kannettava tietokone**: Koodin kirjoitus, tietokannan tarkkailu, etäyhteys Rasbery Pi:lle, sekä Linux-serverille.

### Käyttöjärjestelmät ja työkalut
- **Windows**: Windows 11 ja 10.
- **Linux**: Debian pohjainen 32bit Raspberry Pi OS (uusin versio).
- **Github ja GitBash**

### Ohjelmointikielet ja kehitysympäristöt
- **Python**: Rasberry pi:n clientti joka vastaanottaa anturidataa ja vie sen tietokantaan. + Koneoppiminen.
- **SQL**: MySQL tietokanta kiihtyvyysanturin datan keräämiseen.
- **C**: nRF 5349-DK:n hyödyntämä ohjelmointikieli.
- **Linux**: Rasberry:n ja Linux-serverin käyttö.

### Tietokantaohjelmistot
- **MySQL**: Itse luotu tietokanta toiselle Linux-serverin osoitteista.

### Datan analysointi ja koneoppiminen
- **Käytetty algoritmi....... k-means??? tai joku vastaava**
- **WireShark**: Liikenteen tutkimiseen.

### Versionhallinta ja yhteistyö
- **Git ja GitHub**: Tiedostokokonaisuuden hallintaan.
- **Kanban-taulu**: Tehtyjen ja keskeneräisten tehtävien seurantaan.
- **Discord**: Päivittäinen tiedon - ja keskeneräisten tiedostojen jako.

### Viestintä
- **Discord**: Opettajan luoma Discord-kanava, sekä erilliset yhteistyökanavat.
- **Sähköposti**:
- Jaakko Lukkari: t3luja00@students.oamk.fi
- Juho Kupila: t3kuju03@students.oamk.fi

![cat](https://github.com/user-attachments/assets/40d21bcd-b78e-4812-a3a4-a9b49c3251da)
