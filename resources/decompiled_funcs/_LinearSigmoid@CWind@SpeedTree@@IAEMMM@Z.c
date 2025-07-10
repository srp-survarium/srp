double __thiscall SpeedTree::CWind::LinearSigmoid(SpeedTree::CWind *this, float a2, float a3)
{
  float v5; // [esp+Ch] [ebp-18h]
  float v6; // [esp+14h] [ebp-10h]
  float v7; // [esp+20h] [ebp-4h]

  v6 = ((float)6.0 - (float)-6.0) * a2 + (float)-6.0;
  v5 = exp(-v6);
  v7 = 1.0 / (v5 + 1.0);
  return (float)(a3 * (a2 - v7) + v7);
}
