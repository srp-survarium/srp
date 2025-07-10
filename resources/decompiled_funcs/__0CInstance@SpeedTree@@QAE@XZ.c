SpeedTree::CInstance *__thiscall SpeedTree::CInstance::CInstance(SpeedTree::CInstance *this)
{
  this->m_vPos.x = 0.0;
  this->m_vPos.y = 0.0;
  this->m_vPos.z = 0.0;
  this->m_fScale = 1.0;
  this->m_vGeometricCenter.x = 0.0;
  this->m_vGeometricCenter.y = 0.0;
  this->m_vGeometricCenter.z = 0.0;
  this->m_fCullingRadius = 0.0;
  SpeedTree::CInstance::SetRotation(this, 0.0);
  return this;
}
