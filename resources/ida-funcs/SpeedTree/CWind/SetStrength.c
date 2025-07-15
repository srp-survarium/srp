void __thiscall SpeedTree::CWind::SetStrength(SpeedTree::CWind *this, float a2)
{
  float v2; // [esp+8h] [ebp-30h]
  float v3; // [esp+Ch] [ebp-2Ch]
  float v4; // [esp+10h] [ebp-28h]
  float v6; // [esp+1Ch] [ebp-1Ch]
  float v7; // [esp+30h] [ebp-8h]
  float v8; // [esp+34h] [ebp-4h]

  if ( (float)1.0 <= (double)a2 )
    v4 = 1.0;
  else
    v4 = a2;
  if ( (float)0.0 >= (double)v4 )
    v3 = 0.0;
  else
    v3 = v4;
  if ( this->m_fStrength != v3 )
  {
    this->m_fStrengthChangeStartTime = this->m_fLastTime;
    v7 = this->m_sParams.m_fStrengthResponse * 0.5;
    v6 = v3 - this->m_fStrength;
    v2 = fabs(v6);
    v8 = v2 * (this->m_sParams.m_fStrengthResponse - v7) + v7;
    this->m_fStrengthChangeEndTime = this->m_fStrengthChangeStartTime + v8;
    this->m_fStrengthAtStart = this->m_fStrength;
    this->m_fStrengthTarget = v3;
  }
}
