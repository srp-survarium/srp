DName *__cdecl UnDecorator::getVdispMapType(DName *result, const DName *superType)
{
  const DName *Scope; // eax
  DName v4; // [esp+4h] [ebp-8h] BYREF

  *result = *superType;
  DName::operator+=(result, "{for ");
  Scope = UnDecorator::getScope(&v4);
  DName::operator+=(result, Scope);
  DName::operator+=(result, 125);
  if ( *UnDecorator::gName == 64 )
    ++UnDecorator::gName;
  return result;
}
