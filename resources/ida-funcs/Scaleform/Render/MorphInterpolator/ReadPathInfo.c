Scaleform::Render::ShapePathType __thiscall Scaleform::Render::MorphInterpolator::ReadPathInfo(
        Scaleform::Render::MorphInterpolator *this,
        Scaleform::Render::ShapePosInfo *pos1,
        float *coord1,
        unsigned int *styles1)
{
  Scaleform::Render::MorphShapeData *pObject; // eax
  int v7; // ebx
  unsigned int styles2[3]; // [esp+Ch] [ebp-24h] BYREF
  float coord2[6]; // [esp+18h] [ebp-18h] BYREF

  pObject = this->pMorphData.pObject;
  if ( !pObject )
    return this->pShapeData.pObject->ReadPathInfo(this->pShapeData.pObject, pos1, coord1, styles1);
  v7 = pObject->ShapeData1.ReadPathInfo(&pObject->ShapeData1, pos1, coord1, styles1);
  this->pMorphData.pObject->ShapeData2.ReadPathInfo(&this->pMorphData.pObject->ShapeData2, &this->Pos2, coord2, styles2);
  if ( v7 )
  {
    *coord1 = (coord2[0] - *coord1) * this->MorphRatio + *coord1;
    coord1[1] = (coord2[1] - coord1[1]) * this->MorphRatio + coord1[1];
  }
  return v7;
}
