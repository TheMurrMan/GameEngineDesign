#include "customMouseNode.h"


CustomMouseNode::CustomMouseNode(){}


void CustomMouseNode::setSprite(const Ref<Texture>& p_texture)
{
	if (p_texture == m_Texture)
		return;

	if (m_Texture.is_valid())
		m_Texture->disconnect(CoreStringNames::get_singleton()->changed, this, "_texture_changed");

	m_Texture = p_texture;

	if (m_Texture.is_valid())
		m_Texture->connect(CoreStringNames::get_singleton()->changed, this, "_texture_changed");

	update();
	emit_signal("texture_changed");
	item_rect_changed();
	_change_notify("texture");
}

//Bind all your methods used in this class
void CustomMouseNode::_bind_methods()
{
	ClassDB::bind_method(D_METHOD("setPosition", "position"), &CustomMouseNode::setPosition);
	ClassDB::bind_method(D_METHOD("setSprite", "texture"), &CustomMouseNode::setSprite);
	ClassDB::bind_method(D_METHOD("getPosition"), &CustomMouseNode::getPosition);
	ClassDB::bind_method(D_METHOD("getSprite"), &CustomMouseNode::getSprite);
	//ClassDB::bind_method(D_METHOD("draw", "a", "b"), &CustomMouseNode::draw);
}



