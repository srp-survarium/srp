unsigned int __thiscall vostok::math::random32::random(vostok::math::random32 *this, unsigned int range)
{
  unsigned int v2; // eax

  v2 = 134775813 * this->m_seed + 1;
  this->m_seed = v2;
  return (range * (unsigned __int64)v2) >> 32;
}
