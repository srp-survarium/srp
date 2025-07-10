_DWORD *__thiscall SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CTreeCell,1>::CNode::DeleteChildren(
        _DWORD *this,
        _DWORD *a2)
{
  _DWORD *result; // eax

  result = this;
  if ( this[36] )
  {
    SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CTreeCell,1>::CNode::DeleteChildren(a2);
    result = SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CTreeCell,1>::Deallocate(a2, this + 36);
  }
  if ( this[37] )
  {
    SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CTreeCell,1>::CNode::DeleteChildren(a2);
    return SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CTreeCell,1>::Deallocate(a2, this + 37);
  }
  return result;
}
