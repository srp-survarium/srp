void __thiscall SpeedTree::Mat4x4::RotateZ(SpeedTree::Mat4x4 *this, float a2)
{
  float v2; // [esp+10h] [ebp-D8h]
  float v3; // [esp+14h] [ebp-D4h]
  unsigned __int8 v5[128]; // [esp+60h] [ebp-88h] BYREF
  float v6; // [esp+E0h] [ebp-8h]
  float v7; // [esp+E4h] [ebp-4h]

  v3 = cos(a2);
  v6 = v3;
  v2 = sin(a2);
  v7 = v2;
  memset((int)&v5[64], 0, 0x40u);
  *(float *)&v5[124] = 1.0;
  *(float *)&v5[104] = 1.0;
  *(float *)&v5[64] = v3;
  *(float *)&v5[80] = -v2;
  *(float *)&v5[68] = v2;
  *(float *)&v5[84] = v3;
  qmemcpy(this, (const void *)SpeedTree::Mat4x4::operator*(v5, this), sizeof(SpeedTree::Mat4x4));
}
