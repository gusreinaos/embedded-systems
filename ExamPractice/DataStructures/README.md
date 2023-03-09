## Data Structures

- Cuando estamos creando BSTs y queremos eliminar un elemento tenemos que fijarnos que no tengan hijos y si tienen hijos entonces tenemos que coger el mas pqueno de la derecha y sustituirlo por el nodo que queremos cambiar

- Hacer malloc(sizeof(Node)) a la memoria y free(nodo a limpiar) de cada nodo que querramos borrar

- En una linked list en la que empezamos de izquierda a derecha, la parte de la izquierda es la HEAD y la parte de la derecha es la TAIL

- Si hay que traversar podemos hacer dos cosas:
    1. Hacerlo de forma recursiva metiendo el mismo root continuamente pero actualizado
    2. General una variable la cual se va a estar actualizando con el nuevo nodo que haya que ver como por ejemplo: 
    ```
    int length() { 
    // TODO: write the code to count the number of elements in the list 
    struct node* ptr = head;
    int length = 0;
    
    //Como no podemos asignar el head a next continuamente tenemos que crear a nuevo ptr con el que traversar toda la linked list

    if (head != NULL)
    {
        while(ptr->next != NULL) {
            ptr = ptr->next;
            length++;
        }
    }
    return length; 
    } 
    ``` 
    **Aunque siempre observar como estan hechos el resto de los metodos para ver si tenemos que generar un puntero temporal o no**



