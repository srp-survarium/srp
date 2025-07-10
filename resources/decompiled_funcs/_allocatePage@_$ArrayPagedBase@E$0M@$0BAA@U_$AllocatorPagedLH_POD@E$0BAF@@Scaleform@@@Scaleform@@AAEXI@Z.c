void __thiscall Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261>>::allocatePage(
        Scaleform::ArrayPagedBase<unsigned char,12,256,Scaleform::AllocatorPagedLH_POD<unsigned char,261> > *this,
        unsigned int nb)
{
  unsigned int MaxPages; // eax
  unsigned int v4; // edi
  unsigned __int8 **Pages; // edx
  unsigned __int8 **v6; // eax

  MaxPages = this->MaxPages;
  v4 = nb;
  if ( nb >= MaxPages )
  {
    Pages = this->Pages;
    if ( Pages )
    {
      v6 = (unsigned __int8 **)Scaleform::Memory::pGlobalHeap->Realloc(
                                 Scaleform::Memory::pGlobalHeap,
                                 Pages,
                                 4 * MaxPages + 1024);
    }
    else
    {
      nb = 261;
      v6 = (unsigned __int8 **)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                 Scaleform::Memory::pGlobalHeap,
                                 this,
                                 1024,
                                 &nb);
    }
    this->MaxPages += 256;
    this->Pages = v6;
  }
  nb = 261;
  this->Pages[v4] = (unsigned __int8 *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                         Scaleform::Memory::pGlobalHeap,
                                         this,
                                         4096,
                                         &nb);
  ++this->NumPages;
}
