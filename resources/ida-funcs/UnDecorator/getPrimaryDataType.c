DName *__cdecl UnDecorator::getPrimaryDataType(DName *result, DName *superType)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax
  DNameNode *node; // eax
  int v6; // esi
  char v7; // al
  const char *v8; // edx
  const DName *DataIndirectType; // eax
  DName v11; // [esp+8h] [ebp-18h] BYREF
  DName superName; // [esp+10h] [ebp-10h] BYREF
  DName cvType; // [esp+18h] [ebp-8h] BYREF

  v2 = *UnDecorator::gName;
  *((_DWORD *)&cvType + 1) &= 0xFFFF0000;
  cvType.node = 0;
  if ( !v2 )
    goto LABEL_19;
  v3 = v2 - 36;
  if ( !v3 )
  {
    v7 = UnDecorator::gName[1];
    if ( v7 == 36 )
    {
      v8 = UnDecorator::gName + 2;
      UnDecorator::gName = v8;
      if ( *v8 )
      {
        switch ( *v8 )
        {
          case 'A':
            UnDecorator::gName = v8 + 1;
            UnDecorator::getFunctionIndirectType(result, superType);
            return result;
          case 'B':
            UnDecorator::gName = v8 + 1;
            UnDecorator::getPtrRefDataType(result, superType, 1);
            return result;
          case 'C':
            *((_DWORD *)&cvType + 1) &= 0xFFFF0000;
            UnDecorator::gName = v8 + 1;
            cvType.node = 0;
            DataIndirectType = UnDecorator::getDataIndirectType(&v11, superType, 0, &cvType, 0);
            UnDecorator::getBasicDataType(result, DataIndirectType);
            return result;
        }
        goto LABEL_11;
      }
    }
    else if ( v7 )
    {
LABEL_11:
      DName::DName(result, DN_invalid);
      return result;
    }
LABEL_19:
    operator+(result, DN_truncated, superType);
    return result;
  }
  v4 = v3 - 29;
  if ( !v4 )
  {
LABEL_8:
    node = superType->node;
    v6 = *((_DWORD *)superType + 1);
    ++UnDecorator::gName;
    superName.node = node;
    *((_DWORD *)&superName + 1) = v6 | 0x100;
    UnDecorator::getReferenceType(result, &cvType, &superName);
    return result;
  }
  if ( v4 == 1 )
  {
    DName::operator=(&cvType, "volatile");
    if ( superType->node )
      DName::operator+=(&cvType, 32);
    goto LABEL_8;
  }
  UnDecorator::getBasicDataType(result, superType);
  return result;
}
