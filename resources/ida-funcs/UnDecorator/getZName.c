DName *__cdecl UnDecorator::getZName(DName *result, bool fUpdateCachedNames, bool fAllowEmptyName)
{
  char v3; // bl
  unsigned int v4; // eax
  DName *v5; // eax
  DName *TemplateName; // eax
  DNameNode *node; // ecx
  const char *v8; // eax
  char *v9; // edi
  unsigned int v10; // eax
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
  DName v21; // [esp+1Ch] [ebp-24h] BYREF
  DName rd; // [esp+24h] [ebp-1Ch] BYREF
  char v23[16]; // [esp+2Ch] [ebp-14h] BYREF

  v3 = *UnDecorator::gName;
  v4 = *UnDecorator::gName - 48;
  v19 = result;
  if ( v4 <= 9 )
  {
    ++UnDecorator::gName;
    Replicator::operator[](UnDecorator::pZNameList, result, v4);
    return result;
  }
  rd.node = 0;
  *((_DWORD *)&rd + 1) &= 0xFFFF0000;
  if ( v3 == 63 )
  {
    TemplateName = UnDecorator::getTemplateName(&v21, 0);
    node = TemplateName->node;
    *((_DWORD *)&rd + 1) = *((_DWORD *)TemplateName + 1);
    rd.node = node;
    LOBYTE(node) = *UnDecorator::gName;
    v8 = ++UnDecorator::gName;
    if ( (_BYTE)node != 64 )
    {
      UnDecorator::gName = v8 - 1;
      DName::operator=(&rd, (DNameStatus)((*(v8 - 1) != 0) + 1));
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
    UnDecorator::getSignedDimension(&v21);
    if ( (UnDecorator::disableFlags & 0x4000) != 0 )
    {
      DName::getString(&v21, v23, 0x10u);
      v10 = atol(v3, v23);
      Parameter = UnDecorator::m_pGetParameter(v10);
      if ( Parameter )
      {
        DName::operator=(&rd, Parameter);
        goto LABEL_20;
      }
      DName::operator=(&rd, "`");
      v17 = &v18;
      v12 = operator+(&v20, v9, &v21);
    }
    else
    {
      DName::operator=(&rd, "`");
      v17 = &v20;
      v12 = operator+(&v18, v9, &v21);
    }
    v13 = DName::operator+(v12, v17, "'");
    DName::operator+=(&rd, v13);
    goto LABEL_20;
  }
  if ( fAllowEmptyName && v3 == 64 )
  {
    ++UnDecorator::gName;
    rd.node = 0;
    *((_DWORD *)&rd + 1) = *((_DWORD *)&v20 + 1) & 0xFFFF0000;
  }
  else
  {
    v14 = DName::DName(&v20, (char **)&UnDecorator::gName, 64);
    v15 = v14->node;
    v16 = *((_DWORD *)v14 + 1);
    rd.node = v15;
    *((_DWORD *)&rd + 1) = v16;
  }
LABEL_20:
  if ( fUpdateCachedNames && UnDecorator::pZNameList->index != 9 )
    Replicator::operator+=(UnDecorator::pZNameList, &rd);
  v5 = v19;
  *v19 = rd;
  return v5;
}
