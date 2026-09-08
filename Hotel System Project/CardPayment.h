#pragma once
#include "Payment.h"
class CardPayment : public Payment
{
public:
    void pay(double price) override;
};
