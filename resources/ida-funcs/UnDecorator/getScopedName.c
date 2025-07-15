DName *__cdecl UnDecorator::getScopedName(DName *result)
{
  const DName *ZName; // eax
  DName *Scope; // eax
  DName *v3; // eax
  const DName *v4; // eax
  DName *v5; // eax
  DName *v6; // eax
  const DName *v7; // eax
  DName v9; // [esp+Ch] [ebp-18h] BYREF
  DName v10; // [esp+14h] [ebp-10h] BYREF
  DName resulta; // [esp+1Ch] [ebp-8h] BYREF

  *((_BYTE *)result + 4) = 0;
  *((_DWORD *)result + 1) &= 0xFFFF00FF;
  result->node = 0;
  ZName = UnDecorator::getZName(&resulta, 1, 0);
  DName::operator=(result, ZName);
  if ( !*((_BYTE *)result + 4) && *UnDecorator::gName )
  {
    if ( *UnDecorator::gName == 64 )
    {
LABEL_6:
      ++UnDecorator::gName;
      return result;
    }
    Scope = UnDecorator::getScope(&v9);
    v3 = DName::operator+(Scope, &v10, "::");
    v4 = DName::operator+(v3, &resulta, result);
    DName::operator=(result, v4);
  }
  if ( *UnDecorator::gName == 64 )
    goto LABEL_6;
  if ( *UnDecorator::gName )
  {
    DName::operator=(result, DN_invalid);
  }
  else if ( result->node )
  {
    v5 = DName::DName(&resulta, DN_truncated);
    v6 = DName::operator+(v5, &v10, "::");
    v7 = DName::operator+(v6, &v9, result);
    DName::operator=(result, v7);
  }
  else
  {
    DName::operator=(result, DN_truncated);
  }
  return result;
}
