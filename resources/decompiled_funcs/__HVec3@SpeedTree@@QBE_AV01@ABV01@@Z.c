float *__thiscall SpeedTree::Vec3::operator+(float *this, float *a2, float *a3)
{
  float v4; // [esp+4h] [ebp-Ch]
  float v5; // [esp+8h] [ebp-8h]
  float v6; // [esp+Ch] [ebp-4h]

  v4 = *a3 + *this;
  v5 = a3[1] + this[1];
  v6 = a3[2] + this[2];
  *a2 = v4;
  a2[1] = v5;
  a2[2] = v6;
  return a2;
}
