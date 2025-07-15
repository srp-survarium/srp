Scaleform::RefCountVImpl *__thiscall Scaleform::Render::ShapeMeshProvider::getComplexFill(
        Scaleform::Render::ShapeMeshProvider *this,
        unsigned int drawLayer,
        unsigned int fillIndex,
        unsigned int *imgFillStyle)
{
  Scaleform::Render::ShapeMeshProvider::DrawLayerType *v4; // esi
  unsigned int StrokeStyle; // edx
  Scaleform::RefCountVImpl *result; // eax
  unsigned int v7; // esi
  Scaleform::Render::ShapeDataInterface *v8; // ecx
  Scaleform::RefCountVImpl *v9; // ecx
  Scaleform::RefCountVImpl *v10; // ebx
  Scaleform::Render::ShapeDataInterface *pObject; // ecx
  Scaleform::RefCountVImpl *v12; // eax
  Scaleform::RefCountVImpl *v13; // esi
  char v14; // [esp+4h] [ebp-24h] BYREF
  Scaleform::RefCountVImpl *v15; // [esp+8h] [ebp-20h]
  char v16; // [esp+Ch] [ebp-1Ch] BYREF
  Scaleform::RefCountVImpl *v17; // [esp+20h] [ebp-8h]
  Scaleform::RefCountVImpl *v18; // [esp+24h] [ebp-4h]

  v4 = &this->DrawLayers.Data.Data[drawLayer];
  StrokeStyle = v4->StrokeStyle;
  result = 0;
  if ( StrokeStyle )
  {
    pObject = this->pShapeData.pObject;
    v17 = 0;
    v18 = 0;
    pObject->GetStrokeStyle(pObject, StrokeStyle, (Scaleform::Render::StrokeStyleType *)&v16);
    v12 = v17;
    v13 = v17;
    if ( v18 )
    {
      Scaleform::RefCountImpl::Release(v18);
      v12 = v17;
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
      v15 = 0;
      v8->GetFillStyle(v8, v7, (Scaleform::Render::FillStyleType *)&v14);
      v9 = v15;
      v10 = v15;
      if ( imgFillStyle )
        *imgFillStyle = v7;
      if ( v9 )
        Scaleform::RefCountImpl::Release(v9);
      return v10;
    }
  }
  return result;
}
