const Scaleform::Render::Matrix4x4<float> *__thiscall Scaleform::Render::MatrixState::updateStereoProjection(
        Scaleform::Render::MatrixState *this,
        float factor)
{
  Scaleform::Render::StereoDisplay S3DDisplay; // eax
  Scaleform::Render::Matrix4x4<float> *p_Proj3DLeft; // esi
  Scaleform::Render::Matrix4x4<float> *p_Proj3DRight; // esi
  float screenDist; // [esp+Ch] [ebp-4h]

  S3DDisplay = this->S3DDisplay;
  if ( S3DDisplay == StereoCenter )
    return &this->Proj3D;
  screenDist = -this->View3D.M[2][3];
  if ( S3DDisplay == StereoLeft )
  {
    p_Proj3DLeft = &this->Proj3DLeft;
    Scaleform::Render::MatrixState::getStereoProjectionMatrix(
      this,
      &this->Proj3DLeft,
      0,
      &this->Proj3D,
      screenDist,
      factor);
    return p_Proj3DLeft;
  }
  if ( S3DDisplay != StereoRight )
    return &this->Proj3D;
  p_Proj3DRight = &this->Proj3DRight;
  Scaleform::Render::MatrixState::getStereoProjectionMatrix(
    this,
    0,
    &this->Proj3DRight,
    &this->Proj3D,
    screenDist,
    factor);
  return p_Proj3DRight;
}
