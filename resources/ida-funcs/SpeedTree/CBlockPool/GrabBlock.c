unsigned int __thiscall SpeedTree::CBlockPool<1>::GrabBlock(SpeedTree::CBlockPool<1> *this)
{
  if ( !this->m_uiCurrent )
    SpeedTree::CBlockPool<1>::resize(this, 2 * this->m_uiSize + 1);
  return this->m_pFreeLocations[--this->m_uiCurrent];
}
