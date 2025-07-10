void __thiscall Scaleform::Render::HAL::SetStereoParams(
        Scaleform::Render::HAL *this,
        Scaleform::Render::StereoParams sParams)
{
  if ( sParams.DisplayWidthCm == 0.0 )
    sParams.DisplayWidthCm = sParams.DisplayDiagInches
                           / sqrtf(
                               (float)((float)(*(float *)&clear_value / sParams.DisplayAspectRatio)
                                     * (float)(*(float *)&clear_value / sParams.DisplayAspectRatio))
                             + *(float *)&clear_value)
                           * 2.54;
  this->Matrices.pObject->S3DParams = sParams;
}
