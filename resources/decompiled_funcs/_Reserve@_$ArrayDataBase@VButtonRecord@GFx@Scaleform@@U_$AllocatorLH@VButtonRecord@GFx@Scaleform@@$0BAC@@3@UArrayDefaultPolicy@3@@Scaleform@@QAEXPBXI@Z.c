void __thiscall Scaleform::ArrayDataBase<Scaleform::GFx::ButtonRecord,Scaleform::AllocatorLH<Scaleform::GFx::ButtonRecord,258>,Scaleform::ArrayDefaultPolicy>::Reserve(
        Scaleform::ArrayDataBase<Scaleform::GFx::ButtonRecord,Scaleform::AllocatorLH<Scaleform::GFx::ButtonRecord,258>,Scaleform::ArrayDefaultPolicy> *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  unsigned int v4; // esi
  Scaleform::GFx::ButtonRecord *v5; // eax

  if ( newCapacity )
  {
    v4 = 4 * ((newCapacity + 3) >> 2);
    if ( this->Data )
    {
      v5 = (Scaleform::GFx::ButtonRecord *)Scaleform::Memory::pGlobalHeap->Realloc(
                                             Scaleform::Memory::pGlobalHeap,
                                             this->Data,
                                             384 * ((newCapacity + 3) >> 2));
    }
    else
    {
      newCapacity = 258;
      v5 = (Scaleform::GFx::ButtonRecord *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                             Scaleform::Memory::pGlobalHeap,
                                             pheapAddr,
                                             96 * v4,
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
