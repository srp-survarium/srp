void __userpurge vostok::particle::particle_action_acceleration::update(
        vostok::particle::particle_action_acceleration *this@<ecx>,
        unsigned int a2@<edi>,
        vostok::particle::particle_emitter_instance *instance,
        vostok::particle::base_particle *P,
        float time)
{
  vostok::math::curve_line_ranged_xyz_float *v6; // ecx
  float lifetime; // [esp+0h] [ebp-2Ch]
  unsigned int m_seed; // [esp+8h] [ebp-24h]
  vostok::math::float3 v10; // [esp+14h] [ebp-18h] BYREF
  vostok::math::float3 v11; // [esp+20h] [ebp-Ch] BYREF

  m_seed = P->m_seed;
  lifetime = P->lifetime;
  memset(&v11, 0, sizeof(v11));
  vostok::particle::base_particle::get_linear_lifetime_impl((vostok::particle::base_particle *)this, (int)P, lifetime);
  vostok::math::curve_line_ranged_xyz_float::evaluate(v6, (int)&this->m_acceleration, 0.0, &v10, 0.0, &v11, m_seed, a2);
  P->velocity.x = P->velocity.x + v10.x;
  P->velocity.y = P->velocity.y + v10.y;
  P->velocity.z = P->velocity.z + v10.z;
}
