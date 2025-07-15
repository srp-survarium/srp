Scaleform::Render::Point<float> *__thiscall Scaleform::GFx::MovieImpl::TranslateToScreen(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::Render::Point<float> *result,
        const Scaleform::Render::Point<float> *p,
        Scaleform::Render::Matrix2x4<float> *puserMatrix)
{
  Scaleform::GFx::InteractiveObject *pMainMovie; // ecx
  Scaleform::Render::Point<float> *v6; // eax
  float v7; // [esp+18h] [ebp-48h]
  float v8; // [esp+1Ch] [ebp-44h]
  Scaleform::Render::Matrix2x4<float> v9; // [esp+20h] [ebp-40h] BYREF
  Scaleform::Render::Matrix2x4<float> pmat; // [esp+40h] [ebp-20h] BYREF

  pmat.M[0][0] = 1.0;
  pMainMovie = this->pMainMovie;
  pmat.M[0][1] = 0.0;
  pmat.M[0][2] = 0.0;
  pmat.M[0][3] = 0.0;
  pmat.M[1][0] = 0.0;
  pmat.M[1][2] = 0.0;
  pmat.M[1][3] = 0.0;
  pmat.M[1][1] = 1.0;
  Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(pMainMovie, &pmat);
  v9.M[0][0] = this->ViewportMatrix.M[0][0];
  v9.M[0][1] = this->ViewportMatrix.M[0][1];
  v9.M[0][2] = this->ViewportMatrix.M[0][2];
  v9.M[0][3] = this->ViewportMatrix.M[0][3];
  v9.M[1][0] = this->ViewportMatrix.M[1][0];
  v9.M[1][1] = this->ViewportMatrix.M[1][1];
  v9.M[1][2] = this->ViewportMatrix.M[1][2];
  v9.M[1][3] = this->ViewportMatrix.M[1][3];
  if ( puserMatrix )
    Scaleform::Render::Matrix2x4<float>::Prepend(&v9, puserMatrix);
  Scaleform::Render::Matrix2x4<float>::Prepend(&v9, &pmat);
  v6 = result;
  v7 = p->x * 20.0;
  v8 = 20.0 * p->y;
  result->x = v8 * v9.M[0][1] + v7 * v9.M[0][0] + v9.M[0][3];
  result->y = v8 * v9.M[1][1] + v7 * v9.M[1][0] + v9.M[1][3];
  return v6;
}


__m128 *__thiscall Scaleform::GFx::MovieImpl::TranslateToScreen(
        Scaleform::GFx::MovieImpl *this,
        __m128 *result,
        const Scaleform::Render::Rect<float> *r,
        Scaleform::Render::Matrix2x4<float> *puserMatrix)
{
  Scaleform::GFx::InteractiveObject *pMainMovie; // ecx
  Scaleform::Render::Rect<float> ra; // [esp+10h] [ebp-50h] BYREF
  Scaleform::Render::Matrix2x4<float> v8; // [esp+20h] [ebp-40h] BYREF
  Scaleform::Render::Matrix2x4<float> pmat; // [esp+40h] [ebp-20h] BYREF

  pmat.M[0][0] = 1.0;
  pMainMovie = this->pMainMovie;
  pmat.M[0][1] = 0.0;
  pmat.M[0][2] = 0.0;
  pmat.M[0][3] = 0.0;
  pmat.M[1][0] = 0.0;
  pmat.M[1][2] = 0.0;
  pmat.M[1][3] = 0.0;
  pmat.M[1][1] = 1.0;
  Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(pMainMovie, &pmat);
  v8.M[0][0] = this->ViewportMatrix.M[0][0];
  v8.M[0][1] = this->ViewportMatrix.M[0][1];
  v8.M[0][2] = this->ViewportMatrix.M[0][2];
  v8.M[0][3] = this->ViewportMatrix.M[0][3];
  v8.M[1][0] = this->ViewportMatrix.M[1][0];
  v8.M[1][1] = this->ViewportMatrix.M[1][1];
  v8.M[1][2] = this->ViewportMatrix.M[1][2];
  v8.M[1][3] = this->ViewportMatrix.M[1][3];
  if ( puserMatrix )
    Scaleform::Render::Matrix2x4<float>::Prepend(&v8, puserMatrix);
  Scaleform::Render::Matrix2x4<float>::Prepend(&v8, &pmat);
  ra.x1 = r->x1 * 20.0;
  ra.y1 = r->y1 * 20.0;
  ra.x2 = r->x2 * 20.0;
  ra.y2 = 20.0 * r->y2;
  Scaleform::Render::Matrix2x4<float>::EncloseTransform(&v8, result, (__m128 *)&ra);
  return result;
}
