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


void __thiscall Scaleform::ArrayPagedBase<Scaleform::GFx::AS3::CallFrame,6,64,Scaleform::AllocatorPagedCC<Scaleform::GFx::AS3::CallFrame,329>>::allocatePage(
        Scaleform::ArrayPagedBase<Scaleform::GFx::AS3::CallFrame,6,64,Scaleform::AllocatorPagedCC<Scaleform::GFx::AS3::CallFrame,329> > *this,
        unsigned int nb)
{
  unsigned int MaxPages; // eax
  unsigned int v4; // edi
  Scaleform::GFx::AS3::CallFrame **Pages; // edx
  Scaleform::GFx::AS3::CallFrame **v6; // eax

  MaxPages = this->MaxPages;
  v4 = nb;
  if ( nb >= MaxPages )
  {
    Pages = this->Pages;
    if ( Pages )
    {
      v6 = (Scaleform::GFx::AS3::CallFrame **)Scaleform::Memory::pGlobalHeap->Realloc(
                                                Scaleform::Memory::pGlobalHeap,
                                                Pages,
                                                4 * MaxPages + 256);
    }
    else
    {
      nb = 329;
      v6 = (Scaleform::GFx::AS3::CallFrame **)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                Scaleform::Memory::pGlobalHeap,
                                                this,
                                                256,
                                                &nb);
    }
    this->MaxPages += 64;
    this->Pages = v6;
  }
  nb = 329;
  this->Pages[v4] = (Scaleform::GFx::AS3::CallFrame *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                        Scaleform::Memory::pGlobalHeap,
                                                        this,
                                                        6144,
                                                        &nb);
  ++this->NumPages;
}
