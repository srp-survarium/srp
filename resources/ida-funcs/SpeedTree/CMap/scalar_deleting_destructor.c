SpeedTree::CMap<SpeedTree::CCore const *,int,1> *__thiscall SpeedTree::CMap<SpeedTree::CCore const *,int,1>::`scalar deleting destructor'(
        SpeedTree::CMap<SpeedTree::CCore const *,int,1> *this,
        char a2)
{
  SpeedTree::CMap<SpeedTree::CCore const *,int,1>::~CMap<SpeedTree::CCore const *,int,1>(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}


int __thiscall SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CGrassCell,1>::`scalar deleting destructor'(
        int this,
        char a2)
{
  *(_DWORD *)this = &SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CGrassCell,1>::`vftable';
  SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CGrassCell,1>::clear((_DWORD *)this);
  *(_DWORD *)(this + 12) = &SpeedTree::CBlockPool<1>::`vftable';
  SpeedTree::CBlockPool<1>::clear((SpeedTree::CBlockPool<1> *)(this + 12), 0);
  if ( (a2 & 1) != 0 )
    operator delete((void *)this);
  return this;
}
