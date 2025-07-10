Scaleform::Render::ComplexFill *__thiscall Scaleform::Render::ShapeMeshProvider::getComplexFill(
        Scaleform::Render::ShapeMeshProvider *this,
        unsigned int drawLayer,
        unsigned int fillIndex,
        unsigned int *imgFillStyle)
{
  Scaleform::Render::ShapeMeshProvider::DrawLayerType *v4; // esi
  unsigned int StrokeStyle; // edx
  Scaleform::Render::ComplexFill *result; // eax
  unsigned int v7; // esi
  Scaleform::Render::ShapeDataInterface *v8; // ecx
  Scaleform::RefCountVImpl *v9; // ecx
  Scaleform::Render::ComplexFill *v10; // ebx
  Scaleform::Render::ShapeDataInterface *pObject; // ecx
  Scaleform::RefCountVImpl *v12; // eax
  Scaleform::Render::ComplexFill *v13; // esi
  Scaleform::Render::FillStyleType fillStyle; // [esp+4h] [ebp-24h] BYREF
  Scaleform::Render::StrokeStyleType stroke; // [esp+Ch] [ebp-1Ch] BYREF

  v4 = &this->DrawLayers.Data.Data[drawLayer];
  StrokeStyle = v4->StrokeStyle;
  result = 0;
  if ( StrokeStyle )
  {
    pObject = this->pShapeData.pObject;
    stroke.pFill.pObject = 0;
    stroke.pDashes.pObject = 0;
    pObject->GetStrokeStyle(pObject, StrokeStyle, &stroke);
    v12 = (Scaleform::RefCountVImpl *)stroke.pFill.pObject;
    v13 = stroke.pFill.pObject;
    if ( stroke.pDashes.pObject )
    {
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)stroke.pDashes.pObject);
      v12 = (Scaleform::RefCountVImpl *)stroke.pFill.pObject;
    }
    if ( v12 )
      Scaleform::RefCountImpl::Release(v12);
    return v13;
  }
  else
  {
    v7 = this->FillToStyleTable.Data.Data[fillIndex + v4->StartFill];
    if ( v7 )
    {
      v8 = this->pShapeData.pObject;
      fillStyle.pFill.pObject = 0;
      v8->GetFillStyle(v8, v7, &fillStyle);
      v9 = (Scaleform::RefCountVImpl *)fillStyle.pFill.pObject;
      v10 = fillStyle.pFill.pObject;
      if ( imgFillStyle )
        *imgFillStyle = v7;
      if ( v9 )
        Scaleform::RefCountImpl::Release(v9);
      return v10;
    }
  }
  return result;
}
