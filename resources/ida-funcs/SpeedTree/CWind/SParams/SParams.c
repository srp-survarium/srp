SpeedTree::CWind::SParams *__thiscall SpeedTree::CWind::SParams::SParams(SpeedTree::CWind::SParams *this)
{
  __int16 j; // [esp+4h] [ebp-8h]
  __int16 i; // [esp+8h] [ebp-4h]

  this->m_fStrengthResponse = 5.0;
  this->m_fDirectionResponse = 2.5;
  this->m_fWindHeight = 50.0;
  this->m_fWindHeightExponent = 2.0;
  this->m_fWindHeightOffset = 0.1;
  this->m_fGustFrequency = 0.0;
  this->m_fGustPrimaryDistance = 0.0;
  this->m_fGustScale = 1.0;
  this->m_fGustStrengthMin = 0.5;
  this->m_fGustStrengthMax = 1.0;
  this->m_fGustDurationMin = 1.0;
  this->m_fGustDurationMax = 4.0;
  this->m_fGustDirectionAdjustment = 0.0;
  this->m_fGustUnison = 0.85000002;
  this->m_fFrondUTile = 0.5;
  this->m_fFrondVTile = 10.0;
  this->m_fLeavesLightingChange = 0.0;
  this->m_fLeavesWindwardScalar = 1.0;
  this->m_fRollingBranchesMaxScale = 1.0;
  this->m_fRollingBranchesMinScale = 1.0;
  this->m_fRollingBranchesSpeed = 0.30000001;
  this->m_fRollingBranchesWavelength = 5.0;
  this->m_fRollingLeavesMaxScale = 1.0;
  this->m_fRollingLeavesMinScale = 1.0;
  this->m_fRollingLeavesSpeed = 0.30000001;
  this->m_fRollingLeavesWavelength = 5.0;
  this->m_fLeavesTwitchAmount = 0.0;
  this->m_fLeavesTwitchSharpness = 20.0;
  this->m_fLeavesTwitchFreq1 = 0.15000001;
  this->m_fLeavesTwitchFreq2 = 0.13;
  this->m_fLeavesTumbleX = 1.0;
  this->m_fLeavesTumbleY = 1.0;
  this->m_fLeavesTumbleZ = 1.0;
  this->m_fLeavesTumbleSeparation = 1.0;
  for ( i = 0; i < 4; ++i )
  {
    this->m_afExponents[i] = 1.0;
    for ( j = 0; j < 4; ++j )
      this->m_afOscillationValues[i][j] = 0.0;
  }
  return this;
}
