void __thiscall Scaleform::ArrayPagedBase<Scaleform::Render::RectPacker::RectType,8,64,Scaleform::AllocatorPagedLH_POD<Scaleform::Render::RectPacker::RectType,2>>::allocatePage(
        Scaleform::ArrayPagedBase<Scaleform::Render::RectPacker::RectType,8,64,Scaleform::AllocatorPagedLH_POD<Scaleform::Render::RectPacker::RectType,2> > *this,
        unsigned int nb)
{
  unsigned int MaxPages; // eax
  unsigned int v4; // edi
  Scaleform::Render::RectPacker::RectType **Pages; // edx
  Scaleform::Render::RectPacker::RectType **v6; // eax

  MaxPages = this->MaxPages;
  v4 = nb;
  if ( nb >= MaxPages )
  {
    Pages = this->Pages;
    if ( Pages )
    {
      v6 = (Scaleform::Render::RectPacker::RectType **)Scaleform::Memory::pGlobalHeap->Realloc(
                                                         Scaleform::Memory::pGlobalHeap,
                                                         Pages,
                                                         4 * MaxPages + 256);
    }
    else
    {
      nb = 2;
      v6 = (Scaleform::Render::RectPacker::RectType **)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                         Scaleform::Memory::pGlobalHeap,
                                                         this,
                                                         256,
                                                         &nb);
    }
    this->MaxPages += 64;
    this->Pages = v6;
  }
  nb = 2;
  this->Pages[v4] = (Scaleform::Render::RectPacker::RectType *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                                 Scaleform::Memory::pGlobalHeap,
                                                                 this,
                                                                 3072,
                                                                 &nb);
  ++this->NumPages;
}
