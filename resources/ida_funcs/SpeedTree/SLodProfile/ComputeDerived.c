void __thiscall SpeedTree::SLodProfile::ComputeDerived(SpeedTree::SLodProfile *this)
{
  this->m_f3dRange = this->m_fLowDetail3dDistance - this->m_fHighDetail3dDistance;
  this->m_fBillboardRange = this->m_fBillboardFinalDistance - this->m_fBillboardStartDistance;
}
