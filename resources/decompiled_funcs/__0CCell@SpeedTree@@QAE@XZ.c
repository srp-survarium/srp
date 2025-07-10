SpeedTree::CCell *__thiscall SpeedTree::CCell::CCell(SpeedTree::CCell *this)
{
  this->__vftable = (SpeedTree::CCell_vtbl *)&SpeedTree::CCell::`vftable';
  this->m_nRow = -99999;
  this->m_nCol = -99999;
  this->m_nUpdateIndex = -1;
  SpeedTree::CExtents::CExtents(&this->m_cExtents);
  this->m_vCenter.x = 0.0;
  this->m_vCenter.y = 0.0;
  this->m_vCenter.z = 0.0;
  this->m_fCullRadius = -1.0;
  return this;
}
