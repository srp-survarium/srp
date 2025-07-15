void __userpurge vostok::particle::particle_action_initial_rotation_rate::init(
        vostok::particle::particle_action_initial_rotation_rate *this@<ecx>,
        unsigned int a2@<edi>,
        vostok::particle::particle_emitter_instance *instance,
        vostok::particle::base_particle *P,
        float time)
{
  int v5; // edx
  vostok::math::curve_line_ranged_xyz_float *v6; // ecx
  vostok::math::float3 *v7; // eax
  unsigned int m_seed; // [esp+8h] [ebp-28h]
  vostok::math::float3 v9; // [esp+18h] [ebp-18h] BYREF
  vostok::math::float3 v10; // [esp+24h] [ebp-Ch] BYREF

  m_seed = P->m_seed;
  memset(&v10, 0, sizeof(v10));
  vostok::particle::particle_emitter_instance::get_linear_emitter_time((vostok::particle::particle_emitter_instance *)this);
  v7 = vostok::math::curve_line_ranged_xyz_float::evaluate(v6, v5 + 24, 0.0, &v9, 0.0, &v10, m_seed, a2);
  P->start_rotation_rate = *v7;
  P->rotation_rate = *v7;
}
