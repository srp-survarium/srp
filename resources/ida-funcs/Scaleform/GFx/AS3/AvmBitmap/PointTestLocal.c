bool __thiscall Scaleform::GFx::AS3::AvmBitmap::PointTestLocal(
        Scaleform::GFx::AS3::AvmBitmap *this,
        const Scaleform::Render::Point<float> *pt,
        unsigned __int8 hitTestMask)
{
  Scaleform::GFx::ImageResource *pObject; // eax
  bool result; // al
  float v5; // [esp+28h] [ebp-18h]
  float v6; // [esp+2Ch] [ebp-14h]
  Scaleform::Render::Rect<float> v7; // [esp+30h] [ebp-10h] BYREF

  pObject = this->pImage.pObject;
  result = 0;
  if ( pObject )
  {
    pObject->pImage->GetRect(pObject->pImage, (Scaleform::Render::Rect<unsigned long> *)&v7);
    v5 = (double)(unsigned int)(LODWORD(v7.x2) - LODWORD(v7.x1)) * 20.0;
    v6 = 20.0 * (double)(unsigned int)(LODWORD(v7.y2) - LODWORD(v7.y1));
    v7.x1 = 0.0;
    v7.y1 = 0.0;
    v7.x2 = v5 + 0.0;
    v7.y2 = v6 + 0.0;
    if ( Scaleform::Render::Rect<float>::Contains(&v7, pt) )
      return 1;
  }
  return result;
}
