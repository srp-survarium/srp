void __thiscall SpeedTree::CWind::Advance(SpeedTree::CWind *this, bool a2, float a3)
{
  double v3; // st7
  float Y_4; // [esp+Ch] [ebp-A8h]
  double v5; // [esp+14h] [ebp-A0h]
  float v6; // [esp+1Ch] [ebp-98h]
  float v7; // [esp+20h] [ebp-94h]
  float v8; // [esp+24h] [ebp-90h]
  float v9; // [esp+28h] [ebp-8Ch]
  float v10; // [esp+2Ch] [ebp-88h]
  float v11; // [esp+30h] [ebp-84h]
  float v12; // [esp+34h] [ebp-80h]
  float v14; // [esp+58h] [ebp-5Ch]
  float v15; // [esp+7Ch] [ebp-38h]
  float v16; // [esp+88h] [ebp-2Ch]
  float v17; // [esp+98h] [ebp-1Ch]
  __int16 i; // [esp+A0h] [ebp-14h]
  float v19[3]; // [esp+A4h] [ebp-10h] BYREF
  float v20; // [esp+B0h] [ebp-4h]

  if ( this->m_fLastTime == -1.0 )
    this->m_fElapsedTime = 0.0;
  else
    this->m_fElapsedTime = a3 - this->m_fLastTime;
  this->m_fLastTime = a3;
  if ( a2 )
  {
    SpeedTree::CWind::Gust(this, a3);
    if ( this->m_pWindLeader )
    {
      Y_4 = SpeedTree::CWind::GetStrenghTargetForFollowers((SpeedTree::CWind *)this->m_pWindLeader);
      SpeedTree::CWind::SetStrength(this, Y_4);
      SpeedTree::CWind::GetDirectionTargetForFollowers((SpeedTree::CWind *)this->m_pWindLeader, v19);
      SpeedTree::CWind::SetDirection(this, v19);
    }
    v20 = 0.0;
    if ( this->m_fDirectionChangeStartTime != this->m_fDirectionChangeEndTime )
    {
      v17 = (a3 - this->m_fDirectionChangeStartTime)
          / (this->m_fDirectionChangeEndTime - this->m_fDirectionChangeStartTime);
      if ( v17 >= (double)(float)0.0 )
        v12 = (a3 - this->m_fDirectionChangeStartTime)
            / (this->m_fDirectionChangeEndTime - this->m_fDirectionChangeStartTime);
      else
        v12 = 0.0;
      if ( v12 <= (double)(float)1.0 )
        v11 = v12;
      else
        v11 = 1.0;
      v20 = v11;
    }
    v20 = SpeedTree::CWind::LinearSigmoid(this, v20, 0.5);
    if ( v20 >= 0.5 )
    {
      v20 = v20 - 0.5 + v20 - 0.5;
      this->m_afDirection[0] = v20 * (this->m_afDirectionTarget[0] - this->m_afDirectionMidTarget[0])
                             + this->m_afDirectionMidTarget[0];
      this->m_afDirection[1] = v20 * (this->m_afDirectionTarget[1] - this->m_afDirectionMidTarget[1])
                             + this->m_afDirectionMidTarget[1];
      v3 = v20 * (this->m_afDirectionTarget[2] - this->m_afDirectionMidTarget[2]) + this->m_afDirectionMidTarget[2];
    }
    else
    {
      v20 = v20 + v20;
      this->m_afDirection[0] = v20 * (this->m_afDirectionMidTarget[0] - this->m_afDirectionAtStart[0])
                             + this->m_afDirectionAtStart[0];
      this->m_afDirection[1] = v20 * (this->m_afDirectionMidTarget[1] - this->m_afDirectionAtStart[1])
                             + this->m_afDirectionAtStart[1];
      v3 = v20 * (this->m_afDirectionMidTarget[2] - this->m_afDirectionAtStart[2]) + this->m_afDirectionAtStart[2];
    }
    this->m_afDirection[2] = v3;
    SpeedTree::CWind::Normalize(this, this->m_afDirection);
    v20 = 0.0;
    if ( this->m_fStrengthChangeStartTime != this->m_fStrengthChangeEndTime )
    {
      v16 = (a3 - this->m_fStrengthChangeStartTime)
          / (this->m_fStrengthChangeEndTime - this->m_fStrengthChangeStartTime);
      if ( v16 >= (double)(float)0.0 )
        v10 = (a3 - this->m_fStrengthChangeStartTime)
            / (this->m_fStrengthChangeEndTime - this->m_fStrengthChangeStartTime);
      else
        v10 = 0.0;
      if ( v10 <= (double)(float)1.0 )
        v9 = v10;
      else
        v9 = 1.0;
      v20 = v9;
    }
    v14 = SpeedTree::CWind::LinearSigmoid(this, v20, 0.0);
    this->m_fStrength = v14 * (this->m_fStrengthTarget - this->m_fStrengthAtStart) + this->m_fStrengthAtStart;
    v15 = this->m_fStrength + this->m_fGust;
    if ( v15 <= (double)(float)1.0 )
      v8 = this->m_fStrength + this->m_fGust;
    else
      v8 = 1.0;
    this->m_fCombinedStrength = v8;
    for ( i = 0; i < 4; ++i )
    {
      v7 = pow(this->m_fCombinedStrength, this->m_sParams.m_afExponents[i]);
      this->m_afEffectiveStrengths[i] = v7;
      v6 = this->m_afEffectiveStrengths[i]
         * (this->m_sParams.m_afOscillationValues[i][3] - this->m_sParams.m_afOscillationValues[i][2])
         + this->m_sParams.m_afOscillationValues[i][2];
      this->m_afOscillationTimes[i] = this->m_fElapsedTime * v6 + this->m_afOscillationTimes[i];
    }
    this->m_afShaderValues[0] = this->m_afDirection[0];
    this->m_afShaderValues[1] = this->m_afDirection[1];
    this->m_afShaderValues[2] = this->m_afDirection[2];
    this->m_afShaderValues[3] = this->m_afOscillationTimes[0];
    this->m_afShaderValues[4] = this->m_afOscillationTimes[1];
    this->m_afShaderValues[5] = this->m_afOscillationTimes[2];
    this->m_afShaderValues[6] = this->m_afOscillationTimes[3];
    this->m_afShaderValues[7] = this->m_afEffectiveStrengths[0]
                              * (this->m_sParams.m_afOscillationValues[0][1]
                               - this->m_sParams.m_afOscillationValues[0][0])
                              + this->m_sParams.m_afOscillationValues[0][0];
    this->m_afShaderValues[8] = this->m_afEffectiveStrengths[1]
                              * (this->m_sParams.m_afOscillationValues[1][1]
                               - this->m_sParams.m_afOscillationValues[1][0])
                              + this->m_sParams.m_afOscillationValues[1][0];
    if ( this->m_sParams.m_fWindHeight == 0.0 )
      v5 = 0.0;
    else
      v5 = 1.0 / this->m_sParams.m_fWindHeight;
    this->m_afShaderValues[9] = v5;
    this->m_afShaderValues[10] = this->m_sParams.m_fWindHeightExponent;
    this->m_afShaderValues[11] = this->m_afEffectiveStrengths[3]
                               * (this->m_sParams.m_afOscillationValues[3][1]
                                - this->m_sParams.m_afOscillationValues[3][0])
                               + this->m_sParams.m_afOscillationValues[3][0];
    this->m_afShaderValues[12] = this->m_sParams.m_fLeavesLightingChange;
    this->m_afShaderValues[13] = this->m_sParams.m_fLeavesWindwardScalar;
    this->m_afShaderValues[14] = this->m_afEffectiveStrengths[2]
                               * (this->m_sParams.m_afOscillationValues[2][1]
                                - this->m_sParams.m_afOscillationValues[2][0])
                               + this->m_sParams.m_afOscillationValues[2][0];
    this->m_afShaderValues[15] = this->m_sParams.m_fFrondUTile;
    this->m_afShaderValues[16] = this->m_sParams.m_fFrondVTile;
    this->m_afShaderValues[17] = this->m_fCombinedStrength;
    this->m_afShaderValues[18] = this->m_afEffectiveStrengths[0] * this->m_sParams.m_fGustPrimaryDistance;
    this->m_afShaderValues[19] = this->m_sParams.m_fGustScale;
    this->m_afShaderValues[20] = this->m_sParams.m_fWindHeightOffset;
    this->m_afShaderValues[21] = this->m_sParams.m_fGustDirectionAdjustment * this->m_fCombinedStrength;
    this->m_afShaderValues[22] = this->m_sParams.m_fGustUnison * this->m_fCombinedStrength;
    this->m_afShaderValues[23] = this->m_sParams.m_fRollingBranchesMaxScale;
    this->m_afShaderValues[24] = this->m_sParams.m_fRollingBranchesMinScale;
    this->m_afShaderValues[25] = this->m_sParams.m_fRollingBranchesSpeed;
    this->m_afShaderValues[26] = this->m_sParams.m_fRollingBranchesWavelength;
    this->m_afShaderValues[27] = this->m_sParams.m_fRollingLeavesMaxScale;
    this->m_afShaderValues[28] = this->m_sParams.m_fRollingLeavesMinScale;
    this->m_afShaderValues[29] = this->m_sParams.m_fRollingLeavesSpeed;
    this->m_afShaderValues[30] = this->m_sParams.m_fRollingLeavesWavelength;
    this->m_afShaderValues[31] = this->m_sParams.m_fLeavesTwitchAmount;
    this->m_afShaderValues[32] = this->m_sParams.m_fLeavesTwitchSharpness;
    this->m_afShaderValues[33] = this->m_sParams.m_fLeavesTwitchFreq1;
    this->m_afShaderValues[34] = this->m_sParams.m_fLeavesTwitchFreq2;
    this->m_afShaderValues[35] = this->m_sParams.m_fLeavesTumbleX * this->m_afShaderValues[11];
    this->m_afShaderValues[36] = this->m_sParams.m_fLeavesTumbleY * this->m_afShaderValues[11];
    this->m_afShaderValues[37] = this->m_sParams.m_fLeavesTumbleZ * this->m_afShaderValues[11];
    this->m_afShaderValues[38] = this->m_sParams.m_fLeavesTumbleSeparation;
  }
  else
  {
    this->m_afShaderValues[0] = 1.0;
    this->m_afShaderValues[1] = 0.0;
    this->m_afShaderValues[2] = 0.0;
    this->m_afShaderValues[3] = 0.0;
    this->m_afShaderValues[4] = 0.0;
    this->m_afShaderValues[5] = 0.0;
    this->m_afShaderValues[6] = 0.0;
    this->m_afShaderValues[7] = 0.0;
    this->m_afShaderValues[8] = 0.0;
    this->m_afShaderValues[9] = 1.0;
    this->m_afShaderValues[10] = 1.0;
    this->m_afShaderValues[11] = 0.0;
    this->m_afShaderValues[12] = 0.0;
    this->m_afShaderValues[13] = 1.0;
    this->m_afShaderValues[14] = 0.0;
    this->m_afShaderValues[15] = 0.0;
    this->m_afShaderValues[16] = 0.0;
    this->m_afShaderValues[17] = 0.0;
    this->m_afShaderValues[18] = 0.0;
    this->m_afShaderValues[19] = 1.0;
    this->m_afShaderValues[20] = 0.0;
    this->m_afShaderValues[21] = 0.0;
    this->m_afShaderValues[22] = 0.0;
    this->m_afShaderValues[23] = 1.0;
    this->m_afShaderValues[24] = 1.0;
    this->m_afShaderValues[25] = 1.0;
    this->m_afShaderValues[26] = 1.0;
    this->m_afShaderValues[27] = 1.0;
    this->m_afShaderValues[28] = 1.0;
    this->m_afShaderValues[29] = 1.0;
    this->m_afShaderValues[30] = 1.0;
    this->m_afShaderValues[31] = 0.0;
    this->m_afShaderValues[32] = 0.0;
    this->m_afShaderValues[33] = 0.0;
    this->m_afShaderValues[34] = 0.0;
    this->m_afShaderValues[35] = 0.0;
    this->m_afShaderValues[36] = 0.0;
    this->m_afShaderValues[37] = 0.0;
    this->m_afShaderValues[38] = 1.0;
  }
}
