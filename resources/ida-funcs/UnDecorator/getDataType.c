DName *__cdecl UnDecorator::getDataType(DName *result, DName *pDeclarator)
{
  char v2; // cl
  DName v4; // [esp+0h] [ebp-18h] BYREF
  DName cvType; // [esp+8h] [ebp-10h] BYREF
  DName superType; // [esp+10h] [ebp-8h] BYREF

  DName::DName(&superType, pDeclarator);
  v2 = *UnDecorator::gName;
  if ( *UnDecorator::gName )
  {
    if ( v2 == 63 )
    {
      ++UnDecorator::gName;
      *((_DWORD *)&cvType + 1) &= 0xFFFF0000;
      cvType.node = 0;
      superType = *UnDecorator::getDataIndirectType(&v4, &superType, 0, &cvType, 0);
      UnDecorator::getPrimaryDataType(result, &superType);
    }
    else if ( v2 == 88 )
    {
      ++UnDecorator::gName;
      if ( superType.node )
        operator+(result, "void ", &superType);
      else
        DName::DName(result, "void");
    }
    else
    {
      UnDecorator::getPrimaryDataType(result, &superType);
    }
  }
  else
  {
    operator+(result, DN_truncated, &superType);
  }
  return result;
}
