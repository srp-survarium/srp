vostok::sound::panning_lut *__thiscall vostok::sound::panning_lut::`vector deleting destructor'(
        vostok::sound::panning_lut *this,
        char a2)
{
  vostok::sound::panning_lut::~panning_lut(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
