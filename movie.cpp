//
// Created by Simon on 2020-04-17.
//

#include "movie.h"

/** Értékadás operator overloadja Movie típusra
 *
 * @param rhs A jobboldali operandus
 * @return A jobboldali operandussal megegyező tulajdonságú Movie&
 */
Movie& Movie::operator=(const Movie& rhs) {
    if (this != &rhs) {
        id = rhs.id;
        title = rhs.title;
        runningTime = rhs.runningTime;
        releaseYear = rhs.releaseYear;
        category = rhs.category;
    }
    return *this;
}

/** Egyenlőségvizsgálat-operator overloadja Movie típusra
 *
 * @param rhs A jobboldali operandus
 * @return True, ha a két film megegyezik
 */
bool Movie::operator==(const Movie& rhs) {
    if (this == &rhs)
        return true;
    else
        return title == rhs.title && runningTime == rhs.runningTime && releaseYear == rhs.releaseYear &&
               category == rhs.category;
}

/** A megadott ostreamre írja a film adatait
 *
 * @param os Az ostream, amire az adatokat írja
 * @param file Igaz, ha fájlba kell írni az adatokat
 */
void Movie::print(ostream& os, bool file) const {
    if (file)
        os << category << ';' << title << ';' << runningTime << ';' << releaseYear;
    else // TODO: konzolra tabulátorral elválasztott megy?
        os << id << '\t' << title << '\t' << runningTime << '\t' << releaseYear << '\t' << getCategoryStr();
}
