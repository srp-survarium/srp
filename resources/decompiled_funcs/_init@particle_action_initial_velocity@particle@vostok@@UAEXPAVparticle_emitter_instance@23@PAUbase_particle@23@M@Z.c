void __thiscall vostok::particle::particle_action_initial_velocity::init(
        vostok::particle::particle_action_initial_velocity *this,
        vostok::particle::particle_emitter_instance *instance,
        vostok::particle::base_particle *P,
        float time)
{
  _BYTE *v4; // eax
  const vostok::math::float3 *v5; // eax
  float other_y; // [esp+4h] [ebp-64h]
  const vostok::math::float3 *other_z; // [esp+8h] [ebp-60h]
  boost::_bi::list1<vostok::network_core::packet_reader &> *m_seed; // [esp+10h] [ebp-58h]
  vostok::math::float3 *p_vel; // [esp+14h] [ebp-54h]
  vostok::math::float3 v11; // [esp+3Ch] [ebp-2Ch] BYREF
  vostok::math::float3 *v12; // [esp+48h] [ebp-20h]
  vostok::math::float3 v13; // [esp+4Ch] [ebp-1Ch] BYREF
  char v14; // [esp+5Bh] [ebp-Dh]
  vostok::math::float3 vel; // [esp+5Ch] [ebp-Ch] BYREF

  v14 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( *v4 )
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)instance);
  m_seed = (boost::_bi::list1<vostok::network_core::packet_reader &> *)P->m_seed;
  vostok::math::float3::float3(&v13, COERCE_UNSIGNED_INT(0.0), COERCE_UNSIGNED_INT(0.0), 0.0);
  other_z = v5;
  other_y = vostok::particle::particle_emitter_instance::get_linear_emitter_time(instance);
  vostok::particle::curve_line_ranged_xyz_float::evaluate(
    &this->m_init_velocity,
    &vel,
    other_y,
    other_z,
    range_time_type,
    m_seed);
  if ( instance->m_emitter->m_world_space )
    p_vel = vostok::math::float4x4::transform_direction(&vel, &v11, &instance->m_transform);
  else
    p_vel = &vel;
  v12 = p_vel;
  P->start_velocity = *p_vel;
  vostok::math::float3_pod::operator+=(&P->start_velocity, &P->velocity);
}
