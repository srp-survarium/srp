char __thiscall SpeedTree::SLeafCards::HasGeometry(SpeedTree::SLeafCards *this)
{
  int i; // [esp+4h] [ebp-4h]

  if ( this->m_nNumMaterialGroups > 0 && this->m_pDrawCallInfo && this->m_pPositions )
  {
    for ( i = 0; i < this->m_nNumMaterialGroups; ++i )
    {
      if ( this->m_pDrawCallInfo[i].m_nLength > 0 )
        return 1;
    }
  }
  return 0;
}
