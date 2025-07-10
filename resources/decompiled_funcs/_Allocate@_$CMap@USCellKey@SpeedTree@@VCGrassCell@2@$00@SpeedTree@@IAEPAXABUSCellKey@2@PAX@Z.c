int __thiscall SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CGrassCell,1>::Allocate(_DWORD *this, int a2, int a3)
{
  int v4; // [esp+8h] [ebp-34h]
  int v6; // [esp+2Ch] [ebp-10h]

  v6 = SpeedTree::CBlockPool<1>::GrabBlock(this + 3);
  if ( v6 )
    v4 = v6 + this[4];
  else
    v4 = 0;
  if ( v4 )
    SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CGrassCell,1>::CNode::CNode(a2, a3);
  return v6;
}
