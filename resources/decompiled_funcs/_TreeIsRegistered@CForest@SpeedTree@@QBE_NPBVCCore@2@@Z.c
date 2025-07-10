char __thiscall SpeedTree::CForest::TreeIsRegistered(SpeedTree::CForest *this, const struct SpeedTree::CCore *a2)
{
  unsigned int i; // [esp+8h] [ebp-8h]
  char v4; // [esp+Fh] [ebp-1h]

  v4 = 0;
  if ( a2 )
  {
    for ( i = 0; i < this->m_aBaseTrees.m_uiSize; ++i )
    {
      if ( a2 == this->m_aBaseTrees.m_pData[i] )
        return 1;
    }
  }
  return v4;
}
