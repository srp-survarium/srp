void __thiscall Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::AS3::Value const *,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        Scaleform::ArrayDataBase<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<Scaleform::GFx::ASString,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  unsigned int v4; // esi
  Scaleform::Pair<Scaleform::GFx::ASString,unsigned long> *v5; // eax
  int (__thiscall *v6)(const void *, unsigned int, unsigned int *); // edx

  if ( newCapacity )
  {
    v4 = 4 * ((newCapacity + 3) >> 2);
    if ( this->Data )
    {
      v5 = (Scaleform::Pair<Scaleform::GFx::ASString,unsigned long> *)Scaleform::Memory::pGlobalHeap->Realloc(
                                                                        Scaleform::Memory::pGlobalHeap,
                                                                        this->Data,
                                                                        32 * ((newCapacity + 3) >> 2));
    }
    else
    {
      v6 = *(int (__thiscall **)(const void *, unsigned int, unsigned int *))(*(_DWORD *)pheapAddr + 40);
      newCapacity = 2;
      v5 = (Scaleform::Pair<Scaleform::GFx::ASString,unsigned long> *)v6(pheapAddr, 8 * v4, &newCapacity);
    }
    this->Policy.Capacity = v4;
    this->Data = v5;
  }
  else
  {
    if ( this->Data )
    {
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Data);
      this->Data = 0;
    }
    this->Policy.Capacity = 0;
  }
}
