DName *__cdecl UnDecorator::getSignedDimension(DName *result)
{
  const DName *Dimension; // eax
  DName v3; // [esp+0h] [ebp-8h] BYREF

  if ( *UnDecorator::gName )
  {
    if ( *UnDecorator::gName == 63 )
    {
      ++UnDecorator::gName;
      Dimension = UnDecorator::getDimension(&v3, 0);
      operator+(result, 45, Dimension);
    }
    else
    {
      UnDecorator::getDimension(result, 0);
    }
  }
  else
  {
    DName::DName(result, DN_truncated);
  }
  return result;
}
