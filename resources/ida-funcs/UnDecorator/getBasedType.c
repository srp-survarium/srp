DName *__cdecl UnDecorator::getBasedType(DName *result)
{
  char *v1; // eax
  int v2; // ecx
  DName *v3; // eax
  const DName *ScopedName; // eax
  DName resulta; // [esp+0h] [ebp-10h] BYREF
  DName v6; // [esp+8h] [ebp-8h] BYREF

  v1 = (char *)UnDecorator::UScore(TOK_basedLp);
  DName::DName(&v6, v1);
  if ( *UnDecorator::gName )
  {
    v2 = *UnDecorator::gName++;
    switch ( v2 )
    {
      case '0':
        DName::operator+=(&v6, "void");
        break;
      case '2':
        ScopedName = UnDecorator::getScopedName(&resulta);
        DName::operator+=(&v6, ScopedName);
        break;
      case '5':
        DName::DName(result, DN_invalid);
        return result;
    }
  }
  else
  {
    DName::operator+=(&v6, DN_truncated);
  }
  DName::operator+=(&v6, ") ");
  v3 = result;
  *result = v6;
  return v3;
}
