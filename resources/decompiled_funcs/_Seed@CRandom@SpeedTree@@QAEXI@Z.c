void __thiscall SpeedTree::CRandom::Seed(SpeedTree::CRandom *this, unsigned int a2)
{
  unsigned int i; // [esp+1Ch] [ebp-Ch]
  unsigned int *v4; // [esp+20h] [ebp-8h]
  unsigned int *m_auiTable; // [esp+24h] [ebp-4h]

  this->m_uiSeed = a2;
  memset((int)this->m_auiTable, 0, sizeof(this->m_auiTable));
  m_auiTable = this->m_auiTable;
  this->m_auiTable[0] = this->m_uiSeed;
  v4 = &this->m_auiTable[1];
  for ( i = 1; i < 0x270; ++i )
  {
    *v4++ = i + 1812433253 * (*m_auiTable ^ (*m_auiTable >> 30));
    ++m_auiTable;
  }
  SpeedTree::CRandom::Reload(this);
}
