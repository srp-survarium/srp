vostok::sound::wav_encoded_sound_interface *__thiscall vostok::sound::wav_encoded_sound_interface::`scalar deleting destructor'(
        vostok::sound::wav_encoded_sound_interface *this,
        char a2)
{
  vostok::sound::wav_encoded_sound_interface::~wav_encoded_sound_interface(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
