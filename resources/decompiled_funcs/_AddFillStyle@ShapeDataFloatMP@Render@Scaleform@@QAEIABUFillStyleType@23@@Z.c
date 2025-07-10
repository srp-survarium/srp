unsigned int __thiscall Scaleform::Render::ShapeDataFloatMP::AddFillStyle(
        Scaleform::Render::ShapeDataFloatMP *this,
        const Scaleform::Render::FillStyleType *fill)
{
  Scaleform::Render::ShapeDataFloat *pObject; // edi
  Scaleform::Render::FillStyleType *v3; // esi
  Scaleform::GFx::Resource *v4; // ecx

  pObject = this->pData.pObject;
  Scaleform::ArrayDataBase<Scaleform::Render::FillStyleType,Scaleform::AllocatorLH<Scaleform::Render::FillStyleType,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &pObject->Fills.Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> >::Data,
    &pObject->Fills,
    pObject->Fills.Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> >::Data.Size
  + 1);
  v3 = &pObject->Fills.Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> >::Data.Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> >::Data[pObject->Fills.Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> >::Data.Size - 1];
  if ( &pObject->Fills.Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> >::Data.Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> >::Data[pObject->Fills.Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> >::Data.Size] != (Scaleform::Render::FillStyleType *)8 )
  {
    v3->Color = fill->Color;
    v4 = (Scaleform::GFx::Resource *)fill->pFill.pObject;
    if ( v4 )
      Scaleform::RefCountImpl::AddRef(v4);
    v3->pFill.pObject = fill->pFill.pObject;
  }
  return pObject->Fills.Scaleform::Render::ShapeDataFloatTempl<Scaleform::Array<unsigned char,2,Scaleform::ArrayDefaultPolicy> >::Data.Size;
}
