char __thiscall Scaleform::Render::ShapeMeshProvider::checkI9gLayer(
        Scaleform::Render::ShapeMeshProvider *this,
        const Scaleform::Render::ShapeMeshProvider::DrawLayerType *dl)
{
  unsigned int StartPos; // ecx
  Scaleform::Render::ShapeDataInterface *pObject; // ecx
  int v6; // eax
  unsigned int v7; // eax
  Scaleform::Render::ShapeDataInterface *v8; // ecx
  Scaleform::RefCountVImpl *v9; // edi
  Scaleform::Render::ShapePathType v10; // eax
  int v11; // [esp+28h] [ebp-64h] BYREF
  Scaleform::RefCountVImpl *v12; // [esp+2Ch] [ebp-60h]
  unsigned int v13; // [esp+30h] [ebp-5Ch] BYREF
  unsigned int v14; // [esp+34h] [ebp-58h]
  int v15; // [esp+38h] [ebp-54h]
  float v16[6]; // [esp+3Ch] [ebp-50h] BYREF
  _DWORD v17[13]; // [esp+54h] [ebp-38h] BYREF
  char v18; // [esp+88h] [ebp-4h]

  if ( this->pMorphData.pObject )
    return 0;
  StartPos = dl->StartPos;
  *(float *)&v17[12] = 1.0;
  v17[0] = StartPos;
  pObject = this->pShapeData.pObject;
  memset(&v17[1], 0, 44);
  v18 = 0;
  v6 = pObject->ReadPathInfo(pObject, (Scaleform::Render::ShapePosInfo *)v17, v16, &v13);
  if ( v6 != 2 && v6 != 1 || (v13 == 0) == (v14 == 0) || v15 )
    return 0;
  v7 = v13;
  if ( !v13 )
    v7 = v14;
  v8 = this->pShapeData.pObject;
  v12 = 0;
  v8->GetFillStyle(v8, v7, (Scaleform::Render::FillStyleType *)&v11);
  v9 = v12;
  if ( !v12 )
    return 0;
  if ( !v12[1].__vftable
    || Scaleform::Render::Matrix2x4<float>::IsFreeRotation((Scaleform::Render::Matrix2x4<float> *)&v12[2], 0.000001)
    || ((int)v9[6].__vftable & 1) == 0 )
  {
LABEL_19:
    if ( v9 )
      Scaleform::RefCountImpl::Release(v9);
    return 0;
  }
  this->pShapeData.pObject->SkipPathData(this->pShapeData.pObject, (Scaleform::Render::ShapePosInfo *)v17);
  v10 = this->pShapeData.pObject->ReadPathInfo(
          this->pShapeData.pObject,
          (Scaleform::Render::ShapePosInfo *)v17,
          v16,
          &v13);
  if ( v10 != Shape_NewLayer && v10 )
  {
    v9 = v12;
    goto LABEL_19;
  }
  if ( v12 )
    Scaleform::RefCountImpl::Release(v12);
  return 1;
}
