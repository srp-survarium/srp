Scaleform::Render::Point<float> *__thiscall Scaleform::GFx::MovieImpl::TranslateToScreen(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::Render::Point<float> *result,
        const Scaleform::Render::Point<float> *p,
        Scaleform::Render::Matrix2x4<float> *puserMatrix)
{
  Scaleform::GFx::InteractiveObject *pMainMovie; // ecx
  Scaleform::Render::Point<float> *v6; // eax
  float v7; // [esp+78h] [ebp-48h]
  float v8; // [esp+7Ch] [ebp-44h]
  Scaleform::Render::Matrix2x4<float> v9; // [esp+80h] [ebp-40h] BYREF
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
