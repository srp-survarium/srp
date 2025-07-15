void *__cdecl Scaleform::AllocatorBaseLH<2>::Alloc(const void *pheapAddr, unsigned int size)
{
  Scaleform::MemoryHeap_vtbl *v2; // eax
  int v4; // [esp+0h] [ebp-4h] BYREF

  v2 = Scaleform::Memory::pGlobalHeap->__vftable;
  v4 = 2;
  return v2->AllocAutoHeap(Scaleform::Memory::pGlobalHeap, pheapAddr, size, (const Scaleform::AllocInfo *)&v4);
}


void *__cdecl Scaleform::AllocatorBaseLH<75>::Alloc(const void *pheapAddr, unsigned int size)
{
  Scaleform::MemoryHeap_vtbl *v2; // eax
  int v4; // [esp+0h] [ebp-4h] BYREF

  v2 = Scaleform::Memory::pGlobalHeap->__vftable;
  v4 = 75;
  return v2->AllocAutoHeap(Scaleform::Memory::pGlobalHeap, pheapAddr, size, (const Scaleform::AllocInfo *)&v4);
}
