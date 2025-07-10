vostok::sound::sound_environment_cook *__thiscall vostok::sound::single_sound_cook::`vector deleting destructor'(
        vostok::sound::sound_environment_cook *this,
        char a2)
{
  this->__vftable = (vostok::sound::sound_environment_cook_vtbl *)&vostok::resources::cook_base::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
