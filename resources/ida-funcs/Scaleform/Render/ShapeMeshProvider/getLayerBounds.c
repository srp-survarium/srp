Scaleform::Render::Rect<float> *__thiscall Scaleform::Render::ShapeMeshProvider::getLayerBounds(
        Scaleform::Render::ShapeMeshProvider *this,
        Scaleform::Render::Rect<float> *result,
        unsigned int drawLayer)
{
  unsigned int StartPos; // edx
  Scaleform::Render::ShapeDataInterface *pObject; // ecx
  Scaleform::Render::ShapePathType i; // eax
  char v8; // [esp+17h] [ebp-85h]
  _DWORD v9[3]; // [esp+18h] [ebp-84h] BYREF
  float v10[6]; // [esp+24h] [ebp-78h] BYREF
  float v11[10]; // [esp+3Ch] [ebp-60h] BYREF
  Scaleform::Render::ShapePosInfo v12; // [esp+64h] [ebp-38h] BYREF

  StartPos = this->DrawLayers.Data.Data[drawLayer].StartPos;
  v12.Sfactor = 1.0;
  pObject = this->pShapeData.pObject;
  result->x1 = 1.0e30;
  result->y1 = 1.0e30;
  v12.Pos = StartPos;
  result->x2 = -1.0e30;
  result->y2 = -1.0e30;
  v11[0] = 1.0;
  memset(&v12.StartX, 0, 44);
  v11[1] = 0.0;
  v11[2] = 0.0;
  v11[3] = 0.0;
  v11[4] = 0.0;
  v11[6] = 0.0;
  v11[7] = 0.0;
  v11[5] = 1.0;
  v12.Initialized = 0;
  v8 = 1;
  for ( i = pObject->ReadPathInfo(pObject, &v12, v10, v9);
        i;
        i = this->pShapeData.pObject->ReadPathInfo(this->pShapeData.pObject, &v12, v10, v9) )
  {
    if ( !v8 && i == Shape_NewLayer )
      break;
    v8 = 0;
    if ( v9[0] || v9[1] )
      Scaleform::Render::ExpandBoundsToPath<Scaleform::Render::Matrix2x4<float>>(
        this->pShapeData.pObject,
        COERCE_FLOAT(v11),
        &v12,
        COERCE_FLOAT(v10),
        result);
    else
      this->pShapeData.pObject->SkipPathData(this->pShapeData.pObject, &v12);
  }
  return result;
}
