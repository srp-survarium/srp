void __thiscall Scaleform::ArrayDataBase<Scaleform::Render::FillStyleType,Scaleform::AllocatorGH<Scaleform::Render::FillStyleType,259>,Scaleform::ArrayDefaultPolicy>::Reserve(
        Scaleform::ArrayDataBase<Scaleform::Render::FillStyleType,Scaleform::AllocatorGH<Scaleform::Render::FillStyleType,259>,Scaleform::ArrayDefaultPolicy> *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  unsigned int v4; // esi
  Scaleform::Render::FillStyleType *v5; // eax

  if ( newCapacity )
  {
    v4 = 4 * ((newCapacity + 3) >> 2);
    if ( this->Data )
    {
      v5 = (Scaleform::Render::FillStyleType *)Scaleform::Memory::pGlobalHeap->Realloc(
                                                 Scaleform::Memory::pGlobalHeap,
                                                 this->Data,
                                                 32 * ((newCapacity + 3) >> 2));
    }
    else
    {
      newCapacity = 259;
      v5 = (Scaleform::Render::FillStyleType *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                 Scaleform::Memory::pGlobalHeap,
                                                 8 * v4,
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
