void __thiscall SpeedTree::CCellContainer<SpeedTree::CTreeCell>::~CCellContainer<SpeedTree::CTreeCell>(char *this)
{
  *(_DWORD *)this = &SpeedTree::CCellContainer<SpeedTree::CTreeCell>::`vftable';
  *(_DWORD *)this = &SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CTreeCell,1>::`vftable';
  SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CTreeCell,1>::clear(this);
  *((_DWORD *)this + 3) = &SpeedTree::CBlockPool<1>::`vftable';
  SpeedTree::CBlockPool<1>::clear((SpeedTree::CBlockPool<1> *)(this + 12), 0);
}
