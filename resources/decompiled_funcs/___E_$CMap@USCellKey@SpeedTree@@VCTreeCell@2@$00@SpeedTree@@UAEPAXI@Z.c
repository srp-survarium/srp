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
