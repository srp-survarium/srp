Scaleform::Render::Point<float> *__thiscall Scaleform::GFx::DisplayObjectBase::GlobalToLocal(
        Scaleform::GFx::DisplayObjectBase *this,
        Scaleform::Render::Point<float> *result,
        const Scaleform::Render::Point<float> *ptIn)
{
  Scaleform::GFx::MovieImpl *pMovieImpl; // eax
  double v4; // st7
  double v5; // st6
  float v8; // [esp+0h] [ebp-Ch]
  float v9; // [esp+4h] [ebp-8h]
  float v10; // [esp+8h] [ebp-4h]
  float pt; // [esp+14h] [ebp+8h]
  float pta; // [esp+14h] [ebp+8h]
  float ptb; // [esp+14h] [ebp+8h]
  float ptc; // [esp+14h] [ebp+8h]

  pMovieImpl = this->pASRoot->pMovieImpl;
  if ( pMovieImpl )
  {
    v9 = (ptIn->x - pMovieImpl->ViewOffsetX) / pMovieImpl->ViewScaleX;
    v10 = (ptIn->y - pMovieImpl->ViewOffsetY) / pMovieImpl->ViewScaleY;
    pt = pMovieImpl->ViewOffsetY * 20.0;
    v4 = v10 - pt;
    pta = pMovieImpl->VisibleFrameRect.y2 - pMovieImpl->VisibleFrameRect.y1;
    v8 = v4 / pta * 2.0 - 1.0;
    ptb = 20.0 * pMovieImpl->ViewOffsetX;
    v5 = v9 - ptb;
    ptc = pMovieImpl->VisibleFrameRect.x2 - pMovieImpl->VisibleFrameRect.x1;
    pMovieImpl->ScreenToWorld.Sx = v5 / ptc * 2.0 - 1.0;
    pMovieImpl->ScreenToWorld.Sy = -v8;
    Scaleform::GFx::DisplayObjectBase::TransformPointToLocal(this, result, ptIn, 0, 0);
  }
  return result;
}
