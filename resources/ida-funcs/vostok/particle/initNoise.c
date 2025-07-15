int __thiscall vostok::particle::initNoise(void *this)
{
  float *v1; // ecx

  v1 = g;
  do
  {
    randomizer_173.m_seed = 134775813 * randomizer_173.m_seed + 1;
    *v1++ = (double)((unsigned __int64)randomizer_173.m_seed >> 24) * 0.0078125 - s_bm_current_air_resistance;
  }
  while ( (int)v1 < (int)&vostok::linkage_helpers::mixing_n_ary_tree_serializer );
  return 0;
}
