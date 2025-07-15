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
  float v9[5]; // [esp+20h] [ebp-1Ch] BYREF
  Scaleform::RefCountVImpl *v10; // [esp+34h] [ebp-8h]
  Scaleform::RefCountVImpl *v11; // [esp+38h] [ebp-4h]

  this->pShapeData.pObject->GetStrokeStyle(this->pShapeData.pObject, idx, s1);
  pObject = this->pMorphData.pObject;
  if ( pObject && 0.0 != morphRatio )
  {
    v10 = 0;
    v11 = 0;
    pObject->pMorphTo.pObject->GetStrokeStyle(pObject->pMorphTo.pObject, idx, (Scaleform::Render::StrokeStyleType *)v9);
    v6 = s1->pFill.pObject == 0;
    v7 = morphRatio;
    s1->Width = s1->Width + (v9[0] - s1->Width) * morphRatio;
    if ( v6 )
    {
      f = v7;
      s1->Color = Scaleform::Render::Color::Blend(
                    (Scaleform::Render::Color *)&morphRatio,
                    (Scaleform::Render::Color)s1->Color,
                    LODWORD(v9[4]),
                    f)->Raw;
    }
    if ( v11 )
      Scaleform::RefCountImpl::Release(v11);
    if ( v10 )
      Scaleform::RefCountImpl::Release(v10);
  }
}
