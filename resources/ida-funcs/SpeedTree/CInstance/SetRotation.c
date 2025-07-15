void __thiscall SpeedTree::CInstance::SetRotation(SpeedTree::CInstance *this, float fRadians)
{
  long double v3; // [esp+8h] [ebp-8h]
  long double v4; // [esp+8h] [ebp-8h]
  float fRadiansa; // [esp+18h] [ebp+8h]

  fRadiansa = fmodf(fRadians, 6.2831855) + 6.2831855;
  this->m_nRotation = (int)(float)((float)(fRadiansa * 0.15915494) * 255.0);
  __libm_sse2_sin(v3);
  this->m_anRotationVector[0] = (int)(float)(fRadiansa * 127.0);
  __libm_sse2_cos(v4);
  this->m_anRotationVector[1] = (int)(float)(fRadiansa * 127.0);
}
