#ifndef ANIMALDOG_H
#define ANIMALDOG_H

#include "animal.h"

G_BEGIN_DECLS


#define ANIMAL_TYPE_DOG animal_dog_get_type()
G_DECLARE_DERIVABLE_TYPE(AnimalDog,animal_dog,ANIMAL,DOG,BaseAnimal)


struct _AnimalDogClass{
    BaseAnimalClass parent_class;
};


AnimalDog* animal_dog_new();

G_END_DECLS

#endif // ANIMALDOG_H
