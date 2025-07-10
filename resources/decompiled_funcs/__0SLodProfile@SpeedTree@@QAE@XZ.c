SpeedTree::SLodProfile *__thiscall SpeedTree::SLodProfile::SLodProfile(SpeedTree::SLodProfile *this)
{
  this->m_fHighDetail3dDistance = 300.0;
  this->m_fLowDetail3dDistance = 1200.0;
  this->m_fBillboardStartDistance = 1300.0;
  this->m_fBillboardFinalDistance = 1500.0;
  this->m_bLodIsPresent = 1;
  SpeedTree::SLodProfile::ComputeDerived(this);
  return this;
}
