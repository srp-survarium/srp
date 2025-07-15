DName *__cdecl UnDecorator::getArgumentTypes(DName *result)
{
  int v1; // ecx
  char v2; // al
  char *v3; // eax
  DName *v4; // eax
  char *v5; // eax
  DName v6; // [esp+0h] [ebp-10h] BYREF
  DName arguments; // [esp+8h] [ebp-8h] BYREF

  if ( *UnDecorator::gName == 88 )
  {
    ++UnDecorator::gName;
    DName::DName(result, "void");
    return result;
  }
  if ( *UnDecorator::gName == 90 )
  {
    ++UnDecorator::gName;
    v5 = "...";
    if ( (UnDecorator::disableFlags & 0x40000) != 0 )
      v5 = "<ellipsis>";
    DName::DName(result, v5);
    return result;
  }
  UnDecorator::getArgumentList(&arguments);
  v1 = *((_DWORD *)&arguments + 1);
  if ( *((_BYTE *)&arguments + 4) || (v2 = *UnDecorator::gName) == 0 )
  {
LABEL_12:
    v4 = result;
    result->node = arguments.node;
    *((_DWORD *)result + 1) = v1;
    return v4;
  }
  if ( v2 == 64 )
  {
    ++UnDecorator::gName;
    goto LABEL_12;
  }
  if ( v2 != 90 )
  {
    DName::DName(result, DN_invalid);
    return result;
  }
  ++UnDecorator::gName;
  v3 = ",...";
  if ( (UnDecorator::disableFlags & 0x40000) != 0 )
    v3 = ",<ellipsis>";
  *result = *DName::operator+(&arguments, &v6, v3);
  return result;
}
