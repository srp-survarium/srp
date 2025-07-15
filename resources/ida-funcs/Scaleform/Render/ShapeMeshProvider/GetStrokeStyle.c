void __thiscall Scaleform::Render::ShapeMeshProvider::GetStrokeStyle(
        Scaleform::Render::ShapeMeshProvider *this,
        unsigned int idx,
        Scaleform::Render::StrokeStyleType *s1,
        float morphRatio)
{
  Scaleform::Render::MorphShapeData *pObject; // edi
  bool v6; // zf
  double v7; // st7
  float f; // [esp+10h] [ebp-2Ch]
  Scaleform::Render::StrokeStyleType s2; // [esp+20h] [ebp-1Ch] BYREF

  this->pShapeData.pObject->GetStrokeStyle(this->pShapeData.pObject, idx, s1);
  pObject = this->pMorphData.pObject;
  if ( pObject && 0.0 != morphRatio )
  {
    s2.pFill.pObject = 0;
    s2.pDashes.pObject = 0;
    pObject->pMorphTo.pObject->GetStrokeStyle(pObject->pMorphTo.pObject, idx, &s2);
    v6 = s1->pFill.pObject == 0;
    v7 = morphRatio;
    s1->Width = s1->Width + (s2.Width - s1->Width) * morphRatio;
    if ( v6 )
    {
      f = v7;
      s1->Color = Scaleform::Render::Color::Blend(
                    (Scaleform::Render::Color *)&morphRatio,
                    (Scaleform::Render::Color)s1->Color,
                    (Scaleform::Render::Color)s2.Color,
                    f)->Raw;
    }
    if ( s2.pDashes.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)s2.pDashes.pObject);
    if ( s2.pFill.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)s2.pFill.pObject);
  }
}
