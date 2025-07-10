int __thiscall Scaleform::GFx::AS3::AvmBitmap::GetTopMostMouseEntity(
        Scaleform::GFx::AS3::AvmBitmap *this,
        const Scaleform::Render::Point<float> *pt,
        Scaleform::GFx::DisplayObjectBase::TopMostDescr *pdescr)
{
  float v5; // [esp+48h] [ebp-20h]
  float v6; // [esp+4Ch] [ebp-1Ch]
  Scaleform::Render::Point<float> v7; // [esp+50h] [ebp-18h] BYREF
  Scaleform::Render::Rect<float> v8; // [esp+58h] [ebp-10h] BYREF

  if ( !this->GetVisible(this) )
    return 2;
  if ( !this->pImage.pObject )
    return 2;
  Scaleform::GFx::DisplayObjectBase::TransformPointToLocal(this, &v7, pt, 1, 0);
  this->pImage.pObject->pImage->GetRect(this->pImage.pObject->pImage, (Scaleform::Render::Rect<unsigned long> *)&v8);
  v5 = (double)(unsigned int)(LODWORD(v8.x2) - LODWORD(v8.x1)) * 20.0;
  v6 = 20.0 * (double)(unsigned int)(LODWORD(v8.y2) - LODWORD(v8.y1));
  v8.x1 = 0.0;
  v8.y1 = 0.0;
  v8.x2 = v5 + 0.0;
  v8.y2 = v6 + 0.0;
  if ( !Scaleform::Render::Rect<float>::Contains(&v8, &v7) )
    return 2;
  pdescr->pResult = this->pParent;
  return 1;
}
