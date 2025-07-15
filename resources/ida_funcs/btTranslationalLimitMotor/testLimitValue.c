int __userpurge btTranslationalLimitMotor::testLimitValue@<eax>(
        btTranslationalLimitMotor *this@<ecx>,
        int limitIndex@<eax>,
        float test_value)
{
  float v3; // xmm1_4
  float v4; // xmm2_4

  v3 = this->m_lowerLimit.mVec128.m128_f32[limitIndex];
  v4 = this->m_upperLimit.mVec128.m128_f32[limitIndex];
  if ( v3 > v4 )
    goto LABEL_6;
  if ( v3 > test_value )
  {
    this->m_currentLimit[limitIndex] = 2;
    this->m_currentLimitError.mVec128.m128_f32[limitIndex] = test_value - v3;
    return 2;
  }
  if ( test_value <= v4 )
  {
LABEL_6:
    this->m_currentLimit[limitIndex] = 0;
    this->m_currentLimitError.mVec128.m128_i32[limitIndex] = 0;
    return 0;
  }
  else
  {
    this->m_currentLimit[limitIndex] = 1;
    this->m_currentLimitError.mVec128.m128_f32[limitIndex] = test_value - v4;
    return 1;
  }
}
