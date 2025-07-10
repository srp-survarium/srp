Scaleform::Render::PathEdgeType __thiscall Scaleform::Render::MorphInterpolator::ReadEdge(
        Scaleform::Render::MorphInterpolator *this,
        Scaleform::Render::ShapePosInfo *pos1,
        float *coord1)
{
  Scaleform::Render::MorphShapeData *pObject; // eax
  int v6; // ebx
  float coord2[6]; // [esp+10h] [ebp-18h] BYREF

  pObject = this->pMorphData.pObject;
  if ( !pObject )
    return this->pShapeData.pObject->ReadEdge(this->pShapeData.pObject, pos1, coord1);
  v6 = pObject->ShapeData1.ReadEdge(&pObject->ShapeData1, pos1, coord1);
  this->pMorphData.pObject->ShapeData2.ReadEdge(&this->pMorphData.pObject->ShapeData2, &this->Pos2, coord2);
  if ( v6 )
  {
    *coord1 = (coord2[0] - *coord1) * this->MorphRatio + *coord1;
    coord1[1] = (coord2[1] - coord1[1]) * this->MorphRatio + coord1[1];
    if ( v6 == 2 || v6 == 3 )
    {
      coord1[2] = (coord2[2] - coord1[2]) * this->MorphRatio + coord1[2];
      coord1[3] = (coord2[3] - coord1[3]) * this->MorphRatio + coord1[3];
      if ( v6 == 3 )
      {
        coord1[4] = (coord2[4] - coord1[4]) * this->MorphRatio + coord1[4];
        coord1[5] = (coord2[5] - coord1[5]) * this->MorphRatio + coord1[5];
      }
    }
  }
  return v6;
}
