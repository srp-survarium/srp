void __userpurge SpeedTree::CForest::SetWindLeader(const SpeedTree::CWind *pLeader@<eax>, SpeedTree::CForest *this)
{
  SpeedTree::CWind *p_m_cWindLeader; // ebp
  unsigned int i; // esi
  SpeedTree::CWind *Wind; // eax

  p_m_cWindLeader = &this->m_cWindLeader;
  qmemcpy(&this->m_cWindLeader, pLeader, sizeof(this->m_cWindLeader));
  for ( i = 0; i < this->m_aBaseTrees.m_uiSize; ++i )
  {
    Wind = SpeedTree::CCore::GetWind(this->m_aBaseTrees.m_pData[i]);
    SpeedTree::CWind::SetWindLeader(Wind, p_m_cWindLeader);
  }
  SpeedTree::CWind::SetWindLeader(p_m_cWindLeader, 0);
}
