void __thiscall Scaleform::Render::MorphInterpolator::GetFillStyle(
        Scaleform::Render::MorphInterpolator *this,
        unsigned int idx,
        Scaleform::Render::FillStyleType *f1)
{
  Scaleform::Render::Color *v3; // esi
  Scaleform::Render::MorphShapeData *pObject; // ecx
  Scaleform::Render::Color c1; // [esp+20h] [ebp-8h] BYREF
  Scaleform::RefCountVImpl *v7; // [esp+24h] [ebp-4h]

  v3 = (Scaleform::Render::Color *)f1;
  this->pShapeData.pObject->GetFillStyle(this->pShapeData.pObject, idx, f1);
  pObject = this->pMorphData.pObject;
  if ( pObject && 0.0 != this->MorphRatio )
  {
    v7 = 0;
    pObject->pMorphTo.pObject->GetFillStyle(pObject->pMorphTo.pObject, idx, (Scaleform::Render::FillStyleType *)&c1);
    if ( !v3[1].Raw )
      *v3 = *Scaleform::Render::Color::Blend((Scaleform::Render::Color *)&f1, *v3, c1, this->MorphRatio);
    if ( v7 )
      Scaleform::RefCountImpl::Release(v7);
  }
}
