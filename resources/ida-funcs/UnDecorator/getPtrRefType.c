DName *__cdecl UnDecorator::getPtrRefType(DName *result, const DName *cvType, const DName *superType, char ptrChar)
{
  char v4; // al
  DName *v5; // eax
  DName superTypea; // [esp+8h] [ebp-8h] BYREF

  v4 = *UnDecorator::gName;
  if ( *UnDecorator::gName )
  {
    if ( v4 >= 54 && v4 <= 57 || v4 == 95 )
    {
      DName::operator=(&superTypea, ptrChar);
      if ( cvType->node && (!superType->node || (*((_DWORD *)superType + 1) & 0x100) == 0) )
        DName::operator+=(&superTypea, cvType);
      if ( superType->node )
        DName::operator+=(&superTypea, superType);
      UnDecorator::getFunctionIndirectType(result, &superTypea);
    }
    else
    {
      UnDecorator::getDataIndirectType(&superTypea, superType, ptrChar, cvType, 0);
      UnDecorator::getPtrRefDataType(result, &superTypea, ptrChar == 42);
    }
    return result;
  }
  else
  {
    DName::DName(&superTypea, DN_truncated);
    DName::operator+=(&superTypea, ptrChar);
    if ( cvType->node )
      DName::operator+=(&superTypea, cvType);
    if ( superType->node )
    {
      if ( cvType->node )
        DName::operator+=(&superTypea, 32);
      DName::operator+=(&superTypea, superType);
    }
    v5 = result;
    *result = superTypea;
  }
  return v5;
}
