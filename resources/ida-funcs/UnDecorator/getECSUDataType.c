DName *__cdecl UnDecorator::getECSUDataType(DName *result)
{
  BOOL v1; // edi
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  const DName *EnumType; // eax
  DName *v9; // eax
  DNameNode *node; // ecx
  int v11; // eax
  DName *v12; // eax
  DName v13; // [esp+8h] [ebp-18h] BYREF
  DName resulta; // [esp+10h] [ebp-10h] BYREF
  DName rd; // [esp+18h] [ebp-8h] BYREF

  v1 = 1;
  if ( ((UnDecorator::disableFlags >> 15) & 1) != 0 || (UnDecorator::disableFlags & 0x1000) != 0 )
    v1 = 0;
  v2 = *UnDecorator::gName;
  rd.node = 0;
  *((_DWORD *)&rd + 1) &= 0xFFFF0000;
  ++UnDecorator::gName;
  if ( v2 )
  {
    v3 = v2 - 84;
    if ( v3 )
    {
      v4 = v3 - 1;
      if ( v4 )
      {
        v5 = v4 - 1;
        if ( v5 )
        {
          v6 = v5 - 1;
          if ( v6 )
          {
            v7 = v6 - 1;
            if ( v7 )
            {
              if ( v7 == 1 )
                DName::operator=(&rd, "cointerface ");
            }
            else
            {
              DName::operator=(&rd, "coclass ");
            }
          }
          else
          {
            v1 = ((UnDecorator::disableFlags >> 15) & 1) == 0;
            EnumType = UnDecorator::getEnumType(&resulta);
            v9 = operator+(&v13, "enum ", EnumType);
            node = v9->node;
            v11 = *((_DWORD *)v9 + 1);
            rd.node = node;
            *((_DWORD *)&rd + 1) = v11;
          }
        }
        else
        {
          DName::operator=(&rd, "class ");
        }
      }
      else
      {
        DName::operator=(&rd, "struct ");
      }
    }
    else
    {
      DName::operator=(&rd, "union ");
    }
    resulta.node = 0;
    *((_DWORD *)&resulta + 1) &= 0xFFFF0000;
    if ( v1 )
      resulta = rd;
    UnDecorator::getScopedName(&rd);
    DName::operator+=(&resulta, &rd);
    v12 = result;
    *result = resulta;
  }
  else
  {
    --UnDecorator::gName;
    DName::DName(result, "unknown ecsu'");
    return result;
  }
  return v12;
}
