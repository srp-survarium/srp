void __thiscall Scaleform::Render::ShapeMeshProvider::GetFillStyle(
        Scaleform::Render::ShapeMeshProvider *this,
        unsigned int idx,
        Scaleform::Render::FillStyleType *f1,
        float morphRatio)
{
  Scaleform::Render::MorphShapeData *pObject; // edi
  Scaleform::Render::FillStyleType f2; // [esp+20h] [ebp-8h] BYREF

  this->pShapeData.pObject->GetFillStyle(this->pShapeData.pObject, idx, f1);
  pObject = this->pMorphData.pObject;
  if ( pObject && 0.0 != morphRatio )
  {
    f2.pFill.pObject = 0;
    pObject->pMorphTo.pObject->GetFillStyle(pObject->pMorphTo.pObject, idx, &f2);
    if ( !f1->pFill.pObject )
      f1->Color = Scaleform::Render::Color::Blend(
                    (Scaleform::Render::Color *)&morphRatio,
                    (Scaleform::Render::Color)f1->Color,
                    (Scaleform::Render::Color)f2.Color,
                    morphRatio)->Raw;
    if ( f2.pFill.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)f2.pFill.pObject);
  }
}
