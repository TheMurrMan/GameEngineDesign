#ifndef ECSNODE_H
#define ECSNODE_H

#include <vector>
#include <map>
#include "scene/2d/sprite.h"
#include "scene/2d/node_2d.h"
#include "scene/resources/texture.h"
#include "core/os/Input.h"
#include "core/os/keyboard.h"
#include "core/os/input_event.h"
#include <core\engine.h>
#include <core\core_string_names.h>
#include "scene/2d/collision_shape_2d.h"

// Entity Struct
struct Entity
{
	int ID;
};

//Components

struct TransformComponent
{
	Vector2 pos;
	int speed = 5;
};

struct SpriteComponent
{
	Sprite* s = NULL;
	Color c = Color(0, 0, 0, 1);
};

struct PhysicsComponent
{
	float gravity = 9.8;
	CollisionShape2D collider;
};


// Main Node
class ECSNode : public Node2D {
	GDCLASS(ECSNode, Node2D);
public:
	ECSNode();
	~ECSNode();

	void _notification(int p_what);
	void _update();
	void _ready();
	void _draw();
	void _process(int p_delta);

	void inputSystem();
	void renderSystem();
	void physicsSystem();

	Vector2 getPosition() { return transformComponent.pos; };
	void setPosition(Vector2 newPos) { transformComponent.pos = newPos; };

protected:
	static void _bind_methods();
	//Ref<Texture> m_Texture;// = Load.;
	std::vector<Entity> entities;

	TransformComponent transformComponent;
	SpriteComponent spriteComponent;

	std::map<int, SpriteComponent> spriteComponents;
	std::map<int, TransformComponent> transformComponents;
	std::map<int, PhysicsComponent> physicsComponents;
	
};

#endif
