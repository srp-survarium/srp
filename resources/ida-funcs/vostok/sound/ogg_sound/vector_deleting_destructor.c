vostok::sound::ogg_sound *__thiscall vostok::sound::ogg_sound::`vector deleting destructor'(
        vostok::sound::ogg_sound *this,
        char a2)
{
  vostok::sound::ogg_sound::~ogg_sound(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
