void __thiscall Scaleform::ArrayDataBase<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,Scaleform::AllocatorLH<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,323>,Scaleform::ArrayDefaultPolicy>::Reserve(
        Scaleform::ArrayDataBase<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,Scaleform::AllocatorLH<Scaleform::GFx::AS2::AsFunctionObject::ArgSpec,323>,Scaleform::ArrayDefaultPolicy> *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  unsigned int v4; // esi
  Scaleform::GFx::AS2::AsFunctionObject::ArgSpec *v5; // eax

  if ( newCapacity )
  {
    v4 = 4 * ((newCapacity + 3) >> 2);
    if ( this->Data )
    {
      v5 = (Scaleform::GFx::AS2::AsFunctionObject::ArgSpec *)Scaleform::Memory::pGlobalHeap->Realloc(
                                                               Scaleform::Memory::pGlobalHeap,
                                                               this->Data,
                                                               32 * ((newCapacity + 3) >> 2));
    }
    else
    {
      newCapacity = 323;
      v5 = (Scaleform::GFx::AS2::AsFunctionObject::ArgSpec *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                               Scaleform::Memory::pGlobalHeap,
                                                               pheapAddr,
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
