double __userpurge survarium::weapon_core::get_dispersion_amount@<st0>(
        survarium::weapon_core *this@<ecx>,
        boost::random::linear_congruential_engine<unsigned int,48271,0,2147483647> *a2@<eax>,
        const float max_dispersion,
        const float sigma)
{
  boost::random::linear_congruential_engine<unsigned int,48271,0,2147483647> *v4; // esi
  double v5; // xmm0_8
  double v7; // [esp-4h] [ebp-24h]
  long double v8; // [esp+0h] [ebp-20h]
  long double v9; // [esp+0h] [ebp-20h]
  float v10; // [esp+10h] [ebp-10h]

  v4 = a2 + 265;
  v10 = boost::random::detail::new_uniform_01<float>::operator()<boost::random::linear_congruential_engine<unsigned int,48271,0,2147483647>>(a2 + 265);
  v5 = (float)(s_bm_current_air_resistance
             - boost::random::detail::new_uniform_01<float>::operator()<boost::random::linear_congruential_engine<unsigned int,48271,0,2147483647>>(v4));
  __libm_sse2_log(v8);
  *(float *)&v5 = v5;
  __libm_sse2_cos(v9);
  LODWORD(v7) = &sigma;
  return modf((float)((float)(v10 * 6.2831855) * fsqrt(*(float *)&v5 * -2.0)) * sigma, v7) * max_dispersion * 0.5;
}
