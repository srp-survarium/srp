vostok::ai::navigation::navigation_world *__thiscall vostok::ai::navigation::navigation_world::`scalar deleting destructor'(
        vostok::ai::navigation::navigation_world *this,
        char a2)
{
  vostok::ai::navigation::navigation_world::~navigation_world(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
