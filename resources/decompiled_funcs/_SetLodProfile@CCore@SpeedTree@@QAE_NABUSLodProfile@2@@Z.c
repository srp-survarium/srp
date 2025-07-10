char __thiscall SpeedTree::CCore::SetLodProfile(SpeedTree::CCore *this, const SpeedTree::SLodProfile *sLodProfile)
{
  float m_fLowDetail3dDistance; // xmm1_4
  float m_fBillboardStartDistance; // xmm0_4
  float v4; // xmm1_4
  float v5; // xmm0_4

  m_fLowDetail3dDistance = sLodProfile->m_fLowDetail3dDistance;
  if ( m_fLowDetail3dDistance <= sLodProfile->m_fHighDetail3dDistance
    || (m_fBillboardStartDistance = sLodProfile->m_fBillboardStartDistance,
        sLodProfile->m_fBillboardFinalDistance <= m_fBillboardStartDistance)
    || m_fBillboardStartDistance <= m_fLowDetail3dDistance
    || sLodProfile->m_f3dRange < 0.0
    || sLodProfile->m_fBillboardRange < 0.0 )
  {
    SpeedTree::CCore::SetError("CCore::SetLodRange, one of the near/start values exceeds its corresponding far/end value");
    return 0;
  }
  else
  {
    this->m_sLodProfile = *sLodProfile;
    this->m_sLodProfile.m_f3dRange = this->m_sLodProfile.m_fLowDetail3dDistance
                                   - this->m_sLodProfile.m_fHighDetail3dDistance;
    this->m_sLodProfile.m_fBillboardRange = this->m_sLodProfile.m_fBillboardFinalDistance
                                          - this->m_sLodProfile.m_fBillboardStartDistance;
    this->m_sLodProfileSquared.m_fHighDetail3dDistance = sLodProfile->m_fHighDetail3dDistance
                                                       * sLodProfile->m_fHighDetail3dDistance;
    this->m_sLodProfileSquared.m_fLowDetail3dDistance = sLodProfile->m_fLowDetail3dDistance
                                                      * sLodProfile->m_fLowDetail3dDistance;
    this->m_sLodProfileSquared.m_fBillboardStartDistance = sLodProfile->m_fBillboardStartDistance
                                                         * sLodProfile->m_fBillboardStartDistance;
    v4 = sLodProfile->m_fBillboardFinalDistance * sLodProfile->m_fBillboardFinalDistance;
    this->m_sLodProfileSquared.m_f3dRange = this->m_sLodProfileSquared.m_fLowDetail3dDistance
                                          - this->m_sLodProfileSquared.m_fHighDetail3dDistance;
    v5 = v4 - this->m_sLodProfileSquared.m_fBillboardStartDistance;
    this->m_sLodProfileSquared.m_fBillboardFinalDistance = v4;
    this->m_sLodProfileSquared.m_fBillboardRange = v5;
    return 1;
  }
}
