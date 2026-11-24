#pragma once

class Keys {
public:
    static Keys& getInstance() {
        static Keys obj;
        return obj;
    }
    bool keys[1024];
private:
    Keys(){};
};
