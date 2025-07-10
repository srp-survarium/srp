vostok::sound::sound_environment *__thiscall vostok::sound::sound_environment::`scalar deleting destructor'(
        vostok::sound::sound_environment *this,
        char a2)
{
  vostok::sound::sound_environment::~sound_environment(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
