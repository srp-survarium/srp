char __thiscall SpeedTree::CForest::PopulateAtOnce(
        SpeedTree::CForest *this,
        const struct SpeedTree::CForest::SCompletePopulation *a2)
{
  signed int i; // [esp+2Ch] [ebp-8h]
  char v5; // [esp+33h] [ebp-1h]

  v5 = 0;
  if ( a2->m_aBaseTrees.m_uiSize == a2->m_aaInstances.m_uiSize )
  {
    v5 = 1;
    for ( i = 0; i < (signed int)a2->m_aBaseTrees.m_uiSize; ++i )
    {
      if ( a2->m_aaInstances.m_pData[i].m_uiSize )
        v5 &= SpeedTree::CForest::AddInstances(
                this,
                a2->m_aBaseTrees.m_pData[i],
                a2->m_aaInstances.m_pData[i].m_pData,
                a2->m_aaInstances.m_pData[i].m_uiSize);
    }
  }
  else
  {
    SpeedTree::CCore::SetError("CForest::PopulateAtOnce, sPopulation.m_aBaseTrees and sPopulation.m_aaInstances are not same size");
  }
  return v5;
}
