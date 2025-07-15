void __userpurge vostok::particle::particle_action_initial_size::init(
        vostok::particle::particle_action_initial_size *this@<ecx>,
        unsigned int a2@<edi>,
        vostok::particle::particle_emitter_instance *instance,
        vostok::particle::base_particle *P,
        float time)
{
  int v5; // edx
  vostok::math::curve_line_ranged_xyz_float *v6; // ecx
  vostok::math::float3 *v7; // eax
  vostok::math::float3 *p_start_size; // ecx
  vostok::math::float3 *v9; // esi
  vostok::particle::particle_action_initial_size *v10; // eax
  unsigned int m_seed; // [esp+8h] [ebp-2Ch]
  vostok::math::float3 v12; // [esp+18h] [ebp-1Ch] BYREF
  vostok::math::float3 v13; // [esp+24h] [ebp-10h] BYREF
  vostok::particle::particle_action_initial_size *v14; // [esp+30h] [ebp-4h]

  m_seed = P->m_seed;
  v14 = this;
  memset(&v13, 0, sizeof(v13));
  vostok::particle::particle_emitter_instance::get_linear_emitter_time((vostok::particle::particle_emitter_instance *)this);
  v7 = vostok::math::curve_line_ranged_xyz_float::evaluate(v6, v5 + 24, 0.0, &v12, 0.0, &v13, m_seed, a2);
  p_start_size = &P->start_size;
  v9 = v7;
  v10 = v14;
  P->start_size = *v9;
  if ( v10->m_is_square )
    P->start_size.y = p_start_size->x;
  P->size.x = p_start_size->x + P->size.x;
  P->size.y = P->start_size.y + P->size.y;
  P->size.z = P->start_size.z + P->size.z;
}
