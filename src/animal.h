#ifndef ANIMAL_H
#define ANIMAL_H

#include <glib-object.h>

G_BEGIN_DECLS

#define BASE_TYPE_ANIMAL base_animal_get_type()
G_DECLARE_DERIVABLE_TYPE(BaseAnimal,base_animal,BASE,ANIMAL,GObject)


struct _BaseAnimalClass{
    GObjectClass parent_class;

    /* signals */
    void (*hungry)(BaseAnimal* base);

    /* overwrite */
    void (*say)(BaseAnimal* base);
};

BaseAnimal* base_animal_new();


// test
void base_animal_hungry(BaseAnimal* base);

G_END_DECLS

#endif // ANIMAL_H
