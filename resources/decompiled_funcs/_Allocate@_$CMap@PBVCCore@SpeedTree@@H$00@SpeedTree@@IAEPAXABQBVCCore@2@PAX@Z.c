unsigned int __thiscall SpeedTree::CMap<SpeedTree::CCore const *,int,1>::Allocate(int this, _DWORD *a2, int a3)
{
  _DWORD *v4; // [esp+4h] [ebp-18h]
  unsigned int v6; // [esp+18h] [ebp-4h]

  v6 = SpeedTree::CBlockPool<1>::GrabBlock((SpeedTree::CBlockPool<1> *)(this + 12));
  if ( v6 )
    v4 = (_DWORD *)(v6 + *(_DWORD *)(this + 16));
  else
    v4 = 0;
  if ( v4 )
  {
    *v4 = *a2;
    v4[2] = 0;
    v4[3] = 0;
    v4[4] = a3;
    v4[5] = 0;
  }
  return v6;
}
