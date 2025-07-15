unsigned int __thiscall Scaleform::GFx::DrawingContext::SetNewFill(Scaleform::GFx::DrawingContext *this)
{
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::GFx::DrawingContext::PackedShape *v3; // ebx
  Scaleform::Render::FillStyleType *v4; // edi
  Scaleform::Render::ComplexFill *v5; // ecx
  unsigned int Size; // edx

  this->mFillStyle.Color = 0;
  pObject = (Scaleform::RefCountVImpl *)this->mFillStyle.pFill.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->mFillStyle.pFill.pObject = 0;
  v3 = this->Shapes.pObject;
  Scaleform::ArrayDataBase<Scaleform::Render::FillStyleType,Scaleform::AllocatorLH<Scaleform::Render::FillStyleType,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &v3->FillStyles.Data,
    &v3->FillStyles,
    v3->FillStyles.Data.Size + 1);
  v4 = &v3->FillStyles.Data.Data[v3->FillStyles.Data.Size - 1];
  if ( &v3->FillStyles.Data.Data[v3->FillStyles.Data.Size] != (Scaleform::Render::FillStyleType *)8 )
  {
    v4->Color = this->mFillStyle.Color;
    v5 = this->mFillStyle.pFill.pObject;
    if ( v5 )
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v5);
    v4->pFill.pObject = this->mFillStyle.pFill.pObject;
  }
  Size = v3->FillStyles.Data.Size;
  this->FillStyle0 = Size;
  this->FillStyle1 = 0;
  return Size;
}
