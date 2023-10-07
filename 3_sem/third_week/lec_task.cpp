#include <random>
class Dice {
public:
    Dice(unsigned max, unsigned seed): reng(seed), dstr(1, max) { }

    virtual unsigned choice() const {
        return dstr(reng);
    }

private:
    mutable std::default_random_engine reng;
    mutable std::uniform_int_distribution<unsigned> dstr;
};
#include <random>
#include <algorithm>
class DiceWithBonus : public Dice {
public:
    DiceWithBonus(unsigned max, unsigned seed) : Dice(max, seed), max(max) {}

    unsigned choice() const {
        return std::min(max, Dice::choice() + 1);
    }
private:
    unsigned const max;
};