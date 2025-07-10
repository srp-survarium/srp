SpeedTree::CTreeCell *__thiscall SpeedTree::CTreeCell::`vector deleting destructor'(
        SpeedTree::CTreeCell *this,
        char a2)
{
  this->__vftable = (SpeedTree::CTreeCell_vtbl *)&SpeedTree::CTreeCell::`vftable';
  SpeedTree::CCellInstances::~CCellInstances(&this->m_cCellInstances);
  this->__vftable = (SpeedTree::CTreeCell_vtbl *)&SpeedTree::CCell::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete((void *)this);
  return this;
}
