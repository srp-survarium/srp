void __thiscall Scaleform::ArrayPagedBase<Scaleform::GFx::AS2::RefCountBaseGC<323> *,10,5,Scaleform::AllocatorPagedLH_POD<Scaleform::GFx::AS2::RefCountBaseGC<323> *,2>>::ClearAndRelease(
        Scaleform::ArrayPagedBase<Scaleform::GFx::AS2::RefCountBaseGC<323> *,10,5,Scaleform::AllocatorPagedLH_POD<Scaleform::GFx::AS2::RefCountBaseGC<323> *,2> > *this)
{
  unsigned int NumPages; // eax
  void **v3; // edi

  NumPages = this->NumPages;
  if ( NumPages )
  {
    v3 = (void **)&this->Pages[NumPages - 1];
    do
    {
      --this->NumPages;
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, *v3--);
    }
    while ( this->NumPages );
    --this->NumPages;
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Pages);
  }
  this->MaxPages = 0;
  this->NumPages = 0;
  this->Size = 0;
  this->Pages = 0;
}
