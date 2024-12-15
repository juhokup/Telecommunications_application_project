# Kiihtyvyysanturidatan suuntaluokittelu k-means-algoritmin avulla

## Projektiin osallistujat: Juho Kupila ja Jaakko Lukkari

## Kuvaus
Tässä projektissa kehitetään järjestelmä, jossa käytetään nRF5340-DK-kehitysalustaa, kiihtyvyysanturia, Raspberry PItä, Linux-serveriä ja K-means-algoritmia. nRF5340-DK-laite lähettää siihen kiinnitetyn kiihtyvyysanturin dataa Bluetooth-yhteydellä Raspberry Pille. Raspberry siirtää vastaanotetun datan Linux-serverillä sijaitsevaan MySQL -tietokantaan. Tietokannan vastaanottama data tallennetaan .csv-tiedostoon, jonka avulla kehitetään k-means-algoritmia hyödyntävä Python-sovellus neuroverkon luomiseksi.

## Projektin tavoite
<img src="https://github.com/juhokup/Tietoliikenteen-sovellusprojekti/blob/c8e41dba9452d5bc8dad92ff05780554995899ef/Projektin%20muut%20tiedostot/arkkitehtuuritaulu.jpeg" width="400">

## Projektissa käytettävät teknologiat ja opittavat taidot

### Laitteistot ja alustat
- **nRF5340-DK**: Kiihtyvyysanturin (GY-61 ADXL335) datan, kuten kiihtyvyyden ja asennon mittaus, sekä langaton tiedonsiirto Raspberrylle 433MHz:n Bluetooth-yhteyttä käyttäen.

<img src="https://github.com/juhokup/Tietoliikenteen-sovellusprojekti/blob/c8e41dba9452d5bc8dad92ff05780554995899ef/Projektin%20muut%20tiedostot/nRF%20ja%20GY-61.jpg" width="400">

- **Raspberry Pi 3 model b v1.2**: Välittää nRF3540-DK:lta vastaanotettua dataa koulun verkossa olevalle MySQL-palvelimelle HTTP-protokollaa käyttäen.
- **Kannettava tietokone**: Koodin kirjoitus, tietokannan tarkkailu, etäyhteys Raspberry Pille, sekä Linux-serverille.

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
- **K-means algoritmi**: Käytämme k-means-algoritmia (kuva 3) ryhmittelemään kiihtyvyysanturin x-, y- ja z-akseleiden data kuuteen klusterikeskukseen laskemalla niiden etäisyydet lähimmän klusterin satunnaisarvoon. Klusterin uusi keskipiste lasketaan sen saamien datapisteiden keskiarvolla. Datapisteiden jakoa klustereihin ja keskiarvojen laskentaa jatketaan, kunnes keskipisteissä ei havaita suuria muutoksia.
  
- **Neuroverkkoluokittelija**: Luokittelee mittausdatan kahden Dense-kerroksen avulla oikeaan luokkaan lisäämällä siihen neuroverkon kertoimet. Lopputuloksena on todennäköisyys lukemat jokaiselle suunnalle.  Vaihtoehtoinen tapa luokitella mittausdata K-means algoritmin lisäksi.

<img src="https://github.com/juhokup/Tietoliikenteen-sovellusprojekti/blob/c8e41dba9452d5bc8dad92ff05780554995899ef/Projektin%20muut%20tiedostot/k-means.png" width="400">

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
