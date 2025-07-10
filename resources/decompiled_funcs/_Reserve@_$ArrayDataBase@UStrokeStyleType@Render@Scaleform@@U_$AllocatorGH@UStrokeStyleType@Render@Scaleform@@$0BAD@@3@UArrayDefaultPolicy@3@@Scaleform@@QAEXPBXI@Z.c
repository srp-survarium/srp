void __thiscall Scaleform::ArrayDataBase<Scaleform::Render::StrokeStyleType,Scaleform::AllocatorGH<Scaleform::Render::StrokeStyleType,259>,Scaleform::ArrayDefaultPolicy>::Reserve(
        Scaleform::ArrayDataBase<Scaleform::Render::StrokeStyleType,Scaleform::AllocatorGH<Scaleform::Render::StrokeStyleType,259>,Scaleform::ArrayDefaultPolicy> *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  unsigned int v4; // esi
  Scaleform::Render::StrokeStyleType *v5; // eax

  if ( newCapacity )
  {
    v4 = 4 * ((newCapacity + 3) >> 2);
    if ( this->Data )
    {
      v5 = (Scaleform::Render::StrokeStyleType *)Scaleform::Memory::pGlobalHeap->Realloc(
                                                   Scaleform::Memory::pGlobalHeap,
                                                   this->Data,
                                                   112 * ((newCapacity + 3) >> 2));
    }
    else
    {
      newCapacity = 259;
      v5 = (Scaleform::Render::StrokeStyleType *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                   Scaleform::Memory::pGlobalHeap,
                                                   28 * v4,
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
