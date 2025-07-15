DName *__cdecl UnDecorator::getOperatorName(DName *result, bool fIsTemplate, bool *pfReadTemplateArguments)
{
  int v3; // edx
  int v4; // esi
  const char *v5; // eax
  DName *v6; // eax
  DNameNode *v7; // ecx
  int v8; // eax
  DNameNode *node; // ecx
  DName *v10; // eax
  int v11; // ecx
  const DName *TemplateArgumentList; // eax
  const DName *v13; // eax
  const char *v14; // esi
  DName *ZName; // eax
  int v16; // eax
  DName *v17; // eax
  int v18; // eax
  int v19; // ecx
  int v20; // ecx
  int v21; // ecx
  int v22; // ecx
  unsigned int v23; // eax
  int v24; // eax
  DName *SignedDimension; // eax
  const DName *v26; // eax
  DName *v27; // eax
  const DName *v28; // eax
  DName *v29; // eax
  const DName *v30; // eax
  DName *Dimension; // eax
  const DName *v32; // eax
  DName *v33; // eax
  DName *p_operatorName; // ecx
  DName *v35; // eax
  DNameNode *v36; // ecx
  int v37; // eax
  int v38; // ecx
  const char *v39; // eax
  const DName *DecoratedName; // eax
  const DName *SymbolName; // eax
  DName *v42; // [esp-8h] [ebp-B0h]
  DName v43; // [esp+8h] [ebp-A0h] BYREF
  DName v44; // [esp+10h] [ebp-98h] BYREF
  DName v45; // [esp+18h] [ebp-90h] BYREF
  DName v46; // [esp+20h] [ebp-88h] BYREF
  DName v47; // [esp+28h] [ebp-80h] BYREF
  DName v48; // [esp+30h] [ebp-78h] BYREF
  DName v49; // [esp+38h] [ebp-70h] BYREF
  DName v50; // [esp+40h] [ebp-68h] BYREF
  DName v51; // [esp+48h] [ebp-60h] BYREF
  DName v52; // [esp+50h] [ebp-58h] BYREF
  DName v53; // [esp+58h] [ebp-50h] BYREF
  DName v54; // [esp+60h] [ebp-48h] BYREF
  DName v55; // [esp+68h] [ebp-40h] BYREF
  DName v56; // [esp+70h] [ebp-38h] BYREF
  DName v57; // [esp+78h] [ebp-30h] BYREF
  DName v58; // [esp+80h] [ebp-28h] BYREF
  DName v59; // [esp+88h] [ebp-20h] BYREF
  DName templateArguments; // [esp+90h] [ebp-18h] BYREF
  DName name; // [esp+98h] [ebp-10h] BYREF
  DName operatorName; // [esp+A0h] [ebp-8h] BYREF

  v3 = *UnDecorator::gName;
  *((_DWORD *)&operatorName + 1) &= 0xFFFF0000;
  *((_DWORD *)&templateArguments + 1) &= 0xFFFF0000;
  v4 = 0;
  v5 = UnDecorator::gName + 1;
  operatorName.node = 0;
  templateArguments.node = 0;
  ++UnDecorator::gName;
  if ( v3 <= 65 )
  {
    if ( v3 != 65 )
    {
      if ( v3 )
      {
        if ( v3 > 47 )
        {
          if ( v3 > 49 )
          {
            if ( v3 <= 57 )
            {
              DName::operator=(&operatorName, *(char **)&asc_820378[4 * *(v5 - 1)]);
              goto LABEL_8;
            }
            goto LABEL_68;
          }
          *((_DWORD *)&templateArguments + 1) &= 0xFFFF0000;
          templateArguments.node = 0;
          if ( fIsTemplate )
          {
            TemplateArgumentList = UnDecorator::getTemplateArgumentList(&v52);
            v13 = operator+(&v43, 60, TemplateArgumentList);
            DName::operator+=(&templateArguments, v13);
            if ( templateArguments.node && templateArguments.node->getLastChar(templateArguments.node) == 62 )
              DName::operator+=(&templateArguments, 32);
            DName::operator+=(&templateArguments, 62);
            if ( pfReadTemplateArguments )
              *pfReadTemplateArguments = 1;
            if ( !*UnDecorator::gName )
            {
              v10 = result;
              result->node = templateArguments.node;
              v11 = *((_DWORD *)&templateArguments + 1);
              goto LABEL_12;
            }
            v5 = ++UnDecorator::gName;
          }
          v14 = v5;
          ZName = UnDecorator::getZName(&v56, 0, 0);
          node = ZName->node;
          v16 = *((_DWORD *)ZName + 1);
          operatorName.node = node;
          *((_DWORD *)&operatorName + 1) = v16;
          UnDecorator::gName = v14;
          if ( node && *(v14 - 1) == 49 )
          {
            v17 = operator+(&v46, 126, &operatorName);
            node = v17->node;
            v18 = *((_DWORD *)v17 + 1);
            operatorName.node = node;
            *((_DWORD *)&operatorName + 1) = v18;
          }
          if ( !templateArguments.node )
          {
LABEL_11:
            v10 = result;
            result->node = node;
            v11 = *((_DWORD *)&operatorName + 1);
LABEL_12:
            *((_DWORD *)v10 + 1) = v11;
            return v10;
          }
          DName::operator+=(&operatorName, &templateArguments);
LABEL_10:
          node = operatorName.node;
          goto LABEL_11;
        }
        goto LABEL_68;
      }
      goto LABEL_27;
    }
LABEL_88:
    DName::operator=(&operatorName, *(char **)&asc_82035C[4 * *(v5 - 1)]);
    if ( v4 )
    {
      if ( operatorName.node )
        *((_DWORD *)&operatorName + 1) |= 0x200u;
      goto LABEL_10;
    }
    goto LABEL_8;
  }
  if ( v3 == 66 )
  {
    v4 = 1;
    goto LABEL_88;
  }
  if ( v3 <= 90 )
    goto LABEL_88;
  if ( v3 != 95 )
    goto LABEL_68;
  v19 = *v5++;
  UnDecorator::gName = v5;
  if ( v19 > 79 )
  {
    if ( v19 > 84 )
    {
      if ( v19 <= 86 )
      {
        DName::operator=(&operatorName, *(char **)&aCdecl[4 * *(v5 - 1)]);
        goto LABEL_8;
      }
      if ( v19 <= 87 )
        goto LABEL_68;
      if ( v19 > 89 )
      {
        if ( v19 == 95 )
        {
          v38 = *v5;
          v39 = v5 + 1;
          UnDecorator::gName = v39;
          if ( v38 >= 65 )
          {
            if ( v38 <= 68 )
              goto LABEL_79;
            if ( v38 <= 70 )
            {
              DName::DName(&name, (char *)nameTable[*(v39 - 1) + 4]);
              if ( *UnDecorator::gName == 63 )
              {
                DecoratedName = UnDecorator::getDecoratedName(&v45);
                DName::operator+=(&name, DecoratedName);
                if ( *UnDecorator::gName == 64 )
                  ++UnDecorator::gName;
              }
              else
              {
                SymbolName = UnDecorator::getSymbolName(&v59);
                DName::operator+=(&name, SymbolName);
              }
              DName::operator+=(&name, "''");
              v10 = result;
              result->node = name.node;
              v11 = *((_DWORD *)&name + 1);
              goto LABEL_12;
            }
            if ( v38 <= 74 )
            {
LABEL_79:
              DName::DName(result, (char *)nameTable[*(v39 - 1) + 4]);
              return result;
            }
          }
        }
        goto LABEL_68;
      }
      goto LABEL_85;
    }
    if ( v19 >= 83 )
      goto LABEL_85;
    v21 = v19 - 80;
    if ( v21 )
    {
      v22 = v21 - 1;
      if ( !v22 )
        goto LABEL_10;
      if ( v22 != 1 )
      {
LABEL_68:
        DName::DName(result, DN_invalid);
        return result;
      }
      DName::operator=(&operatorName, *(char **)&aCdecl[4 * *(v5 - 1)]);
      if ( !*UnDecorator::gName )
      {
        DName::operator+(&operatorName, result, DN_truncated);
        return result;
      }
      v23 = *UnDecorator::gName - 48;
      if ( v23 > 4 )
        goto LABEL_68;
      DName::operator=(&templateArguments, (char *)rttiTable[v23]);
      v24 = *UnDecorator::gName++;
      if ( v24 == 48 )
      {
        UnDecorator::getDataType(&name, 0);
        v42 = result;
        v33 = DName::operator+(&name, &v49, 32);
        p_operatorName = DName::operator+(v33, &v51, &operatorName);
LABEL_70:
        DName::operator+(p_operatorName, v42, &templateArguments);
        return result;
      }
      if ( v24 == 49 )
      {
        DName::operator+(&operatorName, &name, &templateArguments);
        SignedDimension = UnDecorator::getSignedDimension(&v48);
        v26 = DName::operator+(SignedDimension, &v54, 44);
        DName::operator+=(&name, v26);
        v27 = UnDecorator::getSignedDimension(&v44);
        v28 = DName::operator+(v27, &v58, 44);
        DName::operator+=(&name, v28);
        v29 = UnDecorator::getSignedDimension(&v57);
        v30 = DName::operator+(v29, &v50, 44);
        DName::operator+=(&name, v30);
        Dimension = UnDecorator::getDimension(&v53, 0);
        v32 = DName::operator+(Dimension, &v55, 41);
        DName::operator+=(&name, v32);
        DName::operator+(&name, result, 39);
        return result;
      }
      if ( (unsigned int)(v24 - 50) > 2 )
      {
        --UnDecorator::gName;
        goto LABEL_28;
      }
    }
    else
    {
      DName::operator=(&operatorName, *(char **)&aCdecl[4 * *(v5 - 1)]);
      v35 = UnDecorator::getOperatorName(&v47, 0, 0);
      v36 = v35->node;
      v37 = *((_DWORD *)v35 + 1);
      templateArguments.node = v36;
      *((_DWORD *)&templateArguments + 1) = v37;
      if ( v36 && (v37 & 0x400) != 0 )
        goto LABEL_68;
    }
    v42 = result;
    p_operatorName = &operatorName;
    goto LABEL_70;
  }
  if ( v19 >= 68 )
    goto LABEL_85;
  if ( v19 > 57 )
  {
    if ( v19 == 63 )
    {
      v20 = *v5++;
      UnDecorator::gName = v5;
      if ( !v20 )
        goto LABEL_27;
      if ( v20 != 48 )
        goto LABEL_68;
      UnDecorator::getStringEncoding(&name, "`anonymous namespace'");
      goto LABEL_48;
    }
    if ( v19 <= 64 )
      goto LABEL_68;
    if ( v19 > 66 )
    {
      UnDecorator::getStringEncoding(&name, "`string'");
LABEL_48:
      v11 = *((_DWORD *)&name + 1) | 0x1000;
      goto LABEL_43;
    }
LABEL_85:
    DName::DName(result, *(char **)&aCdecl[4 * *(v5 - 1)]);
    return result;
  }
  if ( v19 == 57 )
  {
    DName::DName(&name, (char *)tokenTable[*(v5 - 1) + 2]);
    v11 = *((_DWORD *)&name + 1) | 0x8000;
LABEL_43:
    v10 = result;
    result->node = name.node;
    goto LABEL_12;
  }
  if ( v19 )
  {
    if ( v19 <= 47 )
      goto LABEL_68;
    if ( v19 > 54 )
    {
      DName::DName(result, (char *)tokenTable[*(v5 - 1) + 2]);
      return result;
    }
    DName::operator=(&operatorName, (char *)tokenTable[*(v5 - 1) + 2]);
LABEL_8:
    if ( operatorName.node )
    {
      v6 = operator+(&v59, "operator", &operatorName);
      v7 = v6->node;
      v8 = *((_DWORD *)v6 + 1);
      operatorName.node = v7;
      *((_DWORD *)&operatorName + 1) = v8;
    }
    goto LABEL_10;
  }
LABEL_27:
  UnDecorator::gName = v5 - 1;
LABEL_28:
  DName::DName(result, DN_truncated);
  return result;
}
