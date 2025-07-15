DName *__cdecl UnDecorator::getDecoratedName(DName *result)
{
  DName *v1; // eax
  const char *v2; // eax
  const char *i; // eax
  DNameNode *node; // esi
  int v5; // ebx
  int v6; // edi
  DName *v7; // eax
  bool v8; // zf
  DName *v9; // eax
  DName *v10; // eax
  DName *v11; // eax
  DName *v12; // [esp-8h] [ebp-38h]
  DName v13; // [esp+Ch] [ebp-24h] BYREF
  DName v14; // [esp+14h] [ebp-1Ch] BYREF
  DName resulta; // [esp+1Ch] [ebp-14h] BYREF
  DName rd; // [esp+24h] [ebp-Ch] BYREF
  BOOL v17; // [esp+2Ch] [ebp-4h]

  if ( (UnDecorator::disableFlags & 0x2000) != 0 )
  {
    UnDecorator::disableFlags &= ~0x2000u;
    UnDecorator::getDataType(&resulta, 0);
    UnDecorator::disableFlags |= 0x2000u;
LABEL_3:
    v1 = result;
    *result = resulta;
    return v1;
  }
  if ( *UnDecorator::gName != 63 )
  {
    if ( !*UnDecorator::gName )
    {
      DName::DName(result, DN_truncated);
      return result;
    }
    goto LABEL_34;
  }
  v2 = UnDecorator::gName + 1;
  UnDecorator::gName = v2;
  if ( *v2 == 63 && v2[1] == 63 )
  {
    UnDecorator::getDecoratedName(&resulta);
    for ( i = UnDecorator::gName; *i; UnDecorator::gName = i )
      ++i;
    goto LABEL_3;
  }
  UnDecorator::getSymbolName(&rd);
  node = rd.node;
  v5 = *((_DWORD *)&rd + 1);
  v17 = rd.node && (*((_WORD *)&rd + 2) & 0x200) != 0;
  v6 = (*((_DWORD *)&rd + 1) >> 15) & 1;
  if ( *((char *)&rd + 4) > 1 )
    goto LABEL_16;
  if ( *UnDecorator::gName )
  {
    if ( *UnDecorator::gName != 64 )
    {
      UnDecorator::getScope(&resulta);
      if ( resulta.node )
      {
        if ( !UnDecorator::fExplicitTemplateParams )
        {
          v12 = &v13;
          v9 = &v14;
          goto LABEL_24;
        }
        UnDecorator::fExplicitTemplateParams = 0;
        v7 = DName::operator+(&rd, &v14, &resulta);
        node = v7->node;
        v5 = *((_DWORD *)v7 + 1);
        v8 = *UnDecorator::gName == 64;
        rd.node = v7->node;
        *((_DWORD *)&rd + 1) = v5;
        if ( !v8 )
        {
          resulta = *UnDecorator::getScope(&v14);
          v12 = &v14;
          v9 = &v13;
LABEL_24:
          v10 = DName::operator+(&resulta, v9, "::");
          v11 = DName::operator+(v10, v12, &rd);
          v5 = *((_DWORD *)v11 + 1);
          node = v11->node;
          *((_DWORD *)&rd + 1) = v5;
          rd.node = node;
        }
      }
    }
  }
  if ( v17 && node )
  {
    v5 |= 0x200u;
    *((_DWORD *)&rd + 1) = v5;
  }
  if ( v6 )
  {
    v5 |= 0x8000u;
    *((_DWORD *)&rd + 1) = v5;
  }
  if ( !node || (v5 & 0x1000) != 0 )
    goto LABEL_16;
  if ( !*UnDecorator::gName )
  {
LABEL_36:
    if ( (UnDecorator::disableFlags & 0x1000) == 0 || v17 || (v5 & 0x8000) != 0 )
    {
      UnDecorator::composeDeclaration(result, &rd);
      return result;
    }
    resulta.node = 0;
    *((_DWORD *)&resulta + 1) &= 0xFFFF0000;
    UnDecorator::composeDeclaration(&v13, &resulta);
LABEL_16:
    v1 = result;
    result->node = node;
    *((_DWORD *)result + 1) = v5;
    return v1;
  }
  if ( *UnDecorator::gName == 64 )
  {
    ++UnDecorator::gName;
    goto LABEL_36;
  }
LABEL_34:
  DName::DName(result, DN_invalid);
  return result;
}
