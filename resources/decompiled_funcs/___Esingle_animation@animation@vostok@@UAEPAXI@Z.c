vostok::animation::single_animation *__thiscall vostok::animation::single_animation::`vector deleting destructor'(
        vostok::animation::single_animation *this,
        char a2)
{
  vostok::animation::single_animation::~single_animation(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
