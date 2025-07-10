void __thiscall Scaleform::ArrayPagedBase<Scaleform::GFx::FontCompactor::GlyphInfoType,6,64,Scaleform::AllocatorPagedGH_POD<Scaleform::GFx::FontCompactor::GlyphInfoType,261>>::ClearAndRelease(
        Scaleform::ArrayPagedBase<Scaleform::GFx::FontCompactor::KerningPairType,6,64,Scaleform::AllocatorPagedGH_POD<Scaleform::GFx::FontCompactor::KerningPairType,261> > *this)
{
  unsigned int NumPages; // eax
  void **v3; // edi
  Scaleform::GFx::FontCompactor::KerningPairType **Pages; // eax

  NumPages = this->NumPages;
  if ( NumPages )
  {
    v3 = (void **)&this->Pages[NumPages - 1];
    do
    {
      --this->NumPages;
      if ( *v3 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, *v3);
      --v3;
    }
    while ( this->NumPages );
    Pages = this->Pages;
    --this->NumPages;
    if ( Pages )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, Pages);
  }
  this->MaxPages = 0;
  this->NumPages = 0;
  this->Size = 0;
  this->Pages = 0;
}
