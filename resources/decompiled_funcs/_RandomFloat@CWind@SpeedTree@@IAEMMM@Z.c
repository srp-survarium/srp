double __thiscall SpeedTree::CWind::RandomFloat(SpeedTree::CWind *this, float a2, float a3)
{
  float v5; // [esp+3Ch] [ebp-4h]

  v5 = ((double)SpeedTree::CRandom::GetRawInteger(&this->m_cDice) + 0.5) * 2.328306436538696e-10 * (1.0 - 0.0) + 0.0;
  return (float)(v5 * (a3 - a2) + a2);
}
