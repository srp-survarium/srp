void __thiscall Scaleform::ArrayDataBase<Scaleform::Render::Matrix2x4<float>,Scaleform::AllocatorLH<Scaleform::Render::Matrix2x4<float>,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        Scaleform::ArrayDataBase<Scaleform::Render::ExternalFontWinAPI::GlyphType,Scaleform::AllocatorLH<Scaleform::Render::ExternalFontWinAPI::GlyphType,2>,Scaleform::ArrayDefaultPolicy> *this,
        const void *pheapAddr,
        unsigned int newCapacity)
{
  unsigned int v4; // esi
  Scaleform::Render::ExternalFontWinAPI::GlyphType *v5; // eax

  if ( newCapacity )
  {
    v4 = 4 * ((newCapacity + 3) >> 2);
    if ( this->Data )
    {
      v5 = (Scaleform::Render::ExternalFontWinAPI::GlyphType *)Scaleform::Memory::pGlobalHeap->Realloc(
                                                                 Scaleform::Memory::pGlobalHeap,
                                                                 this->Data,
                                                                 (newCapacity + 3) >> 2 << 7);
    }
    else
    {
      newCapacity = 2;
      v5 = (Scaleform::Render::ExternalFontWinAPI::GlyphType *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                                 Scaleform::Memory::pGlobalHeap,
                                                                 pheapAddr,
                                                                 32 * v4,
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
