void __thiscall Scaleform::Render::HAL::SetStereoDisplay(
        Scaleform::Render::HAL *this,
        Scaleform::Render::StereoDisplay sDisplay,
        bool setstate)
{
  this->Matrices.pObject->S3DDisplay = sDisplay;
  this->Matrices.pObject->UVPOChanged = 1;
}
