int __cdecl UnDecorator::getNumberOfDimensions()
{
  const char *v0; // ecx
  char v1; // dl
  int result; // eax
  char v3; // dl

  v0 = UnDecorator::gName;
  v1 = *UnDecorator::gName;
  if ( !*UnDecorator::gName )
    return 0;
  if ( v1 < 48 || v1 > 57 )
  {
    result = 0;
    while ( v1 != 64 )
    {
      if ( !v1 )
        return 0;
      if ( v1 < 65 || v1 > 80 )
        return -1;
      ++v0;
      result = 16 * result + v1 - 65;
      UnDecorator::gName = v0;
      v1 = *v0;
    }
    v3 = *v0;
    UnDecorator::gName = v0 + 1;
    if ( v3 == 64 )
      return result;
    return -1;
  }
  else
  {
    result = v1 - 47;
    ++UnDecorator::gName;
  }
  return result;
}
