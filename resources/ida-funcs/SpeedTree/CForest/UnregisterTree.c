char __thiscall SpeedTree::CForest::UnregisterTree(SpeedTree::CForest *this, const struct SpeedTree::CCore *a2)
{
  unsigned int i; // [esp+14h] [ebp-8h]
  char v5; // [esp+1Ah] [ebp-2h]
  char v6; // [esp+1Bh] [ebp-1h]

  v6 = 0;
  v5 = 0;
  for ( i = 0; i < this->m_aBaseTrees.m_uiSize; ++i )
  {
    if ( !a2 || this->m_aBaseTrees.m_pData[i] == a2 )
    {
      SpeedTree::CForest::ClearInstances(this, a2, 1);
      SpeedTree::CArray<SpeedTree::CCore *,1>::erase((unsigned __int8 *)&this->m_aBaseTrees.m_pData[i--]);
      v5 = 1;
      if ( a2 )
        break;
    }
  }
  if ( !a2 || v5 )
  {
    this->m_bBaseTreesChanged = 1;
    return 1;
  }
  else
  {
    SpeedTree::CCore::SetError("CForest::UnregisterTree, cannot find CTree pointer %p", a2);
  }
  return v6;
}
