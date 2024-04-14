#include <iostream>

class Node{
    public:
        int value;
        Node* next;

        Node(int value){
            this->value = value;
            next = nullptr;
        }
};

class LinkedList{
    private:
        Node* head;
        Node* tail;
        int length = 0;
    public:
        LinkedList(int value){
            Node* new_node = new Node(value);
            this->head = new_node;
            this->tail = new_node;
            length++;
        }

        ~LinkedList(){
            Node* temp = head;
            while(head){
                head = head->next;
                delete temp;
                temp = head;
            };
        }

        void show_all_value(){
            if(length == 0){
                std::cout << "Empty" << std::endl;
                return;
            }
            Node* temp = head;
            while(temp){
                std::cout << temp->value << " ";
                temp = temp->next;
            }
            std::cout << "\n";
        }
        
        void show_head(){
            if(length == 0) return;
            std::cout << head->value << std::endl;
        }

        void show_tail(){
            if(length == 0) return;
            std::cout << tail->value << std::endl;
        }

        void get_length(){
            std::cout << length << std::endl;
        }

        void empty_list(){
            if(length == 0) return;
            Node* temp = head;
            while(head){
                head = head->next;
                delete temp;
                temp = head;
            }
        }

        void prepend(int value){
            Node* new_node = new Node(value);
            if(length == 0){
               this->head = new_node;
               this->tail = new_node;
            }
            else{
                new_node->next = this->head;
                this->head = new_node;
            }
            length++;
        }
        
        void append(int value){
            Node* new_node = new Node(value);
            if(length == 0){
                this->head = new_node;
                this->tail = new_node;
            }
            else{
                tail->next = new_node;
                this->tail = new_node;
            }
            length++;
        }

        void delete_first(){
            if(length == 0) return;
            Node* temp = head;
            if(length == 1){
                this->head = nullptr;
                this->tail = nullptr;
            }
            else{
                this->head = head->next;
            }
            delete  temp; 
            length--;
        }

        void delete_last(){
            if(length == 0) return;
            Node* temp = head;
            if(length  == 1){
                this->head = nullptr;
                this->tail = nullptr;
            }
            else{
                Node* prev = nullptr;
                while(temp->next){
                    prev = temp;
                    temp = temp->next;
                }
                this->tail = prev;
                tail->next = nullptr;
            }
            delete temp;
            length--;
        }

        Node* get(int index){
            if(length == 0){
                std::cout << "GET : Empty" << std::endl;
                return nullptr;
            }
            if(index < 0 || index > length-1){
                std::cout << "GET : Out of Bounds" << std::endl;
                return nullptr;
            }
            else{
                Node* temp = head;
                for(int i=0; i < index; i++){
                    temp = temp->next;
                }
                return temp;
            }
        }
        
        bool set(int index, int value){
            if(length == 0){
                std::cout << "SET : Empty" << std::endl;
                return false;
            }
            if(index < 0 || index > length-1){
                std::cout << "SET : Out Of Bounds" << std::endl;
                return false;
            }
            else{
                Node* temp = head;
                for(int i=0; i < index; i++){
                    temp = temp->next;
                }
                temp->value = value;
                return true;
            }
        }
        
        bool insert(int index, int value){

            if(index < 0 || index > length){
                std::cout << "INSERT: out of bounds " << std::endl;
                return false;
            }

            if(length == 0){
                this->append(value);
                return true;
            }

            else if(length == index){
                this->append(value);
                return true;
            }

            else{
                Node* new_node = new Node(value);
                Node* before = this->get(index - 1);
                Node* after = before->next;
                new_node->next = after;
                before->next = new_node;
            }
            length++;
            return true;
        }

        void remove(int index){
            
            if(index < 0 || index >= length){
                std::cout << "DELETE: out of bounds" << std::endl;
                return;
            }

            if(index == 0){
                this->delete_first();
            }
            
            else if(index == length-1){
                this->delete_last();
            }

            else{
                Node* before = this->get(index-1);
                Node* temp = before->next;
                before->next = temp->next;
                delete temp;
                length--;
            }

        }
};

int main(){
    LinkedList list(10);
    list.delete_first();
    list.show_all_value();
    list.append(20);
    list.append(30);
    list.prepend(10);
    list.show_all_value();
    list.delete_last();
    list.delete_last();
    list.delete_last();
    list.show_all_value();
    list.insert(0, 10);
    list.insert(1, 20);
    list.insert(2, 30);
    list.insert(3, 40);
    list.insert(4, 60);
    list.insert(4, 50);
    list.show_all_value();
    list.remove(0);
    list.remove(4);
    list.remove(1);
    list.show_all_value();
    return 0;
}
