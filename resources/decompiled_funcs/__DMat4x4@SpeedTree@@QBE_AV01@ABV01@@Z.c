void *__thiscall SpeedTree::Mat4x4::operator*(float *this, void *a2, float *a3)
{
  float v4; // [esp+8h] [ebp-58h]
  float v5; // [esp+Ch] [ebp-54h]
  float v6; // [esp+10h] [ebp-50h]
  float v7; // [esp+14h] [ebp-4Ch]
  int i; // [esp+1Ch] [ebp-44h]
  _DWORD dst[16]; // [esp+20h] [ebp-40h] BYREF

  memset((int)dst, 0, sizeof(dst));
  *(float *)&dst[15] = 1.0;
  *(float *)&dst[10] = 1.0;
  *(float *)&dst[5] = 1.0;
  *(float *)dst = 1.0;
  for ( i = 0; i < 4; ++i )
  {
    v7 = this[4 * i] * *a3 + this[4 * i + 1] * a3[4] + this[4 * i + 2] * a3[8] + this[4 * i + 3] * a3[12];
    *(float *)&dst[4 * i] = v7;
    v6 = this[4 * i] * a3[1] + this[4 * i + 1] * a3[5] + this[4 * i + 2] * a3[9] + this[4 * i + 3] * a3[13];
    *(float *)&dst[4 * i + 1] = v6;
    v5 = this[4 * i] * a3[2] + this[4 * i + 1] * a3[6] + this[4 * i + 2] * a3[10] + this[4 * i + 3] * a3[14];
    *(float *)&dst[4 * i + 2] = v5;
    v4 = this[4 * i] * a3[3] + this[4 * i + 1] * a3[7] + this[4 * i + 2] * a3[11] + this[4 * i + 3] * a3[15];
    *(float *)&dst[4 * i + 3] = v4;
  }
  qmemcpy(a2, dst, 0x40u);
  return a2;
}
