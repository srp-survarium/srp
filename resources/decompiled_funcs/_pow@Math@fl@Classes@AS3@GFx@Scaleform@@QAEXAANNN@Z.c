void __thiscall Scaleform::GFx::AS3::Classes::fl::Math::pow(
        Scaleform::GFx::AS3::Classes::fl::Math *this,
        long double *result,
        long double x,
        long double y)
{
  long double v4; // st7
  long double v5; // st6

  v4 = y;
  if ( y == 0.0 )
  {
    *result = 1.0;
    return;
  }
  v5 = x;
  if ( x == 1.0 || -1.0 == x )
  {
    if ( (HIDWORD(y) & 0x7FF00000) == 0x7FF00000 )
    {
      *result = Scaleform::GFx::NumberUtil::NaN();
      return;
    }
    v5 = x;
    v4 = y;
  }
  *result = pow(v5, v4);
}
