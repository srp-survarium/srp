void __thiscall Scaleform::ArrayDataBase<Scaleform::GFx::FontData::AdvanceEntry,Scaleform::AllocatorLH<Scaleform::GFx::FontData::AdvanceEntry,261>,Scaleform::ArrayDefaultPolicy>::Reserve(
        Scaleform::ArrayDataBase<Scaleform::GFx::FontData::AdvanceEntry,Scaleform::AllocatorLH<Scaleform::GFx::FontData::AdvanceEntry,261>,Scaleform::ArrayDefaultPolicy> *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  unsigned int v4; // esi
  Scaleform::GFx::FontData::AdvanceEntry *v5; // eax

  if ( newCapacity )
  {
    v4 = 4 * ((newCapacity + 3) >> 2);
    if ( this->Data )
    {
      v5 = (Scaleform::GFx::FontData::AdvanceEntry *)Scaleform::Memory::pGlobalHeap->Realloc(
                                                       Scaleform::Memory::pGlobalHeap,
                                                       this->Data,
                                                       48 * ((newCapacity + 3) >> 2));
    }
    else
    {
      newCapacity = 261;
      v5 = (Scaleform::GFx::FontData::AdvanceEntry *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                       Scaleform::Memory::pGlobalHeap,
                                                       pheapAddr,
                                                       12 * v4,
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
