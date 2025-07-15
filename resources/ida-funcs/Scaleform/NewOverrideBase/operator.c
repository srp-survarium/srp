void *__cdecl Scaleform::NewOverrideBase<75>::operator new(unsigned int sz, Scaleform::MemAddressStub *adr)
{
  Scaleform::MemoryHeap_vtbl *v2; // eax
  int v4; // [esp+0h] [ebp-4h] BYREF

  v2 = Scaleform::Memory::pGlobalHeap->__vftable;
  v4 = 75;
  return v2->AllocAutoHeap(Scaleform::Memory::pGlobalHeap, adr, sz, (const Scaleform::AllocInfo *)&v4);
}
