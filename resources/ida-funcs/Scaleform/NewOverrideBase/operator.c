int __cdecl Scaleform::NewOverrideBase<75>::operator new(unsigned int sz, Scaleform::MemAddressStub *adr)
{
  int v2; // ecx
  void *(__thiscall *AllocAutoHeap)(Scaleform::MemoryHeap *, const void *, unsigned int, const Scaleform::AllocInfo *); // eax
  int v5; // [esp+0h] [ebp-4h] BYREF

  v5 = v2;
  AllocAutoHeap = Scaleform::Memory::pGlobalHeap->AllocAutoHeap;
  v5 = 75;
  return (int)AllocAutoHeap(Scaleform::Memory::pGlobalHeap, adr, sz, (const Scaleform::AllocInfo *)&v5);
}
