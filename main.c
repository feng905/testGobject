#include <stdio.h>

#include "src/animal.h"
#include "src/animal-dog.h"

static void hungry(BaseAnimal* base,gpointer priv){
    char* name;
    g_object_get(base,"name",&name,NULL);
    g_printerr("main->hungry name:%s\n",name);
}

int main()
{
    g_printerr("Hello World!\n");

    // test 1
//    BaseAnimal* animal = base_animal_new();

//    g_signal_connect(animal,"hungry",G_CALLBACK(hungry),0);

//    base_animal_hungry(animal);

//    g_object_unref(animal);


    // test 2
    AnimalDog* animalDog = animal_dog_new();

    g_object_set(animalDog,"name","dog",NULL);

    g_signal_connect(animalDog,"hungry",G_CALLBACK(hungry),0);

    base_animal_hungry(animalDog);

    g_object_unref(animalDog);
    return 0;
}
