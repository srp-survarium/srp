void __thiscall Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,265>,Scaleform::ArrayDefaultPolicy>::Reserve(
        Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::GFx::MovieDefImpl>,265>,Scaleform::ArrayDefaultPolicy> *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  unsigned int v4; // esi
  Scaleform::Ptr<Scaleform::GFx::MovieDefImpl> *v5; // eax

  if ( newCapacity )
  {
    v4 = 4 * ((newCapacity + 3) >> 2);
    if ( this->Data )
    {
      v5 = (Scaleform::Ptr<Scaleform::GFx::MovieDefImpl> *)Scaleform::Memory::pGlobalHeap->Realloc(
                                                             Scaleform::Memory::pGlobalHeap,
                                                             this->Data,
                                                             16 * ((newCapacity + 3) >> 2));
    }
    else
    {
      newCapacity = 265;
      v5 = (Scaleform::Ptr<Scaleform::GFx::MovieDefImpl> *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                             Scaleform::Memory::pGlobalHeap,
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
