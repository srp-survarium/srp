void __thiscall Scaleform::ArrayUnsafeBase<unsigned char,Scaleform::AllocatorGH_POD<unsigned char,2>>::Reserve(
        Scaleform::ArrayUnsafeBase<unsigned char,Scaleform::AllocatorGH_POD<unsigned char,2> > *this,
        unsigned int cap,
        unsigned int extraTail)
{
  unsigned int v3; // edi
  unsigned int v5; // eax

  v3 = cap;
  if ( cap > this->Capacity )
  {
    if ( this->Data )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Data);
    v5 = v3 + extraTail;
    this->Capacity = v3 + extraTail;
    if ( v5 )
    {
      cap = 2;
      this->Data = (unsigned __int8 *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, v5, &cap);
      this->Size = 0;
      return;
    }
    this->Data = 0;
  }
  this->Size = 0;
}


void __thiscall Scaleform::ArrayUnsafeBase<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,261>>::Reserve(
        Scaleform::ArrayUnsafeBase<unsigned char,Scaleform::AllocatorLH_POD<unsigned char,261> > *this,
        unsigned int cap,
        unsigned int extraTail)
{
  unsigned int v3; // edi
  unsigned int v5; // eax

  v3 = cap;
  if ( cap > this->Capacity )
  {
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Data);
    v5 = v3 + extraTail;
    this->Capacity = v3 + extraTail;
    if ( v5 )
    {
      cap = 261;
      this->Data = (unsigned __int8 *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                        Scaleform::Memory::pGlobalHeap,
                                        this,
                                        v5,
                                        &cap);
      this->Size = 0;
      return;
    }
    this->Data = 0;
  }
  this->Size = 0;
}


void __thiscall Scaleform::ArrayUnsafeBase<int,Scaleform::AllocatorGH<int,2>>::Reserve(
        Scaleform::ArrayUnsafeBase<int,Scaleform::AllocatorGH<int,2> > *this,
        unsigned int cap,
        unsigned int extraTail)
{
  unsigned int v3; // edi
  int v5; // eax

  v3 = cap;
  if ( cap > this->Capacity )
  {
    if ( this->Data )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Data);
    v5 = v3 + extraTail;
    this->Capacity = v3 + extraTail;
    if ( v5 )
    {
      cap = 2;
      this->Data = (int *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 4 * v5, &cap);
      this->Size = 0;
      return;
    }
    this->Data = 0;
  }
  this->Size = 0;
}


void __thiscall Scaleform::ArrayUnsafeBase<Scaleform::Render::GlyphBand,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphBand,79>>::Reserve(
        Scaleform::ArrayUnsafeBase<Scaleform::Render::GlyphBand,Scaleform::AllocatorLH_POD<Scaleform::Render::GlyphBand,79> > *this,
        unsigned int cap,
        unsigned int extraTail)
{
  unsigned int v3; // edi
  int v5; // eax

  v3 = cap;
  if ( cap > this->Capacity )
  {
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Data);
    v5 = v3 + extraTail;
    this->Capacity = v3 + extraTail;
    if ( v5 )
    {
      cap = 79;
      this->Data = (Scaleform::Render::GlyphBand *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                     Scaleform::Memory::pGlobalHeap,
                                                     this,
                                                     v5 << 6,
                                                     &cap);
      this->Size = 0;
      return;
    }
    this->Data = 0;
  }
  this->Size = 0;
}


void __thiscall Scaleform::ArrayUnsafeBase<Scaleform::Render::Texture::UpdateDesc,Scaleform::AllocatorLH_POD<Scaleform::Render::Texture::UpdateDesc,2>>::Reserve(
        Scaleform::ArrayUnsafeBase<Scaleform::Render::Texture::UpdateDesc,Scaleform::AllocatorLH_POD<Scaleform::Render::Texture::UpdateDesc,2> > *this,
        unsigned int cap,
        unsigned int extraTail)
{
  unsigned int v3; // edi
  int v5; // eax

  v3 = cap;
  if ( cap > this->Capacity )
  {
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Data);
    v5 = v3 + extraTail;
    this->Capacity = v3 + extraTail;
    if ( v5 )
    {
      cap = 2;
      this->Data = (Scaleform::Render::Texture::UpdateDesc *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                               Scaleform::Memory::pGlobalHeap,
                                                               this,
                                                               40 * v5,
                                                               &cap);
      this->Size = 0;
      return;
    }
    this->Data = 0;
  }
  this->Size = 0;
}
