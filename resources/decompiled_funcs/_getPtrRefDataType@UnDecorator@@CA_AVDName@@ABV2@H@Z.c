DName *__cdecl UnDecorator::getPtrRefDataType(DName *result, DName *superType, int isPtr)
{
  int v3; // eax
  DName *v4; // eax
  int v5; // ecx
  DName *v6; // eax
  DName v7; // [esp+0h] [ebp-10h] BYREF
  DName bdt; // [esp+8h] [ebp-8h] BYREF

  if ( !*UnDecorator::gName )
  {
    operator+(result, DN_truncated, superType);
    return result;
  }
  if ( isPtr && *UnDecorator::gName == 88 )
  {
    ++UnDecorator::gName;
    if ( superType->node )
      operator+(result, "void ", superType);
    else
      DName::DName(result, "void");
    return result;
  }
  if ( *UnDecorator::gName != 89 )
  {
    UnDecorator::getBasicDataType(&bdt, superType);
    v3 = *((_DWORD *)superType + 1);
    if ( (v3 & 0x4000) != 0 )
    {
      v4 = operator+(&v7, "cli::array<", &bdt);
    }
    else
    {
      if ( (v3 & 0x2000) == 0 )
      {
        v5 = *((_DWORD *)&bdt + 1);
        goto LABEL_15;
      }
      v4 = operator+(&v7, "cli::pin_ptr<", &bdt);
    }
    bdt.node = v4->node;
    v5 = *((_DWORD *)v4 + 1);
LABEL_15:
    v6 = result;
    result->node = bdt.node;
    *((_DWORD *)result + 1) = v5;
    return v6;
  }
  ++UnDecorator::gName;
  UnDecorator::getArrayType(result, superType);
  return result;
}
