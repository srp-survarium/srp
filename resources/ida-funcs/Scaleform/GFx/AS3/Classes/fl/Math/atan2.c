void __thiscall Scaleform::GFx::AS3::Classes::fl::Math::atan2(
        Scaleform::GFx::AS3::Classes::fl::Math *this,
        long double *result,
        long double y,
        long double x)
{
  if ( y == INFINITY )
  {
    if ( __PAIR64__(LODWORD(x), 2146435072) == HIDWORD(x) )
    {
      *result = this->PI * 0.25;
    }
    else if ( *(_QWORD *)&x == 0xFFF0000000000000uLL )
    {
      *result = this->PI * 0.75;
    }
    else
    {
      *result = this->PI * 0.5;
    }
  }
  else if ( y == -INFINITY )
  {
    if ( *(_QWORD *)&x == 0x7FF0000000000000LL )
    {
      *result = this->PI * -0.25;
    }
    else if ( *(_QWORD *)&x == 0xFFF0000000000000uLL )
    {
      *result = this->PI * -0.75;
    }
    else
    {
      *result = this->PI * -0.5;
    }
  }
  else
  {
    *result = atan2(y, x);
  }
}
