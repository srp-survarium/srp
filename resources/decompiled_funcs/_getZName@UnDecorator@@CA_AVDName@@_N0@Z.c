DName *__cdecl UnDecorator::getZName(DName *result, bool fUpdateCachedNames, bool fAllowEmptyName)
{
  char v3; // bl
  unsigned int v4; // eax
  DName *v5; // eax
  DName *TemplateName; // eax
  DNameNode *node; // ecx
  const char *v8; // eax
  char *v9; // edi
  int v10; // eax
  char *Parameter; // eax
  DName *v12; // eax
  DName *v13; // eax
  DName *v14; // eax
  DNameNode *v15; // ecx
  int v16; // eax
  DName *v17; // [esp-Ch] [ebp-4Ch]
  DName v18; // [esp+8h] [ebp-38h] BYREF
  DName *v19; // [esp+10h] [ebp-30h]
  DName v20; // [esp+14h] [ebp-2Ch] BYREF
  DName dimension; // [esp+1Ch] [ebp-24h] BYREF
  DName zName; // [esp+24h] [ebp-1Ch] BYREF
  char buffer[16]; // [esp+2Ch] [ebp-14h] BYREF

  v3 = *UnDecorator::gName;
  v4 = *UnDecorator::gName - 48;
  v19 = result;
  if ( v4 <= 9 )
  {
    ++UnDecorator::gName;
    Replicator::operator[](UnDecorator::pZNameList, result, v4);
    return result;
  }
  zName.node = 0;
  *((_DWORD *)&zName + 1) &= 0xFFFF0000;
  if ( v3 == 63 )
  {
    TemplateName = UnDecorator::getTemplateName(&dimension, 0);
    node = TemplateName->node;
    *((_DWORD *)&zName + 1) = *((_DWORD *)TemplateName + 1);
    zName.node = node;
    LOBYTE(node) = *UnDecorator::gName;
    v8 = ++UnDecorator::gName;
    if ( (_BYTE)node != 64 )
    {
      UnDecorator::gName = v8 - 1;
      DName::operator=(&zName, (DNameStatus)((*(v8 - 1) != 0) + 1));
    }
    goto LABEL_20;
  }
  v9 = "template-parameter-";
  if ( !und_strncmp(UnDecorator::gName, "template-parameter-", 0x13u) )
  {
    UnDecorator::gName += 19;
    goto LABEL_10;
  }
  v9 = "generic-type-";
  if ( !und_strncmp(UnDecorator::gName, "generic-type-", 0xDu) )
  {
    UnDecorator::gName += 13;
LABEL_10:
    UnDecorator::getSignedDimension(&dimension);
    if ( (UnDecorator::disableFlags & 0x4000) != 0 )
    {
      DName::getString(&dimension, buffer, 0x10u);
      v10 = atol(buffer);
      Parameter = UnDecorator::m_pGetParameter(v10);
      if ( Parameter )
      {
        DName::operator=(&zName, Parameter);
        goto LABEL_20;
      }
      DName::operator=(&zName, "`");
      v17 = &v18;
      v12 = operator+(&v20, v9, &dimension);
    }
    else
    {
      DName::operator=(&zName, "`");
      v17 = &v20;
      v12 = operator+(&v18, v9, &dimension);
    }
    v13 = DName::operator+(v12, v17, "'");
    DName::operator+=(&zName, v13);
    goto LABEL_20;
  }
  if ( fAllowEmptyName && v3 == 64 )
  {
    ++UnDecorator::gName;
    zName.node = 0;
    *((_DWORD *)&zName + 1) = *((_DWORD *)&v20 + 1) & 0xFFFF0000;
  }
  else
  {
    v14 = DName::DName(&v20, (char **)&UnDecorator::gName, 64);
    v15 = v14->node;
    v16 = *((_DWORD *)v14 + 1);
    zName.node = v15;
    *((_DWORD *)&zName + 1) = v16;
  }
LABEL_20:
  if ( fUpdateCachedNames && UnDecorator::pZNameList->index != 9 )
    Replicator::operator+=(UnDecorator::pZNameList, &zName);
  v5 = v19;
  *v19 = zName;
  return v5;
}
