int __thiscall SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::CInstance,1>,1>::`vector deleting destructor'(
        int this,
        char a2)
{
  *(_DWORD *)this = &SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::CInstance,1>,1>::`vftable';
  SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::CInstance,1>,1>::clear((_DWORD *)this);
  *(_DWORD *)(this + 12) = &SpeedTree::CBlockPool<1>::`vftable';
  SpeedTree::CBlockPool<1>::clear((SpeedTree::CBlockPool<1> *)(this + 12), 0);
  if ( (a2 & 1) != 0 )
    operator delete((void *)this);
  return this;
}
