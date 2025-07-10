void __thiscall SpeedTree::CForest::RemoveDeletedCells(
        SpeedTree::CForest *this,
        struct SpeedTree::SForestCullResults *a2)
{
  if ( this->m_bCellDeletedSinceLastCull )
  {
    if ( SpeedTree::CArray<SpeedTree::CTreeCell const *,1>::reserve(
           (SpeedTree::CArray<SpeedTree::CCore *,1> *)&a2->m_aVisibleCells,
           0) )
    {
      a2->m_aVisibleCells.m_uiSize = 0;
    }
    else
    {
      a2->m_aVisibleCells.m_uiSize = a2->m_aVisibleCells.m_uiDataSize;
    }
  }
}
