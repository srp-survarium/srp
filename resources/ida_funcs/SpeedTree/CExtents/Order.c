void __thiscall SpeedTree::CExtents::Order(SpeedTree::CExtents *this)
{
  float x; // [esp+4h] [ebp-4h]
  float y; // [esp+4h] [ebp-4h]
  float z; // [esp+4h] [ebp-4h]

  if ( this->m_cMax.x < (double)this->m_cMin.x )
  {
    x = this->m_cMin.x;
    this->m_cMin.x = this->m_cMax.x;
    this->m_cMax.x = x;
  }
  if ( this->m_cMax.y < (double)this->m_cMin.y )
  {
    y = this->m_cMin.y;
    this->m_cMin.y = this->m_cMax.y;
    this->m_cMax.y = y;
  }
  if ( this->m_cMax.z < (double)this->m_cMin.z )
  {
    z = this->m_cMin.z;
    this->m_cMin.z = this->m_cMax.z;
    this->m_cMax.z = z;
  }
}
