void __thiscall SpeedTree::CView::ComputeCameraFacingMatrix(SpeedTree::CView *this)
{
  float v1; // [esp+0h] [ebp-Ch]
  SpeedTree::Mat4x4 *dst; // [esp+8h] [ebp-4h]

  dst = &this->m_mCameraFacingMatrix;
  memset((int)&this->m_mCameraFacingMatrix, 0, sizeof(this->m_mCameraFacingMatrix));
  dst->m_afSingle[15] = 1.0;
  dst->m_afSingle[10] = 1.0;
  dst->m_afSingle[5] = 1.0;
  dst->m_afSingle[0] = 1.0;
  SpeedTree::CCoordSys::RotateUpAxis(&this->m_mCameraFacingMatrix, this->m_fCameraAzimuth);
  if ( (unsigned __int8)SpeedTree::CCoordSys::IsLeftHanded() || !(unsigned __int8)SpeedTree::CCoordSys::IsYAxisUp() )
  {
    v1 = -this->m_fCameraPitch;
    SpeedTree::CCoordSys::RotateOutAxis(&this->m_mCameraFacingMatrix, v1);
  }
  else
  {
    SpeedTree::CCoordSys::RotateOutAxis(&this->m_mCameraFacingMatrix, this->m_fCameraPitch);
  }
}
