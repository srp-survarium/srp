void __thiscall SpeedTree::CWind::Normalize(SpeedTree::CWind *this, float *a2)
{
  float v2; // [esp+8h] [ebp-10h]
  float v3; // [esp+10h] [ebp-8h]

  v3 = a2[2] * a2[2] + a2[1] * a2[1] + *a2 * *a2;
  v2 = sqrt(v3);
  if ( v2 == 0.0 )
  {
    *a2 = 0.0;
    a2[1] = 0.0;
    a2[2] = 0.0;
  }
  else
  {
    *a2 = *a2 / v2;
    a2[1] = a2[1] / v2;
    a2[2] = a2[2] / v2;
  }
}
