void __thiscall Scaleform::GFx::AS3::Classes::fl::Math::round(
        Scaleform::GFx::AS3::Classes::fl::Math *this,
        long double *result,
        long double x)
{
  if ( (HIDWORD(x) & 0x7FF00000) == 0x7FF00000 )
    *result = x;
  else
    *result = floor(x + 0.5);
}
