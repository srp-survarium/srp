void __thiscall Scaleform::ArrayPagedBase<Scaleform::GFx::AS2::RefCountBaseGC<323> *,10,5,Scaleform::AllocatorPagedLH_POD<Scaleform::GFx::AS2::RefCountBaseGC<323> *,2>>::Resize(
        Scaleform::ArrayPagedBase<Scaleform::GFx::AS2::RefCountBaseGC<323> *,10,5,Scaleform::AllocatorPagedLH_POD<Scaleform::GFx::AS2::RefCountBaseGC<323> *,2> > *this,
        unsigned int newSize)
{
  unsigned int Size; // eax
  unsigned int NumPages; // esi
  unsigned int i; // edi

  Size = this->Size;
  if ( newSize <= Size )
  {
    if ( newSize < Size )
      this->Size = newSize;
  }
  else
  {
    NumPages = this->NumPages;
    for ( i = (newSize + 1023) >> 10; NumPages < i; ++NumPages )
      Scaleform::ArrayPagedBase<Scaleform::GFx::AS2::RefCountBaseGC<323> *,10,5,Scaleform::AllocatorPagedLH_POD<Scaleform::GFx::AS2::RefCountBaseGC<323> *,2>>::allocatePage(
        this,
        NumPages);
    this->Size = newSize;
  }
}
