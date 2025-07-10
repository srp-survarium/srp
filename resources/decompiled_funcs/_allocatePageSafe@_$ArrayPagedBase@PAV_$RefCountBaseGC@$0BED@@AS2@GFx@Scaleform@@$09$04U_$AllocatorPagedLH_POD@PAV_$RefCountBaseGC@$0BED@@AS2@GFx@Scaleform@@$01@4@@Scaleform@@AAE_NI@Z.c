bool __thiscall Scaleform::ArrayPagedBase<Scaleform::GFx::AS2::RefCountBaseGC<323> *,10,5,Scaleform::AllocatorPagedLH_POD<Scaleform::GFx::AS2::RefCountBaseGC<323> *,2>>::allocatePageSafe(
        Scaleform::ArrayPagedBase<Scaleform::GFx::AS2::RefCountBaseGC<323> *,10,5,Scaleform::AllocatorPagedLH_POD<Scaleform::GFx::AS2::RefCountBaseGC<323> *,2> > *this,
        unsigned int nb)
{
  unsigned int MaxPages; // eax
  unsigned int v4; // edi
  Scaleform::GFx::AS2::RefCountBaseGC<323> ***Pages; // edx
  Scaleform::GFx::AS2::RefCountBaseGC<323> ***v6; // eax
  bool result; // al

  MaxPages = this->MaxPages;
  v4 = nb;
  if ( nb >= MaxPages )
  {
    Pages = this->Pages;
    if ( Pages )
    {
      v6 = (Scaleform::GFx::AS2::RefCountBaseGC<323> ***)Scaleform::Memory::pGlobalHeap->Realloc(
                                                           Scaleform::Memory::pGlobalHeap,
                                                           Pages,
                                                           4 * MaxPages + 20);
    }
    else
    {
      nb = 2;
      v6 = (Scaleform::GFx::AS2::RefCountBaseGC<323> ***)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                           Scaleform::Memory::pGlobalHeap,
                                                           this,
                                                           20,
                                                           &nb);
    }
    if ( !v6 )
      return 0;
    this->MaxPages += 5;
    this->Pages = v6;
  }
  nb = 2;
  this->Pages[v4] = (Scaleform::GFx::AS2::RefCountBaseGC<323> **)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                                   Scaleform::Memory::pGlobalHeap,
                                                                   this,
                                                                   4096,
                                                                   &nb);
  if ( !this->Pages[v4] )
    return 0;
  result = 1;
  ++this->NumPages;
  return result;
}
