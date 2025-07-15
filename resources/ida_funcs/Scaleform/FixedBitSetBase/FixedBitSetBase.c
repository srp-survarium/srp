void __thiscall Scaleform::FixedBitSetBase<Scaleform::AllocatorDH<unsigned char,341>>::FixedBitSetBase<Scaleform::AllocatorDH<unsigned char,341>>(
        Scaleform::FixedBitSetBase<Scaleform::AllocatorDH<unsigned char,341> > *this,
        int other)
{
  const Scaleform::FixedBitSetBase<Scaleform::AllocatorDH<unsigned char,341> > *v2; // ebx
  unsigned int v3; // eax
  unsigned int v5; // esi
  Scaleform::MemoryHeap *v6; // eax
  void *(__thiscall *Alloc)(Scaleform::MemoryHeap *, unsigned int, const Scaleform::AllocInfo *); // edx
  unsigned __int8 *v8; // eax

  v2 = (const Scaleform::FixedBitSetBase<Scaleform::AllocatorDH<unsigned char,341> > *)other;
  v3 = *(_DWORD *)(other + 4);
  this->BitsCount = v3;
  v5 = (v3 + 7) >> 3;
  v6 = Scaleform::Memory::pGlobalHeap->GetAllocHeap(Scaleform::Memory::pGlobalHeap, v2->pData);
  Alloc = v6->Alloc;
  other = 341;
  v8 = (unsigned __int8 *)Alloc(v6, v5, (const Scaleform::AllocInfo *)&other);
  this->pData = v8;
  memcpy(v8, v2->pData, v5);
}
