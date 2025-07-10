void __thiscall Scaleform::Render::MorphInterpolator::SkipPathData(
        Scaleform::Render::MorphInterpolator *this,
        Scaleform::Render::ShapePosInfo *pos1)
{
  Scaleform::Render::MorphShapeData *pObject; // eax

  pObject = this->pMorphData.pObject;
  if ( pObject )
  {
    pObject->ShapeData1.SkipPathData(&pObject->ShapeData1, pos1);
    this->pMorphData.pObject->ShapeData2.SkipPathData(&this->pMorphData.pObject->ShapeData2, &this->Pos2);
  }
  else
  {
    this->pShapeData.pObject->SkipPathData(this->pShapeData.pObject, pos1);
  }
}
