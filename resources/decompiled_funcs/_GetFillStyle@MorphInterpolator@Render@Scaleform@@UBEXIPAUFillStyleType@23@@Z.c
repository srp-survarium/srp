void __thiscall Scaleform::Render::MorphInterpolator::GetFillStyle(
        Scaleform::Render::MorphInterpolator *this,
        unsigned int idx,
        Scaleform::Render::Color *f1)
{
  Scaleform::Render::Color *v3; // esi
  Scaleform::Render::MorphShapeData *pObject; // ecx
  Scaleform::Render::FillStyleType f2; // [esp+20h] [ebp-8h] BYREF

  v3 = f1;
  this->pShapeData.pObject->GetFillStyle(this->pShapeData.pObject, idx, (Scaleform::Render::FillStyleType *)f1);
  pObject = this->pMorphData.pObject;
  if ( pObject && 0.0 != this->MorphRatio )
  {
    f2.pFill.pObject = 0;
    pObject->pMorphTo.pObject->GetFillStyle(pObject->pMorphTo.pObject, idx, &f2);
    if ( !v3[1].Raw )
      *v3 = *Scaleform::Render::Color::Blend(
               (Scaleform::Render::Color *)&f1,
               *v3,
               (Scaleform::Render::Color)f2.Color,
               this->MorphRatio);
    if ( f2.pFill.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)f2.pFill.pObject);
  }
}
