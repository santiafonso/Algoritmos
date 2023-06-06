
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "pqueue.h"

struct s_pqueue
{
    /*
     * COMPLETAR
     */

    unsigned int size;

    struct s_node *front;
};

struct s_node
{
    pqueue_elem elem;

    float average_grade;

    unsigned int approved_courses;

    float priority;

    struct s_node *next;
};


static float calculate_priority(float average_grade,unsigned int approved_courses)
{
    /*
     * COMPLETAR
     *
     */

    float priority = 0.5 * (average_grade/MAX_GRADE) + 0.5 * (approved_courses/TOTAL_COURSES);

    return priority;

}

static struct s_node *create_node(pqueue_elem e,float average_grade,unsigned int approved_courses)
{
    struct s_node *new_node = malloc(sizeof(struct s_node));

    float p = calculate_priority(average_grade, approved_courses);

    // Completar

    assert(new_node != NULL);
    /*
     * COMPLETAR
     */

    new_node->elem=e;

    new_node->priority=p;

    new_node->next=NULL;

    new_node->approved_courses=approved_courses;

    new_node->average_grade=average_grade;

    return new_node;
}

static struct s_node *destroy_node(struct s_node *node)
{
    assert(node != NULL);

    /*
     * COMPLETAR
     *
     */

    node->next = NULL;
    
    free(node);

    node = NULL;

    assert(node == NULL);

    return node;
}

static bool invrep(pqueue q)
{
    /*
     * COMPLETAR
     *
     */

    bool inv = (q!=NULL);

    if (inv && q->size != 0u && q->front != NULL)
    {
        
        struct s_node* p = q->front;

        unsigned int length = 1;

        while (p->next!=NULL)
        {
            
            inv = inv && p->priority >= p->next->priority ;

            p=p->next;

            length ++;

        }

        inv = inv && length == q->size;
        

    }
    
    return inv;
}

pqueue pqueue_empty(void)
{
    pqueue q = malloc(sizeof(struct s_pqueue));
    /*
     * COMPLETAR
     *
     */

    q->size = 0u;

    q->front = NULL;

    assert(invrep(q) && pqueue_is_empty(q));                     //POS: {q --> pqueue && pqueue_is_empty(q)}

    return q;
}

pqueue pqueue_enqueue(pqueue q,pqueue_elem e,float average_grade,unsigned int approved_courses)
{
    assert(invrep(q));

    struct s_node *new_node = create_node(e, average_grade, approved_courses);

    /*
     * COMPLETAR
     *
     */

    if (q == NULL){
        q->front = new_node;

        q->size = 1;
    }
    
    else{
    
        struct s_node *p; 
        struct s_node *s;

        p = q->front;

        s = NULL;

        while (p != NULL && new_node->priority <=  p->priority) {

            s = p;

            p = p->next;

        }

        new_node->next = p;

        if (s != NULL)
        {
            s->next = new_node;

        }

        else{

            q->front = new_node;

        }  

    q->size++;
    }

    assert(invrep(q) && !pqueue_is_empty(q));

return q;
}

bool pqueue_is_empty(pqueue q)
{
    /*
    * COMPLETAR
    */

  return q->front == NULL;


}


pqueue_elem pqueue_peek(pqueue q)
{
    assert(invrep(q) && !pqueue_is_empty(q));

    pqueue_elem e;

    e = q->front->elem;
    
    assert(invrep(q));

    return e;
}

float pqueue_peek_average_grade(pqueue q)
{
     /*
    * COMPLETAR
    */

    assert(invrep(q) && !pqueue_is_empty(q));

    float average;

    average = q->front->average_grade;
    
    assert(invrep(q));

    return average;

}

unsigned int pqueue_peek_approved_courses(pqueue q)
{
     /*
    * COMPLETAR
    */

    assert(invrep(q) && !pqueue_is_empty(q));

    unsigned int courses;

    courses = q->front->approved_courses;
    
    assert(invrep(q));

    return courses;
}

float pqueue_peek_priority(pqueue q)
{
     /*
    * COMPLETAR
    */

    assert(invrep(q) && !pqueue_is_empty(q));

    float priority;

    priority = q->front->priority;
    
    assert(invrep(q));

    return priority;

}

unsigned int pqueue_size(pqueue q)
{
    assert(invrep(q));

    unsigned int size = 0;
     /*
    * COMPLETAR
    */

    size=q->size;

    return size;
}

pqueue pqueue_copy(pqueue q)
{
    assert(invrep(q));
     /*
    * COMPLETAR
    */

    pqueue copy = pqueue_empty();

    struct s_node* aux;
 
    aux = q->front;

    while (aux!=NULL)
    {
        copy=pqueue_enqueue(copy,aux->elem,aux->average_grade,aux->approved_courses);

        aux=aux->next;

    }
    
    copy->size=q->size;

    return copy;

    assert(invrep(q));

}

pqueue pqueue_dequeue(pqueue q)
{
    assert(invrep(q) && !pqueue_is_empty(q));
     /*
    * COMPLETAR
    */


    assert(invrep(q) && !pqueue_is_empty(q));

    struct s_node *killme = q->front;

    q->front = q->front->next;

    killme = destroy_node(killme);

    q->size --;

    assert(invrep(q));

    return q;

}

pqueue pqueue_destroy(pqueue q)
{
     /*
    * COMPLETAR
    */

    assert(invrep(q));
    
    struct s_node *node = q->front;

    while (node != NULL) {

        struct s_node *killme = node;

        node = node->next;

        killme = destroy_node(killme);
    }

    free(q);

    q = NULL;

    assert(q == NULL);

    return q;

    assert(q == NULL);

    return q;
}

