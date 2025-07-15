DName *__cdecl UnDecorator::getVfTableType(DName *result, const DName *superType)
{
  int v2; // eax
  DName *v3; // eax
  const DName *v4; // eax
  const DName *Scope; // eax
  DName *v6; // eax
  const DName *v7; // eax
  const char *v8; // eax
  const DName *v9; // eax
  DName v11; // [esp+8h] [ebp-18h] BYREF
  DName v12; // [esp+10h] [ebp-10h] BYREF
  DName resulta; // [esp+18h] [ebp-8h] BYREF

  result->node = superType->node;
  v2 = *((_DWORD *)superType + 1);
  *((_DWORD *)result + 1) = v2;
  if ( (char)v2 <= 1 )
  {
    if ( *UnDecorator::gName )
    {
      UnDecorator::getDataIndirectType(&resulta);
      v3 = DName::operator+(&resulta, &v11, 32);
      v4 = DName::operator+(v3, &v12, result);
      DName::operator=(result, v4);
      if ( *((char *)result + 4) <= 1 )
      {
        if ( *UnDecorator::gName == 64 )
          goto LABEL_19;
        DName::operator+=(result, "{for ");
        while ( *((char *)result + 4) <= 1 && *UnDecorator::gName && *UnDecorator::gName != 64 )
        {
          Scope = UnDecorator::getScope(&v12);
          v6 = operator+(&resulta, 96, Scope);
          v7 = DName::operator+(v6, &v11, 39);
          DName::operator+=(result, v7);
          v8 = UnDecorator::gName;
          if ( *UnDecorator::gName == 64 )
            v8 = ++UnDecorator::gName;
          if ( *((char *)result + 4) > 1 )
            goto LABEL_18;
          if ( *v8 != 64 )
            DName::operator+=(result, "s ");
        }
        if ( *((char *)result + 4) <= 1 )
        {
          if ( !*UnDecorator::gName )
            DName::operator+=(result, DN_truncated);
          DName::operator+=(result, 125);
        }
LABEL_18:
        if ( *UnDecorator::gName == 64 )
LABEL_19:
          ++UnDecorator::gName;
      }
    }
    else
    {
      v9 = operator+(&v11, DN_truncated, result);
      DName::operator=(result, v9);
    }
  }
  return result;
}
