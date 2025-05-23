/*
 * Written by 3tawi
- Lien vidéo: https://youtu.be/zPvuzV2fqaA
*/

#ifndef Play_H
#define Play_H

class Play{
public:
    char* name;
    
    virtual unsigned int playframe() {
        return 0;
    };

    virtual void start() {};
    virtual void stop() {};
};

class list : public Play {
public:
    virtual void move(int step) = 0;
    virtual int getCurrentIndex();
};


#endif
