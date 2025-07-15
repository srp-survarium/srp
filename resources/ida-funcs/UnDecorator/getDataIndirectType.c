DName *__cdecl UnDecorator::getDataIndirectType(
        DName *result,
        const DName *superType,
        char prType,
        const DName *cvType,
        int thisFlag)
{
  char v5; // al
  DName *v6; // eax
  int v7; // ecx
  const char *v8; // ecx
  char v9; // al
  bool v10; // dl
  unsigned int v11; // ebx
  const char *v12; // eax
  DName *p_msExtension; // ecx
  DName *v14; // eax
  DName *v15; // eax
  DName *v16; // eax
  DNameNode *v17; // ecx
  int v18; // eax
  const char *v19; // eax
  DName *v20; // eax
  DName *v21; // eax
  DNameNode *node; // ecx
  int v23; // eax
  const char *v24; // eax
  DName *v25; // eax
  DNameNode *v26; // ecx
  int v27; // eax
  DName *v28; // eax
  DName *v29; // eax
  DNameNode *v30; // ecx
  int v31; // eax
  DName *v32; // eax
  DName *v33; // eax
  DNameNode *v34; // ecx
  int v35; // eax
  DName *v36; // eax
  DNameNode *v37; // ecx
  bool v38; // zf
  DName *v39; // eax
  DName *v40; // eax
  DNameNode *v41; // ecx
  int v42; // eax
  const DName *Scope; // eax
  char v44; // al
  DName *v45; // eax
  DName *v46; // eax
  DNameNode *v47; // ecx
  int v48; // eax
  const DName *BasedType; // eax
  DName *v50; // eax
  DNameNode *v51; // ecx
  int v52; // eax
  DName *v53; // eax
  DNameNode *v54; // ecx
  int v55; // eax
  const DName *v56; // eax
  int v57; // edx
  DName *v58; // eax
  DName *v59; // eax
  const DName *v60; // eax
  const DName *v61; // eax
  DName *v62; // eax
  DName *v63; // eax
  DName *v64; // [esp-8h] [ebp-68h]
  char *v65; // [esp-4h] [ebp-64h]
  DName v66; // [esp+Ch] [ebp-54h] BYREF
  DName v67; // [esp+14h] [ebp-4Ch] BYREF
  DName v68; // [esp+1Ch] [ebp-44h] BYREF
  DName v69; // [esp+24h] [ebp-3Ch] BYREF
  DName v70; // [esp+2Ch] [ebp-34h] BYREF
  DName v71; // [esp+34h] [ebp-2Ch] BYREF
  DName szComPlusIndirSpecifier; // [esp+3Ch] [ebp-24h] BYREF
  DName name; // [esp+44h] [ebp-1Ch] BYREF
  DName msExtension; // [esp+4Ch] [ebp-14h] BYREF
  DName ditType; // [esp+54h] [ebp-Ch] BYREF
  bool bIsPinPtr; // [esp+5Fh] [ebp-1h] BYREF

  v5 = *UnDecorator::gName;
  *((_DWORD *)&szComPlusIndirSpecifier + 1) &= 0xFFFF0000;
  szComPlusIndirSpecifier.node = 0;
  bIsPinPtr = 0;
  if ( !v5 )
  {
    if ( !thisFlag )
    {
      v61 = superType;
      if ( superType->node )
      {
        if ( (*((_DWORD *)superType + 1) & 0x100) == 0 && cvType->node )
        {
          v62 = operator+(&v67, DN_truncated, cvType);
          v63 = DName::operator+(v62, &v66, 32);
          DName::operator+(v63, result, superType);
          return result;
        }
        goto LABEL_74;
      }
      v61 = cvType;
      if ( cvType->node )
      {
LABEL_74:
        operator+(result, DN_truncated, v61);
        return result;
      }
    }
    DName::DName(result, DN_truncated);
    return result;
  }
  if ( v5 == 36 )
  {
    UnDecorator::getExtendedDataIndirectType(&name, &prType, &bIsPinPtr, thisFlag);
    if ( name.node )
    {
      v6 = result;
      result->node = name.node;
      v7 = *((_DWORD *)&name + 1);
LABEL_5:
      *((_DWORD *)v6 + 1) = v7;
      return v6;
    }
  }
  v8 = UnDecorator::gName;
  v9 = *UnDecorator::gName;
  v10 = *UnDecorator::gName < 65;
  *((_DWORD *)&msExtension + 1) &= 0xFFFF0000;
  msExtension.node = 0;
  v11 = v9 - (v10 ? 22 : 65);
  *((_DWORD *)&name + 1) &= 0xFFFF0000;
  name.node = 0;
  while ( v11 == 4 )
  {
    if ( (~(UnDecorator::disableFlags >> 1) & 1) != 0 && (~(UnDecorator::disableFlags >> 17) & 1) != 0 )
    {
      v24 = UnDecorator::UScore(TOK_ptr64);
      p_msExtension = &msExtension;
      v65 = (char *)v24;
      if ( !msExtension.node )
      {
LABEL_21:
        DName::operator=(p_msExtension, v65);
        goto LABEL_22;
      }
      v64 = &v67;
      v14 = &v66;
      goto LABEL_13;
    }
LABEL_22:
    if ( *++UnDecorator::gName == 36 )
    {
      UnDecorator::getExtendedDataIndirectType(&ditType, &prType, &bIsPinPtr, thisFlag);
      if ( ditType.node )
      {
        v6 = result;
        result->node = ditType.node;
        v7 = *((_DWORD *)&ditType + 1);
        goto LABEL_5;
      }
    }
    v8 = UnDecorator::gName;
    v11 = *UnDecorator::gName - (*UnDecorator::gName < 65 ? 22 : 65);
  }
  if ( v11 == 5 )
  {
    if ( (~(UnDecorator::disableFlags >> 1) & 1) != 0 )
    {
      v19 = UnDecorator::UScore(TOK_unaligned);
      p_msExtension = &name;
      v65 = (char *)v19;
      if ( !name.node )
        goto LABEL_21;
      v20 = DName::operator+(&name, &v68, 32);
      v21 = DName::operator+(v20, &v69, v65);
      node = v21->node;
      v23 = *((_DWORD *)v21 + 1);
      name.node = node;
      *((_DWORD *)&name + 1) = v23;
    }
    goto LABEL_22;
  }
  if ( v11 == 8 )
  {
    if ( (~(UnDecorator::disableFlags >> 1) & 1) != 0 )
    {
      v12 = UnDecorator::UScore(TOK_restrict);
      p_msExtension = &msExtension;
      v65 = (char *)v12;
      if ( !msExtension.node )
        goto LABEL_21;
      v64 = &v71;
      v14 = &v70;
LABEL_13:
      v15 = DName::operator+(&msExtension, v14, 32);
      v16 = DName::operator+(v15, v64, v65);
      v17 = v16->node;
      v18 = *((_DWORD *)v16 + 1);
      msExtension.node = v17;
      *((_DWORD *)&msExtension + 1) = v18;
      goto LABEL_22;
    }
    goto LABEL_22;
  }
  if ( *v8 )
    UnDecorator::gName = v8 + 1;
  if ( v11 > 0x1F )
    goto LABEL_35;
  DName::operator=(&ditType, prType);
  v25 = DName::operator+(&szComPlusIndirSpecifier, &v66, &ditType);
  v26 = v25->node;
  v27 = *((_DWORD *)v25 + 1);
  ditType.node = v26;
  *((_DWORD *)&ditType + 1) = v27;
  if ( msExtension.node )
  {
    v28 = DName::operator+(&ditType, &v67, 32);
    v29 = DName::operator+(v28, &v66, &msExtension);
    v30 = v29->node;
    v31 = *((_DWORD *)v29 + 1);
    ditType.node = v30;
    *((_DWORD *)&ditType + 1) = v31;
  }
  if ( name.node )
  {
    v32 = DName::operator+(&name, &v67, 32);
    v33 = DName::operator+(v32, &v66, &ditType);
    v34 = v33->node;
    v35 = *((_DWORD *)v33 + 1);
    ditType.node = v34;
    *((_DWORD *)&ditType + 1) = v35;
  }
  if ( (v11 & 0x10) == 0 )
    goto LABEL_46;
  if ( thisFlag )
    goto LABEL_35;
  if ( !prType )
  {
    if ( *UnDecorator::gName )
    {
      Scope = UnDecorator::getScope(&v66);
      DName::operator|=(&ditType, Scope);
      goto LABEL_43;
    }
LABEL_44:
    DName::operator+=(&ditType, DN_truncated);
LABEL_46:
    if ( (UnDecorator::disableFlags & 2) != 0 )
    {
      if ( (v11 & 0xC) == 0xC )
      {
        BasedType = UnDecorator::getBasedType(&v66);
        DName::operator|=(&ditType, BasedType);
      }
    }
    else if ( (v11 & 0xC) == 0xC )
    {
      if ( thisFlag )
        goto LABEL_35;
      v45 = UnDecorator::getBasedType(&v67);
      v46 = DName::operator+(v45, &v66, &ditType);
      v47 = v46->node;
      v48 = *((_DWORD *)v46 + 1);
      ditType.node = v47;
      *((_DWORD *)&ditType + 1) = v48;
    }
    if ( (v11 & 2) != 0 )
    {
      v50 = operator+(&v66, "volatile ", &ditType);
      v51 = v50->node;
      v52 = *((_DWORD *)v50 + 1);
      ditType.node = v51;
      *((_DWORD *)&ditType + 1) = v52;
    }
    if ( (v11 & 1) != 0 )
    {
      v53 = operator+(&v66, "const ", &ditType);
      v54 = v53->node;
      v55 = *((_DWORD *)v53 + 1);
      ditType.node = v54;
      *((_DWORD *)&ditType + 1) = v55;
    }
    if ( thisFlag )
      goto LABEL_66;
    v56 = superType;
    if ( superType->node )
    {
      v57 = *((_DWORD *)superType + 1);
      if ( (v57 & 0x100) == 0 && cvType->node )
      {
        v58 = operator+(&v68, 32, cvType);
        v59 = DName::operator+(v58, &v67, 32);
        v60 = DName::operator+(v59, &v66, superType);
LABEL_65:
        DName::operator+=(&ditType, v60);
        goto LABEL_66;
      }
      if ( (v57 & 0x800) != 0 )
      {
        ditType.node = superType->node;
        *((_DWORD *)&ditType + 1) = v57;
LABEL_66:
        v7 = *((_DWORD *)&ditType + 1) | 0x100;
        if ( bIsPinPtr )
          v7 = *((_DWORD *)&ditType + 1) | 0x2100;
        v6 = result;
        result->node = ditType.node;
        goto LABEL_5;
      }
    }
    else
    {
      v56 = cvType;
      if ( !cvType->node )
        goto LABEL_66;
    }
    v60 = operator+(&v66, 32, v56);
    goto LABEL_65;
  }
  v36 = operator+(&v66, "::", &ditType);
  v37 = v36->node;
  *((_DWORD *)&ditType + 1) = *((_DWORD *)v36 + 1);
  v38 = *UnDecorator::gName == 0;
  ditType.node = v37;
  if ( v38 )
  {
    v40 = operator+(&v66, DN_truncated, &ditType);
  }
  else
  {
    v39 = UnDecorator::getScope(&v67);
    v40 = DName::operator+(v39, &v66, &ditType);
  }
  v41 = v40->node;
  v42 = *((_DWORD *)v40 + 1);
  ditType.node = v41;
  *((_DWORD *)&ditType + 1) = v42;
LABEL_43:
  v44 = *UnDecorator::gName;
  if ( !*UnDecorator::gName )
    goto LABEL_44;
  ++UnDecorator::gName;
  if ( v44 == 64 )
    goto LABEL_46;
LABEL_35:
  DName::DName(result, DN_invalid);
  return result;
}


DName *__cdecl UnDecorator::getDataIndirectType(DName *result)
{
  DName superType; // [esp+0h] [ebp-10h] BYREF
  DName cvType; // [esp+8h] [ebp-8h] BYREF

  *((_DWORD *)&cvType + 1) &= 0xFFFF0000;
  *((_DWORD *)&superType + 1) &= 0xFFFF0000;
  cvType.node = 0;
  superType.node = 0;
  UnDecorator::getDataIndirectType(result, &superType, 0, &cvType, 0);
  return result;
}
