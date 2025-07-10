_DWORD *__thiscall SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CGrassCell,1>::clear(_DWORD *this)
{
  _DWORD *result; // eax

  result = this;
  if ( this[1] )
  {
    SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CGrassCell,1>::CNode::DeleteChildren(this);
    result = (_DWORD *)SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CGrassCell,1>::Deallocate(this + 1);
    this[1] = 0;
  }
  this[2] = 0;
  return result;
}
