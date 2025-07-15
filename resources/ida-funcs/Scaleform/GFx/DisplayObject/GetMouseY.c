double __thiscall Scaleform::GFx::DisplayObject::GetMouseY(Scaleform::GFx::DisplayObject *this)
{
  Scaleform::GFx::MovieImpl *pMovieImpl; // eax
  double v2; // st7
  double v3; // st6
  Scaleform::Render::Point<float> p; // [esp+8h] [ebp-14h] BYREF
  float v6; // [esp+10h] [ebp-Ch]
  Scaleform::Render::Point<float> pt; // [esp+14h] [ebp-8h] BYREF

  pMovieImpl = this->pASRoot->pMovieImpl;
  pt.x = pMovieImpl->mMouseState[0].LastPosition.x;
  pt.y = pMovieImpl->mMouseState[0].LastPosition.y;
  p.x = pMovieImpl->ViewOffsetY * 20.0;
  v2 = pt.y - p.x;
  p.x = pMovieImpl->VisibleFrameRect.y2 - pMovieImpl->VisibleFrameRect.y1;
  v6 = v2 / p.x * 2.0 - 1.0;
  p.x = 20.0 * pMovieImpl->ViewOffsetX;
  v3 = pt.x - p.x;
  p.x = pMovieImpl->VisibleFrameRect.x2 - pMovieImpl->VisibleFrameRect.x1;
  pMovieImpl->ScreenToWorld.Sx = v3 / p.x * 2.0 - 1.0;
  pMovieImpl->ScreenToWorld.Sy = -v6;
  Scaleform::GFx::DisplayObjectBase::TransformPointToLocal(this, &p, &pt, 0, 0);
  return floor(p.y + 0.5) * 0.05;
}
