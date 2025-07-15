void __userpurge vostok::particle::particle_action_rotation_over_velocity::update(
        vostok::particle::particle_action_rotation_over_velocity *this@<ecx>,
        unsigned int a2@<edi>,
        vostok::particle::particle_emitter_instance *instance,
        vostok::particle::base_particle *P,
        float __formal)
{
  double lifetime; // st7
  unsigned int m_seed; // edi
  vostok::math::curve_line_ranged_xyz_float *v9; // ecx
  vostok::math::float3 *v10; // eax
  float v11; // xmm0_4
  float v12; // xmm1_4
  float v13; // [esp+8h] [ebp-2Ch]
  vostok::math::float3 v15; // [esp+18h] [ebp-1Ch] BYREF
  vostok::math::float3 v16; // [esp+24h] [ebp-10h] BYREF
  int v17; // [esp+30h] [ebp-4h]
  float v18; // [esp+40h] [ebp+Ch]

  lifetime = P->lifetime;
  m_seed = P->m_seed;
  v18 = fsqrt(
          (float)((float)(P->velocity.y * P->velocity.y) + (float)(P->velocity.z * P->velocity.z))
        + (float)(P->velocity.x * P->velocity.x));
  v13 = lifetime;
  memset(&v16, 0, sizeof(v16));
  vostok::particle::base_particle::get_linear_lifetime_impl((vostok::particle::base_particle *)this, (int)P, v13);
  v17 = 0;
  v10 = vostok::math::curve_line_ranged_xyz_float::evaluate(
          v9,
          (int)&this->m_rotation_over_velocity,
          0.0,
          &v15,
          0.0,
          &v16,
          m_seed,
          a2);
  v11 = v10->y * v18;
  v12 = v10->z * v18;
  if ( this->m_affect_x )
    P->rotation = P->rotation * (float)(v18 * v10->x);
  if ( this->m_affect_y )
    P->rotationY = P->rotationY * v11;
  if ( this->m_affect_z )
    P->rotationZ = P->rotationZ * v12;
}
