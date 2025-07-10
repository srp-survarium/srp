void __thiscall Scaleform::ArrayPagedBase<Scaleform::Render::RectPacker::PackType,4,16,Scaleform::AllocatorPagedLH_POD<Scaleform::Render::RectPacker::PackType,2>>::allocatePage(
        Scaleform::ArrayPagedBase<Scaleform::Render::RectPacker::PackType,4,16,Scaleform::AllocatorPagedLH_POD<Scaleform::Render::RectPacker::PackType,2> > *this,
        unsigned int nb)
{
  unsigned int MaxPages; // eax
  unsigned int v4; // edi
  Scaleform::Render::RectPacker::PackType **Pages; // edx
  Scaleform::Render::RectPacker::PackType **v6; // eax

  MaxPages = this->MaxPages;
  v4 = nb;
  if ( nb >= MaxPages )
  {
    Pages = this->Pages;
    if ( Pages )
    {
      v6 = (Scaleform::Render::RectPacker::PackType **)Scaleform::Memory::pGlobalHeap->Realloc(
                                                         Scaleform::Memory::pGlobalHeap,
                                                         Pages,
                                                         4 * MaxPages + 64);
    }
    else
    {
      nb = 2;
      v6 = (Scaleform::Render::RectPacker::PackType **)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                         Scaleform::Memory::pGlobalHeap,
                                                         this,
                                                         64,
                                                         &nb);
    }
    this->MaxPages += 16;
    this->Pages = v6;
  }
  nb = 2;
  this->Pages[v4] = (Scaleform::Render::RectPacker::PackType *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                                 Scaleform::Memory::pGlobalHeap,
                                                                 this,
                                                                 128,
                                                                 &nb);
  ++this->NumPages;
}
