vostok::sound::composite_sound *__thiscall vostok::sound::composite_sound::`vector deleting destructor'(
        vostok::sound::composite_sound *this,
        char a2)
{
  vostok::sound::composite_sound::~composite_sound(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}


vostok::sound::composite_sound *__thiscall vostok::sound::composite_sound::`vector deleting destructor'(
        char *this,
        char a2)
{
  return vostok::sound::composite_sound::`vector deleting destructor'(
           (vostok::sound::composite_sound *)(this - 272),
           a2);
}
