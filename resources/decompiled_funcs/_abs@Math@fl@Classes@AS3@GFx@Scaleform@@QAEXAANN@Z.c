void __thiscall Scaleform::GFx::AS3::Classes::fl::Math::abs(
        Scaleform::GFx::AS3::Classes::fl::Math *this,
        long double *result,
        long double x)
{
  long double v3; // st7

  if ( Scaleform::GFx::NumberUtil::IsNEGATIVE_ZERO(x) )
  {
    *result = 0.0;
  }
  else
  {
    v3 = x;
    if ( x < 0.0 )
      v3 = -x;
    *result = v3;
  }
}
