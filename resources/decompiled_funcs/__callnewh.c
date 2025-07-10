BOOL __cdecl _callnewh(unsigned int size)
{
  int (__cdecl *v1)(unsigned int); // eax

  v1 = (int (__cdecl *)(unsigned int))_decode_pointer(_pnhHeap);
  return v1 && v1(size);
}
