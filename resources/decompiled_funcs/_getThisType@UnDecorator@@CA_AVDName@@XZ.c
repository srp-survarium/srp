DName *__cdecl UnDecorator::getThisType(DName *result)
{
  DName superType; // [esp+0h] [ebp-10h] BYREF
  DName cvType; // [esp+8h] [ebp-8h] BYREF

  *((_DWORD *)&cvType + 1) &= 0xFFFF0000;
  *((_DWORD *)&superType + 1) &= 0xFFFF0000;
  cvType.node = 0;
  superType.node = 0;
  UnDecorator::getDataIndirectType(result, &superType, 0, &cvType, 1);
  return result;
}
