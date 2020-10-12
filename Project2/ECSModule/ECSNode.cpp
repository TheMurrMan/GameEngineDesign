#include "ECSNode.h"
using namespace std;

ECSNode::ECSNode() {}
ECSNode::~ECSNode() {}

void ECSNode::_bind_methods()
{
	ClassDB::bind_method(D_METHOD("_ready"), &ECSNode::_ready);
	ClassDB::bind_method(D_METHOD("_update"), &ECSNode::_update);
	ClassDB::bind_method(D_METHOD("_process", "p_delta"), &ECSNode::_process);
	ClassDB::bind_method(D_METHOD("_draw"), &ECSNode::_draw);
	ClassDB::bind_method(D_METHOD("_notification", "p_what"), &ECSNode::_notification);

}

void ECSNode::_ready()
{
	//printf("Ready Called: ");
	//transformComponent.pos = Vector2(200, 200);
	Vector2 p = Vector2(200, 200);
	Sprite* s;
	int64_t childCount = get_child_count();
	entities.resize(childCount);
	for (int64_t x = 0; x < childCount; x++) {
		s = (Sprite*)get_child(x);
		TransformComponent tc;
		tc.pos = p;

		SpriteComponent sc;
		sc.s = s;
		sc.c = Color(255, 0, 0, 1.0f);

		Entity e;
		e.ID = x;
		entities.push_back(e);

		transformComponents.emplace(std::make_pair(e.ID, tc));
		spriteComponents.emplace(std::make_pair(e.ID, sc));
		printf("Tranform added");
	}
}

void ECSNode::_process(int p_delta)
{
	
}

void ECSNode::_update()
{
	if (!Engine::get_singleton()->is_editor_hint())
	{
		inputSystem();
	}
}

void ECSNode::_draw()
{
	if (!Engine::get_singleton()->is_editor_hint())
	{
		renderSystem();
	}
}


void ECSNode::_notification(int p_what)
{
	switch (p_what)
	{
		case NOTIFICATION_PROCESS:
		{
			_update();
			update();
		}
		break;

		/*case NOTIFICATION_PHYSICS_PROCESS:
		{

		}*/

		case NOTIFICATION_READY:
		{
			_ready();
		}
		break;

		case NOTIFICATION_DRAW:
		{
			_draw();
		}
		break;

	}
}



///////////// System Functions

void ECSNode::inputSystem()
{
	
	//printf("Input Called: ");
	//look_at(get_global_mouse_position());

	Input* input = Input::get_singleton();

	// move player up
	if (input->is_action_pressed("ui_up"))
	{
		for (auto& it : entities)
		{
			if (transformComponents.find(it.ID) != transformComponents.end())
			{
				TransformComponent tc = transformComponents.find(it.ID)->second;
				tc.pos.y -= 5;
				
				transformComponent.pos.y -= transformComponent.speed;
				
			}
		}
	}

	// move player down
	if (input->is_action_pressed("ui_down"))
	{	
		for (auto& it : entities)
		{
			if (transformComponents.find(it.ID) != transformComponents.end())
			{
				TransformComponent tc = transformComponents.find(it.ID)->second;
				tc.pos.y -= 5;
				transformComponent.pos.y += transformComponent.speed;
			}
		}
	}

	// move player left
	if (input->is_action_pressed("ui_left"))
	{
		for (auto& it : entities)
		{
			if (transformComponents.find(it.ID) != transformComponents.end())
			{
				TransformComponent tc = transformComponents.find(it.ID)->second;
				tc.pos.x -= 1;
				transformComponent.pos.x -= transformComponent.speed;
			}
		}
	}

	// move player right
	if (input->is_action_pressed("ui_right"))
	{
		for (auto& it : entities)
		{
			if (transformComponents.find(it.ID) != transformComponents.end())
			{
				TransformComponent tc = transformComponents.find(it.ID)->second;
				tc.pos.x += 1;
				transformComponent.pos.x += transformComponent.speed;
			}
		}
	}
}

void ECSNode::renderSystem()
{
	//draw_texture(getSprite(), getPosition());
	//draw_circle(getPosition(), 10, Color(255, 0, 0));

	//Rect2 pos = Rect2(Vector2(300, 300), Vector2(400, 400));
	//draw_rect(Rect2(pos), Color(255, 0, 0), true, 20);
	
	for (auto& it : entities)
	{
		if (spriteComponents.find(it.ID) != spriteComponents.end())
		{
			SpriteComponent sc = spriteComponents.find(it.ID)->second;
			sc.s->set_modulate(sc.c);
			sc.s->set_position(getPosition());
		}
	}

}

void ECSNode::physicsSystem()
{

}


