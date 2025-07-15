SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::SInstanceLod,1>,1> *__thiscall SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::SInstanceLod,1>,1>::`vector deleting destructor'(
        SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::SInstanceLod,1>,1> *this,
        char a2)
{
  SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::SInstanceLod,1>,1>::~CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::SInstanceLod,1>,1>(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}


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


char *__thiscall SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CTreeCell,1>::`vector deleting destructor'(
        char *this,
        char a2)
{
  *(_DWORD *)this = &SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CTreeCell,1>::`vftable';
  SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CTreeCell,1>::clear(this);
  *((_DWORD *)this + 3) = &SpeedTree::CBlockPool<1>::`vftable';
  SpeedTree::CBlockPool<1>::clear((SpeedTree::CBlockPool<1> *)(this + 12), 0);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
