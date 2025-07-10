DName *__cdecl UnDecorator::getVCallThunkType(DName *result)
{
  if ( *UnDecorator::gName )
  {
    if ( *UnDecorator::gName == 65 )
    {
      ++UnDecorator::gName;
      DName::DName(result, "{flat}");
    }
    else
    {
      DName::DName(result, DN_invalid);
    }
  }
  else
  {
    DName::DName(result, DN_truncated);
  }
  return result;
}
