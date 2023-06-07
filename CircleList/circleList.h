#ifndef CIRCLE_H
#define CICRLE_H

typedef int data_type;
typedef struct CircleFL CircleFL;

CircleFL* circle_fl_create();
void circle_fl_push_front(CircleFL *circle, data_type value);
data_type circle_fl_pop_back(CircleFL *circle);
void circle_fl_print(CircleFL *circle, void (*print_fn)(data_type));
int circle_fl_isEmpty(CircleFL *circle);
void circle_fl_destroy(CircleFL *circle);

#endif