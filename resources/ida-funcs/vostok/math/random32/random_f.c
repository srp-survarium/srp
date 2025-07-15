double __thiscall vostok::math::random32::random_f(vostok::math::random32 *this, const float range)
{
  unsigned int v2; // eax

  v2 = 134775813 * this->m_seed + 1;
  this->m_seed = v2;
  return (double)(((unsigned int)&loc_100000 * (unsigned __int64)v2) >> 32) * 0.00000095367432 * range;
}


double __thiscall vostok::math::random32::random_f(vostok::math::random32 *this, const float min, const float max)
{
  return vostok::math::random32::random_f(this, 1.0) * (max - min) + min;
}
