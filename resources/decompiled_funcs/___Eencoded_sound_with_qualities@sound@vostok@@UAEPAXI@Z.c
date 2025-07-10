vostok::sound::encoded_sound_with_qualities *__thiscall vostok::sound::encoded_sound_with_qualities::`vector deleting destructor'(
        vostok::sound::encoded_sound_with_qualities *this,
        char a2)
{
  vostok::sound::encoded_sound_with_qualities::~encoded_sound_with_qualities(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
