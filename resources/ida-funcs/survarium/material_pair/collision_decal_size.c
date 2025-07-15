double __usercall survarium::material_pair::collision_decal_size@<st0>(
        survarium::material_pair *this@<ecx>,
        int a2@<esi>)
{
  return (vostok::math::random32::random_f(
            &size_random,
            COERCE_CONST_FLOAT(*(_DWORD *)(a2 + 140) ^ _mask__NegFloat_),
            *(const float *)(a2 + 140))
        + s_bm_current_air_resistance)
       * *(float *)(a2 + 136);
}
