unsigned int __thiscall SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::CInstance,1>,1>::Allocate(
        int this,
        _DWORD *a2,
        int a3)
{
  unsigned int v4; // [esp+4h] [ebp-1Ch]
  unsigned int v6; // [esp+1Ch] [ebp-4h]

  v6 = SpeedTree::CBlockPool<1>::GrabBlock((SpeedTree::CBlockPool<1> *)(this + 12));
  if ( v6 )
    v4 = v6 + *(_DWORD *)(this + 16);
  else
    v4 = 0;
  if ( v4 )
  {
    *(_DWORD *)v4 = *a2;
    *(_DWORD *)(v4 + 4) = &SpeedTree::CArray<SpeedTree::CInstance,1>::`vftable';
    *(_DWORD *)(v4 + 8) = 0;
    *(_DWORD *)(v4 + 12) = 0;
    *(_DWORD *)(v4 + 16) = 0;
    *(_BYTE *)(v4 + 20) = 0;
    *(_DWORD *)(v4 + 24) = 0;
    *(_DWORD *)(v4 + 28) = 0;
    *(_DWORD *)(v4 + 32) = a3;
    *(_DWORD *)(v4 + 36) = 0;
  }
  return v6;
}
