void __thiscall SpeedTree::CCellInstances::~CCellInstances(SpeedTree::CCellInstances *this)
{
  SpeedTree::CMap<SpeedTree::CCore const *,int,1> *p_m_mBillboardBlocks; // [esp+60h] [ebp-64h]

  this->__vftable = (SpeedTree::CCellInstances_vtbl *)&SpeedTree::CCellInstances::`vftable';
  p_m_mBillboardBlocks = &this->m_mBillboardBlocks;
  this->m_mBillboardBlocks.__vftable = (SpeedTree::CMap<SpeedTree::CCore const *,int,1>_vtbl *)&SpeedTree::CMap<SpeedTree::CCore const *,int,1>::`vftable';
  SpeedTree::CMap<SpeedTree::CCore const *,int,1>::clear(&this->m_mBillboardBlocks);
  p_m_mBillboardBlocks->m_cPool.__vftable = (SpeedTree::CBlockPool<1>_vtbl *)&SpeedTree::CBlockPool<1>::`vftable';
  SpeedTree::CBlockPool<1>::clear(&p_m_mBillboardBlocks->m_cPool, 0);
  this->__vftable = (SpeedTree::CCellInstances_vtbl *)&SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::CInstance,1>,1>::`vftable';
  SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::CInstance,1>,1>::clear(this);
  this->m_cPool.SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::CInstance,1>,1>::__vftable = (SpeedTree::CBlockPool<1>_vtbl *)&SpeedTree::CBlockPool<1>::`vftable';
  SpeedTree::CBlockPool<1>::clear(&this->m_cPool, 0);
}
