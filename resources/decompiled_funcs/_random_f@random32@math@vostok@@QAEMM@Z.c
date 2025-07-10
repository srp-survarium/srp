double __thiscall vostok::math::random32::random_f(vostok::math::random32 *this, float range)
{
  unsigned int v2; // eax

  v2 = 134775813 * this->m_seed + 1;
  this->m_seed = v2;
  return (double)((unsigned __int64)v2 >> 12) * 0.00000095367432 * range;
}
