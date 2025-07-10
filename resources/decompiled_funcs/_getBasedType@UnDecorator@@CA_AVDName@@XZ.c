DName *__cdecl UnDecorator::getBasedType(DName *result)
{
  char *v1; // eax
  int v2; // ecx
  DName *v3; // eax
  const DName *ScopedName; // eax
  DName v5; // [esp+0h] [ebp-10h] BYREF
  DName basedDecl; // [esp+8h] [ebp-8h] BYREF

  v1 = (char *)UnDecorator::UScore(TOK_basedLp);
  DName::DName(&basedDecl, v1);
  if ( *UnDecorator::gName )
  {
    v2 = *UnDecorator::gName++;
    switch ( v2 )
    {
      case '0':
        DName::operator+=(&basedDecl, "void");
        break;
      case '2':
        ScopedName = UnDecorator::getScopedName(&v5);
        DName::operator+=(&basedDecl, ScopedName);
        break;
      case '5':
        DName::DName(result, DN_invalid);
        return result;
    }
  }
  else
  {
    DName::operator+=(&basedDecl, DN_truncated);
  }
  DName::operator+=(&basedDecl, ") ");
  v3 = result;
  *result = basedDecl;
  return v3;
}
