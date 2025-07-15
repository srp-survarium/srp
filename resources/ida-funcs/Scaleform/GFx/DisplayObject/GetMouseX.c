double __thiscall Scaleform::GFx::DisplayObject::GetMouseX(Scaleform::GFx::DisplayObject *this)
{
  Scaleform::GFx::MovieImpl *pMovieImpl; // eax
  double v2; // st7
  double v3; // st6
  Scaleform::Render::Point<float> b; // [esp+8h] [ebp-14h] BYREF
  float v6; // [esp+10h] [ebp-Ch]
  Scaleform::Render::Point<float> a; // [esp+14h] [ebp-8h] BYREF

  pMovieImpl = this->pASRoot->pMovieImpl;
  a.x = pMovieImpl->mMouseState[0].LastPosition.x;
  a.y = pMovieImpl->mMouseState[0].LastPosition.y;
  b.x = pMovieImpl->ViewOffsetY * 20.0;
  v2 = a.y - b.x;
  b.x = pMovieImpl->VisibleFrameRect.y2 - pMovieImpl->VisibleFrameRect.y1;
  v6 = v2 / b.x * 2.0 - 1.0;
  b.x = 20.0 * pMovieImpl->ViewOffsetX;
  v3 = a.x - b.x;
  b.x = pMovieImpl->VisibleFrameRect.x2 - pMovieImpl->VisibleFrameRect.x1;
  pMovieImpl->ScreenToWorld.Sx = v3 / b.x * 2.0 - 1.0;
  pMovieImpl->ScreenToWorld.Sy = -v6;
  Scaleform::GFx::DisplayObjectBase::TransformPointToLocal(this, &b, &a, 0, 0);
  return floor(b.x + 0.5) * 0.05;
}
