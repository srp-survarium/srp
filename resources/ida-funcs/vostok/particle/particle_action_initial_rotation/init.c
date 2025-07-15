void __userpurge vostok::particle::particle_action_initial_rotation::init(
        vostok::particle::particle_action_initial_rotation *this@<ecx>,
        unsigned int a2@<edi>,
        vostok::particle::particle_emitter_instance *instance,
        vostok::particle::base_particle *P,
        float time)
{
  int v5; // edx
  vostok::math::curve_line_ranged_xyz_float *v6; // ecx
  vostok::math::float3 *v7; // eax
  float v8; // xmm2_4
  float v9; // xmm3_4
  unsigned int m_seed; // [esp+8h] [ebp-24h]
  vostok::math::float3 v11; // [esp+14h] [ebp-18h] BYREF
  vostok::math::float3 v12; // [esp+20h] [ebp-Ch] BYREF

  m_seed = P->m_seed;
  memset(&v12, 0, sizeof(v12));
  vostok::particle::particle_emitter_instance::get_linear_emitter_time((vostok::particle::particle_emitter_instance *)this);
  v7 = vostok::math::curve_line_ranged_xyz_float::evaluate(v6, v5 + 24, 0.0, &v11, 0.0, &v12, m_seed, a2);
  v8 = v7->y * 6.2831855;
  v9 = v7->z * 6.2831855;
  P->rotation = P->rotation + (float)(v7->x * 6.2831855);
  P->rotationY = P->rotationY + v8;
  P->rotationZ = P->rotationZ + v9;
}
