void __thiscall Scaleform::Render::FilterEffect::UpdateCxform(
        Scaleform::Render::FilterEffect *this,
        Scaleform::Render::Cxform *cx)
{
  Scaleform::Render::MatrixPoolImpl::HMatrix::SetCxform(&this->BoundsMatrix, cx);
}
