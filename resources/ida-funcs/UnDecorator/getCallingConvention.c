DName *__cdecl UnDecorator::getCallingConvention(DName *result)
{
  unsigned int v1; // eax
  unsigned int v2; // eax
  unsigned int v3; // eax
  unsigned int v4; // eax
  unsigned int v5; // eax
  unsigned int v6; // eax
  char *v7; // eax
  DName *v8; // eax
  DName v9; // [esp+0h] [ebp-8h] BYREF

  if ( *UnDecorator::gName )
  {
    v1 = *UnDecorator::gName++ - 65;
    if ( v1 <= 0xC )
    {
      v9.node = 0;
      *((_DWORD *)&v9 + 1) &= 0xFFFF0000;
      if ( (~(UnDecorator::disableFlags >> 1) & 1) != 0 )
      {
        v2 = v1 & 0xFFFFFFFE;
        if ( !v2 )
        {
          v7 = (char *)UnDecorator::UScore(TOK_cdecl);
          goto LABEL_16;
        }
        v3 = v2 - 2;
        if ( !v3 )
        {
          v7 = (char *)UnDecorator::UScore(TOK_pascal);
          goto LABEL_16;
        }
        v4 = v3 - 2;
        if ( !v4 )
        {
          v7 = (char *)UnDecorator::UScore(TOK_thiscall);
          goto LABEL_16;
        }
        v5 = v4 - 2;
        if ( !v5 )
        {
          v7 = (char *)UnDecorator::UScore(TOK_stdcall);
          goto LABEL_16;
        }
        v6 = v5 - 2;
        if ( !v6 )
        {
          v7 = (char *)UnDecorator::UScore(TOK_fastcall);
          goto LABEL_16;
        }
        if ( v6 == 4 )
        {
          v7 = (char *)UnDecorator::UScore(TOK_cocall);
LABEL_16:
          DName::operator=(&v9, v7);
        }
      }
      v8 = result;
      *result = v9;
      return v8;
    }
    DName::DName(result, DN_invalid);
  }
  else
  {
    DName::DName(result, DN_truncated);
  }
  return result;
}
