void __thiscall Scaleform::ArrayDataBase<Scaleform::Render::FillStyleType,Scaleform::AllocatorGH<Scaleform::Render::FillStyleType,259>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::Render::FillStyleType,Scaleform::AllocatorGH<Scaleform::Render::FillStyleType,259>,Scaleform::ArrayDefaultPolicy>(
        Scaleform::ArrayDataBase<Scaleform::Render::FillStyleType,Scaleform::AllocatorGH<Scaleform::Render::FillStyleType,259>,Scaleform::ArrayDefaultPolicy> *this)
{
  unsigned int Size; // eax
  Scaleform::Render::FillStyleType *v3; // ecx
  Scaleform::RefCountVImpl **p_pFill; // esi
  unsigned int v5; // edi

  Size = this->Size;
  v3 = &this->Data[Size - 1];
  if ( Size )
  {
    p_pFill = (Scaleform::RefCountVImpl **)&v3->pFill;
    v5 = Size;
    do
    {
      if ( *p_pFill )
        Scaleform::RefCountImpl::Release(*p_pFill);
      p_pFill -= 2;
      --v5;
    }
    while ( v5 );
  }
  if ( this->Data )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Data);
}
