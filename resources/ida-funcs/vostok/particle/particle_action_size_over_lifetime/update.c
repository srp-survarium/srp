void __userpurge vostok::particle::particle_action_size_over_lifetime::update(
        vostok::particle::particle_action_size_over_lifetime *this@<ecx>,
        unsigned int a2@<edi>,
        vostok::particle::particle_emitter_instance *instance,
        vostok::particle::base_particle *P,
        float time)
{
  float v5; // xmm0_4
  vostok::math::curve_line_ranged_xyz_float *v7; // ecx
  float lifetime; // [esp+0h] [ebp-30h]
  unsigned int m_seed; // [esp+8h] [ebp-28h]
  vostok::math::float3 v10; // [esp+18h] [ebp-18h] BYREF
  vostok::math::float3 v11; // [esp+24h] [ebp-Ch] BYREF

  v5 = s_bm_current_air_resistance;
  m_seed = P->m_seed;
  lifetime = P->lifetime;
  v11.x = s_bm_current_air_resistance;
  v11.y = s_bm_current_air_resistance;
  v11.z = s_bm_current_air_resistance;
  vostok::particle::base_particle::get_linear_lifetime_impl((vostok::particle::base_particle *)this, (int)P, lifetime);
  vostok::math::curve_line_ranged_xyz_float::evaluate(v7, (int)&this->m_size_over_life, v5, &v10, v5, &v11, m_seed, a2);
  if ( this->m_multiply_x )
    P->size.x = P->size.x * v10.x;
  if ( this->m_multiply_y )
    P->size.y = P->size.y * v10.y;
  if ( this->m_multiply_z )
    P->size.z = P->size.z * v10.z;
}
