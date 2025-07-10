void __thiscall Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2>,Scaleform::ArrayDefaultPolicy>(
        Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::DisplayObject>,2>,Scaleform::ArrayDefaultPolicy> *this)
{
  unsigned int Size; // eax
  Scaleform::Ptr<Scaleform::GFx::DisplayObject> *v3; // esi
  unsigned int v4; // edi

  Size = this->Size;
  v3 = &this->Data[Size - 1];
  if ( Size )
  {
    v4 = this->Size;
    do
    {
      if ( v3->pObject )
        Scaleform::RefCountNTSImpl::Release(v3->pObject);
      --v3;
      --v4;
    }
    while ( v4 );
  }
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Data);
}
