void __thiscall Scaleform::ArrayPagedBase<Scaleform::GFx::FontCompactor::ContourType,6,64,Scaleform::AllocatorPagedGH_POD<Scaleform::GFx::FontCompactor::ContourType,261>>::allocatePage(
        Scaleform::ArrayPagedBase<Scaleform::GFx::FontCompactor::KerningPairType,6,64,Scaleform::AllocatorPagedGH_POD<Scaleform::GFx::FontCompactor::KerningPairType,261> > *this,
        unsigned int nb)
{
  unsigned int MaxPages; // eax
  unsigned int v4; // edi
  Scaleform::GFx::FontCompactor::KerningPairType **Pages; // edx
  Scaleform::GFx::FontCompactor::KerningPairType **v6; // eax

  MaxPages = this->MaxPages;
  v4 = nb;
  if ( nb >= MaxPages )
  {
    Pages = this->Pages;
    if ( Pages )
    {
      v6 = (Scaleform::GFx::FontCompactor::KerningPairType **)Scaleform::Memory::pGlobalHeap->Realloc(
                                                                Scaleform::Memory::pGlobalHeap,
                                                                Pages,
                                                                4 * MaxPages + 256);
    }
    else
    {
      nb = 261;
      v6 = (Scaleform::GFx::FontCompactor::KerningPairType **)Scaleform::Memory::pGlobalHeap->Alloc(
                                                                Scaleform::Memory::pGlobalHeap,
                                                                256,
                                                                &nb);
    }
    this->MaxPages += 64;
    this->Pages = v6;
  }
  nb = 261;
  this->Pages[v4] = (Scaleform::GFx::FontCompactor::KerningPairType *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                                        Scaleform::Memory::pGlobalHeap,
                                                                        512,
                                                                        &nb);
  ++this->NumPages;
}
