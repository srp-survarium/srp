void __thiscall Scaleform::GFx::ConstShapeWithStyles::~ConstShapeWithStyles(Scaleform::GFx::ConstShapeWithStyles *this)
{
  unsigned __int8 *Styles; // ebx
  unsigned int v3; // edi
  Scaleform::RefCountVImpl *v4; // ecx
  unsigned int v5; // ebp
  Scaleform::RefCountVImpl **v6; // edi
  Scaleform::RefCountVImpl *v7; // ecx

  Styles = this->Styles;
  v3 = 0;
  for ( this->__vftable = (Scaleform::GFx::ConstShapeWithStyles_vtbl *)&Scaleform::GFx::ConstShapeWithStyles::`vftable';
        v3 < this->FillStylesNum;
        Styles += 8 )
  {
    v4 = (Scaleform::RefCountVImpl *)*((_DWORD *)Styles + 1);
    if ( v4 )
      Scaleform::RefCountImpl::Release(v4);
    ++v3;
  }
  v5 = 0;
  if ( this->StrokeStylesNum )
  {
    v6 = (Scaleform::RefCountVImpl **)(Styles + 20);
    do
    {
      v7 = v6[1];
      if ( v7 )
        Scaleform::RefCountImpl::Release(v7);
      if ( *v6 )
        Scaleform::RefCountImpl::Release(*v6);
      ++v5;
      v6 += 7;
    }
    while ( v5 < this->StrokeStylesNum );
  }
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Styles);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}
