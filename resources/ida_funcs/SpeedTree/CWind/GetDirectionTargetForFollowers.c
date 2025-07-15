void __thiscall SpeedTree::CWind::GetDirectionTargetForFollowers(SpeedTree::CWind *this, float *const a2)
{
  *a2 = this->m_afDirectionTarget[0];
  a2[1] = this->m_afDirectionTarget[1];
  a2[2] = this->m_afDirectionTarget[2];
}
