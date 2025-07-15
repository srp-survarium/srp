vostok::animation::skeleton_animation_scene_operator *__thiscall vostok::animation::skeleton_animation_scene_operator::`vector deleting destructor'(
        vostok::animation::skeleton_animation_scene_operator *this,
        char a2)
{
  vostok::animation::skeleton_animation_scene_operator::~skeleton_animation_scene_operator(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
