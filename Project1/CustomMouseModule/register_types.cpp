#include "register_types.h"
#include "core/class_db.h"
#include "customMouseNode.h"

void register_CustomMouseModule_types(){
	ClassDB::register_class<CustomMouseNode>();
}

void unregister_CustomMouseModule_types() {
}
