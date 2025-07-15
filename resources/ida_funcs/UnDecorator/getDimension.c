DName *__cdecl UnDecorator::getDimension(DName *result, bool fSigned)
{
  const char *v2; // esi
  int v3; // ecx
  bool v4; // zf
  char v5; // al
  unsigned __int64 v7; // rax
  const DName *v8; // eax
  DName *v9; // eax
  unsigned int v10; // edi
  int v11; // ebx
  char v12; // al
  const DName *v13; // eax
  DName *v14; // eax
  DName v15; // [esp+4h] [ebp-1Ch] BYREF
  DName v16; // [esp+Ch] [ebp-14h] BYREF
  DName v17; // [esp+14h] [ebp-Ch] BYREF
  char *prefix; // [esp+1Ch] [ebp-4h]

  v2 = UnDecorator::gName;
  v3 = 0;
  v4 = *UnDecorator::gName == 81;
  prefix = 0;
  if ( v4 )
  {
    v2 = UnDecorator::gName + 1;
    prefix = "`non-type-template-parameter";
    ++UnDecorator::gName;
  }
  v5 = *v2;
  if ( !*v2 )
  {
    DName::DName(result, DN_truncated);
    return result;
  }
  if ( v5 < 48 || v5 > 57 )
  {
    v10 = 0;
    while ( v5 != 64 )
    {
      if ( !v5 )
      {
        DName::DName(result, DN_truncated);
        return result;
      }
      if ( v5 < 65 || v5 > 80 )
        goto LABEL_18;
      v11 = v5 - 65;
      *((_DWORD *)&v17 + 1) = v11 >> 31;
      ++v2;
      v10 = (16 * __PAIR64__(v10, v3) + v11) >> 32;
      UnDecorator::gName = v2;
      v5 = *v2;
      v3 = 16 * v3 + v11;
    }
    v12 = *v2;
    UnDecorator::gName = v2 + 1;
    if ( v12 != 64 )
    {
LABEL_18:
      DName::DName(result, DN_invalid);
      return result;
    }
    if ( fSigned )
    {
      if ( !prefix )
      {
        v14 = DName::DName(&v17, __SPAIR64__(v10, v3));
LABEL_29:
        *result = *v14;
        return result;
      }
      v13 = DName::DName(&v15, __SPAIR64__(v10, v3));
    }
    else
    {
      if ( !prefix )
      {
        v14 = DName::DName(&v17, __PAIR64__(v10, v3));
        goto LABEL_29;
      }
      v13 = DName::DName(&v15, __PAIR64__(v10, v3));
    }
    v14 = operator+(&v16, prefix, v13);
    goto LABEL_29;
  }
  v7 = *v2 - 47;
  UnDecorator::gName = v2 + 1;
  if ( prefix )
  {
    v8 = DName::DName(&v17, v7);
    v9 = operator+(&v16, prefix, v8);
  }
  else
  {
    v9 = DName::DName(&v15, v7);
  }
  *result = *v9;
  return result;
}
