void __thiscall Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
        Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy> *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  unsigned int v4; // esi
  Scaleform::GFx::AS3::Abc::MetadataInfo::Item *v5; // eax

  if ( newCapacity )
  {
    v4 = 4 * ((newCapacity + 3) >> 2);
    if ( this->Data )
    {
      v5 = (Scaleform::GFx::AS3::Abc::MetadataInfo::Item *)Scaleform::Memory::pGlobalHeap->Realloc(
                                                             Scaleform::Memory::pGlobalHeap,
                                                             this->Data,
                                                             32 * ((newCapacity + 3) >> 2));
    }
    else
    {
      newCapacity = 338;
      v5 = (Scaleform::GFx::AS3::Abc::MetadataInfo::Item *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
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
