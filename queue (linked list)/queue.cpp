#include "queue.h"
#include <iostream>

/* Copy constructor
A queue is initialized using the queue() constructor.
If the queue passed as a parameter is not empty, 
then its nodes are copied into the newly created queue.
The push function takes care of queue_size */
queue::queue(const queue &q) : queue()
{

    if (q.front != nullptr)
    {
        // node_to_copy points to the node
        // whose value is to be pushed into the current queue
        node *node_to_copy = q.front;

        while (node_to_copy)
        {
            push(node_to_copy->value);
            node_to_copy = node_to_copy->next;
        }
    }
}

/* Initializer list constructor
A queue is initialized using the queue() constructor.
An iterator is used to push values of all of the ilist
elements into the queue */
queue::queue(std::initializer_list<int> ilist) : queue()
{

    // ilist_element is an iterator pointing to ilist elements
    auto ilist_element = ilist.begin();

    for (size_t i = 0; i < ilist.size(); ++i)
    {
        // pushes a value pointed to by the iterator
        push(*ilist_element);
        // ilist_element is set to point to the next ilist element
        ++ilist_element;
    }
}

/* Copy assignment
Changes the current queue so that its content is identical
to the content of the queue passed as a parameter. If the
size of the current queue is changed, the push function
takes care of it */
queue &queue::operator=(const queue &q)
{

    // if the current object is passed (self-assignment), no action is needed
    if (this != &q)
    {
        if (queue_size != q.queue_size)
        {
            // If the queues are of different sizes, the current queue is
            // cleared, and copies of nodes of the queue passed as a
            // parameter are added one by one to the current queue.
            clear();
            // node_to_copy points to the node of the passed queue
            // whose value is to be pushed into the current queue
            node *node_to_copy = q.front;

            while (node_to_copy)
            {
                push(node_to_copy->value);
                node_to_copy = node_to_copy->next;
            }
        }
        else
        {
            // Otherwise, only the values of the nodes in the
            // current queue are changed

            // current_node points to the node of the current queue
            // whose value is to be changed
            node *current_node = front;
            // node_to_copy points to the node of the passed queue
            // whose value is to be pushed to the current queue
            node *node_to_copy = q.front;

            while (current_node)
            {
                current_node->value = node_to_copy->value;
                current_node = current_node->next;
                node_to_copy = node_to_copy->next;
            }
        }
    }
    return *this;
}

/* Inserts an item at the back of the queue */
void queue::push(int val)
{
    node *new_back = new node(val);

    if (!front)
    {
        // If the queue is empty, the only item is
        // inserted as both front and back
        front = new_back;
        back = new_back;
    }
    else
    {
        // Otherwise, the new item is added
        // as the next of the current back node
        // and back is set to point to the new node
        back->next = new_back;
        back = new_back;
    }

    queue_size++;
}

/* Returns the value of the front-most item of the queue;
throws an exception if the queue is empty */
int queue::peek() const
{
    if (empty())
        throw std::invalid_argument("peek() : Queue is empty!");

    return front->value;
}

/* Removes the front-most item from the queue,
throws an exception if the queue is empty. */
void queue::pop()
{
    if (empty())
        throw std::invalid_argument("pop() : Queue is empty!");

    if (!front->next)
    {
        // If the next item after the front is nullptr,
        // the queue consists of only one item. It is deleted
        // and front and back pointers are set to nullptr.
        delete front;
        front = nullptr;
        back = nullptr;
    }
    else
    {
        // Otherwise, the memory front points to is cleared and
        // front is set to point to the next item in the queue
        node *old_front = front;
        front = front->next;
        delete old_front;
        old_front = nullptr;
    }

    queue_size--;
}

/* The queue is cleared by popping all of its items */
void queue::clear()
{
    while (front)
        pop();
}

size_t queue::size() const
{
    return queue_size;
}

bool queue::empty() const
{
    return !front;
}

/* Destructor
Deallocates the nodes in a queue, if any */
queue::~queue()
{

    // If the queue is empty, no action is needed since
    // it does not have nodes to deallocate
    // (its front and back are set to nullptr).
    // Otherwise, it is cleared to delete the nodes.
    // In addition, clear() resets front, back and queue_size */
    if (!empty())
    {
        clear();
    }
}