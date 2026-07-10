/**
 * Demo 4 kirjallinen palautustehtävä.
 *
 * Tämä koettaa johdatella käymään läpi samoja kysymyksiä, joita
 * ryhmäharjoitteessa käytiin läpi kasvotusten. Tee kaikki kohdat 1-5.
 *
 * 1. Tutustu seuraavaan C#-ohjelmaan:
 *
 *     https://gitlab.jyu.fi/itka203-kurssimateriaali/itka203-kurssimateriaali-avoin/-/raw/master/clabra/esimerkki.cs
 *
 *    joko JDoodlen tai vaikka Visual Studion avulla.
 *
 *    Aiemmilla demoilla käytimme ReplIttiä, mutta sen käyttö vaatii
 *    nykyään kirjautumisen, eikä siksi ole enää mukavaa, mutta
 *    jos haluat kirjautua, esimerkki löytyy osoitteesta
 * 
 *      https://replit.com/@JonneItkonen/QuerulousImpartialStructures
 *
 * (ryhmäharjoitteessa käydään läpi seuraavat kohdat keskustellen; älä
 * hajota keskittymistä ryhmätyössä niiden parissa, vaan tarvittaessa
 * voit kerrata _myöhemmin_; vain itsenäisesti tekevien tarvitsee
 * täyttää kohdat vastaukseksi demoon)
 *
 * 2. Kirjoita vastaukset seuraaviin kysymyksiin C#-esimerkkiin
 *    liittyen. Vastausten pohtiminen ennakkoon toivottavasti
 *    helpottaa myöhempien tehtävien tekemistä:
 *
 *    Kysymys: Millainen lukujono on Fibonacci? Miten se
 *    muodostetaan?
 *    Vastaus: Fibonacci lukujono on sellainen, että on kaksi alkuarvoa 0 ja 1 joidenka jälkeiset arvot lukujonossa ovat summa kahdesta sitä aikaisemmasta luvusta. esimerkiksi 3. luku on 1, 4. = 2, 5. = 3.
 *
 *    Kysymys: Mikä tietorakenne C#-esimerkkiohjelmassa on käytössä?
 *    Vastaus: Siihen kirjoitettiin oma Luku tietue, joka hyödyntää C#:n luokkia. 
 *
 *    Kysymys: Anna esimerkki rivistä, jolla varataan muistia pinosta.
 *    Vastaus: "for (int i = 0; i < lkm; ++i)". Tässä katsoisin, että luomme primitiivityyppisen muutujan i, joka varastoidaan pinoon.
 *
 *    Kysymys: Anna esimerkki rivistä, jolla varataan muistia keosta.
 *    Vastaus: "uusi = new Luku();". Tässä katsoisin, että luomme olion, joka varastoidaan keossa.
 *
 *    Kysymys: Anna esimerkki rivistä, jolla muutetaan pinomuistissa
 *    sijaitsevaa dataa.
 *    Vastaus: "for (int i = 0; i < lkm; ++i)". Tässä korotamme i muuttujan arvoa joka kierroksella.
 *
 *    Kysymys: Anna esimerkki rivistä, jolla muutetaan kekomuistissa
 *    sijaitsevaa dataa.
 *    Vastaus: "uusi.Arvo = arvo;". Tässä muutamme olion atribuutin arvoa. 
 *
 *    Kysymys: Milloin pinosta varattu muisti vapautuu?
 *    Vastaus: For loopin loputtua se vapauttaa muuttujan i muistista.
 *
 *    Kysymys: Milloin keosta varattu muisti vapautuu?
 *    Vastaus: Muisti vapautuu kun aliohjelman ajo loppuu.
 *
 *
 *
 * 3. Tutustu tähän C-kieliseen esimerkkiohjelmaan ja vastaa
 *    seuraaviin kysymyksiin:
 *
 *    Kysymys: Mikä tietorakenne C-esimerkkiohjelmassa on käytössä?
 *    Vastaus: Struct eli struktuuri.
 *
 *    Kysymys: Anna esimerkki rivistä, jolla varataan muistia pinosta.
 *    Vastaus: "luku *uusi = NULL;". Tässä luodaan "luku", joka on struktuurina määritelty lokaali muuttuja.
 *
 *    Kysymys: Anna esimerkki rivistä, jolla varataan muistia keosta.
 *    Vastaus: "uusi = malloc(sizeof(luku));". Varataan muistia keosta malloc komennolla.
 *
 *    Kysymys: Anna esimerkki rivistä, jolla muutetaan pinomuistissa
 *    sijaitsevaa dataa.
 *    Vastaus: "luku *seuraava = lukujono->seuraava;". Luodaan "luku" ja muutetaan sen atribuutin arvoa, joka sijaitsee pinossa.
 *
 *    Kysymys: Anna esimerkki rivistä, jolla muutetaan kekomuistissa
 *    sijaitsevaa dataa.
 *    Vastaus: "uusi->arvo = arvo;". Aikaisemmin malloc on varannut muistialueen luku struktuurille ja nyt muutamme sen sisällä sijaitsevaa arvoa.
 *
 *    Kysymys: Milloin pinosta varattu muisti vapautuu?
 *    Vastaus: "free(lukujono)". Käsittääkseni tämä vapauttaa myös osoittemelle varatun muistin.  
 *
 *    Kysymys: Milloin keosta varattu muisti vapautuu?
 *    Vastaus: "free(lukujono);". Lukujono on varattu keosta. 
 *
 *    Kysymys: Selitä, miksi aliohjelmaan lisaa() viedään osoitin
 *    luku-tietueeseen.
 *    Vastaus: Tietueen atribuutti "seuraava" vaatii luku-tietueen arvokseen ja aliohjelma on toteutettu siten, että aikaisempaa lukujonoa dynaamisesti pidennetään. Jos tarkoitetaan tarkastella juuri miksi osoitin toisin kuin itse tietue niin kenties se olisi koska voimme muuttaa tietueen sisältöä viemällä vain osoitin ja palauttamalla uusi tietue.
 *
 *    Kysymys: Miksi esimerkiksi rivillä
 *
 *                 lukujono = lisaa(lukujono, 3);
 *
 *    täytyy tehdä sijoitus muuttujaan lukujono? Ts. Miksi ei olisi
 *    vain
 *
 *                 lisaa(lukujono, 3);
 *
 *    Vastaus: Ilman sijoitusta emme tallentaisi muuttujaan uutta aliohjelmassa luotua ja palautettua tietuetta.
 *
 *    Kysymys: Aliohjelman lisaa() kutsumuoto (engl. signature) on
 *
 *                luku *lisaa(luku *lukujono, int arvo);
 *
 *    Miksi se ei voisi olla
 *
 *                luku lisaa(luku *lukujono, int arvo);
 *
 *    Vastaus: Aliohjelma palauttaa osoittimen.
 *
 * 4. Tallenna tämä koodi nimelle "demo4vastaus.c" ja muokkaa tätä
 *    niin, että tämä toimii samoin kuin kohdan 1 C#-ohjelma. Voit
 *    katsoa mallia siitä sekä alkuperäisestä esimerkkikoodista.
 *
 *    HUOM 1: Sinun tulee siis muokata tätä niin, että tämä laskee
 *    Fibonaccin lukujonon ja tallentaa sen samanlaiseen
 *    tietorakenteeseen kuin mitä C#-esimerkki käyttää!
 *
 *    HUOM 2: Helpointa lienee havaita, mikä on erilaista C:llä
 *    verrattuna C#-kieleen, ja sitten kääntää mallia C-kieliseksi
 *    rivi riviltä. Lopullinen vastaus voi lopulta hyvinkin sisältä
 *    täysin saman määrän ei-kommenttirivejä kuin C#-malli. Jokainen
 *    rivi voi tehdä olennaisesti saman asian C:llä kuin mitä C#:lla
 *    tehdään.
 *
 *    HUOM 3: Kuten aina, tee pieni muutos kerrallaan ja varmistu
 *    muutoksen jälkeen, että koodi edelleen kääntyy ja toimii
 *    nykyisen oletuksen mukaisesti. Sillä tavoin ei pääse kertymään
 *    montaa uutta virhettä kerralla, jolloin korjaaminen pysyy
 *    mahdollisena!
 *
 * 5. Palauta syntynyt tiedosto "demo4vastaus.c" kommentteineen.
 *
 */


