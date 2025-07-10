Scaleform::Render::Rect<float> *__thiscall Scaleform::GFx::MovieImpl::TranslateToScreen(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::Render::Rect<float> *result,
        const Scaleform::Render::Rect<float> *r,
        Scaleform::Render::Matrix2x4<float> *puserMatrix)
{
  Scaleform::GFx::InteractiveObject *pMainMovie; // ecx
  Scaleform::Render::Rect<float> v7; // [esp+70h] [ebp-50h] BYREF
  Scaleform::Render::Matrix2x4<float> v8; // [esp+80h] [ebp-40h] BYREF
  Scaleform::Render::Matrix2x4<float> pmat; // [esp+A0h] [ebp-20h] BYREF

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
  v7.x1 = r->x1 * 20.0;
  v7.y1 = r->y1 * 20.0;
  v7.x2 = r->x2 * 20.0;
  v7.y2 = 20.0 * r->y2;
  Scaleform::Render::Matrix2x4<float>::EncloseTransform(&v8, result, &v7);
  return result;
}
