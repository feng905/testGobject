#include "animal.h"

typedef struct{
    gchar* name;
    gint age;
    gpointer obj;
}BaseAnimalPrivate;

/* PROP */
enum{
    PROP_0,
    PROP_NAME,
    PROP_AGE,
    PROP_OBJ
};

/* Signals */
enum{
    BASE_ANIMAL_HUNGRY,
    BASE_ANIMAL_LAST
};

static guint signals[BASE_ANIMAL_LAST];

//G_DEFINE_TYPE(BaseAnimal,base_animal,G_TYPE_OBJECT)
G_DEFINE_TYPE_WITH_PRIVATE(BaseAnimal,base_animal,G_TYPE_OBJECT)

static void base_animal_say(BaseAnimal* base);
static void base_animal_finalize(GObject* obj);

static void base_animal_get_property (GObject *object,
                                      guint prop_id,
                                      GValue *value G_GNUC_UNUSED,
                                      GParamSpec *pspec){
    BaseAnimal* self = BASE_ANIMAL(object);
    BaseAnimalPrivate* priv = base_animal_get_instance_private(self);

    switch (prop_id) {
    case PROP_NAME:
        g_value_set_string(value,priv->name);
        break;
    case PROP_AGE:
         g_value_set_int(value,priv->age);
        break;
    case PROP_OBJ:
        g_value_set_object(value,priv->obj);
        break;
    default:
        G_OBJECT_WARN_INVALID_PROPERTY_ID(self, prop_id, pspec);
        break;
    }
}

static void base_animal_set_property(GObject *object,
                                     guint prop_id,
                                     const GValue *value,
                                     GParamSpec *pspec){
    BaseAnimal* self = BASE_ANIMAL(object);
    BaseAnimalPrivate* priv = base_animal_get_instance_private(self);

    switch (prop_id) {
    case PROP_NAME:
        g_free(priv->name);
        priv->name = g_value_dup_string(value);
        break;
    case PROP_AGE:
        priv->age = g_value_get_int(value);
        break;
    case PROP_OBJ:
        priv->obj = g_value_get_object(value);
        break;
    default:
        G_OBJECT_WARN_INVALID_PROPERTY_ID(self, prop_id, pspec);
        break;
    }
}


static void base_animal_init(BaseAnimal* self){
    g_printerr("base_animal_init\n");

    BaseAnimalPrivate* priv = base_animal_get_instance_private(self);
    priv->name = g_strdup("i am base_animal");

    g_printerr("priv->name:%s\n",priv->name);
}

static void base_animal_class_init(BaseAnimalClass* klass){
    g_printerr("base_animal_class_init\n");
    GObjectClass *gobject_class = G_OBJECT_CLASS(klass);
    klass->parent_class.set_property = base_animal_set_property;
    klass->parent_class.get_property = base_animal_get_property;
    klass->parent_class.finalize = base_animal_finalize;
    klass->say = base_animal_say;

    /* install prop */
    g_object_class_install_property
        (gobject_class, PROP_NAME,
         g_param_spec_string("name",   //name
                             "Name",   // nick
                             "Animal name",  // blurb  'simple introduce'
                             "animal", // default value
                             G_PARAM_READWRITE |
                             G_PARAM_CONSTRUCT |
                             G_PARAM_STATIC_STRINGS));

    g_object_class_install_property(
                gobject_class,PROP_AGE,
                g_param_spec_int("age",
                                 "age",
                                 "the animal age",
                                 0,G_MAXINT,0,
                                 G_PARAM_READWRITE |
                                 G_PARAM_STATIC_STRINGS));

    g_object_class_install_property(gobject_class,
                                    PROP_OBJ,
                g_param_spec_object("obj",
                                    "Obj",
                                    "one object",
                                    G_TYPE_OBJECT,
                                    G_PARAM_READWRITE |
                                    G_PARAM_STATIC_STRINGS));

    /* init signals */
    signals[BASE_ANIMAL_HUNGRY] = g_signal_new(
                "hungry",
                G_OBJECT_CLASS_TYPE(klass),
                G_SIGNAL_RUN_FIRST,
                G_STRUCT_OFFSET(BaseAnimalClass, hungry),
                NULL,NULL,
                g_cclosure_marshal_VOID__VOID,
                G_TYPE_NONE,
                0
                );
}

static void base_animal_finalize(GObject* obj){
    g_printerr("base_animal_finalize\n");
    BaseAnimal* baseAnimal = BASE_ANIMAL(obj);
    BaseAnimalPrivate* priv = base_animal_get_instance_private(baseAnimal);
    g_free(priv->name);
}

BaseAnimal* base_animal_new(){
    return g_object_new(BASE_TYPE_ANIMAL,NULL);
}

void base_animal_hungry(BaseAnimal* base){
    g_signal_emit(base,signals[BASE_ANIMAL_HUNGRY],0);
}

static void base_animal_say(BaseAnimal* base){
    g_printerr("base_animal_say\n");
}
