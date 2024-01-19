#include <iostream>

class Item {
public:
    virtual std::string getName() const = 0;
    virtual int getQuantity() const = 0;
};

class Money : public Item {
public:
    Money(const std::string& currency, double amount): currency_(currency), amount_(amount) {}

    std::string getName() const override {
        return currency_;
    }

    int getQuantity() const override {
        return static_cast<int>(amount_);
    }

private:
    std::string currency_;
    double amount_;
};

class Toy : public Item {
public:
    Toy(const std::string& name, int quantity): name_(name), quantity_(quantity) {}

    std::string getName() const override {
        return name_;
    }

    int getQuantity() const override {
        return quantity_;
    }

private:
    std::string name_;
    int quantity_;
};

class Collar : public Item {
public:
    Collar(const std::string& name, int quantity): name_(name), quantity_(quantity) {}

    std::string getName() const override {
        return name_;
    }

    int getQuantity() const override {
        return quantity_;
    }

private:
    std::string name_;
    int quantity_;
};





