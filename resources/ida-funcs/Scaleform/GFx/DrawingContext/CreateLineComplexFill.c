Scaleform::GFx::Resource *__thiscall Scaleform::GFx::DrawingContext::CreateLineComplexFill(
        Scaleform::GFx::DrawingContext *this)
{
  Scaleform::GFx::DrawingContext::PackedShape *pObject; // ebp
  Scaleform::GFx::Resource *v3; // eax
  Scaleform::GFx::Resource *v4; // esi
  Scaleform::GFx::DrawingContext::PackedShape *v5; // ecx
  unsigned int StrokeStyle; // eax
  Scaleform::GFx::DrawingContext::PackedShape *v7; // edx
  unsigned int v8; // ecx
  Scaleform::Render::StrokeStyleType __that; // [esp+10h] [ebp-1Ch] BYREF

  if ( (this->States & 2) == 0 )
  {
    pObject = this->Shapes.pObject;
    Scaleform::ArrayDataBase<Scaleform::Render::StrokeStyleType,Scaleform::AllocatorLH<Scaleform::Render::StrokeStyleType,2>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &pObject->StrokeStyles.Data,
      &pObject->StrokeStyles,
      pObject->StrokeStyles.Data.Size + 1);
    if ( &pObject->StrokeStyles.Data.Data[pObject->StrokeStyles.Data.Size] != (Scaleform::Render::StrokeStyleType *)28 )
      Scaleform::Render::StrokeStyleType::StrokeStyleType(
        &pObject->StrokeStyles.Data.Data[pObject->StrokeStyles.Data.Size - 1],
        &this->mLineStyle);
    this->StrokeStyle = pObject->StrokeStyles.Data.Size;
  }
  v3 = (Scaleform::GFx::Resource *)this->pHeap->Alloc(this->pHeap, 64, 0);
  if ( v3 )
  {
    v3->__vftable = (Scaleform::GFx::Resource_vtbl *)&Scaleform::RefCountImplCore::`vftable';
    v3->RefCount.Value = 1;
    v3->__vftable = (Scaleform::GFx::Resource_vtbl *)&Scaleform::Render::ComplexFill::`vftable';
    *(float *)&v3[1].RefCount.Value = 1.0;
    v3->pLib = 0;
    *(float *)&v3[1].pLib = 0.0;
    v3[1].__vftable = 0;
    *(float *)&v3[2].__vftable = 0.0;
    v4 = v3;
    *(float *)&v3[2].RefCount.Value = 0.0;
    *(float *)&v3[2].pLib = 0.0;
    *(float *)&v3[3].RefCount.Value = 0.0;
    *(float *)&v3[3].pLib = 0.0;
    *(float *)&v3[3].__vftable = 1.0;
    LOBYTE(v3[4].__vftable) = 0;
    v3[4].RefCount.Value = -1;
  }
  else
  {
    v4 = 0;
  }
  v5 = this->Shapes.pObject;
  StrokeStyle = this->StrokeStyle;
  __that.pFill.pObject = 0;
  __that.pDashes.pObject = 0;
  v5->GetStrokeStyle(v5, StrokeStyle, &__that);
  if ( v4 )
    Scaleform::RefCountImpl::AddRef(v4);
  if ( __that.pFill.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)__that.pFill.pObject);
  v7 = this->Shapes.pObject;
  v8 = this->StrokeStyle;
  __that.pFill.pObject = (Scaleform::Render::ComplexFill *)v4;
  Scaleform::Render::StrokeStyleType::operator=(&v7->StrokeStyles.Data.Data[v8 - 1], &__that);
  if ( __that.pDashes.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)__that.pDashes.pObject);
  if ( __that.pFill.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)__that.pFill.pObject);
  if ( v4 )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v4);
  return v4;
}
