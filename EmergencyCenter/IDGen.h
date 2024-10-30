#ifndef IDGEN_H
#define IDGEN_H

class IDGenerator {
private:

    // Private constructor
    IDGenerator() {}


    // Disable copy constructor and assignment operator
    // Singletons should not be cloneable or assignable
    // IDGenerator(const IDGenerator&) = delete; // same as IDGenerator(const IDGenerator& obj) = delete; // Disable copy constructor
    IDGenerator(const IDGenerator& obj) = delete; // Disable copy constructor
    /*e.g. we cannot use "IDGenerator singleton3 = singleton1;"*/

    IDGenerator& operator=(const IDGenerator&) = delete;
    /*e.g. singleton2 = singleton1;   is not working*/

    // static ID counter, ensure thread safety
    static int currentId;




public:
    // get singleton instance
    static IDGenerator& getInstance() {
        //Magic Static, compare to Double-Checked Locking
        // magic static will return a same ref, while DCL returns a same ptr
        static IDGenerator instance;
        return instance;
    }

    // // Static method to get the Singleton instance   Double-Checked Locking
    // static Singleton* getInstance() {
    //     if (instancePtr == nullptr) {
    //         lock_guard<mutex> lock(mtx);
    //         if (instancePtr == nullptr) {
    //             instancePtr = new Singleton();
    //         }
    //     }
    //     return instancePtr;
    // }

    // generate new ID
    int generateID() {
        return ++currentId;
    }
};

#endif // IDGEN_H
