unsigned int __thiscall SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CTreeCell,1>::Allocate(
        int this,
        _DWORD *a2,
        int a3)
{
  int v3; // eax
  unsigned int v5; // [esp+8h] [ebp-70h]
  unsigned int v7; // [esp+68h] [ebp-10h]

  v7 = SpeedTree::CBlockPool<1>::GrabBlock((SpeedTree::CBlockPool<1> *)(this + 12));
  if ( v7 )
    v5 = v7 + *(_DWORD *)(this + 16);
  else
    v5 = 0;
  if ( v5 )
  {
    v3 = a2[1];
    *(_DWORD *)v5 = *a2;
    *(_DWORD *)(v5 + 4) = v3;
    SpeedTree::CTreeCell::CTreeCell((SpeedTree::CTreeCell *)(v5 + 8));
    *(_DWORD *)(v5 + 144) = 0;
    *(_DWORD *)(v5 + 148) = 0;
    *(_DWORD *)(v5 + 152) = a3;
    *(_DWORD *)(v5 + 156) = 0;
  }
  return v7;
}
