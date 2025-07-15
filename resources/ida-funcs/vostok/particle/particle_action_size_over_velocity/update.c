void __userpurge vostok::particle::particle_action_size_over_velocity::update(
        vostok::particle::particle_action_size_over_velocity *this@<ecx>,
        unsigned int a2@<edi>,
        vostok::particle::particle_emitter_instance *instance,
        vostok::particle::base_particle *P,
        float time)
{
  double lifetime; // st7
  unsigned int m_seed; // ebx
  float v8; // xmm0_4
  vostok::math::curve_line_ranged_xyz_float *v10; // ecx
  vostok::math::float3 *v11; // eax
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // [esp+8h] [ebp-2Ch]
  vostok::math::float3 v16; // [esp+18h] [ebp-1Ch] BYREF
  vostok::math::float3 v17; // [esp+24h] [ebp-10h] BYREF
  float v18; // [esp+30h] [ebp-4h]
  float v19; // [esp+40h] [ebp+Ch]

  lifetime = P->lifetime;
  m_seed = P->m_seed;
  v19 = fsqrt(
          (float)((float)(P->velocity.y * P->velocity.y) + (float)(P->velocity.z * P->velocity.z))
        + (float)(P->velocity.x * P->velocity.x));
  v8 = s_bm_current_air_resistance;
  v14 = lifetime;
  v17.x = s_bm_current_air_resistance;
  v17.y = s_bm_current_air_resistance;
  v17.z = s_bm_current_air_resistance;
  vostok::particle::base_particle::get_linear_lifetime_impl((vostok::particle::base_particle *)this, (int)P, v14);
  v18 = v8;
  v11 = vostok::math::curve_line_ranged_xyz_float::evaluate(
          v10,
          (int)&this->m_size_over_velocity,
          v8,
          &v16,
          v8,
          &v17,
          m_seed,
          a2);
  v12 = (float)(v11->y * v19) * P->size.y;
  v13 = (float)(v11->z * v19) * P->size.z;
  P->size.x = (float)(v19 * v11->x) * P->size.x;
  P->size.y = v12;
  P->size.z = v13;
}
