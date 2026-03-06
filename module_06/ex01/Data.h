#pragma once

typedef struct Data
{
    char key;
    int value;
    struct Data* next;
} Data;