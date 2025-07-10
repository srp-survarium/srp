BOOL __thiscall Scaleform::Render::MaskEffect::UpdateMatrix(
        Scaleform::Render::MaskEffect *this,
        Scaleform::Render::MaskEffectState mes,
        const Scaleform::Render::Matrix2x4<float> *areaMatrix)
{
  Scaleform::Render::MatrixPoolImpl::HMatrix::SetMatrix2D(&this->BoundsMatrix, areaMatrix);
  return mes != this->MES;
}
