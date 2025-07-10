void __thiscall Scaleform::ArrayDataBase<Scaleform::GFx::XML::DOMBuilder::PrefixOwnership,Scaleform::AllocatorGH<Scaleform::GFx::XML::DOMBuilder::PrefixOwnership,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        Scaleform::ArrayDataBase<tagKERNINGPAIR,Scaleform::AllocatorGH<tagKERNINGPAIR,2>,Scaleform::ArrayDefaultPolicy> *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  unsigned int v4; // esi
  tagKERNINGPAIR *v5; // eax

  if ( newCapacity )
  {
    v4 = 4 * ((newCapacity + 3) >> 2);
    if ( this->Data )
    {
      v5 = (tagKERNINGPAIR *)Scaleform::Memory::pGlobalHeap->Realloc(
                               Scaleform::Memory::pGlobalHeap,
                               this->Data,
                               32 * ((newCapacity + 3) >> 2));
    }
    else
    {
      newCapacity = 2;
      v5 = (tagKERNINGPAIR *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 8 * v4, &newCapacity);
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
