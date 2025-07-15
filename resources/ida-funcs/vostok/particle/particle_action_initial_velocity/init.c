void __userpurge vostok::particle::particle_action_initial_velocity::init(
        vostok::particle::particle_action_initial_velocity *this@<ecx>,
        unsigned int a2@<edi>,
        vostok::particle::particle_emitter_instance *instance,
        vostok::particle::base_particle *P,
        float time)
{
  int v5; // edx
  vostok::math::curve_line_ranged_xyz_float *v6; // ecx
  vostok::particle::particle_emitter_instance *v7; // ecx
  vostok::math::float4x4 *transform; // eax
  float v9; // xmm1_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  vostok::math::float3 *v12; // esi
  unsigned int m_seed; // [esp+8h] [ebp-68h]
  vostok::math::float4x4 v14; // [esp+18h] [ebp-58h] BYREF
  vostok::math::float3 v15; // [esp+58h] [ebp-18h] BYREF
  vostok::math::float3 v16; // [esp+64h] [ebp-Ch] BYREF

  m_seed = P->m_seed;
  memset(&v15, 0, sizeof(v15));
  vostok::particle::particle_emitter_instance::get_linear_emitter_time((vostok::particle::particle_emitter_instance *)this);
  vostok::math::curve_line_ranged_xyz_float::evaluate(v6, v5 + 24, 0.0, &v16, 0.0, &v15, m_seed, a2);
  if ( instance->m_emitter->m_world_space )
  {
    transform = vostok::particle::particle_emitter_instance::get_transform(v7, instance, &v14);
    v9 = transform->j.y * v16.y;
    v15.x = (float)((float)(transform->k.x * v16.z) + (float)(transform->j.x * v16.y)) + (float)(transform->i.x * v16.x);
    v10 = (float)((float)(transform->k.y * v16.z) + v9) + (float)(transform->i.y * v16.x);
    v11 = transform->j.z * v16.y;
    v15.y = v10;
    v15.z = (float)((float)(transform->k.z * v16.z) + v11) + (float)(transform->i.z * v16.x);
    v12 = &v15;
  }
  else
  {
    v12 = &v16;
  }
  P->start_velocity = *v12;
  P->velocity.x = P->velocity.x + P->start_velocity.x;
  P->velocity.y = P->start_velocity.y + P->velocity.y;
  P->velocity.z = P->start_velocity.z + P->velocity.z;
}
