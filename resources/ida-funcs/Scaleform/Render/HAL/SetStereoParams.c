void __thiscall Scaleform::Render::HAL::SetStereoParams(
        Scaleform::Render::HAL *this,
        Scaleform::Render::StereoParams sParams)
{
  if ( sParams.DisplayWidthCm == 0.0 )
    sParams.DisplayWidthCm = (float)(sParams.DisplayDiagInches
                                   / fsqrt(
                                       (float)((float)(s_bm_current_air_resistance / sParams.DisplayAspectRatio)
                                             * (float)(s_bm_current_air_resistance / sParams.DisplayAspectRatio))
                                     + s_bm_current_air_resistance))
                           * 2.54;
  qmemcpy(&this->Matrices.pObject->S3DParams, &sParams, sizeof(this->Matrices.pObject->S3DParams));
}
