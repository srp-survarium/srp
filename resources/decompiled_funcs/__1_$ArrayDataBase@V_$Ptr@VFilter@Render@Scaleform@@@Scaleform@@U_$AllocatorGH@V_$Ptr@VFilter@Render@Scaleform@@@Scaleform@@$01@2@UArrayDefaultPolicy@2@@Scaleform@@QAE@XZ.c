void __thiscall Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::Render::Filter>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::Render::Filter>,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::Ptr<Scaleform::Render::Filter>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::Render::Filter>,2>,Scaleform::ArrayDefaultPolicy>(
        Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::Render::Filter>,Scaleform::AllocatorGH<Scaleform::Ptr<Scaleform::Render::Filter>,2>,Scaleform::ArrayDefaultPolicy> *this)
{
  unsigned int Size; // eax
  Scaleform::RefCountVImpl **v3; // esi
  unsigned int v4; // edi

  Size = this->Size;
  v3 = (Scaleform::RefCountVImpl **)&this->Data[Size - 1];
  if ( Size )
  {
    v4 = this->Size;
    do
    {
      if ( *v3 )
        Scaleform::RefCountImpl::Release(*v3);
      --v3;
      --v4;
    }
    while ( v4 );
  }
  if ( this->Data )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Data);
}
