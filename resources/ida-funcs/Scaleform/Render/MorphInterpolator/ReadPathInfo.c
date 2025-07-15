Scaleform::Render::ShapePathType __thiscall Scaleform::Render::MorphInterpolator::ReadPathInfo(
        Scaleform::Render::MorphInterpolator *this,
        Scaleform::Render::ShapePosInfo *pos1,
        float *coord1,
        unsigned int *styles1)
{
  Scaleform::Render::MorphShapeData *pObject; // eax
  int v7; // ebx
  _BYTE v8[12]; // [esp+Ch] [ebp-24h] BYREF
  float v9[6]; // [esp+18h] [ebp-18h] BYREF

  pObject = this->pMorphData.pObject;
  if ( !pObject )
    return this->pShapeData.pObject->ReadPathInfo(this->pShapeData.pObject, pos1, coord1, styles1);
  v7 = pObject->ShapeData1.ReadPathInfo(&pObject->ShapeData1, pos1, coord1, styles1);
  this->pMorphData.pObject->ShapeData2.ReadPathInfo(
    &this->pMorphData.pObject->ShapeData2,
    &this->Pos2,
    v9,
    (unsigned int *)v8);
  if ( v7 )
  {
    *coord1 = (v9[0] - *coord1) * this->MorphRatio + *coord1;
    coord1[1] = (v9[1] - coord1[1]) * this->MorphRatio + coord1[1];
  }
  return v7;
}
