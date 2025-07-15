vostok::input::input_world *__thiscall vostok::input::input_world::`vector deleting destructor'(
        vostok::input::input_world *this,
        char a2)
{
  vostok::input::input_world::~input_world(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
