void __thiscall Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::TraitInfo *,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::TraitInfo *,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
        Scaleform::ArrayDataBase<int,Scaleform::AllocatorLH_POD<int,338>,Scaleform::ArrayDefaultPolicy> *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  unsigned int v4; // esi
  int *v5; // eax

  if ( newCapacity )
  {
    v4 = 4 * ((newCapacity + 3) >> 2);
    if ( this->Data )
    {
      v5 = (int *)Scaleform::Memory::pGlobalHeap->Realloc(
                    Scaleform::Memory::pGlobalHeap,
                    this->Data,
                    16 * ((newCapacity + 3) >> 2));
    }
    else
    {
      newCapacity = 338;
      v5 = (int *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                    Scaleform::Memory::pGlobalHeap,
                    pheapAddr,
                    4 * v4,
                    &newCapacity);
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
