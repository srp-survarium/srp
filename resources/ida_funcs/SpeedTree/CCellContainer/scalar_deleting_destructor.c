int __thiscall SpeedTree::CCellContainer<SpeedTree::CGrassCell>::`scalar deleting destructor'(int this, char a2)
{
  *(_DWORD *)this = &SpeedTree::CCellContainer<SpeedTree::CGrassCell>::`vftable';
  *(_DWORD *)this = &SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CGrassCell,1>::`vftable';
  SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CGrassCell,1>::clear((_DWORD *)this);
  *(_DWORD *)(this + 12) = &SpeedTree::CBlockPool<1>::`vftable';
  SpeedTree::CBlockPool<1>::clear((SpeedTree::CBlockPool<1> *)(this + 12), 0);
  if ( (a2 & 1) != 0 )
    operator delete((void *)this);
  return this;
}


char *__thiscall SpeedTree::CCellContainer<SpeedTree::CTreeCell>::`scalar deleting destructor'(char *this, char a2)
{
  *(_DWORD *)this = &SpeedTree::CCellContainer<SpeedTree::CTreeCell>::`vftable';
  *(_DWORD *)this = &SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CTreeCell,1>::`vftable';
  SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CTreeCell,1>::clear(this);
  *((_DWORD *)this + 3) = &SpeedTree::CBlockPool<1>::`vftable';
  SpeedTree::CBlockPool<1>::clear((SpeedTree::CBlockPool<1> *)(this + 12), 0);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
