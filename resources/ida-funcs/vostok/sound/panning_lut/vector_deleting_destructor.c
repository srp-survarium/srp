vostok::sound::panning_lut *__thiscall vostok::sound::panning_lut::`vector deleting destructor'(
        vostok::sound::panning_lut *this,
        char a2)
{
  this->__vftable = (vostok::sound::panning_lut_vtbl *)&vostok::sound::panning_lut::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
