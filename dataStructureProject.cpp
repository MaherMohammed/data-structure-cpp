#include<iostream>

using namespace std;


struct node
{
    int data;
    node *next;
};

class stack
{
    private: node *top;
    public:
    stack(){top=NULL;}
    

    void push(int val)
    {
        node* temp=new node;
        temp ->data = val;
        if(top==NULL)
            temp ->next =NULL;
        else
            temp ->next = top;
        top = temp;
    }

    int pop()
    { int item;
        // list is empty
        if(top==NULL){ cout<<"Stack Underflow"<<endl;}
        //only one node
        else if (top->next==NULL)
        { item=top->data; top = NULL;}//or{item=top->data; top=NULL}
        //more than one node
        else
        {
            item=top->data;
            node *temp=top;
            top=temp->next;
            delete temp;
            
        }
        
        return item;
    }

    bool isEmpty(){
        if (top == NULL)
        {
            return 1;
        }
        return 0;
        
    }

};

void displayMainMenu(){
    cout<<"1- implement stack using queue\n"<<endl;
    cout<<"2- implement queue using stack\n"<<endl;
    cout<<"3- reverse linked list items using stack\n"<<endl;
    cout<<"4- level order of BST traverse using queue\n"<<endl;
    cout<<"5- Exit\n"<<endl;
}



class queue
{
    private: node *front,*rear;
    // private: int *size;
    public:
    queue(){front=NULL;rear=NULL;}
    void enqueue(int value);
    int dequeue();
    // int size();
    // void display();
};

void queue:: enqueue (int value){
    if (rear == NULL)
    {
        rear = new node;
        rear->next = NULL;
        rear->data = value;
        front = rear;
    }
    else {
        node * temp=new node;
        temp->data = value;
        temp->next = NULL;
        rear->next = temp;
        rear = temp;
    }
}

int queue:: dequeue() //delete first in linked list
    { 
        int item;
        node * temp;
        temp = front;
        if (front == NULL)
        { cout<<"Underflow"<<endl; exit(0); }
        else if (temp->next == NULL)
        { item =front->data;
        front = NULL; rear = NULL; }
        else
        {
        item= temp->data;
        temp = temp->next;
        front = temp; }
        return item;
    }

int main()

{

    displayMainMenu();

    int input = 0;
    cout<<"please enter your choice: ";
    cin>>input;

    while (!(input >= 5))
    {
        int numberOfItems;
        if (input == 1)
        {
            //implement stack using queue
            queue q1;
            queue q2;
            cout<<"please enter number of items you have: ";
            cin>>numberOfItems;
            int saveNumber = numberOfItems;
            int index = 1;
            //fill the first queue
            while (index <= numberOfItems)
            {
                int item;
                cout<<"please enter item number ";
                cout<<index;
                cout<<": ";
                cin>>item;
                q1.enqueue(item);
                index++;
            }
            
            index = 1;
            while (index <= numberOfItems)
            {
                if (numberOfItems == index)
                {
                    q2.enqueue(q1.dequeue());
                    numberOfItems--;
                    index = 1;
                }else
                {
                    q1.enqueue(q1.dequeue());
                    index ++;
                }
            }

            index = 0;
            while (index < saveNumber)
            {
                cout<<q2.dequeue()<<endl;
                index++;
            }
            
            


        }else if (input == 2)
        {
            stack s;
            cout<<"please enter number of items you have: ";
            cin>>numberOfItems;
            int index = 1;
            while (index <= numberOfItems)
            {
                //print enter items
                int item;
                cout<<"please enter item number ";
                cout<<index;
                cout<<": ";
                cin>>item;
                //push the item to the stack
                s.push(item);
                //increase the index
                index++;
             //   cout<<index<<endl;
            }
            //initialize another stack to implement the queue
            stack outputStack;
            //push the other stack to it
            while (!s.isEmpty())
            {
                int i = s.pop();
                outputStack.push(i);
            }
            //print the outputstack as the queue
            cout<<"Queue vlaues are"<<endl;
            while (!outputStack.isEmpty())
            {
                cout<<outputStack.pop();
                cout<<" ";
            }
            
            
        }    

        cout<<""<<endl;
        cin.ignore();
        cout<<"hit enter to return";
        cin.get();
        displayMainMenu();
        cout<<"please enter your choice: ";
        cin>>input;    
        cout<<""<<endl;
    }




    

    return 0;

}