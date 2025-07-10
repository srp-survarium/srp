_DWORD *__thiscall SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CGrassCell,1>::CNode::DeleteChildren(
        _DWORD *this,
        _DWORD *a2)
{
  _DWORD *result; // eax

  result = this;
  if ( this[19] )
  {
    SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CGrassCell,1>::CNode::DeleteChildren(a2);
    result = SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CGrassCell,1>::Deallocate(a2, this + 19);
  }
  if ( this[20] )
  {
    SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CGrassCell,1>::CNode::DeleteChildren(a2);
    return SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CGrassCell,1>::Deallocate(a2, this + 20);
  }
  return result;
}
