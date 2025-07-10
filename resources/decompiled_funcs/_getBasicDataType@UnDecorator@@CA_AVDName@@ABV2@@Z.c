DName *__cdecl UnDecorator::getBasicDataType(DName *result, const DName *superType)
{
  unsigned __int8 v2; // al
  int v3; // edi
  int v4; // ebx
  unsigned __int8 v5; // al
  const DName *BasicDataType; // eax
  DName *p_superName; // eax
  DName *ECSUDataType; // eax
  int v9; // edx
  DName *v10; // eax
  DNameNode *v11; // edx
  int v12; // edx
  int v13; // ecx
  DName *v14; // eax
  DNameNode *node; // ecx
  int v16; // eax
  const DName *v17; // eax
  DName v18; // [esp+Ch] [ebp-24h] BYREF
  DName arType; // [esp+14h] [ebp-1Ch] BYREF
  DName superName; // [esp+1Ch] [ebp-14h] BYREF
  DName cvType; // [esp+24h] [ebp-Ch] BYREF
  unsigned __int8 extended_bdtCode; // [esp+2Fh] [ebp-1h]

  v2 = *UnDecorator::gName;
  if ( !*UnDecorator::gName )
  {
    operator+(result, DN_truncated, superType);
    return result;
  }
  ++UnDecorator::gName;
  cvType.node = 0;
  v3 = v2;
  *((_DWORD *)&cvType + 1) &= 0xFFFF0000;
  v4 = -1;
  extended_bdtCode = 0;
  if ( v2 <= 0x4Eu )
  {
    if ( v2 != 78 )
    {
      switch ( v2 )
      {
        case 'C':
        case 'D':
        case 'E':
          DName::operator=(&cvType, "char");
          goto LABEL_55;
        case 'F':
        case 'G':
          DName::operator=(&cvType, "short");
          goto LABEL_55;
        case 'H':
        case 'I':
          DName::operator=(&cvType, "int");
          goto LABEL_55;
        case 'J':
        case 'K':
          DName::operator=(&cvType, "long");
          goto LABEL_55;
        case 'M':
          DName::operator=(&cvType, "float");
          goto LABEL_55;
        default:
          goto LABEL_51;
      }
    }
    goto LABEL_53;
  }
  if ( v2 == 79 )
  {
    DName::operator=(&cvType, "long ");
LABEL_53:
    DName::operator+=(&cvType, "double");
LABEL_54:
    if ( v4 == -1 )
      goto LABEL_55;
    goto LABEL_41;
  }
  if ( v2 <= 0x4Fu )
    goto LABEL_51;
  if ( v2 <= 0x53u )
  {
    v4 = v2 & 3;
    goto LABEL_54;
  }
  if ( v2 == 88 )
  {
    DName::operator=(&cvType, "void");
    goto LABEL_55;
  }
  if ( v2 != 95 )
  {
LABEL_51:
    p_superName = &v18;
LABEL_37:
    --UnDecorator::gName;
    ECSUDataType = UnDecorator::getECSUDataType(p_superName);
    v9 = *((_DWORD *)ECSUDataType + 1);
    cvType.node = ECSUDataType->node;
    *((_DWORD *)&cvType + 1) = v9;
    if ( !cvType.node )
    {
      v10 = result;
      result->node = 0;
      *((_DWORD *)result + 1) = v9;
      return v10;
    }
LABEL_55:
    if ( v3 == 67 )
    {
      v14 = operator+(&superName, "signed ", &cvType);
    }
    else if ( v3 == 69 || v3 == 71 || v3 == 73 || v3 == 75 )
    {
      v14 = operator+(&arType, "unsigned ", &cvType);
    }
    else
    {
      if ( v3 != 95
        || extended_bdtCode != 69
        && extended_bdtCode != 71
        && extended_bdtCode != 73
        && extended_bdtCode != 75
        && extended_bdtCode != 77 )
      {
LABEL_70:
        if ( superType->node )
        {
          v17 = operator+(&v18, 32, superType);
          DName::operator+=(&cvType, v17);
        }
        v10 = result;
        result->node = cvType.node;
        v13 = *((_DWORD *)&cvType + 1);
LABEL_73:
        *((_DWORD *)v10 + 1) = v13;
        return v10;
      }
      v14 = operator+(&v18, "unsigned ", &cvType);
    }
    node = v14->node;
    v16 = *((_DWORD *)v14 + 1);
    cvType.node = node;
    *((_DWORD *)&cvType + 1) = v16;
    goto LABEL_70;
  }
  v5 = *UnDecorator::gName++;
  extended_bdtCode = v5;
  if ( v5 <= 0x4Bu )
  {
    if ( v5 >= 0x4Au )
    {
      DName::operator=(&cvType, "__int64");
      goto LABEL_55;
    }
    if ( v5 > 0x45u )
    {
      if ( v5 >= 0x46u )
      {
        if ( v5 <= 0x47u )
        {
          DName::operator=(&cvType, "__int16");
          goto LABEL_55;
        }
        if ( v5 <= 0x49u )
        {
          DName::operator=(&cvType, "__int32");
          goto LABEL_55;
        }
      }
    }
    else
    {
      if ( v5 >= 0x44u )
      {
        DName::operator=(&cvType, "__int8");
        goto LABEL_55;
      }
      if ( !v5 )
      {
        --UnDecorator::gName;
        DName::operator=(&cvType, DN_truncated);
        goto LABEL_55;
      }
      if ( v5 == 36 )
      {
        BasicDataType = UnDecorator::getBasicDataType(&arType, superType);
        operator+(result, "__w64 ", BasicDataType);
        return result;
      }
    }
LABEL_47:
    DName::operator=(&cvType, "UNKNOWN");
    goto LABEL_55;
  }
  if ( v5 < 0x4Cu )
    goto LABEL_47;
  if ( v5 <= 0x4Du )
  {
    DName::operator=(&cvType, "__int128");
    goto LABEL_55;
  }
  if ( v5 == 78 )
  {
    DName::operator=(&cvType, "bool");
    goto LABEL_55;
  }
  if ( v5 != 79 )
  {
    if ( v5 == 87 )
    {
      DName::operator=(&cvType, "wchar_t");
      goto LABEL_55;
    }
    if ( (unsigned int)v5 - 88 > 1 )
      goto LABEL_47;
    p_superName = &superName;
    goto LABEL_37;
  }
  v4 = -2;
LABEL_41:
  v11 = superType->node;
  *((_DWORD *)&cvType + 1) &= 0xFFFF0000;
  superName.node = v11;
  v12 = *((_DWORD *)superType + 1);
  cvType.node = 0;
  *((_DWORD *)&superName + 1) = v12;
  if ( v4 == -2 )
  {
    *((_DWORD *)&superName + 1) |= 0x800u;
    UnDecorator::getPtrRefType(&arType, &cvType, &superName, 0);
    if ( (*((_WORD *)&arType + 2) & 0x800) == 0 )
      DName::operator+=(&arType, "[]");
    v10 = result;
    result->node = arType.node;
    v13 = *((_DWORD *)&arType + 1);
    goto LABEL_73;
  }
  if ( !superType->node )
  {
    if ( (v4 & 1) != 0 )
    {
      DName::operator=(&cvType, "const");
      if ( (v4 & 2) != 0 )
        DName::operator+=(&cvType, " volatile");
    }
    else if ( (v4 & 2) != 0 )
    {
      DName::operator=(&cvType, "volatile");
    }
  }
  UnDecorator::getPointerType(result, &cvType, &superName);
  return result;
}
