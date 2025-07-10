char __thiscall SpeedTree::CForest::RegisterTree(SpeedTree::CForest *this, struct SpeedTree::CCore *tNew)
{
  SpeedTree::CWind *v2; // eax
  float m_fGlobalWindStrength; // [esp+0h] [ebp-54h]
  struct SpeedTree::CWind *Wind; // [esp+4Ch] [ebp-8h]
  char v7; // [esp+53h] [ebp-1h]

  v7 = 0;
  if ( tNew )
  {
    SpeedTree::CArray<SpeedTree::CCore *,1>::push_back(&this->m_aBaseTrees, &tNew);
    Wind = SpeedTree::CCore::GetWind(tNew);
    SpeedTree::CWind::SetWindLeader(Wind, &this->m_cWindLeader);
    m_fGlobalWindStrength = this->m_fGlobalWindStrength;
    v2 = SpeedTree::CCore::GetWind(tNew);
    SpeedTree::CWind::SetStrength(v2, m_fGlobalWindStrength);
    this->m_bBaseTreesChanged = 1;
    return 1;
  }
  else
  {
    SpeedTree::CCore::SetError("CForest::RegisterTree, NULL CTree pointer passed in");
  }
  return v7;
}
