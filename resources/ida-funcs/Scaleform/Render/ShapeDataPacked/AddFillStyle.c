unsigned int __thiscall Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::AddFillStyle(
        Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy> > *this,
        const Scaleform::Render::FillStyleType *fill)
{
  Scaleform::ArrayLH<Scaleform::Render::FillStyleType,2,Scaleform::ArrayDefaultPolicy> *p_FillStyles; // esi
  Scaleform::Render::FillStyleType *v4; // esi
  Scaleform::Render::ComplexFill *pObject; // ecx

  p_FillStyles = &this->FillStyles;
  Scaleform::ArrayDataBase<Scaleform::Render::FillStyleType,Scaleform::AllocatorLH<Scaleform::Render::FillStyleType,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->FillStyles.Data,
    &this->FillStyles,
    this->FillStyles.Data.Size + 1);
  v4 = &p_FillStyles->Data.Data[p_FillStyles->Data.Size - 1];
  if ( v4 )
  {
    v4->Color = fill->Color;
    pObject = fill->pFill.pObject;
    if ( pObject )
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)pObject);
    v4->pFill.pObject = fill->pFill.pObject;
  }
  return this->FillStyles.Data.Size;
}
