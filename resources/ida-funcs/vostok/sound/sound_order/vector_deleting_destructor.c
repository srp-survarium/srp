vostok::sound::sound_order *__thiscall vostok::sound::sound_order::`vector deleting destructor'(
        vostok::sound::sound_order *this,
        char a2)
{
  this->__vftable = (vostok::sound::sound_order_vtbl *)&vostok::sound::sound_order::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
