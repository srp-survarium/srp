SpeedTree::CGrassCell *__thiscall SpeedTree::CGrassCell::`scalar deleting destructor'(
        SpeedTree::CGrassCell *this,
        char a2)
{
  this->__vftable = (SpeedTree::CGrassCell_vtbl *)&SpeedTree::CGrassCell::`vftable';
  this->__vftable = (SpeedTree::CGrassCell_vtbl *)&SpeedTree::CCell::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
