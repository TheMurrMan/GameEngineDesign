//insert the Headername here
#ifndef CUSTOMMOUSENODE_H
#define CUSTOMMOUSENODE_H

#include "scene/2d/sprite.h"
#include "scene/2d/node_2d.h"
#include "scene/resources/texture.h"
#include <core\core_string_names.h>

class CustomMouseNode : public Sprite {
	GDCLASS(CustomMouseNode, Sprite);

protected:
  static void _bind_methods();
  Point2 m_Pos;
  Ref <Texture> m_Texture;

public:
  CustomMouseNode ();

  // getters
  Point2 getPosition() { return m_Pos; };
  Ref<Texture> getSprite() const { return m_Texture; };


  // setters
  void setPosition(Point2 newPos) { m_Pos = newPos; };
  void setSprite(const Ref<Texture>& texture);
};

#endif
