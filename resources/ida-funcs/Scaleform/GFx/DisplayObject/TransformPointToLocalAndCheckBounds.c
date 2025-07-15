char __thiscall Scaleform::GFx::DisplayObject::TransformPointToLocalAndCheckBounds(
        Scaleform::GFx::DisplayObject *this,
        Scaleform::Render::Point<float> *p,
        const Scaleform::Render::Point<float> *pt,
        bool bPtInParentSpace,
        Scaleform::Render::Matrix2x4<float> *mat)
{
  long double x; // st7
  long double y; // st6
  Scaleform::GFx::DisplayObject::ScrollRectInfo *pScrollRect; // ecx
  Scaleform::GFx::DisplayObject::ScrollRectInfo *v9; // esi
  float x1; // [esp+4h] [ebp-10h]
  float y1; // [esp+8h] [ebp-Ch]
  Scaleform::Render::Point<float> localPt2; // [esp+Ch] [ebp-8h] BYREF

  if ( this->pScrollRect )
  {
    Scaleform::GFx::DisplayObjectBase::TransformPointToLocal(this, &localPt2, pt, bPtInParentSpace, mat);
    x = localPt2.x;
    p->x = localPt2.x;
    y = localPt2.y;
    p->y = localPt2.y;
    pScrollRect = this->pScrollRect;
    x1 = pScrollRect->Rectangle.x1;
    y1 = pScrollRect->Rectangle.y1;
    p->x = x1 + x;
    p->y = y1 + y;
    if ( x < 0.0 )
      return 0;
    if ( y < 0.0 )
      return 0;
    v9 = this->pScrollRect;
    if ( v9->Rectangle.x2 - v9->Rectangle.x1 < x )
      return 0;
    if ( v9->Rectangle.y2 - v9->Rectangle.y1 < y )
      return 0;
  }
  else
  {
    Scaleform::GFx::DisplayObjectBase::TransformPointToLocal(this, p, pt, bPtInParentSpace, mat);
  }
  return 1;
}
