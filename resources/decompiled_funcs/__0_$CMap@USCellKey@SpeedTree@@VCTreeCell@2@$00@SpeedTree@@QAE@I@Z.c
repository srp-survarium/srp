char *__thiscall SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CTreeCell,1>::CMap<SpeedTree::SCellKey,SpeedTree::CTreeCell,1>(
        char *this,
        unsigned int uiSize)
{
  *(_DWORD *)this = &SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CTreeCell,1>::`vftable';
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = &SpeedTree::CBlockPool<1>::`vftable';
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 7) = 0;
  *((_DWORD *)this + 8) = 160;
  SpeedTree::CBlockPool<1>::resize((SpeedTree::CBlockPool<1> *)(this + 12), uiSize);
  return this;
}
