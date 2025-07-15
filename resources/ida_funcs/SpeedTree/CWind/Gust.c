void __thiscall SpeedTree::CWind::Gust(SpeedTree::CWind *this, float a2)
{
  float v2; // [esp+8h] [ebp-6Ch]
  float m_fGust; // [esp+Ch] [ebp-68h]
  float v4; // [esp+10h] [ebp-64h]
  float v5; // [esp+14h] [ebp-60h]
  float v6; // [esp+18h] [ebp-5Ch]
  float v7; // [esp+1Ch] [ebp-58h]
  float v8; // [esp+20h] [ebp-54h]
  float v9; // [esp+24h] [ebp-50h]
  float v10; // [esp+28h] [ebp-4Ch]
  float v11; // [esp+2Ch] [ebp-48h]
  float v13; // [esp+38h] [ebp-3Ch]
  float v14; // [esp+40h] [ebp-34h]
  float v15; // [esp+4Ch] [ebp-28h]
  float v16; // [esp+60h] [ebp-14h]
  float v17; // [esp+64h] [ebp-10h]
  float GustTargetForFollowers; // [esp+68h] [ebp-Ch]
  float v19; // [esp+6Ch] [ebp-8h]
  char v20; // [esp+73h] [ebp-1h]

  v20 = 0;
  if ( this->m_pWindLeader )
  {
    if ( this->m_fGustFallTarget < (double)a2
      || this->m_fGustFallStart > (double)a2 && this->m_fGustRiseTarget < (double)a2 )
    {
      GustTargetForFollowers = SpeedTree::CWind::GetGustTargetForFollowers((SpeedTree::CWind *)this->m_pWindLeader, a2);
      if ( GustTargetForFollowers > 0.0 )
      {
        this->m_fGustTarget = GustTargetForFollowers;
        v20 = 1;
      }
    }
  }
  else if ( this->m_fGustFallTarget < (double)a2
         || this->m_fGustFallStart > (double)a2 && this->m_fGustRiseTarget < (double)a2 )
  {
    v19 = this->m_sParams.m_fGustFrequency * 0.009999999776482582;
    if ( this->m_fElapsedTime * v19 > SpeedTree::CWind::RandomFloat(this, 0.0, this->m_fElapsedTime) )
    {
      this->m_fGustTarget = SpeedTree::CWind::RandomFloat(
                              this,
                              this->m_sParams.m_fGustStrengthMin,
                              this->m_sParams.m_fGustStrengthMax);
      v20 = 1;
    }
  }
  if ( v20 )
  {
    this->m_fGustStart = a2;
    this->m_fGustAtStart = this->m_fGust;
    if ( this->m_fGustTarget > 1.0 - this->m_fStrength )
      this->m_fGustTarget = 1.0 - this->m_fStrength;
    v16 = this->m_sParams.m_fStrengthResponse * 0.5;
    v15 = this->m_fGustTarget - this->m_fStrength;
    v11 = fabs(v15);
    v17 = v11 * (this->m_sParams.m_fStrengthResponse - v16) + v16;
    if ( this->m_fGust >= (double)this->m_fGustTarget )
    {
      v8 = v17 + v17;
      this->m_fGustRiseTarget = SpeedTree::CWind::RandomFloat(this, v17, v8) + a2;
    }
    else
    {
      v10 = v17 + v17;
      v9 = v17 * 0.5;
      this->m_fGustRiseTarget = SpeedTree::CWind::RandomFloat(this, v9, v10) + a2;
    }
    this->m_fGustFallStart = SpeedTree::CWind::RandomFloat(
                               this,
                               this->m_sParams.m_fGustDurationMin,
                               this->m_sParams.m_fGustDurationMax)
                           + this->m_fGustRiseTarget;
    v7 = v17 * 3.0;
    v6 = v17 + v17;
    this->m_fGustFallTarget = SpeedTree::CWind::RandomFloat(this, v6, v7) + this->m_fGustFallStart;
  }
  if ( this->m_fGustRiseTarget <= (double)a2 )
  {
    if ( this->m_fGustFallStart < (double)a2
      && this->m_fGustFallTarget > 0.0
      && this->m_fGustFallStart < (double)this->m_fGustFallTarget )
    {
      v4 = (a2 - this->m_fGustFallStart) / (this->m_fGustFallTarget - this->m_fGustFallStart);
      v13 = SpeedTree::CWind::LinearSigmoid(this, v4, 0.5);
      this->m_fGust = v13 * ((float)0.0 - this->m_fGustTarget) + this->m_fGustTarget;
    }
  }
  else
  {
    v5 = (a2 - this->m_fGustStart) / (this->m_fGustRiseTarget - this->m_fGustStart);
    v14 = SpeedTree::CWind::LinearSigmoid(this, v5, 0.0);
    this->m_fGust = v14 * (this->m_fGustTarget - this->m_fGustAtStart) + this->m_fGustAtStart;
  }
  if ( this->m_fGust <= (double)(float)1.0 )
    m_fGust = this->m_fGust;
  else
    m_fGust = 1.0;
  if ( m_fGust >= (double)(float)0.0 )
    v2 = m_fGust;
  else
    v2 = 0.0;
  this->m_fGust = v2;
}
