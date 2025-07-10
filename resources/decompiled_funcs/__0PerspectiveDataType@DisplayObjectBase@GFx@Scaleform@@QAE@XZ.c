void __thiscall Scaleform::GFx::DisplayObjectBase::PerspectiveDataType::PerspectiveDataType(
        Scaleform::GFx::DisplayObjectBase::PerspectiveDataType *this)
{
  float *p_ViewMatrix3D; // edi

  this->FieldOfView = 0.0;
  p_ViewMatrix3D = (float *)&this->ViewMatrix3D;
  this->FocalLength = 0.0;
  memset((int)&this->ViewMatrix3D, 0, sizeof(this->ViewMatrix3D));
  *p_ViewMatrix3D = 1.0;
  p_ViewMatrix3D[5] = 1.0;
  p_ViewMatrix3D[10] = 1.0;
  this->ProjectionCenter.x = Scaleform::GFx::NumberUtil::NaN();
  this->ProjectionCenter.y = Scaleform::GFx::NumberUtil::NaN();
}
