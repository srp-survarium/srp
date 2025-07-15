char __thiscall SpeedTree::CView::Set(
        SpeedTree::CView *this,
        const struct SpeedTree::Vec3 *a2,
        struct SpeedTree::Mat4x4 *lhs,
        struct SpeedTree::Mat4x4 *a4,
        float a5,
        float a6)
{
  float v7; // [esp+18h] [ebp-1E8h]
  float m_fHorzFadeValue; // [esp+1Ch] [ebp-1E4h]
  float v9; // [esp+20h] [ebp-1E0h]
  float v10; // [esp+24h] [ebp-1DCh]
  float v11; // [esp+28h] [ebp-1D8h]
  bool v12; // [esp+2Ch] [ebp-1D4h]
  float v14; // [esp+44h] [ebp-1BCh]
  float v15; // [esp+48h] [ebp-1B8h]
  float v16; // [esp+4Ch] [ebp-1B4h]
  float v17; // [esp+54h] [ebp-1ACh]
  float v18; // [esp+58h] [ebp-1A8h]
  float v19; // [esp+5Ch] [ebp-1A4h]
  _BYTE v20[64]; // [esp+17Ch] [ebp-84h] BYREF
  _BYTE v21[67]; // [esp+1BCh] [ebp-44h] BYREF
  char v22; // [esp+1FFh] [ebp-1h]

  v22 = 0;
  v12 = this->m_vCameraPos.x != a2->x || this->m_vCameraPos.y != a2->y || this->m_vCameraPos.z != a2->z;
  if ( v12
    || memcmp((unsigned __int8 *)lhs, (unsigned __int8 *)&this->m_mProjection, 0x40u)
    || memcmp((unsigned __int8 *)a4, (unsigned __int8 *)&this->m_mModelview, 0x40u)
    || this->m_fNearClip != a5
    || this->m_fFarClip != a6 )
  {
    this->m_vCameraPos = *a2;
    qmemcpy(&this->m_mProjection, lhs, sizeof(this->m_mProjection));
    qmemcpy(&this->m_mModelview, a4, sizeof(this->m_mModelview));
    this->m_fNearClip = a5;
    this->m_fFarClip = a6;
    qmemcpy(&this->m_mModelviewNoTranslate, &this->m_mModelview, sizeof(this->m_mModelviewNoTranslate));
    SpeedTree::Mat4x4::Translate(&this->m_mModelviewNoTranslate, &this->m_vCameraPos);
    qmemcpy(
      &this->m_mComposite,
      SpeedTree::Mat4x4::operator*(this->m_mModelview.m_afSingle, v21, this->m_mProjection.m_afSingle),
      sizeof(this->m_mComposite));
    qmemcpy(
      &this->m_mCompositeNoTranslate,
      SpeedTree::Mat4x4::operator*(this->m_mModelviewNoTranslate.m_afSingle, v20, this->m_mProjection.m_afSingle),
      sizeof(this->m_mCompositeNoTranslate));
    v17 = -this->m_mModelview.m_afSingle[2];
    v18 = -this->m_mModelview.m_afSingle[6];
    v19 = -this->m_mModelview.m_afSingle[10];
    this->m_vCameraDir.x = v17;
    this->m_vCameraDir.y = v18;
    this->m_vCameraDir.z = v19;
    v15 = SpeedTree::CCoordSys::OutComponent(&this->m_vCameraDir.x);
    v16 = SpeedTree::CCoordSys::RightComponent(&this->m_vCameraDir.x);
    v11 = atan2(v15, v16);
    this->m_fCameraAzimuth = v11;
    v14 = SpeedTree::CCoordSys::UpComponent(&this->m_vCameraDir.x);
    v10 = asin(v14);
    this->m_fCameraPitch = v10;
    if ( (unsigned __int8)SpeedTree::CCoordSys::IsLeftHanded() )
    {
      this->m_fCameraAzimuth = -this->m_fCameraAzimuth;
      if ( (unsigned __int8)SpeedTree::CCoordSys::IsYAxisUp() )
        this->m_fCameraPitch = -this->m_fCameraPitch;
    }
    v9 = fabs(this->m_fCameraPitch);
    this->m_fHorzFadeValue = (v9 - this->m_fHorzFadeStartAngle)
                           / (this->m_fHorzFadeEndAngle - this->m_fHorzFadeStartAngle);
    if ( (float)1.0 <= (double)this->m_fHorzFadeValue )
      m_fHorzFadeValue = 1.0;
    else
      m_fHorzFadeValue = this->m_fHorzFadeValue;
    this->m_fHorzFadeValue = m_fHorzFadeValue;
    if ( (float)0.0 >= (double)this->m_fHorzFadeValue )
      v7 = 0.0;
    else
      v7 = this->m_fHorzFadeValue;
    this->m_fHorzFadeValue = v7;
    SpeedTree::CView::ComputeCameraFacingMatrix(this);
    SpeedTree::CView::ComputeFrustumValues(this);
    return 1;
  }
  return v22;
}
