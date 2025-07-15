char __thiscall Scaleform::Render::ShapeMeshProvider::checkI9gLayer(
        Scaleform::Render::ShapeMeshProvider *this,
        const Scaleform::Render::ShapeMeshProvider::DrawLayerType *dl)
{
  unsigned int StartPos; // ecx
  Scaleform::Render::ShapeDataInterface *pObject; // ecx
  int v6; // eax
  unsigned int v7; // eax
  Scaleform::Render::ShapeDataInterface *v8; // ecx
  Scaleform::Render::ComplexFill *v9; // edi
  Scaleform::Render::ShapePathType v10; // eax
  Scaleform::Render::FillStyleType f; // [esp+28h] [ebp-64h] BYREF
  unsigned int styles[3]; // [esp+30h] [ebp-5Ch] BYREF
  float coords[6]; // [esp+3Ch] [ebp-50h] BYREF
  Scaleform::Render::ShapePosInfo posInfo; // [esp+54h] [ebp-38h] BYREF

  if ( this->pMorphData.pObject )
    return 0;
  StartPos = dl->StartPos;
  posInfo.Sfactor = 1.0;
  posInfo.Pos = StartPos;
  pObject = this->pShapeData.pObject;
  memset(&posInfo.StartX, 0, 44);
  posInfo.Initialized = 0;
  v6 = pObject->ReadPathInfo(pObject, &posInfo, coords, styles);
  if ( v6 != 2 && v6 != 1 || (styles[0] == 0) == (styles[1] == 0) || styles[2] )
    return 0;
  v7 = styles[0];
  if ( !styles[0] )
    v7 = styles[1];
  v8 = this->pShapeData.pObject;
  f.pFill.pObject = 0;
  v8->GetFillStyle(v8, v7, &f);
  v9 = f.pFill.pObject;
  if ( !f.pFill.pObject )
    return 0;
  if ( !f.pFill.pObject->pImage.pObject
    || Scaleform::Render::Matrix2x4<float>::IsFreeRotation(&f.pFill.pObject->ImageMatrix, 0.000001)
    || (v9->FillMode.Fill & 1) == 0 )
  {
LABEL_19:
    if ( v9 )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v9);
    return 0;
  }
  this->pShapeData.pObject->SkipPathData(this->pShapeData.pObject, &posInfo);
  v10 = this->pShapeData.pObject->ReadPathInfo(this->pShapeData.pObject, &posInfo, coords, styles);
  if ( v10 != Shape_NewLayer && v10 )
  {
    v9 = f.pFill.pObject;
    goto LABEL_19;
  }
  if ( f.pFill.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)f.pFill.pObject);
  return 1;
}
