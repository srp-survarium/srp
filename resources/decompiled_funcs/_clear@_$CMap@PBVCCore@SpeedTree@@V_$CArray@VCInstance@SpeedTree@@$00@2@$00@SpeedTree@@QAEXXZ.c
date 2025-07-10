_DWORD *__thiscall SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::CInstance,1>,1>::clear(
        _DWORD *this)
{
  _DWORD *result; // eax

  result = this;
  if ( this[1] )
  {
    SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::CInstance,1>,1>::CNode::DeleteChildren(this);
    result = (_DWORD *)SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::CInstance,1>,1>::Deallocate(this + 1);
    this[1] = 0;
  }
  this[2] = 0;
  return result;
}
