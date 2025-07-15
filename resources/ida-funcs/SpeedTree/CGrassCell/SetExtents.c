void __thiscall SpeedTree::CGrassCell::SetExtents(SpeedTree::CGrassCell *this, const struct SpeedTree::CExtents *a2)
{
  float *v2; // eax
  float v4[3]; // [esp+20h] [ebp-18h] BYREF
  SpeedTree::Vec3 v5; // [esp+2Ch] [ebp-Ch] BYREF

  this->m_cExtents = *a2;
  v2 = SpeedTree::Vec3::operator+(&a2->m_cMin.x, v4, &a2->m_cMax.x);
  SpeedTree::Vec3::operator*(v2, &v5.x, 0.5);
  this->m_vCenter = v5;
}
