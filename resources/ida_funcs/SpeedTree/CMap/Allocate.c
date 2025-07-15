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


unsigned int __thiscall SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::SInstanceLod,1>,1>::Allocate(
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
    *(_DWORD *)(v4 + 4) = &SpeedTree::CArray<SpeedTree::SInstanceLod,1>::`vftable';
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
