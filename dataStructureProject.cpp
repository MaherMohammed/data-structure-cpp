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


int main()

{

    displayMainMenu();

    int input = 0;
    cout<<"please enter your choice: ";
    cin>>input;

    while (!(input >= 5))
    {
        if (input == 1)
        {
            
        }else if (input == 2)
        {
            stack s;
            int numberOfItems;
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
            cout<<""<<endl;
            cin.ignore();
            cout<<"hit enter to return";
            cin.get();
            
        }    

        displayMainMenu();
        cout<<"please enter your choice: ";
        cin>>input;    
        cout<<""<<endl;
    }




    

    return 0;

}