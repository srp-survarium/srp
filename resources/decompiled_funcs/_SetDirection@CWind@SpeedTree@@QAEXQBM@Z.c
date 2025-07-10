void __thiscall SpeedTree::CWind::SetDirection(SpeedTree::CWind *this, const float *a2)
{
  float v2; // [esp+4h] [ebp-10h]
  float v3; // [esp+8h] [ebp-Ch]
  float v4; // [esp+Ch] [ebp-8h]
  float v5; // [esp+10h] [ebp-4h]

  if ( this->m_afDirection[0] != *a2 || this->m_afDirection[1] != a2[1] || this->m_afDirection[2] != a2[2] )
  {
    this->m_afDirectionTarget[0] = *a2;
    this->m_afDirectionTarget[1] = a2[1];
    this->m_afDirectionTarget[2] = a2[2];
    v5 = this->m_afDirection[0] * *a2 + this->m_afDirection[1] * a2[1] + this->m_afDirection[2] * a2[2];
    v4 = 1.0 - (v5 + 1.0) * 0.5;
    this->m_fDirectionChangeStartTime = this->m_fLastTime;
    v2 = this->m_sParams.m_fDirectionResponse * 0.5;
    v3 = v4 * (this->m_sParams.m_fDirectionResponse - v2) + v2;
    this->m_fDirectionChangeEndTime = this->m_fDirectionChangeStartTime + v3;
    this->m_afDirectionAtStart[0] = this->m_afDirection[0];
    this->m_afDirectionAtStart[1] = this->m_afDirection[1];
    this->m_afDirectionAtStart[2] = this->m_afDirection[2];
    this->m_afDirectionMidTarget[0] = (this->m_afDirectionAtStart[0] + this->m_afDirectionTarget[0]) * 0.5;
    this->m_afDirectionMidTarget[1] = (this->m_afDirectionAtStart[1] + this->m_afDirectionTarget[1]) * 0.5;
    this->m_afDirectionMidTarget[2] = (this->m_afDirectionAtStart[2] + this->m_afDirectionTarget[2]) * 0.5;
    SpeedTree::CWind::Normalize(this, this->m_afDirectionMidTarget);
  }
}
