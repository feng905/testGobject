#include "animal-dog.h"


typedef struct {
    int i;
}AnimalDogPrivate;

G_DEFINE_TYPE_WITH_PRIVATE(AnimalDog,animal_dog,BASE_TYPE_ANIMAL)

static void animal_dog_final(AnimalDog* self);
static void animal_dog_say(AnimalDog* self);

static animal_dog_init(AnimalDog* self){
    g_printerr("animal_dog_init\n");
}


static void animal_dog_class_init(AnimalDogClass* klass){
    g_printerr("animal_dog_class_init\n");
    GObjectClass *object_class = G_OBJECT_CLASS(klass);

    object_class->finalize = animal_dog_final;

    klass->parent_class.say = animal_dog_say;
}

static void animal_dog_final(AnimalDog* self){
    g_printerr("animal_dog_final\n");
}

static void animal_dog_say(AnimalDog* self){
    g_printerr("animal_dog_say\n");
}

AnimalDog* animal_dog_new(){
    return g_object_new(ANIMAL_TYPE_DOG,NULL);
}

