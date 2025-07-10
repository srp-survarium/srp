vostok::sound::single_sound *__thiscall vostok::sound::single_sound::`scalar deleting destructor'(
        vostok::sound::single_sound *this,
        char a2)
{
  vostok::sound::single_sound::~single_sound(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
