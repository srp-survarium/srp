vostok::render::grass_world *__thiscall vostok::render::grass_world::`scalar deleting destructor'(
        vostok::render::grass_world *this,
        char a2)
{
  vostok::render::grass_world::~grass_world(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
