vostok::animation::skeleton_animation_scene_node *__thiscall vostok::animation::skeleton_animation_scene_node::`scalar deleting destructor'(
        vostok::animation::skeleton_animation_scene_node *this,
        char a2)
{
  vostok::animation::skeleton_animation_scene_node::~skeleton_animation_scene_node(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
