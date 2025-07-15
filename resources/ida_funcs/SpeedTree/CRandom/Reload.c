void __thiscall SpeedTree::CRandom::Reload(SpeedTree::CRandom *this)
{
  int j; // [esp+10h] [ebp-Ch]
  int i; // [esp+14h] [ebp-8h]
  unsigned int *m_auiTable; // [esp+18h] [ebp-4h]

  m_auiTable = this->m_auiTable;
  for ( i = 227; i; --i )
  {
    *m_auiTable = -(m_auiTable[1] & 1)
                & 0x9908B0DF
                ^ m_auiTable[397]
                ^ ((m_auiTable[1] & 0x7FFFFFFF | *m_auiTable & 0x80000000) >> 1);
    ++m_auiTable;
  }
  for ( j = 397; j; --j )
  {
    *m_auiTable = -(m_auiTable[1] & 1)
                & 0x9908B0DF
                ^ *(m_auiTable - 227)
                ^ ((m_auiTable[1] & 0x7FFFFFFF | *m_auiTable & 0x80000000) >> 1);
    ++m_auiTable;
  }
  *m_auiTable = -(this->m_auiTable[0] & 1)
              & 0x9908B0DF
              ^ *(m_auiTable - 227)
              ^ ((this->m_auiTable[0] & 0x7FFFFFFF | *m_auiTable & 0x80000000) >> 1);
  this->m_nCount = 624;
  this->m_pNext = this->m_auiTable;
}
