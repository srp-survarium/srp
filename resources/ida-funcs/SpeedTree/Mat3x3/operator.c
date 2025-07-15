void *__thiscall SpeedTree::Mat3x3::operator*(float *this, void *a2, float *a3)
{
  float v4; // [esp+8h] [ebp-38h]
  float v5; // [esp+Ch] [ebp-34h]
  float v6; // [esp+10h] [ebp-30h]
  int i; // [esp+18h] [ebp-28h]
  _DWORD dst[9]; // [esp+1Ch] [ebp-24h] BYREF

  memset((int)dst, 0, sizeof(dst));
  *(float *)&dst[8] = 1.0;
  *(float *)&dst[4] = 1.0;
  *(float *)dst = 1.0;
  for ( i = 0; i < 3; ++i )
  {
    v6 = this[3 * i] * *a3 + this[3 * i + 1] * a3[3] + this[3 * i + 2] * a3[6];
    *(float *)&dst[3 * i] = v6;
    v5 = this[3 * i] * a3[1] + this[3 * i + 1] * a3[4] + this[3 * i + 2] * a3[7];
    *(float *)&dst[3 * i + 1] = v5;
    v4 = this[3 * i] * a3[2] + this[3 * i + 1] * a3[5] + this[3 * i + 2] * a3[8];
    *(float *)&dst[3 * i + 2] = v4;
  }
  qmemcpy(a2, dst, 0x24u);
  return a2;
}


float *__thiscall SpeedTree::Mat3x3::operator*(float *this, float *a2, float *a3)
{
  float v4; // [esp+4h] [ebp-Ch]
  float v5; // [esp+8h] [ebp-8h]
  float v6; // [esp+Ch] [ebp-4h]

  v4 = a3[2] * this[2] + a3[1] * this[1] + *a3 * *this;
  v5 = a3[2] * this[5] + a3[1] * this[4] + *a3 * this[3];
  v6 = a3[2] * this[8] + a3[1] * this[7] + *a3 * this[6];
  *a2 = v4;
  a2[1] = v5;
  a2[2] = v6;
  return a2;
}
