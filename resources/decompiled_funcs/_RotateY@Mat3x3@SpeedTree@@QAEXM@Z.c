void __thiscall SpeedTree::Mat3x3::RotateY(SpeedTree::Mat3x3 *this, float a2)
{
  float v2; // [esp+10h] [ebp-84h]
  float v3; // [esp+14h] [ebp-80h]
  _BYTE v5[36]; // [esp+44h] [ebp-50h] BYREF
  unsigned __int8 dst[36]; // [esp+68h] [ebp-2Ch] BYREF
  float v7; // [esp+8Ch] [ebp-8h]
  float v8; // [esp+90h] [ebp-4h]

  memset((int)dst, 0, sizeof(dst));
  *(float *)&dst[32] = 1.0;
  *(float *)&dst[16] = 1.0;
  *(float *)dst = 1.0;
  v3 = cos(a2);
  v7 = v3;
  v2 = sin(a2);
  v8 = v2;
  *(float *)dst = v7;
  *(float *)&dst[8] = -v2;
  *(float *)&dst[24] = v2;
  *(float *)&dst[32] = v7;
  qmemcpy(this, SpeedTree::Mat3x3::operator*((float *)dst, v5, this->m_afSingle), sizeof(SpeedTree::Mat3x3));
}
