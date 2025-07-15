void __thiscall Scaleform::Render::ShapeMeshProvider::GetFillStyle(
        Scaleform::Render::ShapeMeshProvider *this,
        unsigned int idx,
        Scaleform::Render::FillStyleType *f1,
        float morphRatio)
{
  Scaleform::Render::MorphShapeData *pObject; // edi
  Scaleform::Render::Color c1; // [esp+20h] [ebp-8h] BYREF
  Scaleform::RefCountVImpl *v7; // [esp+24h] [ebp-4h]

  this->pShapeData.pObject->GetFillStyle(this->pShapeData.pObject, idx, f1);
  pObject = this->pMorphData.pObject;
  if ( pObject && 0.0 != morphRatio )
  {
    v7 = 0;
    pObject->pMorphTo.pObject->GetFillStyle(pObject->pMorphTo.pObject, idx, (Scaleform::Render::FillStyleType *)&c1);
    if ( !f1->pFill.pObject )
      f1->Color = Scaleform::Render::Color::Blend(
                    (Scaleform::Render::Color *)&morphRatio,
                    (Scaleform::Render::Color)f1->Color,
                    c1,
                    morphRatio)->Raw;
    if ( v7 )
      Scaleform::RefCountImpl::Release(v7);
  }
}
