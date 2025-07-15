void __thiscall SpeedTree::CWind::Scale(SpeedTree::CWind *this, float a2)
{
  int i; // [esp+4h] [ebp-4h]

  this->m_sParams.m_fWindHeight = this->m_sParams.m_fWindHeight * a2;
  this->m_sParams.m_fGustPrimaryDistance = this->m_sParams.m_fGustPrimaryDistance * a2;
  for ( i = 0; i < 4; ++i )
  {
    this->m_sParams.m_afOscillationValues[i][0] = this->m_sParams.m_afOscillationValues[i][0] * a2;
    this->m_sParams.m_afOscillationValues[i][1] = this->m_sParams.m_afOscillationValues[i][1] * a2;
  }
  this->m_sParams.m_fLeavesLightingChange = this->m_sParams.m_fLeavesLightingChange / a2;
}
