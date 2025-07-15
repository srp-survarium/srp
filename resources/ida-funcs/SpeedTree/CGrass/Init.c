char __thiscall SpeedTree::CGrass::Init(SpeedTree::CGrass *this, char *buf, int a3, int a4, float a5)
{
  char v7; // [esp+47h] [ebp-1h]

  v7 = 0;
  if ( SpeedTree::CCore::IsAuthorized() )
  {
    SpeedTree::CBasicFixedString<1024>::operator=((int)&this->m_strTexture, (unsigned __int8 *)buf);
    this->m_nNumImageRows = a3;
    this->m_nNumImageCols = a4;
    this->m_cGrassCellMap.m_fCellSize = a5;
    SpeedTree::CMap<SpeedTree::SCellKey,SpeedTree::CGrassCell,1>::clear(&this->m_cGrassCellMap);
    SpeedTree::CGrass::BuildTexCoordTable(this);
    return 1;
  }
  else
  {
    SpeedTree::CCore::SetError("Grass system failed to initialize, SDK has not been authorized; expired eval key?");
  }
  return v7;
}
