void __thiscall SpeedTree::CExtents::ExpandAround(SpeedTree::CExtents *this, const struct SpeedTree::Vec3 *a2)
{
  float v2; // [esp+0h] [ebp-1Ch]
  float v3; // [esp+4h] [ebp-18h]
  float v4; // [esp+8h] [ebp-14h]
  float z; // [esp+Ch] [ebp-10h]
  float y; // [esp+10h] [ebp-Ch]
  float x; // [esp+14h] [ebp-8h]

  if ( this->m_cMin.x <= (double)a2->x )
    x = this->m_cMin.x;
  else
    x = a2->x;
  this->m_cMin.x = x;
  if ( this->m_cMin.y <= (double)a2->y )
    y = this->m_cMin.y;
  else
    y = a2->y;
  this->m_cMin.y = y;
  if ( this->m_cMin.z <= (double)a2->z )
    z = this->m_cMin.z;
  else
    z = a2->z;
  this->m_cMin.z = z;
  if ( this->m_cMax.x >= (double)a2->x )
    v4 = this->m_cMax.x;
  else
    v4 = a2->x;
  this->m_cMax.x = v4;
  if ( this->m_cMax.y >= (double)a2->y )
    v3 = this->m_cMax.y;
  else
    v3 = a2->y;
  this->m_cMax.y = v3;
  if ( this->m_cMax.z >= (double)a2->z )
    v2 = this->m_cMax.z;
  else
    v2 = a2->z;
  this->m_cMax.z = v2;
}
