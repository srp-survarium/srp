unsigned int __thiscall SpeedTree::CRandom::GetRawInteger(SpeedTree::CRandom *this)
{
  unsigned int v3; // [esp+1Ch] [ebp-4h]
  unsigned int v4; // [esp+1Ch] [ebp-4h]

  if ( !this->m_nCount )
    SpeedTree::CRandom::Reload(this);
  --this->m_nCount;
  v3 = *this->m_pNext++;
  v4 = v3 ^ (v3 >> 11) ^ ((v3 ^ (v3 >> 11)) << 7) & 0x9D2C5680;
  return v4 ^ (v4 << 15) & 0xEFC60000 ^ ((v4 ^ (v4 << 15) & 0xEFC60000) >> 18);
}
