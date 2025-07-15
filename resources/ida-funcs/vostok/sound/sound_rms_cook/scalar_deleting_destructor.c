vostok::sound::sound_rms_cook *__thiscall vostok::sound::sound_rms_cook::`scalar deleting destructor'(
        vostok::sound::sound_rms_cook *this,
        char a2)
{
  vostok::sound::sound_rms_cook::~sound_rms_cook(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
