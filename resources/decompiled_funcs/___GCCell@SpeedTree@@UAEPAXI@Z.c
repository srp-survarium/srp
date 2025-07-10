SpeedTree::CCell *__thiscall SpeedTree::CCell::`scalar deleting destructor'(SpeedTree::CCell *this, char a2)
{
  this->__vftable = (SpeedTree::CCell_vtbl *)&SpeedTree::CCell::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
