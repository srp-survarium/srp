_DWORD *__thiscall SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::CInstance,1>,1>::Deallocate(
        _DWORD *this,
        _DWORD *a2)
{
  _DWORD *result; // eax

  if ( *a2 )
    SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::CInstance,1>,1>::CNode::~CNode(*a2 + this[4]);
  else
    SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::CInstance,1>,1>::CNode::~CNode(0);
  *(_DWORD *)(this[5] + 4 * this[7]) = *a2;
  result = this + 3;
  ++this[7];
  *a2 = 0;
  return result;
}
