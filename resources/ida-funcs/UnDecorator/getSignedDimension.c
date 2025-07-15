DName *__cdecl UnDecorator::getSignedDimension(DName *result)
{
  const DName *Dimension; // eax
  DName resulta; // [esp+0h] [ebp-8h] BYREF

  if ( *UnDecorator::gName )
  {
    if ( *UnDecorator::gName == 63 )
    {
      ++UnDecorator::gName;
      Dimension = UnDecorator::getDimension(&resulta, 0);
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
