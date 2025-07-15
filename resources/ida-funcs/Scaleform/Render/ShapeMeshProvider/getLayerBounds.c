Scaleform::Render::Rect<float> *__thiscall Scaleform::Render::ShapeMeshProvider::getLayerBounds(
        Scaleform::Render::ShapeMeshProvider *this,
        Scaleform::Render::Rect<float> *result,
        unsigned int drawLayer)
{
  unsigned int StartPos; // edx
  Scaleform::Render::ShapeDataInterface *pObject; // ecx
  Scaleform::Render::ShapePathType i; // eax
  char v8; // [esp+231h] [ebp-85h]
  _DWORD v9[3]; // [esp+232h] [ebp-84h] BYREF
  float v10[6]; // [esp+23Eh] [ebp-78h] BYREF
  Scaleform::Render::Matrix2x4<float> trans; // [esp+256h] [ebp-60h] BYREF
  Scaleform::Render::ShapePosInfo pos; // [esp+27Eh] [ebp-38h] BYREF

  StartPos = this->DrawLayers.Data.Data[drawLayer].StartPos;
  pos.Sfactor = 1.0;
  pObject = this->pShapeData.pObject;
  result->x1 = 1.0e30;
  result->y1 = 1.0e30;
  pos.Pos = StartPos;
  result->x2 = -1.0e30;
  result->y2 = -1.0e30;
  trans.M[0][0] = 1.0;
  memset(&pos.StartX, 0, 44);
  trans.M[0][1] = 0.0;
  trans.M[0][2] = 0.0;
  trans.M[0][3] = 0.0;
  trans.M[1][0] = 0.0;
  trans.M[1][2] = 0.0;
  trans.M[1][3] = 0.0;
  trans.M[1][1] = 1.0;
  pos.Initialized = 0;
  v8 = 1;
  for ( i = pObject->ReadPathInfo(pObject, &pos, v10, v9);
        i;
        i = this->pShapeData.pObject->ReadPathInfo(this->pShapeData.pObject, &pos, v10, v9) )
  {
    if ( !v8 && i == Shape_NewLayer )
      break;
    v8 = 0;
    if ( v9[0] || v9[1] )
      Scaleform::Render::ExpandBoundsToPath<Scaleform::Render::Matrix2x4<float>>(
        this->pShapeData.pObject,
        COERCE_FLOAT(&trans),
        &pos,
        COERCE_FLOAT(v10),
        result);
    else
      this->pShapeData.pObject->SkipPathData(this->pShapeData.pObject, &pos);
  }
  return result;
}
