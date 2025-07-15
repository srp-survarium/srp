void __thiscall vostok::particle::particle_action_kill_volume::update(
        vostok::particle::particle_action_kill_volume *this,
        vostok::particle::particle_emitter_instance *instance,
        vostok::particle::base_particle *P,
        float time)
{
  bool v4; // zf
  vostok::math::float4x4 *p_m_second_inverted_transform; // esi
  vostok::math::float3 point; // [esp+10h] [ebp-58h] BYREF
  vostok::math::float3 v7; // [esp+1Ch] [ebp-4Ch]
  float v8[16]; // [esp+28h] [ebp-40h] BYREF

  v4 = !instance->m_world_space;
  point = P->position;
  if ( !v4 )
  {
    p_m_second_inverted_transform = &instance->m_second_inverted_transform;
    if ( !instance->m_use_second_transform )
      p_m_second_inverted_transform = &instance->m_first_inverted_transform;
    qmemcpy(v8, p_m_second_inverted_transform, sizeof(v8));
    v7.x = (float)((float)((float)(v8[0] * point.x) + (float)(v8[8] * point.z)) + (float)(point.y * v8[4])) + v8[12];
    v7.y = (float)((float)((float)(v8[9] * point.z) + (float)(point.x * v8[1])) + (float)(v8[5] * point.y)) + v8[13];
    v7.z = (float)((float)((float)(v8[2] * point.x) + (float)(v8[10] * point.z)) + (float)(v8[6] * point.y)) + v8[14];
    point = v7;
  }
  if ( this->m_kill_inside )
  {
    if ( !vostok::particle::particle_domain_complex::inside(&point, &this->m_domain) )
      return;
  }
  else if ( vostok::particle::particle_domain_complex::inside(&point, &this->m_domain) )
  {
    return;
  }
  P->lifetime = FLOAT_1000_0;
  P->duration = s_spot_max_distance;
}
