#include "register_types.h"
#include "core/class_db.h"
#include "ECSNode.h"

void register_ECSModule_types(){
	ClassDB::register_class<ECSNode>();
}

void unregister_ECSModule_types() {
}
