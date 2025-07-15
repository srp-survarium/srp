DName *__cdecl UnDecorator::getThrowTypes(DName *result)
{
  DName *v1; // eax
  unsigned int v2; // edx
  const DName *ArgumentTypes; // eax
  DName *v4; // eax
  DName *v5; // eax
  DName *v6; // [esp-8h] [ebp-18h]
  DName v7; // [esp+0h] [ebp-10h] BYREF
  DName resulta; // [esp+8h] [ebp-8h] BYREF

  if ( *UnDecorator::gName )
  {
    if ( *UnDecorator::gName == 90 )
    {
      ++UnDecorator::gName;
      v1 = result;
      v2 = *((_DWORD *)&resulta + 1) & 0xFFFF0000;
      result->node = 0;
      *((_DWORD *)result + 1) = v2;
      return v1;
    }
    v6 = result;
    ArgumentTypes = UnDecorator::getArgumentTypes(&resulta);
    v4 = operator+(&v7, " throw(", ArgumentTypes);
  }
  else
  {
    v6 = result;
    v5 = DName::DName(&resulta, " throw(");
    v4 = DName::operator+(v5, &v7, DN_truncated);
  }
  DName::operator+(v4, v6, 41);
  return result;
}
