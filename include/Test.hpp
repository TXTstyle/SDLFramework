#pragma once

#include "App.hpp"
#include "Container.hpp"

class Test: public App
{
private:
    Container container;
public:
    Test();
    ~Test();

    virtual void Init() override;
    virtual void Update() override;
    virtual void Shutdown() override;
};
