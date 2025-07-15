double __thiscall SpeedTree::CWind::GetGustTargetForFollowers(SpeedTree::CWind *this, float a2)
{
  if ( this->m_fGustFallStart >= (double)a2 )
    return this->m_fGustTarget;
  else
    return 0.0;
}
