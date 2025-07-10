DName *__cdecl UnDecorator::getExternalDataType(DName *result, const DName *superType)
{
  char *Memory; // eax
  DName *v3; // esi
  DName *v4; // eax
  const DName *v5; // eax
  DName v7; // [esp+4h] [ebp-18h] BYREF
  DName v8; // [esp+Ch] [ebp-10h] BYREF
  DName v9; // [esp+14h] [ebp-8h] BYREF

  Memory = HeapManager::getMemory(&heap, 8u, 0);
  if ( Memory )
  {
    *(_DWORD *)Memory = 0;
    Memory[4] = 0;
    *((_DWORD *)Memory + 1) &= 0xFFFF00FF;
    v3 = (DName *)Memory;
  }
  else
  {
    v3 = 0;
  }
  UnDecorator::getDataType(result, v3);
  UnDecorator::getDataIndirectType(&v9);
  v4 = DName::operator+(&v9, &v7, 32);
  v5 = DName::operator+(v4, &v8, superType);
  DName::operator=(v3, v5);
  return result;
}
