int __thiscall SpeedTree::SForestCullResults::VisibleInstances(
        SpeedTree::SForestCullResults *this,
        const SpeedTree::CCore *nBaseTreeIndex)
{
  SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::SInstanceLod,1>,1>::iterator iFind; // [esp+8h] [ebp-8h] BYREF

  nBaseTreeIndex = this->m_pBaseTrees->m_pData[(_DWORD)nBaseTreeIndex];
  SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::SInstanceLod,1>,1>::find(
    &this->m_m3dInstances,
    &iFind,
    &nBaseTreeIndex);
  if ( !iFind.m_pNode )
    return 0;
  if ( iFind.m_pPool )
    return (int)iFind.m_pNode + (unsigned int)iFind.m_pPool->m_pData + 4;
  return 4;
}
