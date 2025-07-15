SpeedTree::CTreeCell *__thiscall SpeedTree::CTreeCell::CTreeCell(SpeedTree::CTreeCell *this)
{
  SpeedTree::CCell::CCell(&this->SpeedTree::CCell);
  this->__vftable = (SpeedTree::CTreeCell_vtbl *)&SpeedTree::CTreeCell::`vftable';
  SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::CInstance,1>,1>::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::CInstance,1>,1>(0xAu);
  this->m_cCellInstances.__vftable = (SpeedTree::CCellInstances_vtbl *)&SpeedTree::CCellInstances::`vftable';
  SpeedTree::CMap<SpeedTree::CCore const *,int,1>::CMap<SpeedTree::CCore const *,int,1>(
    &this->m_cCellInstances.m_mBillboardBlocks,
    0xAu);
  this->m_bContentsChanged = 0;
  this->m_nBillboardBlock = -1;
  return this;
}
