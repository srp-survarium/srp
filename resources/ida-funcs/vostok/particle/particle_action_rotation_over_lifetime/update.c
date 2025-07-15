void __userpurge vostok::particle::particle_action_rotation_over_lifetime::update(
        vostok::particle::particle_action_rotation_over_lifetime *this@<ecx>,
        unsigned int a2@<edi>,
        vostok::particle::particle_emitter_instance *instance,
        vostok::particle::base_particle *P,
        float __formal)
{
  float v5; // xmm0_4
  vostok::math::curve_line_ranged_xyz_float *v7; // ecx
  float lifetime; // [esp+0h] [ebp-2Ch]
  unsigned int m_seed; // [esp+8h] [ebp-24h]
  vostok::math::float3 v11; // [esp+14h] [ebp-18h] BYREF
  vostok::math::float3 v12; // [esp+20h] [ebp-Ch] BYREF

  v5 = s_bm_current_air_resistance;
  m_seed = P->m_seed;
  lifetime = P->lifetime;
  v12.x = s_bm_current_air_resistance;
  v12.y = s_bm_current_air_resistance;
  v12.z = s_bm_current_air_resistance;
  vostok::particle::base_particle::get_linear_lifetime_impl((vostok::particle::base_particle *)this, (int)P, lifetime);
  vostok::math::curve_line_ranged_xyz_float::evaluate(
    v7,
    (int)&this->m_rotation_over_life,
    v5,
    &v11,
    v5,
    &v12,
    m_seed,
    a2);
  P->rotation = v11.x * P->rotation;
  P->rotationY = v11.y * P->rotationY;
  P->rotationZ = v11.z * P->rotationZ;
}
