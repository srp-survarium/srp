vostok::sound::sound_spl *__thiscall vostok::sound::sound_spl::`vector deleting destructor'(
        vostok::sound::sound_spl *this,
        char a2)
{
  vostok::sound::sound_spl::~sound_spl(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
