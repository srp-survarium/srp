SpeedTree::CCore *__thiscall SpeedTree::CCore::CCore(SpeedTree::CCore *this)
{
  int j; // [esp+5Ch] [ebp-14h]
  int i; // [esp+60h] [ebp-10h]

  this->__vftable = (SpeedTree::CCore_vtbl *)&SpeedTree::CCore::`vftable';
  this->m_strFilename.__vftable = (SpeedTree::CBasicFixedString<256>_vtbl *)&SpeedTree::CBasicFixedString<1024>::`vftable';
  SpeedTree::CBasicFixedString<1024>::operator=((unsigned __int8 *)&buf);
  this->m_pSrtBuffer = 0;
  SpeedTree::SGeometry::SGeometry(&this->m_sGeometry);
  SpeedTree::SLodProfile::SLodProfile(&this->m_sLodProfile);
  SpeedTree::SLodProfile::SLodProfile(&this->m_sLodProfileSquared);
  SpeedTree::CWind::CWind(&this->m_cWind);
  SpeedTree::CExtents::CExtents(&this->m_cExtents);
  this->m_nNumCollisionObjects = 0;
  this->m_pCollisionObjects = 0;
  SpeedTree::CBasicString<1>::CBasicString<1>();
  this->m_bOwnsSrtBuffer = 0;
  this->m_bBillboardTexCoordsCopied = 0;
  for ( i = 0; i < 6; ++i )
    this->m_abGeometryTypesPresent[i] = 0;
  for ( j = 0; j < 5; ++j )
    this->m_pUserStrings[j] = 0;
  return this;
}
