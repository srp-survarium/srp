double __cdecl vostok::particle::random_float(float min_value, float max_value)
{
  randomizer_173.m_seed = 134775813 * randomizer_173.m_seed + 1;
  return (1.0 - (double)((0xFFFF * (unsigned __int64)randomizer_173.m_seed) >> 32) * 0.000015259022) * min_value
       + (double)((0xFFFF * (unsigned __int64)randomizer_173.m_seed) >> 32) * 0.000015259022 * max_value;
}
