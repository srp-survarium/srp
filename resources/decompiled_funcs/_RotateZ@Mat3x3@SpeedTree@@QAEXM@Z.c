void __thiscall SpeedTree::Mat3x3::RotateZ(SpeedTree::Mat3x3 *this, float a2)
{
  float v2; // [esp+10h] [ebp-84h]
  float v3; // [esp+14h] [ebp-80h]
  unsigned __int8 v5[72]; // [esp+44h] [ebp-50h] BYREF
  float v6; // [esp+8Ch] [ebp-8h]
  float v7; // [esp+90h] [ebp-4h]

  memset((int)&v5[36], 0, 0x24u);
  *(float *)&v5[68] = 1.0;
  *(float *)&v5[52] = 1.0;
  *(float *)&v5[36] = 1.0;
  v3 = cos(a2);
  v6 = v3;
  v2 = sin(a2);
  v7 = v2;
  *(float *)&v5[36] = v6;
  *(float *)&v5[48] = -v2;
  *(float *)&v5[40] = v2;
  *(float *)&v5[52] = v6;
  qmemcpy(this, (const void *)SpeedTree::Mat3x3::operator*(v5, this), sizeof(SpeedTree::Mat3x3));
}
