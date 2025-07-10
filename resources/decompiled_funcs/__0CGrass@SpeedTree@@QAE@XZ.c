SpeedTree::CGrass *__thiscall SpeedTree::CGrass::CGrass(SpeedTree::CGrass *this)
{
  this->__vftable = (SpeedTree::CGrass_vtbl *)&SpeedTree::CGrass::`vftable';
  this->m_fStartFade = 200.0;
  this->m_fEndFade = 700.0;
  SpeedTree::CWind::CWind(&this->m_cWind);
  this->m_nUpdateIndex = 1;
  SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CGrassCell,1>::CMap<SpeedTree::SCellKey,SpeedTree::CGrassCell,1>(0xAu);
  this->m_cGrassCellMap.__vftable = (SpeedTree::CCellContainer<SpeedTree::CGrassCell>_vtbl *)&SpeedTree::CCellContainer<SpeedTree::CGrassCell>::`vftable';
  this->m_cGrassCellMap.m_fCellSize = 1200.0;
  this->m_fGlobalLowPoint = -100.0;
  this->m_fGlobalHighPoint = 100.0;
  this->m_strTexture.__vftable = (SpeedTree::CBasicFixedString<256>_vtbl *)&SpeedTree::CBasicFixedString<1024>::`vftable';
  SpeedTree::CBasicFixedString<1024>::operator=((int)&this->m_strTexture, (unsigned __int8 *)&buf);
  this->m_nNumImageCols = -1;
  this->m_nNumImageRows = -1;
  this->m_aBladeTexCoords.__vftable = (SpeedTree::CArray<float,1>_vtbl *)&SpeedTree::CArray<float,1>::`vftable';
  this->m_aBladeTexCoords.m_pData = 0;
  this->m_aBladeTexCoords.m_uiSize = 0;
  this->m_aBladeTexCoords.m_uiDataSize = 0;
  this->m_aBladeTexCoords.m_bExternalMemory = 0;
  this->m_aBladeTexCoordsUChar.__vftable = (SpeedTree::CArray<unsigned char,1>_vtbl *)&SpeedTree::CArray<unsigned char,1>::`vftable';
  this->m_aBladeTexCoordsUChar.m_pData = 0;
  this->m_aBladeTexCoordsUChar.m_uiSize = 0;
  this->m_aBladeTexCoordsUChar.m_uiDataSize = 0;
  this->m_aBladeTexCoordsUChar.m_bExternalMemory = 0;
  this->m_nHintMaxGrassBladesPerCell = 400;
  this->m_nHintMaxNumVisibleCells = 75;
  return this;
}
