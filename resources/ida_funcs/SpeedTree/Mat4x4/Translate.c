void __thiscall SpeedTree::Mat4x4::Translate(SpeedTree::Mat4x4 *this, const struct SpeedTree::Vec3 *a2)
{
  SpeedTree::Mat4x4::Translate(this, a2->x, a2->y, a2->z);
}


void __thiscall SpeedTree::Mat4x4::Translate(SpeedTree::Mat4x4 *this, float a2, float a3, float a4)
{
  _BYTE v5[64]; // [esp+50h] [ebp-80h] BYREF
  unsigned __int8 dst[64]; // [esp+90h] [ebp-40h] BYREF

  memset((int)dst, 0, sizeof(dst));
  *(float *)&dst[60] = 1.0;
  *(float *)&dst[40] = 1.0;
  *(float *)&dst[20] = 1.0;
  *(float *)dst = 1.0;
  *(float *)&dst[48] = a2;
  *(float *)&dst[52] = a3;
  *(float *)&dst[56] = a4;
  qmemcpy(this, SpeedTree::Mat4x4::operator*((float *)dst, v5, this->m_afSingle), sizeof(SpeedTree::Mat4x4));
}
