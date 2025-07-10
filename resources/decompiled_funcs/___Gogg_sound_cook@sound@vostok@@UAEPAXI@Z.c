vostok::sound::ogg_sound_cook *__thiscall vostok::sound::ogg_sound_cook::`scalar deleting destructor'(
        vostok::sound::ogg_sound_cook *this,
        char a2)
{
  vostok::sound::ogg_sound_cook::~ogg_sound_cook(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
