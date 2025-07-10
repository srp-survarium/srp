DName *__cdecl UnDecorator::getEnumType(DName *result)
{
  char v1; // al
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  DName *v6; // eax
  DNameNode *node; // ecx
  int v8; // edx
  DName *v9; // eax
  DName v10; // [esp+0h] [ebp-10h] BYREF
  DName ecsuName; // [esp+8h] [ebp-8h] BYREF

  v1 = *UnDecorator::gName;
  ecsuName.node = 0;
  *((_DWORD *)&ecsuName + 1) &= 0xFFFF0000;
  if ( v1 )
  {
    switch ( v1 )
    {
      case '0':
      case '1':
        DName::operator=(&ecsuName, "char ");
        break;
      case '2':
      case '3':
        DName::operator=(&ecsuName, "short ");
        break;
      case '4':
        break;
      case '5':
        DName::operator=(&ecsuName, "int ");
        break;
      case '6':
      case '7':
        DName::operator=(&ecsuName, "long ");
        break;
      default:
        DName::DName(result, DN_invalid);
        return result;
    }
    v2 = *UnDecorator::gName++;
    v3 = v2 - 49;
    if ( v3 && (v4 = v3 - 2) != 0 && (v5 = v4 - 2) != 0 && v5 != 2 )
    {
      v8 = *((_DWORD *)&ecsuName + 1);
      node = ecsuName.node;
    }
    else
    {
      v6 = operator+(&v10, "unsigned ", &ecsuName);
      node = v6->node;
      v8 = *((_DWORD *)v6 + 1);
    }
    v9 = result;
    result->node = node;
    *((_DWORD *)result + 1) = v8;
  }
  else
  {
    DName::DName(result, DN_truncated);
    return result;
  }
  return v9;
}
