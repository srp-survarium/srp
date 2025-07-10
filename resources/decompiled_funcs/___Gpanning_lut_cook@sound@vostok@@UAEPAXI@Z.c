vostok::sound::panning_lut_cook *__thiscall vostok::sound::panning_lut_cook::`scalar deleting destructor'(
        vostok::sound::panning_lut_cook *this,
        char a2)
{
  vostok::sound::panning_lut_cook::~panning_lut_cook(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