#include <stdio.h>
#include <stdlib.h>

typedef struct _luku luku;

struct _luku  {
    int arvo;
    luku *seuraava;
};

luku *lisaa(luku *lukujono, int arvo) {
    luku *uusi = NULL;
    uusi = malloc(sizeof(luku));
    uusi->arvo = arvo;
    uusi->seuraava = lukujono;
    return uusi;
}

void tyhjenna(luku *lukujono) {
    if (lukujono == NULL) return;
    luku *seuraava = lukujono->seuraava;
    free(lukujono);
    tyhjenna(seuraava);
}


int laske_summa(luku *lukujono, int summa) {
    luku *nykyinen = lukujono;
    if (nykyinen == NULL) return summa;
    return laske_summa(nykyinen->seuraava, summa+nykyinen->arvo);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Anna argumenttina tulostettavien lukujen lukumäärä, joka on >= 2.\n");
        return 1;
    }

    int lkm = atoi(argv[1]);
    lkm = lkm - 2; // Lukumäärästä pois ekat kaksi

    if (lkm < 0) {
        printf("Lukumäärän tulee olla >= 2.\n");
        return 1;
    }

    luku *lukujono = lisaa(NULL, 1);
    printf("%d\n", lukujono->arvo);
    lukujono = lisaa(lukujono, 1);
    printf("%d\n", lukujono->arvo);
    // Tässä lasket sitten C#-esimerkin mukaisesti
    // Fibonaccin luvut. Nyt on vain kovakoodattu esimerkki
    // ja lukujen summan laskeminen:
    for (int i = 0; i < lkm; ++i) {
    	lukujono = lisaa(lukujono, lukujono->arvo+lukujono->seuraava->arvo);
    	printf("%d\n", lukujono->arvo);
    }

    tyhjenna(lukujono);

    return 0;
}
