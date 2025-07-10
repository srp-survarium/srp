void __thiscall SpeedTree::Mat4x4::RotateY(SpeedTree::Mat4x4 *this, float a2)
{
  float v2; // [esp+10h] [ebp-D8h]
  float v3; // [esp+14h] [ebp-D4h]
  _BYTE v5[64]; // [esp+60h] [ebp-88h] BYREF
  unsigned __int8 dst[64]; // [esp+A0h] [ebp-48h] BYREF
  float v7; // [esp+E0h] [ebp-8h]
  float v8; // [esp+E4h] [ebp-4h]

  v3 = cos(a2);
  v7 = v3;
  v2 = sin(a2);
  v8 = v2;
  memset((int)dst, 0, sizeof(dst));
  *(float *)&dst[60] = 1.0;
  *(float *)&dst[20] = 1.0;
  *(float *)dst = v3;
  *(float *)&dst[8] = -v2;
  *(float *)&dst[32] = v2;
  *(float *)&dst[40] = v3;
  qmemcpy(this, SpeedTree::Mat4x4::operator*((float *)dst, v5, this->m_afSingle), sizeof(SpeedTree::Mat4x4));
}
