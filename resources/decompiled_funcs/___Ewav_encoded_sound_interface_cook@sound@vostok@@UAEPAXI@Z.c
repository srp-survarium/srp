vostok::sound::wav_encoded_sound_interface_cook *__thiscall vostok::sound::wav_encoded_sound_interface_cook::`vector deleting destructor'(
        vostok::sound::wav_encoded_sound_interface_cook *this,
        char a2)
{
  vostok::sound::wav_encoded_sound_interface_cook::~wav_encoded_sound_interface_cook(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
