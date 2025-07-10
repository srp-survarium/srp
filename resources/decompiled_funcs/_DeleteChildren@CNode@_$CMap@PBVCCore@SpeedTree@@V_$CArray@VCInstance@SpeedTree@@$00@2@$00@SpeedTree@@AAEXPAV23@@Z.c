_DWORD *__thiscall SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::CInstance,1>,1>::CNode::DeleteChildren(
        _DWORD *this,
        _DWORD *a2)
{
  _DWORD *result; // eax

  result = this;
  if ( this[6] )
  {
    SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::CInstance,1>,1>::CNode::DeleteChildren(a2);
    result = SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::CInstance,1>,1>::Deallocate(
               a2,
               this + 6);
  }
  if ( this[7] )
  {
    SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::CInstance,1>,1>::CNode::DeleteChildren(a2);
    return SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::CInstance,1>,1>::Deallocate(
             a2,
             this + 7);
  }
  return result;
}
