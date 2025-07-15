Scaleform::GFx::Resource *__thiscall Scaleform::GFx::DrawingContext::CreateNewComplexFill(
        Scaleform::GFx::DrawingContext *this)
{
  unsigned int v2; // ebp
  Scaleform::GFx::Resource *v3; // eax
  Scaleform::GFx::Resource *v4; // edi
  Scaleform::GFx::DrawingContext::PackedShape *pObject; // ecx
  Scaleform::GFx::DrawingContext::PackedShape *v6; // ecx
  Scaleform::Render::FillStyleType *v7; // esi
  Scaleform::RefCountVImpl *v8; // ecx
  Scaleform::Render::FillStyleType v10; // [esp+10h] [ebp-8h] BYREF

  v2 = Scaleform::GFx::DrawingContext::SetNewFill(this);
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
  pObject = this->Shapes.pObject;
  v10.pFill.pObject = 0;
  pObject->GetFillStyle(pObject, v2, &v10);
  if ( v4 )
    Scaleform::RefCountImpl::AddRef(v4);
  if ( v10.pFill.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v10.pFill.pObject);
  v6 = this->Shapes.pObject;
  v10.pFill.pObject = (Scaleform::Render::ComplexFill *)v4;
  v7 = &v6->FillStyles.Data.Data[v2 - 1];
  v7->Color = v10.Color;
  if ( v10.pFill.pObject )
    Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v10.pFill.pObject);
  v8 = (Scaleform::RefCountVImpl *)v7->pFill.pObject;
  if ( v8 )
    Scaleform::RefCountImpl::Release(v8);
  v7->pFill.pObject = v10.pFill.pObject;
  if ( v10.pFill.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v10.pFill.pObject);
  if ( v4 )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v4);
  return v4;
}
