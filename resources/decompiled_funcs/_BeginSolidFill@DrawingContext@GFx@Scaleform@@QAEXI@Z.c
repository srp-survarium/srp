void __thiscall Scaleform::GFx::DrawingContext::BeginSolidFill(Scaleform::GFx::DrawingContext *this, unsigned int rgba)
{
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::GFx::DrawingContext::PackedShape *v4; // ebx
  Scaleform::Render::FillStyleType *v5; // edi
  Scaleform::GFx::Resource *v6; // ecx
  bool v7; // zf

  this->mFillStyle.Color = rgba;
  pObject = (Scaleform::RefCountVImpl *)this->mFillStyle.pFill.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->mFillStyle.pFill.pObject = 0;
  v4 = this->Shapes.pObject;
  Scaleform::ArrayDataBase<Scaleform::Render::FillStyleType,Scaleform::AllocatorLH<Scaleform::Render::FillStyleType,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &v4->FillStyles.Data,
    &v4->FillStyles,
    v4->FillStyles.Data.Size + 1);
  v5 = &v4->FillStyles.Data.Data[v4->FillStyles.Data.Size - 1];
  if ( &v4->FillStyles.Data.Data[v4->FillStyles.Data.Size] != (Scaleform::Render::FillStyleType *)8 )
  {
    v5->Color = this->mFillStyle.Color;
    v6 = (Scaleform::GFx::Resource *)this->mFillStyle.pFill.pObject;
    if ( v6 )
      Scaleform::RefCountImpl::AddRef(v6);
    v5->pFill.pObject = this->mFillStyle.pFill.pObject;
  }
  v7 = (this->States & 0x10) == 0;
  this->FillStyle0 = v4->FillStyles.Data.Size;
  this->FillStyle1 = 0;
  if ( !v7 )
  {
    Scaleform::GFx::DrawingContext::FinishPath(this);
    this->StY = 1.1754944e-38;
    this->FillStyle1 = 0;
    this->StX = 1.1754944e-38;
    this->FillStyle0 = 0;
  }
  this->States |= 0x14u;
}
