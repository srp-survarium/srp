void __usercall SpeedTree::CForest::SetGlobalWindDirection(
        SpeedTree::CForest *this@<edi>,
        const SpeedTree::Vec3 *vDir@<eax>)
{
  unsigned int i; // esi
  SpeedTree::CWind *Wind; // eax

  this->m_vWindDir = *vDir;
  for ( i = 0; i < this->m_aBaseTrees.m_uiSize; ++i )
  {
    Wind = SpeedTree::CCore::GetWind(this->m_aBaseTrees.m_pData[i]);
    SpeedTree::CWind::SetDirection(Wind, &this->m_vWindDir.x);
  }
  SpeedTree::CWind::SetDirection(&this->m_cWindLeader, &this->m_vWindDir.x);
}
