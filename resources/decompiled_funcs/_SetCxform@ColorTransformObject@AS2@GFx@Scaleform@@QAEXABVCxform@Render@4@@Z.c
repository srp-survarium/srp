void __thiscall Scaleform::GFx::AS2::ColorTransformObject::SetCxform(
        Scaleform::GFx::AS2::ColorTransformObject *this,
        const Scaleform::Render::Cxform *ct)
{
  qmemcpy(&this->mColorTransform, ct, sizeof(this->mColorTransform));
  this->mColorTransform.M[1][0] = this->mColorTransform.M[1][0] * 255.0;
  this->mColorTransform.M[1][1] = this->mColorTransform.M[1][1] * 255.0;
  this->mColorTransform.M[1][2] = this->mColorTransform.M[1][2] * 255.0;
  this->mColorTransform.M[1][3] = 255.0 * this->mColorTransform.M[1][3];
}
