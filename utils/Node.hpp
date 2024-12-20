#ifndef NODE_HPP
#define NODE_HPP

class Node{
    public:
        int value;
        Node* next;

        // COnstructor
        Node(int value){
            this->value = value;
            this->next = nullptr;
        }
};


#endif