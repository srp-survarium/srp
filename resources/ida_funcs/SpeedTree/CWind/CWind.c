SpeedTree::CWind *__thiscall SpeedTree::CWind::CWind(SpeedTree::CWind *this)
{
  __int16 i; // [esp+2Ch] [ebp-4h]

  SpeedTree::CWind::SParams::SParams(&this->m_sParams);
  this->m_fStrength = 0.0;
  this->m_pWindLeader = 0;
  SpeedTree::CRandom::Seed(&this->m_cDice, 0);
  this->m_fLastTime = -1.0;
  this->m_fElapsedTime = 0.0;
  this->m_fGust = 0.0;
  this->m_fGustTarget = 0.0;
  this->m_fGustRiseTarget = 0.0;
  this->m_fGustFallTarget = 0.0;
  this->m_fGustStart = 0.0;
  this->m_fGustAtStart = 1.0;
  this->m_fGustFallStart = 0.0;
  this->m_fStrengthTarget = 0.0;
  this->m_fStrengthChangeStartTime = 0.0;
  this->m_fStrengthChangeEndTime = 0.0;
  this->m_fStrengthAtStart = 0.0;
  this->m_fDirectionChangeStartTime = 0.0;
  this->m_fDirectionChangeEndTime = 0.0;
  this->m_fCombinedStrength = 0.0;
  for ( i = 0; i < 4; ++i )
  {
    this->m_afEffectiveStrengths[i] = 0.0;
    this->m_afOscillationTimes[i] = 0.0;
  }
  this->m_afDirection[0] = 1.0;
  this->m_afDirectionAtStart[0] = 1.0;
  this->m_afDirectionMidTarget[0] = 1.0;
  this->m_afDirectionTarget[0] = 1.0;
  this->m_afDirection[1] = 0.0;
  this->m_afDirectionAtStart[1] = 0.0;
  this->m_afDirectionMidTarget[1] = 0.0;
  this->m_afDirectionTarget[1] = 0.0;
  this->m_afDirection[2] = 0.0;
  this->m_afDirectionAtStart[2] = 0.0;
  this->m_afDirectionMidTarget[2] = 0.0;
  this->m_afDirectionTarget[2] = 0.0;
  return this;
}
