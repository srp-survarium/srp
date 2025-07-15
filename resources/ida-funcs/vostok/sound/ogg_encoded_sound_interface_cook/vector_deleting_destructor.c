vostok::sound::ogg_encoded_sound_interface_cook *__thiscall vostok::sound::ogg_encoded_sound_interface_cook::`vector deleting destructor'(
        vostok::sound::ogg_encoded_sound_interface_cook *this,
        char a2)
{
  vostok::sound::ogg_encoded_sound_interface_cook::~ogg_encoded_sound_interface_cook(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
