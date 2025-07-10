void __thiscall Scaleform::ArrayPagedBase<unsigned int,6,64,Scaleform::AllocatorPagedLH_POD<unsigned int,2>>::allocatePage(
        Scaleform::ArrayPagedBase<unsigned int,6,64,Scaleform::AllocatorPagedLH_POD<unsigned int,2> > *this,
        unsigned int nb)
{
  unsigned int MaxPages; // eax
  unsigned int v4; // edi
  unsigned int **Pages; // edx
  unsigned int **v6; // eax

  MaxPages = this->MaxPages;
  v4 = nb;
  if ( nb >= MaxPages )
  {
    Pages = this->Pages;
    if ( Pages )
    {
      v6 = (unsigned int **)Scaleform::Memory::pGlobalHeap->Realloc(
                              Scaleform::Memory::pGlobalHeap,
                              Pages,
                              4 * MaxPages + 256);
    }
    else
    {
      nb = 2;
      v6 = (unsigned int **)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                              Scaleform::Memory::pGlobalHeap,
                              this,
                              256,
                              &nb);
    }
    this->MaxPages += 64;
    this->Pages = v6;
  }
  nb = 2;
  this->Pages[v4] = (unsigned int *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                      Scaleform::Memory::pGlobalHeap,
                                      this,
                                      256,
                                      &nb);
  ++this->NumPages;
}
