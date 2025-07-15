bool __userpurge btPoolAllocator::validPtr@<al>(btPoolAllocator *this@<ecx>, _DWORD *a2@<eax>, unsigned int ptr)
{
  unsigned int v3; // ecx
  bool result; // al

  result = 0;
  if ( ptr )
  {
    v3 = a2[4];
    if ( ptr >= v3 && ptr < v3 + *a2 * a2[1] )
      return 1;
  }
  return result;
}
