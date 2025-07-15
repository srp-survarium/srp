vostok::animation::skeleton_animation_scene_node_base *__thiscall vostok::animation::skeleton_animation_scene_node_base::`scalar deleting destructor'(
        vostok::animation::skeleton_animation_scene_node_base *this,
        char a2)
{
  this->__vftable = (vostok::animation::skeleton_animation_scene_node_base_vtbl *)&vostok::animation::skeleton_animation_scene_node_base::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
