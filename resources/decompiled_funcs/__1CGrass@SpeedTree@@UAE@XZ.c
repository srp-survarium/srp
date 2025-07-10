void __thiscall SpeedTree::CGrass::~CGrass(SpeedTree::CGrass *this)
{
  SpeedTree::CArray<unsigned char,1> *p_m_aBladeTexCoordsUChar; // [esp+4Ch] [ebp-24h]

  this->__vftable = (SpeedTree::CGrass_vtbl *)&SpeedTree::CGrass::`vftable';
  p_m_aBladeTexCoordsUChar = &this->m_aBladeTexCoordsUChar;
  this->m_aBladeTexCoordsUChar.__vftable = (SpeedTree::CArray<unsigned char,1>_vtbl *)&SpeedTree::CArray<unsigned char,1>::`vftable';
  if ( this->m_aBladeTexCoordsUChar.m_bExternalMemory )
    SpeedTree::CArray<unsigned char,1>::SetExternalMemory(0, 0);
  SpeedTree::CArray<unsigned char,1>::clear(p_m_aBladeTexCoordsUChar);
  this->m_aBladeTexCoords.__vftable = (SpeedTree::CArray<float,1>_vtbl *)&SpeedTree::CArray<float,1>::`vftable';
  if ( this->m_aBladeTexCoords.m_bExternalMemory )
    SpeedTree::CArray<float,1>::SetExternalMemory(0, 0);
  SpeedTree::CArray<int,1>::clear(&this->m_aBladeTexCoords);
  this->m_strTexture.__vftable = (SpeedTree::CBasicFixedString<256>_vtbl *)&SpeedTree::CBasicFixedString<1024>::`vftable';
  this->m_cGrassCellMap.__vftable = (SpeedTree::CCellContainer<SpeedTree::CGrassCell>_vtbl *)&SpeedTree::CCellContainer<SpeedTree::CGrassCell>::`vftable';
  this->m_cGrassCellMap.__vftable = (SpeedTree::CCellContainer<SpeedTree::CGrassCell>_vtbl *)&SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CGrassCell,1>::`vftable';
  SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CGrassCell,1>::clear(&this->m_cGrassCellMap);
  this->m_cGrassCellMap.m_cPool.__vftable = (SpeedTree::CBlockPool<1>_vtbl *)&SpeedTree::CBlockPool<1>::`vftable';
  SpeedTree::CBlockPool<1>::clear(&this->m_cGrassCellMap.m_cPool, 0);
  SpeedTree::CCellBaseTreeItr::~CCellBaseTreeItr((SpeedTree::CCellBaseTreeItr *)&this->m_cWind);
}
