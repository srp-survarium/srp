bool __thiscall SpeedTree::CExtents::Valid(SpeedTree::CExtents *this)
{
  return this->m_cMin.x != 3.402823466385289e38
      || this->m_cMin.y != 3.402823466385289e38
      || this->m_cMin.z != 3.402823466385289e38
      || this->m_cMax.x != -3.402823466385289e38
      || this->m_cMax.y != -3.402823466385289e38
      || this->m_cMax.z != -3.402823466385289e38;
}
