#include <iostream>

template <typename T> class List;

template <typename T>
class Node {
private:
    T val; 
    Node* next;
    Node* prev;
    friend class List<T>;
public:
    Node(T val): val(val), next(nullptr), prev(nullptr) {}
    T getVal(){
        return val; 
    }
};


template <typename T>
class List {
private:
    Node<T>* root;
    Node<T>* end;
    int size;
public:
    List(T val):size(1){
        root = new Node<T> (val);
        end = root;
    }
    Node<T>* getRoot(){
        return root;
    }
    Node<T>* getEnd(){
        return end;
    }
    int getSize(){
        return size;
    }

    void push_back(T val){
        size+=1;
        if (end){
            end->next = new Node<T> (val);
            end->next->prev = end;    
            end = end->next;
        }
        else{
            root = new Node<T> (val);
            end = root;
        }
    }
     void push_front(T val){
         size+=1;
        if (root){
            root->prev = new Node<T> (val);
            root->prev->next = root;    
            root = root->prev;
        }
        else{
            root = new Node<T> (val);
            end = root;
        }
    }
    void insert(T val, int index){
        if (index < 0 || index > size-1){
            std::cerr << "Index out of bound" <<'\n';
        }
        else {
            if (index == 0){
                push_front(val);
            }
            else if (index == size-1){
                push_back(val);
            }
            else if (index < size/2){
                Node<T>* holder = root;
                while (index){
                    holder = holder->next;
                    index-=1;
                }
                if (auto holdprev = holder->prev){
                    holder->prev->next = new Node<T> (val);
                    holder->prev = holder->prev->next;
                    holder->prev->next = holder;
                    holder->prev->prev = holdprev;
                }
                size+=1;
            }
            else{
                Node<T>* holder = end;
                while (size-1-index){
                    holder = holder->prev;
                    index+=1;
                }
                if (auto holdprev = holder->prev){
                    holder->prev->next = new Node<T> (val);
                    holder->prev = holder->prev->next;
                    holder->prev->next = holder;
                    holder->prev->prev = holdprev;
                }
                size+=1;
            }
        }
    }

    void pop_front(){
        if (size){
            size-=1;
            Node<T>* holder = root;
            root = root->next;
            root->prev = nullptr;
            delete holder;
        }
    }

    void pop_back(){
         if (size){
             size-=1;
             Node<T>* holder = end;
             end = end->prev;
             end->next = nullptr;
             delete holder;
        }
    }

    void deleteAt(int index){
         if (index < 0 || index > size-1){
            std::cerr << "Index out of bound" <<'\n';
        }
        else {
            if (index == 0){
                pop_front();
            }
            else if (index == size-1){
                pop_back();
            }
            else if (index < size/2){
                Node<T>* holder = root;
                while (index){
                    holder = holder->next;
                    index-=1;
                }
                holder->prev->next = holder->next;
                holder->next->prev = holder->prev;
                delete holder;
                size-=1;
            }
            else{
                Node<T>* holder = end;
                while (size-1-index){
                    holder = holder->prev;
                    index+=1;
                }
                holder->prev->next = holder->next;
                holder->next->prev = holder->prev;
                delete holder;
                size+=1;
            }
        }

    }

};

int main() {
    List<int> l (2); 
    l.push_back(3); 
    l.push_back(4); 
    l.push_back(5);
    l.push_front(1);
    l.insert(40,0);
    l.insert(50,0);
    l.insert(60,0);
    l.insert(400,7);
    //l.pop_back();
    //l.deleteAt(l.getSize()-1);
    std::cout << l.getEnd()->getVal() << '\n';
    return 0;


}
