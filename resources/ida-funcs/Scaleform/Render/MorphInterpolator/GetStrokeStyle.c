void __thiscall Scaleform::Render::MorphInterpolator::GetStrokeStyle(
        Scaleform::Render::MorphInterpolator *this,
        unsigned int idx,
        float s1)
{
  float v3; // esi
  Scaleform::Render::MorphShapeData *pObject; // ecx
  bool v6; // zf
  float v7[5]; // [esp+20h] [ebp-1Ch] BYREF
  Scaleform::RefCountVImpl *v8; // [esp+34h] [ebp-8h]
  Scaleform::RefCountVImpl *v9; // [esp+38h] [ebp-4h]

  v3 = s1;
  this->pShapeData.pObject->GetStrokeStyle(
    this->pShapeData.pObject,
    idx,
    (Scaleform::Render::StrokeStyleType *)LODWORD(s1));
  pObject = this->pMorphData.pObject;
  if ( pObject && 0.0 != this->MorphRatio )
  {
    v8 = 0;
    v9 = 0;
    pObject->pMorphTo.pObject->GetStrokeStyle(pObject->pMorphTo.pObject, idx, (Scaleform::Render::StrokeStyleType *)v7);
    v6 = *(_DWORD *)(LODWORD(v3) + 20) == 0;
    s1 = *(float *)LODWORD(v3);
    *(float *)LODWORD(v3) = (v7[0] - s1) * this->MorphRatio + s1;
    if ( v6 )
      *(Scaleform::Render::Color *)(LODWORD(v3) + 16) = *Scaleform::Render::Color::Blend(
                                                           (Scaleform::Render::Color *)&s1,
                                                           *(Scaleform::Render::Color *)(LODWORD(v3) + 16),
                                                           LODWORD(v7[4]),
                                                           this->MorphRatio);
    if ( v9 )
      Scaleform::RefCountImpl::Release(v9);
    if ( v8 )
      Scaleform::RefCountImpl::Release(v8);
  }
}
