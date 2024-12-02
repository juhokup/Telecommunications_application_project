# Kiihtyvyysanturidatan suuntaluokittelu k-means-algoritmin avulla

## Projektiin osallistujat: Juho Kupila ja Jaakko Lukkari

## Kuvaus
Tässä projektissa kehitetään järjestelmä (kuva 1), jossa käytetään nRF5340-DK-kehitysalustaa, kiihtyvyysanturia, Raspberry PItä, Linux-serveriä ja K-means-algoritmia. nRF5340-DK-laite lähettää siihen kiinnitetyn kiihtyvyysanturin dataa Bluetooth-yhteydellä Raspberry Pille. Raspberry siirtää vastaanotetun datan Linux-serverillä sijaitsevaan MySQL -tietokantaan. Tietokannan vastaanottama data tallennetaan .csv-tiedostoon, jonka avulla kehitetään k-means-algoritmia hyödyntävä Python-sovellus neuroverkon luomiseksi.

## Projektin tavoite
![Tietoliikenneprojektin arkkitehtuuritaulu](https://github.com/user-attachments/assets/95631cea-6bd1-427b-b753-c2572d411573)

## Projektissa käytettävät teknologiat ja opittavat taidot

### Laitteistot ja alustat
- **nRF5340-DK**: Kiihtyvyysanturin (GY-61 ADXL335) datan, kuten kiihtyvyyden ja asennon mittaus, sekä langaton tiedonsiirto Raspberrylle 433MHz:n Bluetooth-yhteyttä käyttäen.
- **Raspberry Pi 3 model b v1.2**: Välittää nRF3540-DK:lta vastaanotettua dataa koulun verkossa olevalle MySQL-palvelimelle HTTP-protokollaa käyttäen.
- **Kannettava tietokone**: Koodin kirjoitus, tietokannan tarkkailu, etäyhteys Raspberry Pille, sekä Linux-serverille.

![nRF ja GY-61](https://github.com/juhokup/Tietoliikenteen-sovellusprojekti/blob/main/pictures/nRF%20ja%20GY-61.jpg)

### Käyttöjärjestelmät ja työkalut
- **Windows**: Windows 11 ja 10.
- **Linux**: Debian pohjainen 32-bittinen Raspberry Pi OS (uusin versio).
- **Github ja GitBash**: Projektitiedostojen kokonaisuuden hallintaan.

### Ohjelmointikielet ja kehitysympäristöt
- **Visual Studio Code**: C- ja Python-koodin kirjoittamiseen käytetty kehitysympäristö.
- **Google Colab**: Käytetään neuroverkkoluokittelijan koodin kirjoittamiseen.
- **Python**: Rasberry Pin ohjelma, joka vastaanottaa anturidataa ja vie sen tietokantaan. Koneoppimiseen liittyvät ohjelmat.
- **SQL**: MySQL-tietokanta kiihtyvyysanturin datan keräämiseen.
- **C**: nRF 5340-DK:n hyödyntämä ohjelmointikieli, jolla kerätään kiihtyvyysanturin dataa lähetettäväksi Raspberry Pille Bluetooth-yhteydellä.
- **Linux**: Rasberry:n ja Linux-serverin käyttö.

### Tietokantaohjelmistot
- **MySQL**: Itse luotu tietokanta toiselle Linux-serverin osoitteista.

### Datan analysointi ja koneoppiminen
- **Neuroverkkoluokittelija**: Käytämme k-means-algoritmia (klusterointimenetelmä) ryhmittelemään kiihtyvyysanturin x-, y- ja z-akseleiden data kuuteen klusterikeskukseen laskemalla niiden etäisyydet lähimmän klusterin satunnaisarvoon. Klusterin uusi keskipiste lasketaan sen saamien datapisteiden keskiarvolla. Datapisteiden jakoa klustereihin ja keskiarvojen laskentaa jatketaan, kunnes keskipisteissä ei havaita suuria muutoksia.

![K-means-algoritmin kohdistamat datapisteet](https://github.com/juhokup/Tietoliikenteen-sovellusprojekti/blob/main/pictures/k-means.png)

- **Konfuusiomatriisi**: Konfuusiomatriisi kertoo lajittelualgoritmin toiminnan tehokkuuden.
- **WireShark**: Laitteiden välisen liikenteen datapakettien tutkimiseen käytetty sovellus.

### Versionhallinta ja yhteistyö
- **Git ja GitHub**: Projektin tiedostokokonaisuuden ja tiedostoversioiden hallintaan.
- **Kanban-taulu**: Tehtyjen ja keskeneräisten tehtävien seurantaan.
- **Discord**: Päivittäiseen tiedon- ja tiedostojakoon.

### Viestintä
- **Discord**: Opettajan luoma Discord-kanava sekä erilliset yhteistyökanavat.
- **Sähköposti**:
- Jaakko Lukkari: t3luja00@students.oamk.fi
- Juho Kupila: t3kuju03@students.oamk.fi

![cat](https://github.com/user-attachments/assets/40d21bcd-b78e-4812-a3a4-a9b49c3251da)
