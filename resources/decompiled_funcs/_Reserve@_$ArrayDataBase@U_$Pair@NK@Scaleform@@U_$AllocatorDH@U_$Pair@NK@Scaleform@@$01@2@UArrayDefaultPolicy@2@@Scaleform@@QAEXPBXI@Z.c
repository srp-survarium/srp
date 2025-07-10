void __thiscall Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        Scaleform::ArrayDataBase<Scaleform::Pair<double,unsigned long>,Scaleform::AllocatorDH<Scaleform::Pair<double,unsigned long>,2>,Scaleform::ArrayDefaultPolicy> *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  unsigned int v4; // esi
  Scaleform::Pair<double,unsigned long> *v5; // eax
  int (__thiscall *v6)(const void *, unsigned int, unsigned int *); // edx

  if ( newCapacity )
  {
    v4 = 4 * ((newCapacity + 3) >> 2);
    if ( this->Data )
    {
      v5 = (Scaleform::Pair<double,unsigned long> *)Scaleform::Memory::pGlobalHeap->Realloc(
                                                      Scaleform::Memory::pGlobalHeap,
                                                      this->Data,
                                                      (newCapacity + 3) >> 2 << 6);
    }
    else
    {
      v6 = *(int (__thiscall **)(const void *, unsigned int, unsigned int *))(*(_DWORD *)pheapAddr + 40);
      newCapacity = 2;
      v5 = (Scaleform::Pair<double,unsigned long> *)v6(pheapAddr, 16 * v4, &newCapacity);
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
