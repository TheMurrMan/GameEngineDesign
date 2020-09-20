extends CustomMouseNode


# Declare member variables here. Examples:
# var a = 2
# var b = "text"
var pos = Vector2(500,200)
var sprite = load("Icon.png")
var m = CustomMouseNode.new()

# Called when the node enters the scene tree for the first time.
func _draw():
	
	m.setSprite(sprite)
	m.setPosition(pos)
	print(m.getSprite().to_string())
	draw_texture(m.getSprite(), m.getPosition())
	#

func _process(delta):
	pos = get_viewport().get_mouse_position()
	update()

