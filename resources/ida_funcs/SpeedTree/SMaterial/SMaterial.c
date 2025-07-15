SpeedTree::SMaterial *__thiscall SpeedTree::SMaterial::SMaterial(SpeedTree::SMaterial *this)
{
  this->m_vAmbient.x = 1.0;
  this->m_vAmbient.y = 1.0;
  this->m_vAmbient.z = 1.0;
  this->m_vAmbient.w = 1.0;
  this->m_vDiffuse.x = 1.0;
  this->m_vDiffuse.y = 1.0;
  this->m_vDiffuse.z = 1.0;
  this->m_vDiffuse.w = 1.0;
  this->m_vSpecular.x = 1.0;
  this->m_vSpecular.y = 1.0;
  this->m_vSpecular.z = 1.0;
  this->m_vSpecular.w = 1.0;
  this->m_vEmissive.x = 0.0;
  this->m_vEmissive.y = 0.0;
  this->m_vEmissive.z = 0.0;
  this->m_vEmissive.w = 1.0;
  this->m_fShininess = 30.0;
  this->m_fLightScalar = 1.0;
  this->m_fAlphaScalar = 1.7;
  this->m_fAmbientContrast = 0.0;
  this->m_fTransmissionShadow = 0.0;
  this->m_fTransmissionViewDependence = 0.0;
  this->m_eCullType = CULLTYPE_NONE;
  `eh vector constructor iterator'(
    (char *)this->m_astrTextureFilenames,
    0x108u,
    5,
    SpeedTree::CBasicFixedString<256>::CBasicFixedString<256>,
    (void (__thiscall *)(void *))SpeedTree::SCollisionObject::~SCollisionObject);
  this->m_vTexCoords.x = 0.0;
  this->m_vTexCoords.y = 0.0;
  this->m_vTexCoords.z = 0.0;
  this->m_vTexCoords.w = 1.0;
  this->m_strUserData.__vftable = (SpeedTree::CBasicFixedString<256>_vtbl *)&SpeedTree::CBasicFixedString<1024>::`vftable';
  SpeedTree::CBasicFixedString<1024>::operator=((int)&this->m_strUserData, (unsigned __int8 *)&buf);
  return this;
}
