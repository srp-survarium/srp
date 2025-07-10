void __thiscall Scaleform::ArrayUnsafeBase<Scaleform::Render::GlyphBand,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphBand,79>>::Reserve(
        Scaleform::ArrayUnsafeBase<Scaleform::Render::GlyphBand,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphBand,79> > *this,
        unsigned int cap,
        unsigned int extraTail)
{
  unsigned int v3; // edi
  int v5; // eax

  v3 = cap;
  if ( cap > this->Capacity )
  {
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Data);
    v5 = v3 + extraTail;
    this->Capacity = v3 + extraTail;
    if ( v5 )
    {
      cap = 79;
      this->Data = (Scaleform::Render::GlyphBand *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                     Scaleform::Memory::pGlobalHeap,
                                                     this,
                                                     v5 << 6,
                                                     &cap);
      this->Size = 0;
      return;
    }
    this->Data = 0;
  }
  this->Size = 0;
}
