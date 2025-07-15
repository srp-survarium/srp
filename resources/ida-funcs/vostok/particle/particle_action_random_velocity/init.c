void __thiscall vostok::particle::particle_action_random_velocity::init(
        vostok::particle::particle_action_random_velocity *this,
        vostok::particle::particle_emitter_instance *instance,
        vostok::particle::base_particle *P,
        float time)
{
  vostok::particle::particle_domain_complex *p_m_domain; // eax
  vostok::math::float3 *v5; // esi
  vostok::particle::particle_emitter_instance *v6; // ecx
  vostok::math::float4x4 *transform; // eax
  vostok::particle::particle_domain_complex *v8; // ecx
  float y; // xmm1_4
  float z; // xmm0_4
  float x; // xmm2_4
  float v12; // xmm4_4
  vostok::math::float3 *v13; // eax
  bool v14; // zf
  vostok::math::float4x4 *v15; // eax
  float v16; // xmm1_4
  float v17; // xmm0_4
  float v18; // xmm1_4
  vostok::math::float3 *p_position; // eax
  float m_velocity_multiplier; // xmm0_4
  float v22; // [esp+14h] [ebp-64h] BYREF
  float v23; // [esp+18h] [ebp-60h]
  float v24; // [esp+1Ch] [ebp-5Ch]
  vostok::math::float3 v25; // [esp+20h] [ebp-58h] BYREF
  vostok::math::float3 position; // [esp+2Ch] [ebp-4Ch] BYREF
  vostok::math::float4x4 v27; // [esp+38h] [ebp-40h] BYREF

  p_m_domain = &this->m_domain;
  if ( instance->m_emitter->m_world_space )
  {
    v5 = vostok::particle::particle_domain_complex::generate(
           (vostok::particle::particle_domain_complex *)&v25,
           p_m_domain,
           &v25.x);
    transform = vostok::particle::particle_emitter_instance::get_transform(v6, instance, &v27);
    y = v5->y;
    z = v5->z;
    x = v5->x;
    v12 = transform->j.y;
    position.x = (float)((float)(transform->j.x * y) + (float)(transform->k.x * z)) + (float)(transform->i.x * v5->x);
    position.y = (float)((float)(transform->i.y * x) + (float)(v12 * y)) + (float)(transform->k.y * z);
    position.z = (float)((float)(transform->i.z * x) + (float)(transform->j.z * y)) + (float)(transform->k.z * z);
    v13 = &position;
  }
  else
  {
    v13 = vostok::particle::particle_domain_complex::generate(
            (vostok::particle::particle_domain_complex *)&v22,
            p_m_domain,
            &v22);
  }
  P->start_velocity = *v13;
  vostok::particle::particle_domain_complex::generate(v8, &this->m_domain, &v25.x);
  v14 = !instance->m_emitter->m_world_space;
  position = P->position;
  v22 = v25.x - position.x;
  v23 = v25.y - position.y;
  v24 = v25.z - position.z;
  if ( v14 )
  {
    p_position = (vostok::math::float3 *)&v22;
  }
  else
  {
    v15 = vostok::particle::particle_emitter_instance::get_transform(
            (vostok::particle::particle_emitter_instance *)&v27,
            instance,
            &v27);
    v16 = v15->j.y * v23;
    position.x = (float)((float)(v15->k.x * v24) + (float)(v15->j.x * v23)) + (float)(v15->i.x * v22);
    v17 = (float)((float)(v15->k.y * v24) + v16) + (float)(v15->i.y * v22);
    v18 = v15->j.z * v23;
    position.y = v17;
    position.z = (float)((float)(v15->k.z * v24) + v18) + (float)(v15->i.z * v22);
    p_position = &position;
  }
  m_velocity_multiplier = this->m_velocity_multiplier;
  v25.x = p_position->x * m_velocity_multiplier;
  v25.y = p_position->y * m_velocity_multiplier;
  v25.z = p_position->z * m_velocity_multiplier;
  P->start_velocity = v25;
  P->velocity.x = P->velocity.x + P->start_velocity.x;
  P->velocity.y = P->start_velocity.y + P->velocity.y;
  P->velocity.z = P->start_velocity.z + P->velocity.z;
}
