bool __thiscall Scaleform::GFx::TextField::IsUrlUnderMouseCursor(
        Scaleform::GFx::TextField *this,
        unsigned int mouseIndex,
        Scaleform::Render::Point<float> *pPnt,
        Scaleform::Range *purlRangePos)
{
  Scaleform::GFx::MovieImpl *pMovieImpl; // eax
  unsigned int v7; // eax
  double y; // st7
  double x; // st6
  float m_20; // [esp+6Ch] [ebp-4Ch]
  float m_24; // [esp+70h] [ebp-48h]
  Scaleform::Render::Point<float> p; // [esp+88h] [ebp-30h] BYREF
  Scaleform::Render::Point<float> result; // [esp+90h] [ebp-28h] BYREF
  Scaleform::Render::Matrix2x4<float> pmat; // [esp+98h] [ebp-20h] BYREF

  pMovieImpl = this->pASRoot->pMovieImpl;
  if ( !pMovieImpl )
    return 0;
  if ( mouseIndex < 6 )
    v7 = (unsigned int)&pMovieImpl->mMouseState[mouseIndex];
  else
    v7 = 0;
  p.x = *(float *)(v7 + 32);
  p.y = *(float *)(v7 + 36);
  pmat.M[0][0] = 1.0;
  pmat.M[0][1] = 0.0;
  pmat.M[0][2] = 0.0;
  pmat.M[0][3] = 0.0;
  pmat.M[1][0] = 0.0;
  pmat.M[1][2] = 0.0;
  pmat.M[1][3] = 0.0;
  pmat.M[1][1] = 1.0;
  Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(this, &pmat);
  Scaleform::Render::Matrix2x4<float>::TransformByInverse(&pmat, &result, &p);
  y = result.y;
  x = result.x;
  if ( pPnt )
  {
    pPnt->x = result.x;
    pPnt->y = y;
  }
  m_24 = y;
  m_20 = x;
  return Scaleform::Render::Text::DocView::IsUrlAtPoint(this->pDocument.pObject, m_20, m_24, purlRangePos);
}
