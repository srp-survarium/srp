void __thiscall SpeedTree::CExtents::Scale(SpeedTree::CExtents *this, float a2)
{
  int v3[3]; // [esp+8h] [ebp-18h] BYREF
  int v4[3]; // [esp+14h] [ebp-Ch] BYREF

  SpeedTree::Vec3::operator*=(&this->m_cMin.x, v4, a2);
  SpeedTree::Vec3::operator*=(&this->m_cMax.x, v3, a2);
}
