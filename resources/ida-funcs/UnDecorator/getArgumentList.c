DName *__cdecl UnDecorator::getArgumentList(DName *result)
{
  const char *v1; // edi
  unsigned int v2; // eax
  DName *v3; // eax
  DName v5; // [esp+8h] [ebp-1Ch] BYREF
  DName arg; // [esp+10h] [ebp-14h] BYREF
  DName superType; // [esp+18h] [ebp-Ch] BYREF
  int first; // [esp+20h] [ebp-4h]

  *((_BYTE *)result + 4) = 0;
  *((_DWORD *)result + 1) &= 0xFFFF00FF;
  first = 1;
  result->node = 0;
  if ( !*((_BYTE *)result + 4) )
  {
    while ( *UnDecorator::gName != 64 && *UnDecorator::gName != 90 )
    {
      if ( first )
        first = 0;
      else
        DName::operator+=(result, 44);
      v1 = UnDecorator::gName;
      if ( !*UnDecorator::gName )
      {
        DName::operator+=(result, DN_truncated);
        return result;
      }
      v2 = *UnDecorator::gName - 48;
      if ( v2 > 9 )
      {
        *((_DWORD *)&superType + 1) &= 0xFFFF0000;
        superType.node = 0;
        UnDecorator::getPrimaryDataType(&arg, &superType);
        if ( UnDecorator::gName - v1 > 1 && UnDecorator::pArgList->index != 9 )
          Replicator::operator+=(UnDecorator::pArgList, &arg);
        DName::operator+=(result, &arg);
        if ( UnDecorator::gName == v1 )
          DName::operator=(result, DN_invalid);
      }
      else
      {
        ++UnDecorator::gName;
        v3 = Replicator::operator[](UnDecorator::pArgList, &v5, v2);
        DName::operator+=(result, v3);
      }
      if ( *((_BYTE *)result + 4) )
        return result;
    }
  }
  return result;
}
