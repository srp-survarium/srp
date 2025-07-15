void __thiscall Scaleform::Render::MorphInterpolator::GetStrokeStyle(
        Scaleform::Render::MorphInterpolator *this,
        unsigned int idx,
        Scaleform::Render::StrokeStyleType *s1)
{
  Scaleform::Render::StrokeStyleType *v3; // esi
  Scaleform::Render::MorphShapeData *pObject; // ecx
  bool v6; // zf
  Scaleform::Render::StrokeStyleType s2; // [esp+20h] [ebp-1Ch] BYREF

  v3 = s1;
  this->pShapeData.pObject->GetStrokeStyle(this->pShapeData.pObject, idx, s1);
  pObject = this->pMorphData.pObject;
  if ( pObject && 0.0 != this->MorphRatio )
  {
    s2.pFill.pObject = 0;
    s2.pDashes.pObject = 0;
    pObject->pMorphTo.pObject->GetStrokeStyle(pObject->pMorphTo.pObject, idx, &s2);
    v6 = v3->pFill.pObject == 0;
    s1 = (Scaleform::Render::StrokeStyleType *)LODWORD(v3->Width);
    v3->Width = (s2.Width - *(float *)&s1) * this->MorphRatio + *(float *)&s1;
    if ( v6 )
      v3->Color = Scaleform::Render::Color::Blend(
                    (Scaleform::Render::Color *)&s1,
                    (Scaleform::Render::Color)v3->Color,
                    (Scaleform::Render::Color)s2.Color,
                    this->MorphRatio)->Raw;
    if ( s2.pDashes.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)s2.pDashes.pObject);
    if ( s2.pFill.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)s2.pFill.pObject);
  }
}
