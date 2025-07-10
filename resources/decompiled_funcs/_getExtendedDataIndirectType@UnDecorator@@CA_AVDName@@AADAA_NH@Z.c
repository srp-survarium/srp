DName *__cdecl UnDecorator::getExtendedDataIndirectType(DName *result, char *prType, bool *fIsPinPtr, int thisFlag)
{
  const char *v4; // edi
  char v5; // cl
  int v6; // eax
  char v7; // cl
  unsigned int v8; // esi
  const DName *v9; // eax
  DName *v10; // eax
  DNameNode *node; // ecx
  int v12; // eax
  DName *v13; // eax
  int v14; // ecx
  bool v15; // zf
  DName *v16; // eax
  DName *v17; // eax
  DName v18; // [esp+8h] [ebp-28h] BYREF
  DName v19; // [esp+10h] [ebp-20h] BYREF
  DName v20; // [esp+18h] [ebp-18h] BYREF
  DName v21; // [esp+20h] [ebp-10h] BYREF
  DName szComPlusIndirSpecifier; // [esp+28h] [ebp-8h] BYREF

  *((_DWORD *)&szComPlusIndirSpecifier + 1) &= 0xFFFF0000;
  v4 = UnDecorator::gName + 1;
  UnDecorator::gName = v4;
  v5 = *v4;
  v6 = *v4;
  szComPlusIndirSpecifier.node = 0;
  switch ( v6 )
  {
    case 'A':
      if ( !thisFlag )
        *prType = *prType != 38 ? 94 : 37;
      goto LABEL_24;
    case 'B':
      if ( thisFlag )
        goto LABEL_19;
      *fIsPinPtr = 1;
      DName::operator=(&szComPlusIndirSpecifier, 62);
LABEL_24:
      v17 = result;
      ++UnDecorator::gName;
      *((_BYTE *)result + 4) = 0;
      *((_DWORD *)result + 1) &= 0xFFFF00FF;
      result->node = 0;
      return v17;
    case 'C':
      *prType = 37;
      goto LABEL_24;
  }
  if ( !v5 || (v7 = v4[1]) == 0 )
  {
    DName::DName(result, DN_truncated);
    return result;
  }
  if ( thisFlag )
  {
LABEL_19:
    DName::DName(result, DN_invalid);
    return result;
  }
  v8 = 16 * (v6 - 48) + v7 - 48;
  UnDecorator::gName = v4 + 2;
  if ( v8 > 1 )
  {
    DName::operator=(&szComPlusIndirSpecifier, 44);
    v9 = DName::DName(&v21, v8);
    v10 = DName::operator+(&szComPlusIndirSpecifier, &v20, v9);
    node = v10->node;
    v12 = *((_DWORD *)v10 + 1);
    szComPlusIndirSpecifier.node = node;
    *((_DWORD *)&szComPlusIndirSpecifier + 1) = v12;
  }
  v13 = DName::operator+(&szComPlusIndirSpecifier, &v19, 62);
  szComPlusIndirSpecifier.node = v13->node;
  v14 = *((_DWORD *)v13 + 1);
  v15 = *UnDecorator::gName == 36;
  *((_DWORD *)&szComPlusIndirSpecifier + 1) = v14;
  if ( v15 )
  {
    ++UnDecorator::gName;
  }
  else
  {
    v16 = DName::operator+(&szComPlusIndirSpecifier, &v18, 94);
    szComPlusIndirSpecifier.node = v16->node;
    v14 = *((_DWORD *)v16 + 1);
    *((_DWORD *)&szComPlusIndirSpecifier + 1) = v14;
  }
  if ( *UnDecorator::gName )
  {
    ++UnDecorator::gName;
  }
  else
  {
    DName::operator+=(&szComPlusIndirSpecifier, DN_truncated);
    v14 = *((_DWORD *)&szComPlusIndirSpecifier + 1);
  }
  v17 = result;
  result->node = szComPlusIndirSpecifier.node;
  *((_DWORD *)result + 1) = v14 | 0x4000;
  return v17;
}
