#include "builder.hpp"

int main() {
    Pen *pen = new Pen();
    Graphics *graphics = new Graphics();
    PersonThinBuilder *thin = new PersonThinBuilder(pen, graphics);
    PersonDirector *director = new PersonDirector(thin);
    director->CreatePerson();

    PersonFatBuilder *fat = new PersonFatBuilder(pen, graphics);
    director = new PersonDirector(fat);
    director->CreatePerson();

    delete pen;
    delete graphics;
    delete director;
    return 0;
}