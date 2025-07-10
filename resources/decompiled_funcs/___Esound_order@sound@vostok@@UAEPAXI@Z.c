vostok::sound::sound_order *__thiscall vostok::sound::sound_order::`vector deleting destructor'(
        vostok::sound::sound_order *this,
        char a2)
{
  vostok::sound::sound_order::~sound_order(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
