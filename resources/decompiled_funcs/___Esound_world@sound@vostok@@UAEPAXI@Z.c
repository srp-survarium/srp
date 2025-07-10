vostok::sound::sound_world *__thiscall vostok::sound::sound_world::`vector deleting destructor'(
        vostok::sound::sound_world *this,
        char a2)
{
  vostok::sound::sound_world::~sound_world(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
