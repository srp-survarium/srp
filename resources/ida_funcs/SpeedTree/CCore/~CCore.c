void __thiscall SpeedTree::CCore::~CCore(SpeedTree::CCore *this)
{
  this->__vftable = (SpeedTree::CCore_vtbl *)&SpeedTree::CCore::`vftable';
  SpeedTree::CCore::DeleteGeometry(this, 0);
  this->m_nNumCollisionObjects = 0;
  SpeedTree::st_delete_array<SpeedTree::SCollisionObject>(&this->m_pCollisionObjects);
  SpeedTree::st_delete_array<char>(this->m_pUserStrings);
  SpeedTree::CBasicString<1>::~CBasicString<1>();
  SpeedTree::CCellBaseTreeItr::~CCellBaseTreeItr((SpeedTree::CCellBaseTreeItr *)&this->m_cWind);
  SpeedTree::SGeometry::~SGeometry(&this->m_sGeometry);
  this->m_strFilename.__vftable = (SpeedTree::CBasicFixedString<256>_vtbl *)&SpeedTree::CBasicFixedString<1024>::`vftable';
}
