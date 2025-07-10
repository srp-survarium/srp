void __thiscall Scaleform::ArrayDataBase<Scaleform::GFx::TextKeyMap::KeyMapEntry,Scaleform::AllocatorGH<Scaleform::GFx::TextKeyMap::KeyMapEntry,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorGH<Scaleform::GFx::AS3::Value,2>,Scaleform::ArrayDefaultPolicy> *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  unsigned int v4; // esi
  Scaleform::GFx::AS3::Value *v5; // eax

  if ( newCapacity )
  {
    v4 = 4 * ((newCapacity + 3) >> 2);
    if ( this->Data )
    {
      v5 = (Scaleform::GFx::AS3::Value *)Scaleform::Memory::pGlobalHeap->Realloc(
                                           Scaleform::Memory::pGlobalHeap,
                                           this->Data,
                                           (newCapacity + 3) >> 2 << 6);
    }
    else
    {
      newCapacity = 2;
      v5 = (Scaleform::GFx::AS3::Value *)Scaleform::Memory::pGlobalHeap->Alloc(
                                           Scaleform::Memory::pGlobalHeap,
                                           16 * v4,
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
