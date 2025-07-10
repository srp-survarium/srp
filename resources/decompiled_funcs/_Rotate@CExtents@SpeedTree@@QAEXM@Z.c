void __thiscall SpeedTree::CExtents::Rotate(SpeedTree::CExtents *this, float a2)
{
  float v3; // [esp+1Ch] [ebp-A4h]
  float v4; // [esp+20h] [ebp-A0h]
  float y; // [esp+34h] [ebp-8Ch]
  float z; // [esp+38h] [ebp-88h]
  float v7[3]; // [esp+54h] [ebp-6Ch] BYREF
  float v8[3]; // [esp+60h] [ebp-60h] BYREF
  struct SpeedTree::Vec3 v9; // [esp+6Ch] [ebp-54h] BYREF
  struct SpeedTree::Vec3 v10; // [esp+78h] [ebp-48h] BYREF
  struct SpeedTree::Vec3 v11; // [esp+84h] [ebp-3Ch] BYREF
  struct SpeedTree::Mat3x3 dst; // [esp+90h] [ebp-30h] BYREF
  struct SpeedTree::Vec3 v13; // [esp+B4h] [ebp-Ch] BYREF

  memset((int)&dst, 0, sizeof(dst));
  dst.m_afSingle[8] = 1.0;
  dst.m_afSingle[4] = 1.0;
  dst.m_afSingle[0] = 1.0;
  SpeedTree::CCoordSys::RotateUpAxis(&dst, a2);
  SpeedTree::Mat3x3::operator*(&v13, this);
  SpeedTree::Mat3x3::operator*(&v9, &this->m_cMax);
  y = this->m_cMax.y;
  z = this->m_cMin.z;
  v8[0] = this->m_cMin.x;
  v8[1] = y;
  v8[2] = z;
  SpeedTree::Mat3x3::operator*(&v10, v8);
  v3 = this->m_cMin.y;
  v4 = this->m_cMin.z;
  v7[0] = this->m_cMax.x;
  v7[1] = v3;
  v7[2] = v4;
  SpeedTree::Mat3x3::operator*(&v11, v7);
  this->m_cMin.x = 3.4028235e38;
  this->m_cMin.y = 3.4028235e38;
  this->m_cMin.z = 3.4028235e38;
  this->m_cMax.x = -3.4028235e38;
  this->m_cMax.y = -3.4028235e38;
  this->m_cMax.z = -3.4028235e38;
  SpeedTree::CExtents::ExpandAround(this, &v13);
  SpeedTree::CExtents::ExpandAround(this, &v9);
  SpeedTree::CExtents::ExpandAround(this, &v10);
  SpeedTree::CExtents::ExpandAround(this, &v11);
}
