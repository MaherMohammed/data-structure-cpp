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


class linked_list
{
    private:
    node *start; node * last;
    public:
    linked_list()
    { start=NULL; last= NULL;}
    void insert_last(int value);
    void delete_last();
    void display();
}; 



void linked_list:: insert_last(int value)
{
    node *temp=new node;
    temp->data=value;
    temp->next=NULL;
    if (start == NULL)
    {
        start=temp;
        last=temp;
    }
    else
    {
        last->next = temp;
        last = temp;
    }
}


void linked_list::delete_last()
{// list is empty
if(start==NULL) { cout<<"the list is empty" ; return;}
//only one node
    if (start->next==NULL)
    { 
        cout<<"dffd"<<endl;
        start = NULL;
        last = NULL;
        return;   
    }
//more than one node
    node *current=start;
    node *temp=last;
    while(current->next!=last)
    { current=current->next; }
    current->next=NULL;
    last=current; delete temp; 

}

void linked_list:: display()
{ if(start==NULL) {cout<<"list is empty "; return;}
// cout<<" the elements of the list are "<<endl;
node *temp=start;
while(temp!=NULL)
{
cout<<temp->data<<"\t";
temp=temp->next;
}
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
            cout<<"You have entered (" + numberOfItems << ") item (s)"<<endl;
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
            cout<<"You have entered (" + numberOfItems << ") item (s)"<<endl;
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
        else if (input == 3)
        {
            // reverse linked list using stack
            linked_list l;
            cout<<"please enter number of items you have: ";
            cin>>numberOfItems;
            cout<<"You have entered (" + numberOfItems << ") item (s)"<<endl;
            int index = 0;
            stack s1;
            //add the items to linked list
            while (index < numberOfItems)
            {
                int item;
                cout<<"please enter item number "<< index+1 << ": ";
                cin>>item;
                l.insert_last(item);
                s1.push(item);
                index++;
            }
            //reverse using stack
            //delete all items in the list then pop items from the stack to it
            index = 0;
            while (index < numberOfItems)
            {
                l.delete_last();
                index++;
            }
            index = 0;
            while (index < numberOfItems)
            {
                l.insert_last(s1.pop());
                index++;
            }

            // display
            cout<<"linked list values in reversed order"<<endl;
            l.display();

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



// cout<<"You have entered (" << 1 << ") item (s)"<<endl;
    

    return 0;

}