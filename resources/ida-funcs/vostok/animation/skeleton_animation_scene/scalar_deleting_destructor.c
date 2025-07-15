vostok::animation::skeleton_animation_scene *__thiscall vostok::animation::skeleton_animation_scene::`scalar deleting destructor'(
        vostok::animation::skeleton_animation_scene *this,
        char a2)
{
  vostok::animation::skeleton_animation_scene::~skeleton_animation_scene(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
