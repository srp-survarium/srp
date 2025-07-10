char *__thiscall Scaleform::StackMemPool<512,4,Scaleform::MemPoolImmediateFree>::Alloc(
        Scaleform::StackMemPool<512,4,Scaleform::MemPoolImmediateFree> *this,
        unsigned int nbytes)
{
  char *result; // eax
  unsigned int v3; // edx
  Scaleform::MemoryHeap *pHeap; // ecx

  if ( nbytes > this->BuffSize )
  {
    pHeap = this->pHeap;
    if ( !pHeap )
      pHeap = Scaleform::Memory::pGlobalHeap;
    return (char *)pHeap->Alloc(pHeap, nbytes, 4u, 0);
  }
  else
  {
    result = this->BuffPtr;
    this->BuffPtr = (char *)(((unsigned int)&result[nbytes - 1] & 0xFFFFFFFC) + 4);
    v3 = ((unsigned int)&result[nbytes - 1] & 0xFFFFFFFC) - (_DWORD)this;
    if ( v3 >= 0x200 )
      this->BuffSize = 0;
    else
      this->BuffSize = 512 - v3;
  }
  return result;
}
