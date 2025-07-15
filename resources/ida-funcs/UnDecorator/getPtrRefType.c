DName *__cdecl UnDecorator::getPtrRefType(DName *result, const DName *cvType, const DName *superType, char ptrChar)
{
  char v4; // al
  DName *v5; // eax
  DName trunk; // [esp+8h] [ebp-8h] BYREF

  v4 = *UnDecorator::gName;
  if ( *UnDecorator::gName )
  {
    if ( v4 >= 54 && v4 <= 57 || v4 == 95 )
    {
      DName::operator=(&trunk, ptrChar);
      if ( cvType->node && (!superType->node || (*((_DWORD *)superType + 1) & 0x100) == 0) )
        DName::operator+=(&trunk, cvType);
      if ( superType->node )
        DName::operator+=(&trunk, superType);
      UnDecorator::getFunctionIndirectType(result, &trunk);
    }
    else
    {
      UnDecorator::getDataIndirectType(&trunk, superType, ptrChar, cvType, 0);
      UnDecorator::getPtrRefDataType(result, &trunk, ptrChar == 42);
    }
    return result;
  }
  else
  {
    DName::DName(&trunk, DN_truncated);
    DName::operator+=(&trunk, ptrChar);
    if ( cvType->node )
      DName::operator+=(&trunk, cvType);
    if ( superType->node )
    {
      if ( cvType->node )
        DName::operator+=(&trunk, 32);
      DName::operator+=(&trunk, superType);
    }
    v5 = result;
    *result = trunk;
  }
  return v5;
}
