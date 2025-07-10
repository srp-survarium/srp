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
