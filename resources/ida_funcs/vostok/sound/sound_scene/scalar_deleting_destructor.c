vostok::sound::sound_scene *__thiscall vostok::sound::sound_scene::`scalar deleting destructor'(
        vostok::sound::sound_scene *this,
        char a2)
{
  vostok::sound::sound_scene::~sound_scene(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
